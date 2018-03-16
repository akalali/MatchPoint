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


#ifndef __ITK_IMAGE_REGISTRATION_V4_ALGORITHM_INTERFACE_H
#define __ITK_IMAGE_REGISTRATION_V4_ALGORITHM_INTERFACE_H

#include <itkTransform.h>

#include "mapITKObjectToObjectOptimizerControlInterface.h"
#include "mapITKObjectToObjectMetricControlInterface.h"

#include "mapITKObjectToObjectOptimizerSetterInterface.h"
#include "mapITKObjectToObjectOptimizerGetterInterface.h"
#include "mapITKTransformSetterInterface.h"
#include "mapITKTransformGetterInterface.h"
#include "mapITKObjectToObjectMetricSetterInterface.h"
#include "mapITKObjectToObjectMetricGetterInterface.h"

/*! @namespace map The namespace map is used throughout the MatchPoint project to
    mark code as components of this project
 */
namespace map
{
	namespace algorithm
	{
		namespace itk
		{

			/*! @class ITKImageRegistrationV4AlgorithmInterface
			    @brief This is the interface for image registration v4 algorithms from ITK
			    @ingroup AlgorithmFacets
			 */
			template<class TMovingImage, class TTargetImage, class TTransformScalar>
			class ITKImageRegistrationV4AlgorithmInterface
			{
			public:
				typedef ITKImageRegistrationV4AlgorithmInterface<TMovingImage, TTargetImage, TTransformScalar>
				Self;

				typedef ITKObjectToObjectOptimizerControlInterface OptimizerBaseType;
				typedef ITKObjectToObjectMetricControlInterface<TMovingImage, TTargetImage> MetricBaseType;
				typedef ::itk::Transform<TTransformScalar, TMovingImage::ImageDimension, TTargetImage::ImageDimension> TransformBaseType;

				typedef facet::ITKObjectToObjectOptimizerSetterInterface OptimizerSetterInterfaceType;
				typedef facet::ITKObjectToObjectOptimizerGetterInterface OptimizerGetterInterfaceType;
				typedef facet::ITKTransformSetterInterface<TTransformScalar, TMovingImage::ImageDimension, TTargetImage::ImageDimension>
				TransformSetterInterfaceType;
				typedef facet::ITKTransformGetterInterface<TTransformScalar, TMovingImage::ImageDimension, TTargetImage::ImageDimension>
				TransformGetterInterfaceType;
				typedef facet::ITKObjectToObjectMetricSetterInterface<TMovingImage, TTargetImage>
				MetricSetterInterfaceType;
				typedef facet::ITKObjectToObjectMetricGetterInterface<TMovingImage, TTargetImage>
				MetricGetterInterfaceType;

			protected:
				ITKImageRegistrationV4AlgorithmInterface();
				virtual ~ITKImageRegistrationV4AlgorithmInterface();

			private:
				//No copy constructor allowed
				ITKImageRegistrationV4AlgorithmInterface(const Self& source);
				void operator=(const Self&);  //purposely not implemented

			};

		}
	}
}

#ifndef MatchPoint_MANUAL_TPP
#include "mapITKImageRegistrationV4AlgorithmInterface.tpp"
#endif


#endif
