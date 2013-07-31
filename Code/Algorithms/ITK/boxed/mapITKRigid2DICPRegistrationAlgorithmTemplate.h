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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Algorithms/ITK/boxed/mapITKRigid2DICPRegistrationAlgorithmTemplate.h $
*/


#ifndef __MAP_RIGID_2D_ICP_REGISTRATION_ALGORITHM_H
#define __MAP_RIGID_2D_ICP_REGISTRATION_ALGORITHM_H

#include "mapITKPointSetRegistrationAlgorithm.h"

#include "mapITKLevenbergMarquardtOptimizer.h"
#include "mapITKEuclideanDistancePointMetric.h"
#include "mapITKRigid2DTransform.h"

#include "mapFixedPointSetToPointSetMetricPolicy.h"
#include "mapFixedInterpolatorPolicy.h"
#include "mapFixedMVNLOptimizerPolicy.h"
#include "mapFixedTransformPolicy.h"

namespace map
{
	namespace algorithm
	{
		namespace boxed
		{

			mapGenerateAlgorithmUIDPolicyMacro(DefaultITKRigid2DICPRegistrationAlgorithmUIDPolicy, "de.dkfz.matchpoint", "ITKRigid2DICPRegistrationAlgorithm.default", "1.0.0");

			/** @brief Boxing of a simple rigid point set registration algorithm using Rigid3D transform
			@ingroup Boxed
			*/
			template < class TMovingPointSet, class TTargetPointSet = TMovingPointSet,
			         class TIdentificationPolicy = DefaultITKRigid2DICPRegistrationAlgorithmUIDPolicy,
			         class TDistanceMap = typename map::core::discrete::Elements<TMovingPointSet::PointDimension>::InternalImageType >
			class ITKRigid2DICPRegistrationAlgorithm: public map::algorithm::itk::ITKPointSetRegistrationAlgorithm < TMovingPointSet,
				TTargetPointSet,
				TIdentificationPolicy,
				SealedFixedPointSetToPointSetMetricPolicyMacro< ::itk::EuclideanDistancePointMetric<TTargetPointSet, TMovingPointSet, TDistanceMap> >,
				SealedFixedMVNLOptimizerPolicyMacro< ::itk::LevenbergMarquardtOptimizer>,
				SealedFixedTransformPolicyMacro< ::itk::Rigid2DTransform< map::core::continuous::ScalarType> > >
			{
			public:
				//optional
				typedef ::itk::EuclideanDistancePointMetric<TTargetPointSet, TMovingPointSet, TDistanceMap> MetricType;
				typedef ::itk::LevenbergMarquardtOptimizer OptimizerType;
				typedef ::itk::Rigid2DTransform< map::core::continuous::ScalarType> TransformType;

				typedef SealedFixedPointSetToPointSetMetricPolicyMacro<MetricType> MetricPolicyType;
				typedef SealedFixedMVNLOptimizerPolicyMacro<OptimizerType> OptimizerPolicyType;
				typedef SealedFixedTransformPolicyMacro<TransformType> TransformPolicyType;

				typedef ITKRigid2DICPRegistrationAlgorithm Self;

				typedef map::algorithm::itk::ITKPointSetRegistrationAlgorithm < TMovingPointSet,
				        TTargetPointSet,
				        TIdentificationPolicy,
				        SealedFixedPointSetToPointSetMetricPolicyMacro< ::itk::EuclideanDistancePointMetric<TTargetPointSet, TMovingPointSet, TDistanceMap> >,
				        SealedFixedMVNLOptimizerPolicyMacro< ::itk::LevenbergMarquardtOptimizer>,
				        SealedFixedTransformPolicyMacro< ::itk::Rigid2DTransform< map::core::continuous::ScalarType> > >  Superclass;

				typedef ::itk::SmartPointer<Self>                                     Pointer;
				typedef ::itk::SmartPointer<const Self>                               ConstPointer;

				itkTypeMacro(ITKRigid2DICPRegistrationAlgorithm, ITKPointSetRegistrationAlgorithm);
				mapNewAlgorithmMacro(Self);

			protected:
				ITKRigid2DICPRegistrationAlgorithm()
				{
				};

				virtual ~ITKRigid2DICPRegistrationAlgorithm()
				{
				};

				void configureAlgorithm()
				{
					OptimizerType::ScalesType scales(4);
					scales[0] = 1.0;
					scales[1] = 1.0 / 1000;
					scales[2] = 1.0 / 1000;
					scales[3] = 1.0 / 1000;

					this->getConcreteTransformModel()->getConcreteTransform()->SetIdentity();
					this->getConcreteITKOptimizer()->SetScales(scales);
					this->getConcreteITKOptimizer()->SetValueTolerance(1e-5);
					this->getConcreteITKOptimizer()->SetGradientTolerance(1e-5);
					this->getConcreteITKOptimizer()->SetEpsilonFunction(1e-6);
					this->getConcreteITKOptimizer()->SetNumberOfIterations(2000);
					this->getConcreteITKOptimizer()->SetUseCostFunctionGradient(false);
				}

			private:

				ITKRigid2DICPRegistrationAlgorithm(const Self &source);  //purposely not implemented
				void operator=(const Self &); //purposely not implemented

			};

		}
	}
}


#endif
