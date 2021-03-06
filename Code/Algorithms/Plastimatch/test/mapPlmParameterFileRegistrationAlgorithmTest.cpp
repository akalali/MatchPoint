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

#include "itksys/SystemTools.hxx"

#include "litCheckMacros.h"
#include "litTestImageIO.h"
#include "litTransformFieldTester.h"
#include "litImageTester.h"
#include "litPointSetTester.h"

#include "mapDiscreteElements.h"
#include "mapPlmParameterFileRegistrationAlgorithm.h"
#include "mapITKTranslationTransform.h"
#include "mapSimpleLandMarkFileReader.h"

namespace map
{
    namespace testing
    {

        //defined by mapAlgorithmsPlastimatchTests.cpp. It is the path to the current running executable.
        //It is needed to bypass 2 problems: 1) that when using MS Visual Studio the actual binary
        //path depends of the compile mode (release/debug) and is not the CMake binary path.
        //2) we want to ensure that the dummy plastimatich is used.
        extern const char* _callingAppPath;

        mapGenerateAlgorithmUIDPolicyMacro(TestPlm3DRegistrationUIDPolicy,
            "de.dkfz.matchpoint.plastimatch.test", "ProgramFileRegistration.3D.default", "1.0.0", "");

        typedef std::vector< ::map::core::String> ArgumentsType;

        ArgumentsType getLoggedArguments(const core::String& logFilePath)
        {
            std::ifstream logFile;
            logFile.open(logFilePath.c_str());

            if (logFile.fail())
            {
                mapDefaultExceptionStaticMacro(<< "Error cannot find or access plastimatchDummyCall.log");
            }

            ::map::core::String item;
            ArgumentsType list;

            while (std::getline(logFile, item))
            {
                list.push_back(item);
            }

            return list;
        }

        ::map::core::String getLoggedTempDir(const ArgumentsType& loggedArguments)
        {
            //the temp dir should be deduced by the 3rd line (plastimatch configuration file)

            if (loggedArguments.size() < 3)
            {
                mapDefaultExceptionStaticMacro(<<
                    "Error. PlastimatchDummyCall.log seems to be invalid, line with configuration file is missing.");
            }

            ::map::core::String dir = loggedArguments[2];
            dir = core::FileDispatch::getPath(dir);

            return dir;
        }

        void onRegistrationEvent(itk::Object* pCaller, const itk::EventObject& e, void*)
        {
            const map::events::AlgorithmEvent* pEvent = dynamic_cast<const map::events::AlgorithmEvent*>(&e);

            if (pEvent)
            {
                std::cout << std::endl << pEvent->GetEventName() << " (@" << pCaller << "): " <<
                    pEvent->getComment() << std::endl;
            }
        }

        typedef itk::TranslationTransform<map::core::continuous::ScalarType, 3> TransformModelType;

        TransformModelType::Pointer generateInverseReferenceTransformModel()
        {
            TransformModelType::Pointer spModel = TransformModelType::New();
            TransformModelType::ParametersType params(3);
            params[0] = 10.0;
            params[1] = -16.0;
            params[2] = -5.0;
            spModel->SetParameters(params);
            return spModel;
        }

        TransformModelType::InverseTransformBaseType::Pointer generateDirectReferenceTransformModel()
        {
            TransformModelType::Pointer spModel = generateInverseReferenceTransformModel();
            TransformModelType::InverseTransformBaseType::Pointer spInvModel;
            spInvModel = spModel->GetInverseTransform();
            return spInvModel;
        }

