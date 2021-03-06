// -----------------------------------------------------------------------
// MatchPoint - DKFZ translational registration framework
//
// Copyright (c) German Cancer Research Center (DKFZ),
// Software development for Integrated Diagnostics and Therapy (SIDT).
// ALL RIGHTS RESERVED.
// See mapCopyright.txt or
// http://www.dkfz.de/en/sidt/projects/MatchPoint/copyright.html
//
// This software is distributed WITHOUT ANY WARRANTY; without even
// the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
// PURPOSE.  See the above copyright notices for more information.
//
//------------------------------------------------------------------------
/*!
// @file
// @version $Revision$ (last changed revision)
// @date    $Date$ (last change date)
// @author  $Author$ (last changed by)
// Subversion HeadURL: $HeadURL$
*/

#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif

#include "litCheckMacros.h"
#include "litTestCommand.h"

#include "mapITKRigid3DClosedFormRegistrationAlgorithmTemplate.h"
#include "mapSimpleLandMarkFileReader.h"

namespace map
{
	namespace testing
	{

		namespace
		{
			class RegTestCommand : public lit::TestCommand
			{
			public:
				/** Standard class typedefs. */
				typedef RegTestCommand   Self;
				typedef itk::SmartPointer<Self>    Pointer;

				/** Run-time type information (and related methods). */
				itkTypeMacro(RegTestCommand, TestCommand);

				/** Method for creation through the object factory. */
				itkNewMacro(Self);

			protected:
				virtual void checkEvent(const ::itk::Object* caller, const ::itk::EventObject& e)
				{
					const events::AlgorithmEvent* pChangeEvent = dynamic_cast<const events::AlgorithmEvent*>(&e);

					if (pChangeEvent)
					{
						std::cout << std::endl << pChangeEvent->GetEventName() << " (@" << caller << "): " <<
								  pChangeEvent->getComment() << std::endl;
					}
					else
					{
						std::cout << std::endl << e.GetEventName() << " (@" << caller << ")" << std::endl;
					}
				};

				RegTestCommand() {};
				virtual ~RegTestCommand() {};

			private:
				RegTestCommand(const Self&);  //purposely not implemented
				void operator=(const Self&);  //purposely not implemented
			};
		}

		typedef core::continuous::Elements<3>::InternalPointSetType LandmarksType;

		int mapITKRigid3DClosedFormRegistrationAlgorithmTemplateTest(int argc, char* argv[])
		{
			//ARGUMENTS: 1: moving land marks
			//           2: target land marks

			PREPARE_DEFAULT_TEST_REPORTING;

			std::string movingLMFileName = "";
			std::string targetLMFileName = "";

			if (argc > 1)
			{
				movingLMFileName = argv[1];
			}

			if (argc > 2)
			{
				targetLMFileName = argv[2];
			}

			//load input data
			LandmarksType::Pointer spMovingLMs = utilities::loadLandMarksFromFile<LandmarksType>
												 (movingLMFileName);
			LandmarksType::Pointer spTargetLMs = utilities::loadLandMarksFromFile<LandmarksType>
												 (targetLMFileName);
			LandmarksType::Pointer spMovingLMs2 = utilities::loadLandMarksFromFile<LandmarksType>
												  (movingLMFileName);
			LandmarksType::Pointer spTargetLMs2 = utilities::loadLandMarksFromFile<LandmarksType>
												  (targetLMFileName);


			typedef algorithm::boxed::ITKRigid3DClosedFormRegistrationAlgorithmTemplate<>::Type
			RegistrationAlgorithmType;

			RegistrationAlgorithmType::Pointer spAlgorithm = RegistrationAlgorithmType::New();

			//Add observer for algorithm events.
			RegTestCommand::Pointer spTestCommand = RegTestCommand::New();

			spAlgorithm->AddObserver(::map::events::AlgorithmEvent(), spTestCommand);
			spAlgorithm->AddObserver(::itk::AnyEvent(), spTestCommand);

			//Set land marks
			spAlgorithm->setMovingPointSet(spMovingLMs);
			spAlgorithm->setTargetPointSet(spTargetLMs);

			RegistrationAlgorithmType::RegistrationPointer spRegistration;
			CHECK_NO_THROW(spRegistration = spAlgorithm->getRegistration());

			const core::RegistrationKernel<3, 3>* pInverseKernel =
          dynamic_cast<const core::RegistrationKernel<3, 3>* >(&
						(spRegistration->getInverseMapping()));
      ::map::core::RegistrationKernel<3, 3>::TransformType::ParametersType parameters =
				pInverseKernel->getTransformModel()->GetParameters();

			CHECK_CLOSE(0.0, parameters[0], 0.01);
			CHECK_CLOSE(0.0, parameters[1], 0.01);
			CHECK_CLOSE(0.0, parameters[2], 0.01);
			CHECK_CLOSE(13.0, parameters[3], 0.01);
			CHECK_CLOSE(17.0, parameters[4], 0.01);
			CHECK_CLOSE(5.0, parameters[5], 0.01);

			RegistrationAlgorithmType::RegistrationPointer spRegistration2nd;
			CHECK_NO_THROW(spRegistration2nd = spAlgorithm->getRegistration());
			/** Check for same MTimes because there is no reason to determine the reg again*/
			CHECK(spRegistration->GetMTime() == spRegistration2nd->GetMTime());

			RETURN_AND_REPORT_TEST_SUCCESS;
		}
	} //namespace testing
} //namespace map
