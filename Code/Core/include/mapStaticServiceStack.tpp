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


#ifndef __MAP_STATIC_SERVICE_STACK_TPP
#define __MAP_STATIC_SERVICE_STACK_TPP

#include "mapStaticServiceStack.h"

namespace map
{
	namespace core
	{
		namespace services
		{

			template <class TConcreteServiceStack, template <class> class TStaticLoadStaticPolicy, class TThreadingStaticPolicy>
			typename StaticServiceStack<TConcreteServiceStack, TStaticLoadStaticPolicy, TThreadingStaticPolicy>::ProviderBaseType*
			StaticServiceStack<TConcreteServiceStack, TStaticLoadStaticPolicy, TThreadingStaticPolicy>::
			getProvider(const RequestType& request)
			{
				typename ThreadingStaticPolicyType::SentinelType sentinel;
				ThreadingStaticPolicyType::activateSentinel(sentinel);

				ensureStack();
				ProviderBaseType* pProvider = _spConcreteStack->getProvider(request);

				return pProvider;
			};

			template <class TConcreteServiceStack, template <class> class TStaticLoadStaticPolicy, class TThreadingStaticPolicy>
			typename StaticServiceStack<TConcreteServiceStack, TStaticLoadStaticPolicy, TThreadingStaticPolicy>::ProviderBaseType*
			StaticServiceStack<TConcreteServiceStack, TStaticLoadStaticPolicy, TThreadingStaticPolicy>::
			getProvider(const String& providerName)
			{
				typename ThreadingStaticPolicyType::SentinelType sentinel;
				ThreadingStaticPolicyType::activateSentinel(sentinel);

				ensureStack();
				ProviderBaseType* pProvider = _spConcreteStack->getProvider(providerName);

				return pProvider;
			};

			template <class TConcreteServiceStack, template <class> class TStaticLoadStaticPolicy, class TThreadingStaticPolicy>
			bool
			StaticServiceStack<TConcreteServiceStack, TStaticLoadStaticPolicy, TThreadingStaticPolicy>::
			providerIsAvailable(const RequestType& request)
			{
				typename ThreadingStaticPolicyType::SentinelType sentinel;
				ThreadingStaticPolicyType::activateSentinel(sentinel);

				ensureStack();
				bool result = _spConcreteStack->providerIsAvailable(request);

				return result;
			};

			template <class TConcreteServiceStack, template <class> class TStaticLoadStaticPolicy, class TThreadingStaticPolicy>
			bool
			StaticServiceStack<TConcreteServiceStack, TStaticLoadStaticPolicy, TThreadingStaticPolicy>::
			registerProvider(ProviderBaseType* pProvider)
			{
				typename ThreadingStaticPolicyType::SentinelType sentinel;
				ThreadingStaticPolicyType::activateSentinel(sentinel);

				ensureStack();
				bool result = _spConcreteStack->registerProvider(pProvider);

				return result;
			};

			template <class TConcreteServiceStack, template <class> class TStaticLoadStaticPolicy, class TThreadingStaticPolicy>
			bool
			StaticServiceStack<TConcreteServiceStack, TStaticLoadStaticPolicy, TThreadingStaticPolicy>::
			unregisterProviderByPointer(ProviderBaseType* pProvider)
			{
				typename ThreadingStaticPolicyType::SentinelType sentinel;
				ThreadingStaticPolicyType::activateSentinel(sentinel);

				ensureStack();
				bool result = _spConcreteStack->unregisterProviderByPointer(pProvider);

				return result;
			};

			template <class TConcreteServiceStack, template <class> class TStaticLoadStaticPolicy, class TThreadingStaticPolicy>
			bool
			StaticServiceStack<TConcreteServiceStack, TStaticLoadStaticPolicy, TThreadingStaticPolicy>::
			unregisterProvider(const String& providerName)
			{
				typename ThreadingStaticPolicyType::SentinelType sentinel;
				ThreadingStaticPolicyType::activateSentinel(sentinel);

				ensureStack();
				bool result = _spConcreteStack->unregisterProvider(providerName);

				return result;
			};

