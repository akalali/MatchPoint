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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Core/include/mapModelFieldKernelCombinator.tpp $
*/

#ifndef __MAP_MODEL_FIELD_KERNEL_COMBINATOR_TPP
#define __MAP_MODEL_FIELD_KERNEL_COMBINATOR_TPP

#include "mapModelFieldKernelCombinator.h"
#include "mapServiceException.h"
#include "mapFieldByModelFieldCombinationFunctor.h"
#include "mapCombinedFieldBasedRegistrationKernel.h"

namespace map
{
	namespace core
	{

		template <unsigned int VInputDimensions, unsigned int VInterimDimensions, unsigned int VOutputDimensions>
		typename ModelFieldKernelCombinator< VInputDimensions, VInterimDimensions, VOutputDimensions >::CombinedKernelBasePointer
		ModelFieldKernelCombinator< VInputDimensions, VInterimDimensions, VOutputDimensions >::
		combineKernels(const RequestType &request,
		               const InputFieldRepresentationType *pInputFieldRepresentation,
		               bool usePadding,
		               const PaddingVectorType &paddingVector) const
		{
			assert(pInputFieldRepresentation);

			if (!pInputFieldRepresentation)
			{
				mapExceptionMacro(ServiceException, << "Error: cannot combine kernels. Reason: input field representation is NULL");
			}

			const Kernel1Type *pKernel1 = dynamic_cast<const Kernel1Type *>(request._spKernel1.GetPointer());
			const Kernel2Type *pKernel2 = dynamic_cast<const Kernel2Type *>(request._spKernel2.GetPointer());

			if (pKernel1 == NULL)
			{
				mapExceptionMacro(ServiceException, << "Error: cannot combine kernels. Reason: cannot cast first kernel to ModelBasedRegistrationKernel: " << pKernel1);
			}

			if (pKernel2 == NULL)
			{
				mapExceptionMacro(ServiceException, << "Error: cannot combine kernels. Reason: cannot cast second kernel to FieldBasedRegistrationKernel: " << pKernel2);
			}

			typedef CombinedFieldBasedRegistrationKernel<VInputDimensions, VInterimDimensions, VOutputDimensions> CombinedKernelType;
			typename CombinedKernelType::Pointer spCombinedKernel = CombinedKernelType::New();

			typedef functors::FieldByModelFieldCombinationFunctor<VInputDimensions, VInterimDimensions, VOutputDimensions> FunctorType;
			typename FunctorType::Pointer spFunctor = FunctorType::New(*pKernel1, *pKernel2, pInputFieldRepresentation);

			spFunctor->setUsePadding(usePadding);
			spFunctor->setPaddingVector(paddingVector);

			spCombinedKernel->setFieldFunctor(*(spFunctor.GetPointer()));

			CombinedKernelBasePointer spResult = spCombinedKernel.GetPointer();
			return spResult;
		};

		template <unsigned int VInputDimensions, unsigned int VInterimDimensions, unsigned int VOutputDimensions>
		bool
		ModelFieldKernelCombinator< VInputDimensions, VInterimDimensions, VOutputDimensions >::
		canHandleRequest(const RequestType &request) const
		{
			// get the two kernels from the request (which is a RegistrationCombinationRequest object)
			// and check if they are both FieldKernels
			const Kernel1Type *pKernel1 = dynamic_cast<const Kernel1Type *>(request._spKernel1.GetPointer());
			const Kernel2Type *pKernel2 = dynamic_cast<const Kernel2Type *>(request._spKernel2.GetPointer());

			return ((pKernel1 != NULL) && (pKernel2 != NULL));
		}

		template <unsigned int VInputDimensions, unsigned int VInterimDimensions, unsigned int VOutputDimensions>
		String
		ModelFieldKernelCombinator< VInputDimensions, VInterimDimensions, VOutputDimensions >::
		getProviderName() const
		{
			return Self::getStaticProviderName();
		}

		template <unsigned int VInputDimensions, unsigned int VInterimDimensions, unsigned int VOutputDimensions>
		String
		ModelFieldKernelCombinator<VInputDimensions, VInterimDimensions, VOutputDimensions>::
		getStaticProviderName()
		{
			OStringStream os;
			os << "ModelFieldKernelCombinator<" << VInputDimensions << "," << VInterimDimensions << "," << VOutputDimensions << ">";
			return os.str();
		}

		template <unsigned int VInputDimensions, unsigned int VInterimDimensions, unsigned int VOutputDimensions>
		String
		ModelFieldKernelCombinator< VInputDimensions, VInterimDimensions, VOutputDimensions >::
		getDescription() const
		{
			OStringStream os;
			os << "ModelFieldKernelCombinator, VInputDimensions: " << VInputDimensions << ", VInterimDimensions: " << VInterimDimensions << ", VOutputDimensions: " << VOutputDimensions << ".";
			return os.str();
		}


	} // end namespace core
} // end namespace map

#endif
