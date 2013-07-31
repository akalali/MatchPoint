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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Core/include/mapSyncInterface.h $
*/


#ifndef __MAP_SYNC_INTERFACE_H
#define __MAP_SYNC_INTERFACE_H

#include "mapSyncObject.h"

namespace map
{
	namespace core
	{

		/** This interface is implemented by every class, that deals/needs to
		 * sync internals accros deployment dlls boundaries (e.g. core::Logbook).
		 * */
		class SyncInterface
		{
		public:
			/** This function is called to add all information to pSyncObject
			 * that are needed to performe a synchronisation of an other instance*/
			virtual void getSynchronization(deployment::SyncObject &pSyncObject) const = 0;
			/** This function is called to synchronize the instance with
			 * the information of pSyncObject.*/
			virtual void setSynchronization(const deployment::SyncObject &pSyncObject) = 0;
			/** This function is called to desynchronize the instance.*/
			virtual void deSynchronize() = 0;
		};
	} // end namespace core
} // end namespace map

#endif
