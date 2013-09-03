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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Algorithms/Common/include/mapAlgorithmIdentificationInterface.h $
*/




#ifndef __ALGORITHM_PROFILE_HELPER_H
#define __ALGORITHM_PROFILE_HELPER_H

#include "mapSDElement.h"

#include "mapMAPAlgorithmsExports.h"

namespace map
{

	namespace tags
	{
		/** Top node of a algorithm profile.*/
		const char *const AlgorithmProfile = "Profile";
    const char *const AlgorithmDescription = "Description";
	}

	namespace algorithm
	{

    /** Helper function that takes an algorithm profile string and converts it into structuredData
     * elements.
     * @return Pointer to the root element of the profile (Tag: Profile). If an invalid or empty string is passed,
     * the result will be a NULL pointer.*/
    MAPAlgorithms_EXPORT structuredData::Element::Pointer parseProfileString(const core::String& profileStr);

    /** Helper function that extracts the description from a profile.
     * @param Pointer to the root element of the profile (e.g. generated by parseProfileString).
     * @return Description string, may be empty if profileRoot is invalid or does not contain a description.*/
    MAPAlgorithms_EXPORT const ::map::core::String getAlgorithmDescription(const structuredData::Element* profileRoot);

  }
}

#endif
