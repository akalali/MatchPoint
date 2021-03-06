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




#ifndef __ITK_INTERPOLATOR_GETTER_INTERFACE_H
#define __ITK_INTERPOLATOR_GETTER_INTERFACE_H

#include "itkInterpolateImageFunction.h"

namespace map
{
	namespace algorithm
	{
		namespace facet
		{

			/*! @class ITKInterpolatorGetterInterface
			* Interface inherited by every algorithm that is able to get and change (by none const getter) an interpolator
			@ingroup AlgorithmFacets
			*/

			template<class TInputImage, class TCoordRep>
			class ITKInterpolatorGetterInterface
			{
			public:
				typedef ITKInterpolatorGetterInterface<TInputImage, TCoordRep> Self;

				typedef ::itk::InterpolateImageFunction<TInputImage, TCoordRep> InterpolatorType;
				using CoordRepType = TCoordRep;

				/*! gets the interpolator
				@eguarantee strong
				@return a pointer to a InterpolatorType object
				*/
				virtual const InterpolatorType* getInterpolator() const = 0;

				/*! gets the interpolator
				 * @eguarantee strong
				 * @return a pointer to a InterpolatorType object
				*/
				virtual InterpolatorType* getInterpolator() = 0;

			protected:
				ITKInterpolatorGetterInterface() {};
				virtual ~ITKInterpolatorGetterInterface() {};

			private:
				//No copy constructor allowed
				ITKInterpolatorGetterInterface(const Self& source);
				void operator=(const Self&);  //purposely not implemented

			};
		}  // namespace facet
	}  // namespace algorithm
}  // namespace map

#endif
