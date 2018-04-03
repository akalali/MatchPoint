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

#ifndef __INVERTING_FIELD_BASED_REGISTRATION_KERNEL_H
#define __INVERTING_FIELD_BASED_REGISTRATION_KERNEL_H

#include "mapLazyRegistrationKernel.h"
#include "mapClassMacros.h"

namespace map
{
	namespace core
	{

		/*!@brief  InvertingRegistrationKernel is a special implementation of a lazy field based registration kernel.
		 * This implementation is used to indicated that an other kernel is inverted and to give the posibility to check which
		* kernel will be inverted. It is used amongst other by the DefaultKernelInverter and optimized field kernel file I/O.
		 * @ingroup RegKernel
		 */
		template<unsigned int VInputDimensions, unsigned int VOutputDimensions>
		class InvertingRegistrationKernel : public LazyRegistrationKernel<VInputDimensions, VOutputDimensions>
		{
		public:
			typedef InvertingRegistrationKernel<VInputDimensions, VOutputDimensions>
			Self;
      typedef LazyRegistrationKernel<VInputDimensions, VOutputDimensions>
			Superclass;
			typedef itk::SmartPointer<Self> Pointer;
			typedef itk::SmartPointer<const Self> ConstPointer;

			itkTypeMacro(InvertingRegistrationKernel, ConcreteFieldBasedRegistrationKernel);
			itkNewMacro(Self);

			typedef typename Superclass::RepresentationDescriptorType RepresentationDescriptorType;
			typedef typename Superclass::RepresentationDescriptorPointer RepresentationDescriptorPointer;
			typedef typename Superclass::RepresentationDescriptorConstPointer
			RepresentationDescriptorConstPointer;
			typedef typename Superclass::InputPointType  InputPointType;
			typedef typename Superclass::OutputPointType OutputPointType;

			typedef RegistrationKernelBase<VOutputDimensions, VInputDimensions> SourceKernelType;
			typedef typename SourceKernelType::ConstPointer SourceKernelConstPointer;

			mapSetConstObjectMacro(SourceKernel, SourceKernelType);
			mapGetConstObjectMacro(SourceKernel, SourceKernelType);

		protected:

			SourceKernelConstPointer _SourceKernel;

			InvertingRegistrationKernel();
			virtual ~InvertingRegistrationKernel();


			/*! Methods invoked by itk::LightObject::Print().  */
			virtual void PrintSelf(std::ostream& os, itk::Indent indent) const;

		private:

			//No copy constructor allowed
			InvertingRegistrationKernel(const Self& source);
			void operator=(const Self&);  //purposely not implemented

		};

	}
}

#ifndef MatchPoint_MANUAL_TPP
#include "mapInvertingRegistrationKernel.tpp"
#endif

#endif
