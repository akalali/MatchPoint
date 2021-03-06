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


#include "mapEvents.h"

#include <utility>

namespace map
{
	namespace core
	{


		EventObject::
		EventObject(void* pData, std::string  comment): _pData(pData), _comment(std::move(comment))
		{};

		EventObject::
		~EventObject() = default;

		void*
		EventObject::
		getData() const
		{
			return _pData;
		};

		const std::string&
		EventObject::
		getComment() const
		{
			return _comment;
		};

		const char*
		EventObject::
		GetEventName() const
		{
			return "map::EventObject";
		};

		bool
		EventObject::
		CheckEvent(const ::itk::EventObject* e) const
		{
			return dynamic_cast<const Self*>(e) != nullptr;
		}

		::itk::EventObject*
		EventObject::
		MakeObject() const
		{
			return new EventObject(*this);
		}

		EventObject::
		EventObject(const Self& s) : Superclass(s)
		{
			_comment = s.getComment();
			_pData = s.getData();
		};

		void
		EventObject::
		Print(std::ostream& os) const
		{
			Superclass::Print(os);
			os << "Comment: " << _comment << std::endl;
			os << "Data pointer: " << _pData << std::endl;
		};


	}  // namespace core
}  // namespace map