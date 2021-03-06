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


#ifndef __ITK_PDE_DEFORMABLE_REGISTRATION_ALGORITHM_TPP
#define __ITK_PDE_DEFORMABLE_REGISTRATION_ALGORITHM_TPP

#include <itkHistogramMatchingImageFilter.h>

#include "mapAlgorithmException.h"

#include "mapRegistrationManipulator.h"
#include "mapAlgorithmWrapperEvent.h"
#include "mapMetaProperty.h"

namespace map
{
	namespace algorithm
	{
		namespace itk
		{

			template < class TImageType, class TIdentificationPolicy, class TDisplacementField, class TInternalRegistrationFilter>
			ITKPDEDeformableRegistrationAlgorithm<TImageType, TIdentificationPolicy, TDisplacementField, TInternalRegistrationFilter>::
			ITKPDEDeformableRegistrationAlgorithm()
			{
			};

			template < class TImageType, class TIdentificationPolicy, class TDisplacementField, class TInternalRegistrationFilter>
			ITKPDEDeformableRegistrationAlgorithm<TImageType, TIdentificationPolicy, TDisplacementField, TInternalRegistrationFilter>::
			~ITKPDEDeformableRegistrationAlgorithm()
			{
			};

			template < class TImageType, class TIdentificationPolicy, class TDisplacementField, class TInternalRegistrationFilter>
			bool
			ITKPDEDeformableRegistrationAlgorithm<TImageType, TIdentificationPolicy, TDisplacementField, TInternalRegistrationFilter>::
			doStopAlgorithm()
			{
				this->getInternalRegistrationMethod().StopRegistration();
				return true;
			};

			template < class TImageType, class TIdentificationPolicy, class TDisplacementField, class TInternalRegistrationFilter>
			void
			ITKPDEDeformableRegistrationAlgorithm<TImageType, TIdentificationPolicy, TDisplacementField, TInternalRegistrationFilter>::
			prepSetInternalInputData()
			{
				//Connect images
				this->InvokeEvent(::map::events::AlgorithmEvent(this, "Connect images to itk registration method."));
				this->getInternalRegistrationMethod().SetFixedImage(this->_spInternalTargetImage);
				this->getInternalRegistrationMethod().SetMovingImage(this->_spInternalMovingImage);
			}

			template < class TImageType, class TIdentificationPolicy, class TDisplacementField, class TInternalRegistrationFilter>
			bool
			ITKPDEDeformableRegistrationAlgorithm<TImageType, TIdentificationPolicy, TDisplacementField, TInternalRegistrationFilter>::
			runAlgorithm()
			{
				this->getInternalRegistrationMethod().Update();
				return true;
			};

			template < class TImageType, class TIdentificationPolicy, class TDisplacementField, class TInternalRegistrationFilter>
			typename TDisplacementField::Pointer
			ITKPDEDeformableRegistrationAlgorithm<TImageType, TIdentificationPolicy, TDisplacementField, TInternalRegistrationFilter>::
			getFinalDisplacementField()
			{
				return this->getInternalRegistrationMethod().GetDisplacementField();
			};


		} // end namespace itk
	} // end namespace algorithm
} // end namespace map

#endif
