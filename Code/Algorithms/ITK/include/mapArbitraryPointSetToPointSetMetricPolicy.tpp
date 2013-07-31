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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Algorithms/ITK/include/mapArbitraryPointSetToPointSetMetricPolicy.tpp $
*/


#ifndef __ARBITRARY_POINT_SET_TO_POINT_SET_METRIC_POLICY_TPP
#define __ARBITRARY_POINT_SET_TO_POINT_SET_METRIC_POLICY_TPP

#include "mapAlgorithmEvents.h"

namespace map
{
	namespace algorithm
	{
		namespace itk
		{

			template<class TMovingPointSet, class TTargetPointSet>
			unsigned long
			ArbitraryPointSetToPointSetMetricPolicy<TMovingPointSet, TTargetPointSet>::
			GetMTime() const
			{
				unsigned long mt = _mTime.getMTime();
				return mt;
			};

			template<class TMovingPointSet, class TTargetPointSet>
			void
			ArbitraryPointSetToPointSetMetricPolicy<TMovingPointSet, TTargetPointSet>::
			setMetricControl(MetricControlType *pMetric)
			{
				if (pMetric != _spMetric.GetPointer())
				{
					//there is really the need to change
					if (this->_spOnChange.IsNotNull())
					{
						events::UnregisterAlgorithmComponentEvent unRegEvent(_spMetric.GetPointer(), "Unregister current metric");
						this->_spOnChange->Execute((::itk::Object *)NULL, unRegEvent);
					}

					_spMetric  = pMetric;
					_mTime.setWatchedObject(pMetric);

					if (this->_spOnChange.IsNotNull())
					{
						events::RegisterAlgorithmComponentEvent regEvent(_spMetric.GetPointer(), "Register new metric");
						this->_spOnChange->Execute((::itk::Object *)NULL, regEvent);
					}
				}
			};

			template<class TMovingPointSet, class TTargetPointSet>
			ArbitraryPointSetToPointSetMetricPolicy<TMovingPointSet, TTargetPointSet>::
			ArbitraryPointSetToPointSetMetricPolicy()
			{
			};

			template<class TMovingPointSet, class TTargetPointSet>
			ArbitraryPointSetToPointSetMetricPolicy<TMovingPointSet, TTargetPointSet>::
			~ArbitraryPointSetToPointSetMetricPolicy()
			{
			};

			template<class TMovingPointSet, class TTargetPointSet>
			typename ArbitraryPointSetToPointSetMetricPolicy<TMovingPointSet, TTargetPointSet>::MetricControlType *
			ArbitraryPointSetToPointSetMetricPolicy<TMovingPointSet, TTargetPointSet>::
			getMetricInternal()
			{
				return _spMetric;
			};

			template<class TMovingPointSet, class TTargetPointSet>
			const typename ArbitraryPointSetToPointSetMetricPolicy<TMovingPointSet, TTargetPointSet>::MetricControlType *
			ArbitraryPointSetToPointSetMetricPolicy<TMovingPointSet, TTargetPointSet>::
			getMetricInternal() const
			{
				return _spMetric;
			};

			template<class TMovingPointSet, class TTargetPointSet>
			typename ArbitraryPointSetToPointSetMetricPolicy<TMovingPointSet, TTargetPointSet>::MetricControlType *
			ArbitraryPointSetToPointSetMetricPolicy<TMovingPointSet, TTargetPointSet>::
			getMetricControl()
			{
				return _spMetric;
			};

			template<class TMovingPointSet, class TTargetPointSet>
			const typename ArbitraryPointSetToPointSetMetricPolicy<TMovingPointSet, TTargetPointSet>::MetricControlType *
			ArbitraryPointSetToPointSetMetricPolicy<TMovingPointSet, TTargetPointSet>::
			getMetricControl() const
			{
				return _spMetric;
			};

			template<class TMovingPointSet, class TTargetPointSet>
			void
			ArbitraryPointSetToPointSetMetricPolicy<TMovingPointSet, TTargetPointSet>::
			prepareMetric()
			{
				//default implementation does nothing;
			};

			template<class TMovingPointSet, class TTargetPointSet>
			void
			ArbitraryPointSetToPointSetMetricPolicy<TMovingPointSet, TTargetPointSet>::
			prepareMetricAfterAssembly()
			{
				//default implementation does nothing;
			};

		}
	} // end namespace algorithm
} // end namespace map

#endif
