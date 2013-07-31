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
// @version $Revision: 4912 $ (last changed revision)
// @date    $Date: 2013-07-31 10:04:21 +0200 (Mi, 31 Jul 2013) $ (last change date)
// @author  $Author: floca $ (last changed by)
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Algorithms/ITK/boxed/mapTransMattesMIRegistrationAlgorithmTemplate.h $
*/


#ifndef __MAP_TRANS_MATTES_MI_REGISTRATION_ALGORITHM_H
#define __MAP_TRANS_MATTES_MI_REGISTRATION_ALGORITHM_H

#include "mapITKImageRegistrationAlgorithm.h"

#include "mapITKRegularStepGradientDescentOptimizer.h"
#include "mapITKMattesMutualInformationImageToImageMetric.h"
#include "mapITKTranslationTransform.h"
#include "mapITKLinearInterpolateImageFunction.h"

#include "mapFixedImageToImageMetricPolicy.h"
#include "mapFixedInterpolatorPolicy.h"
#include "mapFixedSVNLOptimizerPolicy.h"
#include "mapFixedTransformPolicy.h"


namespace map
{
	namespace algorithm
	{
		namespace boxed
		{

			mapGenerateAlgorithmUIDPolicyMacro(DefaultTransMattesRegistrationAlgorithmUIDPolicy, "de.dkfz.matchpoint", "TransMIRegistrationAlgorithm.default", "1.0.0");

			/** @brief Boxing of a simple Mattes MI based image registration algorithm just supporting translation
			 @ingroup Boxed
			*/
			template < class TMovingImage, class TTargetImage = TMovingImage,
			         class TIdentificationPolicy = DefaultTransMattesRegistrationAlgorithmUIDPolicy >
			struct TransMattesMIRegistrationAlgorithmTemplate
			{
public:
				//optional
				typedef ::itk::MattesMutualInformationImageToImageMetric<TTargetImage, TMovingImage> MetricType;
				typedef ::itk::RegularStepGradientDescentOptimizer OptimizerType;
				typedef ::itk::LinearInterpolateImageFunction<TTargetImage, map::core::continuous::ScalarType> InterpolatorType;
				typedef ::itk::TranslationTransform<map::core::continuous::ScalarType, TMovingImage::ImageDimension> TranformType;

				typedef SealedFixedImageToImageMetricPolicyMacro<MetricType> MetricPolicyType;
				typedef SealedFixedSVNLOptimizerPolicyMacro<OptimizerType> OptimizerPolicyType;
				typedef SealedFixedInterpolatorPolicyMacro<InterpolatorType> InterpolatorPolicyType;
				typedef SealedFixedTransformPolicyMacro<TranformType> TransformPolicyType;

				//default typdefs
				typedef map::algorithm::itk::ITKImageRegistrationAlgorithm < TMovingImage, TTargetImage,
				        TIdentificationPolicy,
				        InterpolatorPolicyType,
				        MetricPolicyType,
				        OptimizerPolicyType,
				        TransformPolicyType > Type;
				typedef typename Type::Pointer Pointer;
			};
		}
	}
}

#endif
