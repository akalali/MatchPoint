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




#ifndef __MAP_PLM_BSPLINE_CLI_REGISTRATION_ALGORITHM_H
#define __MAP_PLM_BSPLINE_CLI_REGISTRATION_ALGORITHM_H

//MatchPoint
#include "mapContinuous.h"

#include "mapPlmCLIRegistrationAlgorithmBase.h"
#include "mapClassMacros.h"

namespace map
{
	namespace algorithm
	{
		namespace boxed
		{

			/*! @class PlmBSplineCLIRegistrationAlgorithm
						@brief The class is a boxed plastimatch BSpline registration algorithm (using CLI, in many aspects similar to the SLICER PLastimatch BSpline plugin).
						The algorithm has three stages (1. rigid registration, 2./3. BSpline registration). It uses plastimatch via CLI and uses auto
						generated parameter files.
			    @ingroup Algorithms
						@ingroup Plastimatch
						@ingroup Boxed
			 */
      template<class TMovingImage, class TTargetImage, class TMovingPointSet, class TTargetPointSet, class TIdentificationPolicy>
      class PlmBSplineCLIRegistrationAlgorithm : public
				plastimatch::CLIRegistrationAlgorithmBase<TMovingImage, TTargetImage, TMovingPointSet, TTargetPointSet, TIdentificationPolicy>
			{
			public:
				typedef PlmBSplineCLIRegistrationAlgorithm<TMovingImage, TTargetImage, TMovingPointSet, TTargetPointSet, TIdentificationPolicy> Self;
				typedef plastimatch::CLIRegistrationAlgorithmBase<TMovingImage, TTargetImage, TMovingPointSet, TTargetPointSet, TIdentificationPolicy>
				Superclass;

				typedef ::itk::SmartPointer<Self>                                     Pointer;
				typedef ::itk::SmartPointer<const Self>                               ConstPointer;
				itkTypeMacro(PlmBSplineCLIRegistrationAlgorithm, CLIRegistrationAlgorithmBase);
				mapNewAlgorithmMacro(Self);

				typedef typename Superclass::UIDType UIDType;
				typedef typename Superclass::UIDPointer UIDPointer;

				typedef typename Superclass::TargetImageType TargetImageType;
				typedef typename Superclass::MovingImageType MovingImageType;
				typedef typename Superclass::MovingRepresentationDescriptorType MovingRepresentationDescriptorType;
				typedef typename Superclass::TargetRepresentationDescriptorType TargetRepresentationDescriptorType;

				typedef typename Superclass::RegistrationPointer RegistrationPointer;
				typedef typename Superclass::RegistrationType RegistrationType;
				typedef typename Superclass::FieldRepRequirement FieldRepRequirement;

			protected:
				PlmBSplineCLIRegistrationAlgorithm();
				virtual ~PlmBSplineCLIRegistrationAlgorithm();

				/*! @reimplemented */
				virtual void prepConfigurationPLM();
			private:

				PlmBSplineCLIRegistrationAlgorithm(const Self& source);  //purposely not implemented
				void operator=(const Self&);  //purposely not implemented
			};

		}
	}
}

#ifndef MatchPoint_MANUAL_TPP
#include "mapPlmBSplineCLIRegistrationAlgorithm.tpp"
#endif

#endif
