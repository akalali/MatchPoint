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


#ifndef __MAP_COMBINATION_FUNCTOR_INTERFACE_H
#define __MAP_COMBINATION_FUNCTOR_INTERFACE_H

#include "mapRegistrationTopology.h"
#include "mapRegistrationKernelBase.h"

#include "itkObject.h"

namespace map
{
	namespace core
	{
		namespace functors
		{

			/*! @class CombinationFunctorInterface
			* @brief Interface class for combination functors that gernerate vector fields
			* by kernel combination
			*
			* @ingroup RegFunctors
			* @tparam VInputDimensions Dimensions of the input space the field should map from.
			* @tparam VInterimDimensions Dimensions of the interim space into which the transformation maps.
			* @tparam VOutputDimensions Dimensions of the output space the field should map into.
			*/
			template <unsigned int VInputDimensions, unsigned int VInterimDimensions, unsigned int VOutputDimensions>
			class CombinationFunctorInterface
			{
			public:
				/*! Standard class typedefs. */
				typedef CombinationFunctorInterface<VInputDimensions, VInterimDimensions, VOutputDimensions>
				Self;
				using Pointer = itk::SmartPointer<Self>;
				using ConstPointer = itk::SmartPointer<const Self>;

				itkStaticConstMacro(InputDimensions, unsigned int, VInputDimensions);
				itkStaticConstMacro(InterimDimensions, unsigned int, VInterimDimensions);
				itkStaticConstMacro(OutputDimensions, unsigned int, VOutputDimensions);

				virtual const char* GetNameOfClass() const
				{
					return "FieldGenerationFunctor";
				};

				typedef typename RegistrationTopology<VInputDimensions, VOutputDimensions>::DirectMappingVectorType
				PaddingVectorType;

				typedef RegistrationKernelBase<VInputDimensions, VInterimDimensions> SourceKernel1BaseType;
				typedef RegistrationKernelBase<VInterimDimensions, VOutputDimensions> SourceKernel2BaseType;

				/*! Returns a const pointer to the first source kernel base that will be used in order
				 * to generate the field.
				 * @eguarantee no fail
				 * @return Pointer to the source field kernel.
				 * @post Return value is guaranteed not to be NULL.
				 */
				virtual const SourceKernel1BaseType* get1stSourceKernelBase() const = 0;

				/*! Returns a const pointer to the second source kernel base that will be used in order
				 * to generate the field.
				 * @eguarantee no fail
				 * @return Pointer to the source field kernel.
				 * @post Return value is guaranteed not to be NULL.
				 */
				virtual const SourceKernel2BaseType* get2ndSourceKernelBase() const = 0;

			protected:

				CombinationFunctorInterface();
				virtual ~CombinationFunctorInterface();

				/*! Methods invoked by itk::LightObject::Print().  */
				virtual void PrintSelf(std::ostream& os, itk::Indent indent) const;

			private:
				CombinationFunctorInterface(const Self&);  //purposely not implemented
				void operator=(const Self&);  //purposely not implemented
			};

		} // end namespace functors
	} // end namespace core
} // end namespace map

#ifndef MatchPoint_MANUAL_TPP
# include "mapCombinationFunctorInterface.tpp"
#endif

#endif