        int mapPlmParameterFileRegistrationAlgorithmTest(int argc, char* argv[])
        {

            //ARGUMENTS: 1: moving image
            //           2: target image
            //           3: parameter file
            //           4: moving point set
            //           5: target point set

            PREPARE_DEFAULT_TEST_REPORTING;

            ::map::core::String movingImageFileName = "";
            ::map::core::String targetImageFileName = "";
            ::map::core::String paramFileName = "";
            ::map::core::String movingPointSetFileName = "";
            ::map::core::String targetPointSetFileName = "";

            ::map::core::String callingAppPath = _callingAppPath;
            ::map::core::String plastimatichPath = map::core::FileDispatch::getPath(_callingAppPath);

            if (argc > 1)
            {
                movingImageFileName = argv[1];
            }

            if (argc > 2)
            {
                targetImageFileName = argv[2];
            }

            if (argc > 3)
            {
                paramFileName = argv[3];
            }

            if (argc > 4)
            {
              movingPointSetFileName = argv[4];
            }

            if (argc > 5)
            {
              targetPointSetFileName = argv[5];
            }

            //load input data
            typedef map::core::discrete::Elements<3>::InternalImageType ImageType;
            typedef map::core::continuous::Elements<3>::InternalPointSetType PointSetType;

            typedef algorithm::plastimatch::ParameterFileRegistrationAlgorithm < ImageType, ImageType, PointSetType, PointSetType, TestPlm3DRegistrationUIDPolicy >
                Plm3DRegistrationAlgorithmType;

            ImageType::Pointer spMovingImage = lit::TestImageIO<unsigned char, ImageType>::readImage(
                movingImageFileName);
            ImageType::Pointer spTargetImage = lit::TestImageIO<unsigned char, ImageType>::readImage(
                targetImageFileName);

            PointSetType::Pointer movingPoints = ::map::utilities::loadLandMarksFromFile<PointSetType>(movingPointSetFileName);
            PointSetType::Pointer targetPoints = ::map::utilities::loadLandMarksFromFile<PointSetType>(targetPointSetFileName);

            Plm3DRegistrationAlgorithmType::Pointer spAlgorithm = Plm3DRegistrationAlgorithmType::New();

            //Add observer for algorithm events.
            itk::CStyleCommand::Pointer spRegCommand = itk::CStyleCommand::New();
            spRegCommand->SetCallback(&onRegistrationEvent);

            spAlgorithm->AddObserver(map::events::AlgorithmIterationEvent(), spRegCommand);

            ///////////////////////////////////////////////////////
            //Test algorithm execution without images
            CHECK_THROW_EXPLICIT(spAlgorithm->determineRegistration(), algorithm::AlgorithmException);
            CHECK_THROW_EXPLICIT(spAlgorithm->getRegistration(), algorithm::AlgorithmException);

            ::map::core::String testString;
            CHECK(spAlgorithm->getParameterFilePath(testString));
            CHECK_EQUAL("", testString);
            bool delDir;
            CHECK(spAlgorithm->getDeleteTempDirectory(delDir));
            CHECK_EQUAL(true, delDir);
            CHECK(spAlgorithm->getMovingImage().IsNull());
            CHECK(spAlgorithm->getTargetImage().IsNull());

            spAlgorithm->setMovingImage(spMovingImage);
            spAlgorithm->setTargetImage(spTargetImage);
            spAlgorithm->setParameterFilePath(paramFileName);
            spAlgorithm->setPlastimatchDirectory(plastimatichPath);

            ///////////////////////////////////////////////////////
            //Test legal algorithm execution and registration result
            Plm3DRegistrationAlgorithmType::RegistrationPointer spRegistration;
            CHECK_NO_THROW(spRegistration = spAlgorithm->getRegistration());
            CHECK_EQUAL(Plm3DRegistrationAlgorithmType::AlgorithmState::Finalized,
                spAlgorithm->getCurrentState());

            // test result
            typedef lit::TransformFieldTester < map::core::discrete::Elements<3>::VectorFieldType, TransformModelType >
                TesterType;
            TesterType tester;
            typedef map::core::RegistrationKernel<3, 3> KernelBaseType;
            const KernelBaseType* pKernel = dynamic_cast<const KernelBaseType*>(&
                (spRegistration->getInverseMapping()));
            CHECK(pKernel != NULL);

            ::map::core::FieldDecomposer<3, 3>::FieldConstPointer actualField;
            ::map::core::FieldDecomposer<3, 3>::decomposeKernel(pKernel, actualField);

            tester.setReferenceTransform(generateInverseReferenceTransformModel());
            tester.setActualField(actualField);
            tester.setCheckThreshold(0.01);
            CHECK_TESTER(tester);

            ///////////////////////////////////////////////////////
            //Test the correct implementation of DeleteTempDirectory.

            //DeleteTempDirectory is true (see above) -> temp dir must be deleted after algorithm execution
            CHECK(spAlgorithm->getDeleteTempDirectory(delDir));
            CHECK_EQUAL(true, delDir);
            CHECK_NO_THROW(spAlgorithm->determineRegistration());
            ArgumentsType cmdArg = getLoggedArguments(::map::core::FileDispatch::createFullPath(plastimatichPath,"plastimatchDummyCall.log"));
            ::map::core::String tempDir = getLoggedTempDir(cmdArg);

            CHECK(!(itksys::SystemTools::FileExists(tempDir.c_str(), false)));

            //DeleteTempDirectory is false -> temp dir must still exists after algorithm execution
            spAlgorithm->setDeleteTempDirectory(false);
            CHECK(spAlgorithm->getDeleteTempDirectory(delDir));
            CHECK_EQUAL(false, delDir);
            CHECK_NO_THROW(spAlgorithm->determineRegistration());
            cmdArg = getLoggedArguments(::map::core::FileDispatch::createFullPath(plastimatichPath, "plastimatchDummyCall.log"));
            tempDir = getLoggedTempDir(cmdArg);

            CHECK(itksys::SystemTools::FileExists(tempDir.c_str(), false));

            ///////////////////////////////////////////////////////
            //Test the correct temp storage of target and moving image
            //use data of the last run (where the temp dir was not deleted).

            ImageType::Pointer spStoredMovingImage =
                lit::TestImageIO< ::map::core::discrete::InternalPixelType, ImageType>::readImage(
                ::map::core::FileDispatch::createFullPath(tempDir, "moving.mhd"));
            ImageType::Pointer spStoredTargetImage =
                lit::TestImageIO< ::map::core::discrete::InternalPixelType, ImageType>::readImage(
                ::map::core::FileDispatch::createFullPath(tempDir, "target.mhd"));

            lit::ImageTester<ImageType, ImageType> imageTester;

            imageTester.setExpectedImage(spMovingImage);
            imageTester.setActualImage(spStoredMovingImage);
            CHECK_TESTER(imageTester);

            imageTester.setExpectedImage(spTargetImage);
            imageTester.setActualImage(spStoredTargetImage);
            CHECK_TESTER(imageTester);

            //point set files should not exist because they are not set.
            CHECK(!(itksys::SystemTools::FileExists(::map::core::FileDispatch::createFullPath(tempDir, "movingPointSet.txt").c_str(), true)));
            CHECK(!(itksys::SystemTools::FileExists(::map::core::FileDispatch::createFullPath(tempDir, "targetPointSet.txt").c_str(), true)));

            itksys::SystemTools::RemoveADirectory(tempDir.c_str());

            ///////////////////////////////////////////////////////
            //Check other public methods
            spAlgorithm = Plm3DRegistrationAlgorithmType::New();

            CHECK_EQUAL(false, spAlgorithm->hasCurrentOptimizerValue());
            CHECK_EQUAL(false, spAlgorithm->hasMaxIterationCount());
            CHECK_EQUAL(false, spAlgorithm->hasIterationCount());
            CHECK_EQUAL(false, spAlgorithm->isStoppable());

            ::map::core::String envPlastimatchPath = "";
            itksys::SystemTools::GetEnv("MAP_PLASTIMATCH_PATH", envPlastimatchPath);

            ::map::core::String dir;
            CHECK(spAlgorithm->getWorkingDirectory(dir));
            CHECK_EQUAL(itksys::SystemTools::GetCurrentWorkingDirectory(), dir);
            CHECK(spAlgorithm->getPlastimatchDirectory(dir));
            CHECK_EQUAL(envPlastimatchPath, dir);

            spAlgorithm->setWorkingDirectory("../newWorkingDir");
            spAlgorithm->setPlastimatchDirectory("../newPlastimatchDir");
            CHECK(spAlgorithm->getWorkingDirectory(dir));
            CHECK_EQUAL("../newWorkingDir", dir);
            CHECK(spAlgorithm->getPlastimatchDirectory(dir));
            CHECK_EQUAL("../newPlastimatchDir", dir);

            CHECK_EQUAL(true, spAlgorithm->hasCoupledPointSetInputs());
            CHECK_EQUAL(1, spAlgorithm->getTargetPointSetCount());
            CHECK_EQUAL(0, spAlgorithm->getTargetPointSetCount(true));
            CHECK_EQUAL(1, spAlgorithm->getMovingPointSetCount());
            CHECK_EQUAL(0, spAlgorithm->getMovingPointSetCount(true));

            //////////////////////////////////////////////////////////
            //Check of correct temporal mask storage
            //* @TODO Check of correct temporal mask storage

            //////////////////////////////////////////////////////////
            //Check of correct temporal point set storage
            spAlgorithm->setMovingImage(spMovingImage);
            spAlgorithm->setTargetImage(spTargetImage);
            spAlgorithm->setMovingPointSet(movingPoints);
            spAlgorithm->setTargetPointSet(targetPoints);
            spAlgorithm->setParameterFilePath(paramFileName);
            spAlgorithm->setPlastimatchDirectory(plastimatichPath);
            spAlgorithm->setDeleteTempDirectory(false);
            
            spAlgorithm->determineRegistration();
            cmdArg = getLoggedArguments(::map::core::FileDispatch::createFullPath(plastimatichPath, "plastimatchDummyCall.log"));
            tempDir = getLoggedTempDir(cmdArg);

            PointSetType::Pointer storedMovingPoints = ::map::utilities::loadLandMarksFromFile<PointSetType>(::map::core::FileDispatch::createFullPath(tempDir, "movingPointSet.txt"));
            PointSetType::Pointer storedTargetPoints = ::map::utilities::loadLandMarksFromFile<PointSetType>(::map::core::FileDispatch::createFullPath(tempDir, "targetPointSet.txt"));

            lit::PointSetTester<PointSetType> pointTester;

            pointTester.setExpectedPointSet(movingPoints);
            pointTester.setActualPointSet(storedMovingPoints);
            CHECK_TESTER(pointTester);

            pointTester.setExpectedPointSet(targetPoints);
            pointTester.setActualPointSet(storedTargetPoints);
            CHECK_TESTER(pointTester);

            RETURN_AND_REPORT_TEST_SUCCESS;
        }
    } //namespace testing
} //namespace map
