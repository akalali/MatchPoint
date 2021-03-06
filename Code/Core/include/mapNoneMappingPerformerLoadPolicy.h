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


#ifndef __MAP_NONE_MAPPING_PERFORMER_LOAD_POLICY_H
#define __MAP_NONE_MAPPING_PERFORMER_LOAD_POLICY_H

# include "mapGenericStaticLoadPolicyBase.h"

namespace map
{
	namespace core
	{
		/*! @class NoneMappingPerformerLoadPolicy
		* @brief Load class that loads no performer.
		*
		* @ingroup LoadPolicies
		* @ingroup RegTasks
		* @sa PointMappingTask
		* @tparam TProviderBase Base class of the service providers loaded by the policy.
		*/
		template <class TProviderBase>
		class NoneMappingPerformerLoadPolicy : public services::GenericStaticLoadPolicyBase<TProviderBase>
		{
		protected:
			/*! Standard class typedefs. */
			typedef services::GenericStaticLoadPolicyBase<TProviderBase> Superclass;
			typedef typename Superclass::ProviderBaseType      ProviderBaseType;
			typedef typename Superclass::ProviderBasePointer   ProviderBasePointer;
			typedef typename Superclass::LoadInterfaceType     LoadInterfaceType;

			virtual void doLoading();

			NoneMappingPerformerLoadPolicy();
			~NoneMappingPerformerLoadPolicy();

		private:
			NoneMappingPerformerLoadPolicy(const NoneMappingPerformerLoadPolicy&);  //purposely not implemented
			void operator=(const NoneMappingPerformerLoadPolicy&);  //purposely not implemented
		};

	} // end namespace core
} // end namespace map

#ifndef MatchPoint_MANUAL_TPP
# include "mapNoneMappingPerformerLoadPolicy.tpp"
#endif

#endif
