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


#include <cstdlib> // for atoi
#include "mapConvert.h"
#include "mapExceptionObjectMacros.h"

#include <fstream>
#include "itksys/SystemTools.hxx"

namespace map
{
	namespace core
	{
		namespace convert
		{

			String toStr(const double& value, const int precision)
			{
				String sResult;
				OStringStream stream;

				stream.precision(precision);
				stream << std::showpoint << value;

				sResult = stream.str();
				return sResult;
			};

			String toStr(const float& value, const int precision)
			{
				String sResult;
				OStringStream stream;

				stream.precision(precision);
				stream << std::showpoint << value;

				sResult = stream.str();
				return sResult;
			};

			String toStr(const bool& value)
			{
				if (value)
				{
					return "1";
				}
				
				
					return "0";
				
			};

			String toStr(const int& value)
			{
				String sResult;
				OStringStream stream;

				stream << value;

				sResult = stream.str();
				return sResult;
			};

			String toStr(const unsigned int& value)
			{
				String sResult;
				OStringStream stream;

				stream << value;

				sResult = stream.str();
				return sResult;
			};

			String toStr(const long& value)
			{
				String sResult;
				OStringStream stream;

				stream << value;

				sResult = stream.str();
				return sResult;
			};

			String toStr(const unsigned long& value)
			{
				String sResult;
				OStringStream stream;

				stream << value;

				sResult = stream.str();
				return sResult;
			};

			String toStr(const String& str)
			{
				return str;
			};

			double toDouble(const String& value)
			{
				char* pStopstring;
				double x;
				x = strtod(value.c_str(), &pStopstring);
				return x;
			};

			bool isADouble(const String& value)
			{
				char* pStopstring;
				double x;
				x = strtod(value.c_str(), &pStopstring);
				String sTemp = pStopstring;
				return (static_cast<int>(sTemp.empty()) & static_cast<int>(!value.empty())) != 0;
			};

			float toFloat(const String& value)
			{
				return toValueGeneric<float>(value);
			};

			int toInt(const String& value)
			{
				return atoi(value.c_str());
			};

			bool isAInt(const String& value)
			{
				int iTest = toInt(value);
				String sTest = toStr(iTest);
				return value == sTest;
			};

			unsigned int toUInt(const String& value)
			{
				return toValueGeneric<unsigned int>(value);
			};

			long toLong(const String& value)
			{
				return toValueGeneric<long>(value);
			};

			bool isALong(const String& value)
			{
				long lTest = toLong(value);
				String sTest = toStr(lTest);
				return value == sTest;
			};

			unsigned long toULong(const String& value)
			{
				return toValueGeneric<unsigned long>(value);
			};

			bool toBool(const String& value)
			{
				if (value == "0")
				{
					return false;
				}

				if (value == "false")
				{
					return false;
				}

				if (value == "FALSE")
				{
					return false;
				}

				if (value == "False")
				{
					return false;
				}

				return true;
			};

			String fileContentToStr(const String& filePath)
			{
				String result;
				std::ifstream file;

				std::ios_base::openmode iOpenFlag = std::ios_base::in;
				file.open(filePath.c_str(), iOpenFlag);

				if (file.is_open())
				{
					bool hasError = false;
					std::streamsize filesize = itksys::SystemTools::FileLength(filePath);
					char* buffer = new char [filesize];

					try
					{
						file.read(buffer, filesize);

						std::streamsize gsize = file.gcount();

						result.insert(0, buffer, gsize);
					}
					catch (...)
					{
						hasError = true;
					}

					delete[] buffer;
					file.close();

					if (hasError)
					{
						mapDefaultExceptionStaticMacro( << "Error while reading file content into buffer. File path:" <<
														filePath);
					}
				}

				return result;
			};

		}  // namespace convert
	}  // namespace core
}  // namespace map