			template <class TConcreteServiceStack, template <class> class TStaticLoadStaticPolicy, class TThreadingStaticPolicy>
			void
			StaticServiceStack<TConcreteServiceStack, TStaticLoadStaticPolicy, TThreadingStaticPolicy>::
			unregisterAll()
			{
				if (_spConcreteStack.IsNotNull())
				{
					typename ThreadingStaticPolicyType::SentinelType sentinel;
					ThreadingStaticPolicyType::activateSentinel(sentinel);

					ConcreteServiceStackPointer _spOldStack = _spConcreteStack;
					_spConcreteStack = NULL;

					_spOldStack->unregisterAll();
				}
			};

			/*! Clears the stack (unregisterAll) and loads all default providers by calling StaticLoadPolicyType::loadStaticProviders().
			 * @eguarantee basic*/
			template <class TConcreteServiceStack, template <class> class TStaticLoadStaticPolicy, class TThreadingStaticPolicy>
			void
			StaticServiceStack<TConcreteServiceStack, TStaticLoadStaticPolicy, TThreadingStaticPolicy>::
			rehash()
			{
				typename ThreadingStaticPolicyType::SentinelType sentinel;
				ThreadingStaticPolicyType::activateSentinel(sentinel);

				ConcreteServiceStackPointer _spNewStack = establishConcreteStack();

				_spConcreteStack = _spNewStack;
			};

			template <class TConcreteServiceStack, template <class> class TStaticLoadStaticPolicy, class TThreadingStaticPolicy>
			unsigned int
			StaticServiceStack<TConcreteServiceStack, TStaticLoadStaticPolicy, TThreadingStaticPolicy>::
			size()
			{
				typename ThreadingStaticPolicyType::SentinelType sentinel;
				ThreadingStaticPolicyType::activateSentinel(sentinel);

				ensureStack();
				unsigned int size = _spConcreteStack->size();

				return size;
			};

			template <class TConcreteServiceStack, template <class> class TStaticLoadStaticPolicy, class TThreadingStaticPolicy>
			void
			StaticServiceStack<TConcreteServiceStack, TStaticLoadStaticPolicy, TThreadingStaticPolicy>::
			ensureStack()
			{
				if (_spConcreteStack.IsNull())
				{
					ConcreteServiceStackPointer _spNewStack = establishConcreteStack();

					_spConcreteStack = _spNewStack;
				}
			};

			template <class TConcreteServiceStack, template <class> class TStaticLoadStaticPolicy, class TThreadingStaticPolicy>
			typename StaticServiceStack<TConcreteServiceStack, TStaticLoadStaticPolicy, TThreadingStaticPolicy>::ConcreteServiceStackPointer
			StaticServiceStack<TConcreteServiceStack, TStaticLoadStaticPolicy, TThreadingStaticPolicy>::
			establishConcreteStack()
			{
				ConcreteServiceStackPointer spConcreteStack = ConcreteServiceStackType::New(false);
				StaticLoadStaticPolicyType::registerConcreteStack(spConcreteStack);
				spConcreteStack->rehash();
				StaticLoadStaticPolicyType::finalizeStaticLoading(spConcreteStack);

				return spConcreteStack;
			};

			template <class TConcreteServiceStack, template <class> class TStaticLoadStaticPolicy, class TThreadingStaticPolicy>
			typename StaticServiceStack<TConcreteServiceStack, TStaticLoadStaticPolicy, TThreadingStaticPolicy>::ConcreteServiceStackPointer
			StaticServiceStack<TConcreteServiceStack, TStaticLoadStaticPolicy, TThreadingStaticPolicy>::_spConcreteStack;


		} // end namespace services
	} // end namespace core
} // end namespace map

#endif
