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




#ifndef __OPTIMIZER_GETTER_INTERFACE_H
#define __OPTIMIZER_GETTER_INTERFACE_H

#include "mapOptimizerControlInterface.h"

namespace map
{
	namespace algorithm
	{
		namespace facet
		{
			/*! @class OptimizerGetterInterface
			* Interface inherited by every algorithm that is able to get an optimizer and/or change its members (none const getter)
			@ingroup AlgorithmFacets
			*/
			class MAPAlgorithms_EXPORT OptimizerGetterInterface
			{
			public:
				using Self = OptimizerGetterInterface;

				using OptimizerControlType = OptimizerControlInterface;

				/*! @brief gets the optimizer control
				@eguarantee no fail
				@return pointer to an OptimizerControlType object
				*/
				virtual OptimizerControlType* getOptimizerControl() = 0;
				/*! @brief gets the optimizer control
				@eguarantee no fail
				@return pointer to an OptimizerControlType object
				*/
				virtual const OptimizerControlType* getOptimizerControl() const = 0;

			protected:
				OptimizerGetterInterface();
				virtual ~OptimizerGetterInterface();

			private:
				//No copy constructor allowed
				OptimizerGetterInterface(const Self& source) = delete;
				void operator=(const Self&) = delete;  //purposely not implemented

			};
		}  // namespace facet
	}  // namespace algorithm
}  // namespace map


#endif
