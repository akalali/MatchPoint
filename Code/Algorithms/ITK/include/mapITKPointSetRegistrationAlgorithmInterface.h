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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Algorithms/ITK/include/mapITKPointSetRegistrationAlgorithmInterface.h $
*/




#ifndef __ITK_POINT_SET_REGISTRATION_ALGORITHM_INTERFACE_H
#define __ITK_POINT_SET_REGISTRATION_ALGORITHM_INTERFACE_H

#include "mapITKMVNLOptimizerControlInterface.h"
#include "mapITKPointSetToPointSetMetricControlInterface.h"
#include "mapTransformModelBase.h"

#include "mapITKMVNLOptimizerSetterInterface.h"
#include "mapITKMVNLOptimizerGetterInterface.h"
#include "mapITKTransformSetterInterface.h"
#include "mapITKTransformGetterInterface.h"
#include "mapITKPointSetToPointSetMetricSetterInterface.h"
#include "mapITKPointSetToPointSetMetricGetterInterface.h"


/*! @namespace map The namespace map is used throughout the MatchPoint project to
    mark code as components of this project
 */
namespace map
{
	namespace algorithm
	{
		namespace itk
		{

			/*! @class ITKPointSetRegistrationAlgorithmInterface
			    @brief This is the interface for point set to point set registration algorithms from ITK
			    @ingroup AlgorithmFacets
			 */
			template<class TMovingPointSet, class TTargetPointSet, class TTransformScalar>
			class ITKPointSetRegistrationAlgorithmInterface
			{
			public:
				typedef ITKPointSetRegistrationAlgorithmInterface<TMovingPointSet, TTargetPointSet, TTransformScalar> Self;

				typedef ITKMVNLOptimizerControlInterface OptimizerBaseType;
				typedef ITKPointSetToPointSetMetricControlInterface<TMovingPointSet, TTargetPointSet> MetricBaseType;
				typedef core::TransformModelBase<TTransformScalar, TMovingPointSet::PointDimension, TTargetPointSet::PointDimension> TransformBaseType;

				typedef facet::ITKMVNLOptimizerSetterInterface OptimizerSetterInterfaceType;
				typedef facet::ITKMVNLOptimizerGetterInterface OptimizerGetterInterfaceType;
				typedef facet::ITKTransformSetterInterface<TTransformScalar, TMovingPointSet::PointDimension, TTargetPointSet::PointDimension> TransformSetterInterfaceType;
				typedef facet::ITKTransformGetterInterface<TTransformScalar, TMovingPointSet::PointDimension, TTargetPointSet::PointDimension> TransformGetterInterfaceType;
				typedef facet::ITKPointSetToPointSetMetricSetterInterface<TMovingPointSet, TTargetPointSet> MetricSetterInterfaceType;
				typedef facet::ITKPointSetToPointSetMetricGetterInterface<TMovingPointSet, TTargetPointSet> MetricGetterInterfaceType;

			protected:
				ITKPointSetRegistrationAlgorithmInterface();
				virtual ~ITKPointSetRegistrationAlgorithmInterface();

			private:
				//No copy constructor allowed
				ITKPointSetRegistrationAlgorithmInterface(const Self &source);
				void operator=(const Self &); //purposely not implemented

			};

		}
	}
}

#ifndef MatchPoint_MANUAL_TPP
#include "mapITKPointSetRegistrationAlgorithmInterface.tpp"
#endif


#endif
