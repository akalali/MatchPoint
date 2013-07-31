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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Algorithms/ITK/include/mapITKSVNLOptimizerGetterInterface.h $
*/




#ifndef __ITK_SVNL_OPTIMIZER_GETTER_INTERFACE_H
#define __ITK_SVNL_OPTIMIZER_GETTER_INTERFACE_H

#include "itkOptimizer.h"

#include "mapITKSVNLOptimizerControlInterface.h"

namespace map
{
	namespace algorithm
	{
		namespace facet
		{

			/*! @class ITKSVNLOptimizerGetterInterface
			 * Interface inherited by every algorithm that is able to get or change (none const getter) an optimizer
			 @ingroup AlgorithmFacets
			 */
			class MAPAlgorithmsITK_EXPORT ITKSVNLOptimizerGetterInterface
			{
			public:
				typedef ITKSVNLOptimizerGetterInterface Self;

				typedef algorithm::itk::ITKSVNLOptimizerControlInterface ITKOptimizerControlType;

				/*! @brief gets the optimizer
				  @eguarantee no fail
				  @return pointer to an OptimizerControlType object
				 */
				virtual ITKOptimizerControlType *getITKOptimizerControl() = 0;
				/*! @brief gets the optimizer
				  @eguarantee no fail
				  @return pointer to an OptimizerControlType object
				 */
				virtual const ITKOptimizerControlType *getITKOptimizerControl() const = 0;

			protected:
				ITKSVNLOptimizerGetterInterface() {};
				virtual ~ITKSVNLOptimizerGetterInterface() {};

			private:
				//No copy constructor allowed
				ITKSVNLOptimizerGetterInterface(const Self &source);
				void operator=(const Self &); //purposely not implemented

			};
		}
	}
}


#endif
