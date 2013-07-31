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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Algorithms/Common/include/mapIterativeAlgorithmInterface.h $
*/




#ifndef __ITERATIVE_ALGORITHM_INTERFACE_H
#define __ITERATIVE_ALGORITHM_INTERFACE_H

#include "itkSimpleFastMutexLock.h"
#include "itkMutexLockHolder.h"

#include "mapMacros.h"
#include "mapMAPAlgorithmsExports.h"

/*! @namespace map The namespace map is used throughout the MatchPoint project to
mark code as components of this project
*/
namespace map
{
	namespace algorithm
	{
		namespace facet
		{
			/*! @class IterativeAlgorithmInterface
			@brief This is the interface for iterative algorithms
			@ingroup AlgorithmFacets
			@remark Algorithms that want to support iteration events and
			implement this interface should use the AlgorithmIterationEvent
			to indicate the begining of the next iteration
			@see map::events::AlgorithmIterationEvent
			*/
			class MAPAlgorithms_EXPORT IterativeAlgorithmInterface
			{
			public:
				typedef IterativeAlgorithmInterface Self;

				typedef unsigned long IterationCountType;

				/*! has the optimizer an iteration count?
				@eguarantee no fail
				@return Indicates if the algorithm can determin its current iteration count
				*/
				virtual bool hasIterationCount() const = 0;

				/*! @brief gets the number of the algorithm's current iteration
				@eguarantee strong
				@return returns the algorithm's current iteration. If the optimizer has no iteration count (hasIterationCount()==false), return is always 0.
				@retval an IterationCountType specifying the current iteration
				@sa IterationCountType
				*/
				virtual IterationCountType getCurrentIteration() const = 0;

				/*! has the optimizer an maximum iteration count for the current level/stage?
				@eguarantee no fail
				@return Indicates if the algorithm can determin its maximum iteration count
				*/
				virtual bool hasMaxIterationCount() const = 0;

				/*! @brief gets the maximum number of the algorithm's iterations in the current resolution level/stage
				@eguarantee strong
				@return returns the algorithm's maximum iterations count. If the optimizer has no iteration count (hasMaxIterationCount()==false), return is always 0.
				*/
				virtual IterationCountType getMaxIterations() const = 0;

			protected:
				IterativeAlgorithmInterface() {};
				virtual ~IterativeAlgorithmInterface() {};

			private:
				//No copy constructor allowed
				IterativeAlgorithmInterface(const Self &source); //purposely not implemented
				void operator=(const Self &); //purposely not implemented

			};
		}
	}
}

#endif
