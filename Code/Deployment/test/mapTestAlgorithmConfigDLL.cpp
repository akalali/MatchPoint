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

/*! @file
 * Test dll that is used to test the sync mechanisme and correct propagation of global MatchPoint configurations into
 * deployment dlls.
 */

#include "mapDeploymentDLLHelper.h"
#include "mapDiscreteElements.h"
#include "mapDummyImageRegistrationAlgorithm.h"
#include "mapConfigure.h"
#include "mapLogbook.h"


mapGenerateAlgorithmUIDPolicyMacro(TestAlgorithmDLLPolicy, "de.dkfz.matchpoint",
								   "TestAlgorithm.config", "1.0.0", "testprofile");

typedef map::core::discrete::Elements<2>::InternalImageType ImageType;
typedef map::algorithm::DummyImageRegistrationAlgorithm<ImageType, ImageType, TestAlgorithmDLLPolicy>
AlgorithmType;

typedef map::deployment::DeploymentDLLHelper<AlgorithmType> DLLHelperType;

extern "C"
#ifdef _WIN32
__declspec(dllexport)
#endif
void mapGetDLLInterfaceVersion(unsigned int& major, unsigned int& minor)
{
	major = MAP_DLL_INTERFACE_VERSION_MAJOR;
	minor = MAP_DLL_INTERFACE_VERSION_MINOR;
};

extern "C"
#ifdef _WIN32
__declspec(dllexport)
#endif
void mapGetRegistrationAlgorithmUID(map::algorithm::UID::Pointer& spUID)
{
	spUID = DLLHelperType::mapGetRegistrationAlgorithmUID();
};

extern "C"
#ifdef _WIN32
__declspec(dllexport)
#endif
void mapGetRegistrationAlgorithmProfile(map::core::String& profile)
{
	profile = DLLHelperType::mapGetRegistrationAlgorithmProfile();
};

extern "C"
#ifdef _WIN32
__declspec(dllexport)
#endif
void mapGetRegistrationAlgorithmInstance(map::algorithm::RegistrationAlgorithmBase::Pointer&
		spAlgorithm, map::deployment::SyncObject* pSyncObject)
{
	spAlgorithm = DLLHelperType::mapGetRegistrationAlgorithmInstance(pSyncObject);
	map::core::Logbook::fatal("TestEntryOfTheDll. If you read this the dll sync works.");
};