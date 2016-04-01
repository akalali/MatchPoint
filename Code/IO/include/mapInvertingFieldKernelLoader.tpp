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

#ifndef __MAP_INVERTING_FIELD_KERNEL_LOADER_TPP
#define __MAP_INVERTING_FIELD_KERNEL_LOADER_TPP

#include "mapInvertingFieldKernelLoader.h"
#include "mapServiceException.h"
#include "mapRegistrationFileTags.h"
#include "mapRegistrationManipulator.h"
#include "mapConvert.h"
#include "mapInverseRegistrationKernelGenerator.h"
#include "mapSDTags.h"
#include "mapFileDispatch.h"
#include "mapLazyRegistrationKernel.h"

namespace map
{
	namespace io
	{

		template <unsigned int VInputDimensions, unsigned int VOutputDimensions>
		bool
		InvertingFieldKernelLoader<VInputDimensions, VOutputDimensions>::
		canHandleRequest(const RequestType& request) const
		{
			structuredData::Element::ConstSubElementIteratorType typePos = structuredData::findNextSubElement(
						request._spKernelDescriptor->getSubElementBegin(), request._spKernelDescriptor->getSubElementEnd(),
						tags::KernelType);

			bool canHandle = false;

			if (typePos != request._spKernelDescriptor->getSubElementEnd())
			{
				canHandle = ((*typePos)->getValue() == "InvertingFieldKernel") && Superclass::canHandleRequest(request) && request._spComplementaryKernel.IsNotNull();
			}

			return canHandle;
		}


		template <unsigned int VInputDimensions, unsigned int VOutputDimensions>
		::map::core::String
		InvertingFieldKernelLoader<VInputDimensions, VOutputDimensions>::
		getProviderName() const
		{
			return Self::getStaticProviderName();
		}

		template <unsigned int VInputDimensions, unsigned int VOutputDimensions>
		::map::core::String
		InvertingFieldKernelLoader<VInputDimensions, VOutputDimensions>::
		getStaticProviderName()
		{
			::map::core::OStringStream os;
			os << "InvertingFieldKernelLoader<" << VInputDimensions << "," << VOutputDimensions << ">";
			return os.str();
		}


		template <unsigned int VInputDimensions, unsigned int VOutputDimensions>
		::map::core::String
		InvertingFieldKernelLoader<VInputDimensions, VOutputDimensions>::
		getDescription() const
		{
			::map::core::OStringStream os;
			os << "InvertingFieldKernelLoader, InputDimension: " << VInputDimensions << ", OutputDimension: " <<
			   VOutputDimensions << ".";
			return os.str();
		}


		template <unsigned int VInputDimensions, unsigned int VOutputDimensions>
		typename InvertingFieldKernelLoader<VInputDimensions, VOutputDimensions>::GenericKernelPointer
		InvertingFieldKernelLoader<VInputDimensions, VOutputDimensions>::
		loadKernel(const RequestType& request) const
		{
			if (!canHandleRequest(request))
			{
				mapExceptionMacro(::map::core::ServiceException,
								  << "Error: cannot load kernel. Reason: cannot handle request.");
			}

			/*! Kernel base type of kernels that should be inverted to get the requested field kernel.*/
			typedef  core::RegistrationKernelBase<VOutputDimensions, VInputDimensions>	SourceKernelBaseType;
			const SourceKernelBaseType* sourceKernel = dynamic_cast<const SourceKernelBaseType*>
					(request._spComplementaryKernel.GetPointer());

			if (!sourceKernel)
			{
				mapExceptionMacro(::map::core::ServiceException,
								  << "Error: cannot load kernel. Reason: complementary/source kernel has not the correct dimensionality.");
			}

			structuredData::Element::ConstSubElementIteratorType repPos = structuredData::findNextSubElement(
						request._spKernelDescriptor->getSubElementBegin(), request._spKernelDescriptor->getSubElementEnd(),
						tags::InverseFieldRepresentation);

			typename KernelBaseType::RepresentationDescriptorPointer spInverseFieldRep;

			if (repPos != request._spKernelDescriptor->getSubElementEnd())
			{
				spInverseFieldRep = KernelBaseType::RepresentationDescriptorType::New();
				spInverseFieldRep->streamFromStructuredData(*repPos);
			}

			//determin null vector (support)
			typename KernelBaseType::MappingVectorType nullVector;
            bool usesNullVector = this->hasNullVector(request, nullVector);

			typedef core::InverseRegistrationKernelGenerator<VOutputDimensions, VInputDimensions>
			InversionGeneratorType;

			typename InversionGeneratorType::Pointer generator = InversionGeneratorType::New();
			typename core::RegistrationKernelBase<VInputDimensions, VOutputDimensions>::Pointer spResult =
				generator->generateInverse(*sourceKernel, spInverseFieldRep);

			::map::core::LazyRegistrationKernel<VInputDimensions, VOutputDimensions>* fieldKernel =
          dynamic_cast<::map::core::LazyRegistrationKernel<VInputDimensions, VOutputDimensions>*>
				(spResult.GetPointer());

			if (fieldKernel)
			{
				fieldKernel->setNullVectorUsage(usesNullVector);
				fieldKernel->setNullVector(nullVector);
			}

			if (!request._preferLazyLoading)
			{
				spResult->precomputeKernel();
			}

			return spResult.GetPointer();
		}

		template <unsigned int VInputDimensions, unsigned int VOutputDimensions>
		InvertingFieldKernelLoader<VInputDimensions, VOutputDimensions>::
		InvertingFieldKernelLoader()
		{};


	} // end namespace io
} // end namespace map

#endif
