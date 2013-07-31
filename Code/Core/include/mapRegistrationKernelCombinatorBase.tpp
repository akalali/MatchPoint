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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Core/include/mapRegistrationKernelCombinatorBase.tpp $
*/


#ifndef __MAP_REGISTRATION_KERNEL_COMBINATOR_BASE_TPP
#define __MAP_REGISTRATION_KERNEL_COMBINATOR_BASE_TPP

namespace map
{
	namespace core
	{
		template <unsigned int VInputDimensions, unsigned int VInterimDimensions, unsigned int VOutputDimensions>
		void
		RegistrationKernelCombinatorBase<VInputDimensions, VInterimDimensions, VOutputDimensions>::
		PrintSelf(std::ostream &os, itk::Indent indent) const
		{
			Superclass::PrintSelf(os, indent);
		};

		template <unsigned int VInputDimensions, unsigned int VInterimDimensions, unsigned int VOutputDimensions>
		RegistrationKernelCombinatorBase<VInputDimensions, VInterimDimensions, VOutputDimensions>::
		RegistrationKernelCombinatorBase()
		{};

		template <unsigned int VInputDimensions, unsigned int VInterimDimensions, unsigned int VOutputDimensions>
		RegistrationKernelCombinatorBase<VInputDimensions, VInterimDimensions, VOutputDimensions>::
		~RegistrationKernelCombinatorBase() {};


	} // end namespace core
} // end namespace map

#endif
