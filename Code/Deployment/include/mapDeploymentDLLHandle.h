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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Deployment/include/mapDeploymentDLLHandle.h $
*/


#ifndef __MAP_DEPLOYMENT_DLL_HANDLE_H
#define __MAP_DEPLOYMENT_DLL_HANDLE_H

#include "mapDeploymentDLLInfo.h"

// Ugly stuff for library handles
// The OS dependent includes are necessary to define
// the proper library handle type for each OS.
// The itk::DynamicLoader::LibraryHandle is not used
// directly to minimize the included (itk) header files
// and therfore the risk of integration problems when using
// these deployment classes in other application frame works.
// One known problem for example are compilation errors
// when implementing a MeVisLab 2.1 module dll.
#if defined(__hpux)
#include <dl.h>
#elif defined(_WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#elif defined(__APPLE__)
#include <AvailabilityMacros.h>
#if MAC_OS_X_VERSION_MAX_ALLOWED < 1030
#include <mach-o/dyld.h>
#endif
#elif defined(__BEOS__)
#include <be/kernel/image.h>
#endif

namespace map
{
	namespace deployment
	{
		/** @class DLLHandle
		* @brief Information of deployment DLLs that contain MatchPoint algorithms.
		*
		* Structur contains in addition to DeploymentDLLInfo the library handle for
		* managing purposes.
		* @ingroup DeployHost
		*/
		class MAPDeployment_EXPORT DLLHandle: public DLLInfo
		{
		public:
			/** Smart pointer typedef support. */
			typedef DLLHandle  Self;
			typedef DLLInfo  Superclass;
			typedef ::itk::SmartPointer<Self>  Pointer;
			typedef ::itk::SmartPointer<const Self>  ConstPointer;

			// Ugly stuff for library handles
			// They are different on several different OS's
#if defined(__hpux)
			typedef shl_t LibraryHandleType;
#elif defined(_WIN32) && !defined(__CYGWIN__)
			typedef HMODULE LibraryHandleType;
#elif defined(__APPLE__)
#if MAC_OS_X_VERSION_MAX_ALLOWED < 1030
			typedef NSModule LibraryHandleType;
#else
			typedef void *LibraryHandleType;
#endif
#elif defined(__BEOS__)
			typedef image_id LibraryHandleType;
#else  // POSIX
			typedef void *LibraryHandleType;
#endif

			/** Run-time type information (and related methods). */
			itkTypeMacro(DLLHandle, DLLInfo);

			/**
			* @brief Creates a DLLHandle instance, initializes it and returns it via smartpointer.
			* @return A pointer to the MetaProperty.
			* @param pUID pointer to the UID of the algorithm offered by the DLL.
			* @param libraryHandle handle to the deployment DLL.
			* @param libraryFile File path of the DLL containing the algorithm
			* @eguarantee strong
			*/
			static Pointer New(const LibraryHandleType &libraryHandle,
			                   const map::algorithm::UID *pUID,
			                   const core::String &libraryFile,
              const core::String &profileStr,
              const core::String &description);

			const LibraryHandleType &getLibraryHandle() const;

		protected:
			DLLHandle(const LibraryHandleType &libraryHandle,
			          const map::algorithm::UID *pUID,
			          const core::String &libraryFile,
              const core::String &profileStr,
              const core::String &description);

			~DLLHandle();

			LibraryHandleType _libraryHandle;

		private:
			DLLHandle(const Self &);//purposely not implemented
			void operator=(const Self &); //purposely not implemented

		};


	} // end namespace deployment
} // end namespace map

#endif
