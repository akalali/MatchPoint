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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Algorithms/Common/include/mapAlgorithmStateChangeEvent.h $
*/


#ifndef __MAP_ALGORITHM_STATE_CHANGE_EVENTS_H
#define __MAP_ALGORITHM_STATE_CHANGE_EVENTS_H

#include "mapAlgorithmEvents.h"
#include "mapRegistrationAlgorithmBase.h"
#include "mapMAPAlgorithmsExports.h"

namespace map
{
	namespace events
	{

		/*! @class AlgorithmStateChangeEvent
		 * @ingroup Events*/
		class MAPAlgorithms_EXPORT AlgorithmStateChangeEvent : public AlgorithmEvent
		{
		public:
			typedef AlgorithmStateChangeEvent Self;
			typedef AlgorithmEvent Superclass;
			typedef algorithm::RegistrationAlgorithmBase::AlgorithmState::Type AlgorithmStateType;

			AlgorithmStateChangeEvent(const AlgorithmStateType &oldState = algorithm::RegistrationAlgorithmBase::AlgorithmState::Pending, const AlgorithmStateType &newState = algorithm::RegistrationAlgorithmBase::AlgorithmState::Pending);

			virtual ~AlgorithmStateChangeEvent();

			virtual const char *GetEventName() const;

			virtual bool CheckEvent(const ::itk::EventObject *e) const;

			virtual ::itk::EventObject *MakeObject() const;

			AlgorithmStateChangeEvent(const Self &s);

			AlgorithmStateType getOldState() const;
			AlgorithmStateType getNewState() const;

			virtual void Print(std::ostream &os) const;

		private:
			AlgorithmStateType _oldState;
			AlgorithmStateType _newState;
			void operator=(const Self &);
		};
	}
}

#endif
