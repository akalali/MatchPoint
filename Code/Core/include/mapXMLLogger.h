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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Core/include/mapXMLLogger.h $
*/


#ifndef __MAP_XML_LOGGER_H
#define __MAP_XML_LOGGER_H

#include "itkLogger.h"

#include "mapMacros.h"
#include "mapMAPCoreExports.h"


namespace map
{
	namespace core
	{

		/*! @class XMLLogger
		* @brief Logger based on itk::Logger but generating XML outputs.
		*
		* Build xml log entries, regarding the following pattern:\n
		* <logentry time='...' priorityLevel='...' logger='...'>\n
		*   ...content...\n
		* </logentry>
		* @remark The logger does not escape any special xml characters,
		* thus it is possible to inject further xml strutcures with the content
		* string. If you want to prevent such an injection you may convert the
		* string we the global function escapeSpecialXMLCharacters() befor you pass
		* the string to the logger.
		* @ingroup Logging
		*/
		class MAPCore_EXPORT XMLLogger: public itk::Logger
		{
		public:
			typedef XMLLogger  Self;
			typedef Logger  Superclass;
			typedef itk::SmartPointer<Self>  Pointer;
			typedef itk::SmartPointer<const Self>  ConstPointer;

			/** Run-time type information (and related methods). */
			itkTypeMacro(XMLLogger, itk::Logger);

			/** New macro for creation of through a Smart Pointer */
			itkNewMacro(Self);

			/** Provides a xml formatted log entry */
			virtual std::string BuildFormattedEntry(PriorityLevelType level, std::string const &content);

		protected:

			/** Constructor */
			XMLLogger() {};

			/** Destructor */
			virtual ~XMLLogger() {};

		private:
			XMLLogger(const Self &); //purposely not implemented
			void operator=(const Self &); //purposely not implemented
		};

		/*! Converts the passed content and "escapes" any special xml characters.
		 * (e.g. "<" to "&lt;").
		 * @return Converted string.*/
		MAPCore_EXPORT std::string escapeSpecialXMLCharacters(std::string content);

	} // end namespace core
} // end namespace map

#endif
