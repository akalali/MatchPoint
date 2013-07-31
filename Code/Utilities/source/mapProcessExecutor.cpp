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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Utilities/source/mapProcessExecutor.cpp $
*/


#include <iostream>
#include <fstream>

#include "itksys/Process.h"
#include "itksys/SystemTools.hxx"

#include "mapProcessExecutor.h"
#include "mapFileDispatch.h"

namespace map
{
	namespace utilities
	{

		core::String
		ProcessExecutor::
		getOSDependendExecutableName(const core::String &name)
		{
#if defined(_WIN32)

			if (core::FileDispatch::getExtension(name).empty())
			{
				return name + ".exe";
			}
			else
			{
				return name;
			}

#else

			if (core::FileDispatch::getPath(name).empty())
			{
				return "./" + name;
			}
			else
			{
				return name;
			}

#endif
		};

		int
		ProcessExecutor::
		getExitValue()
		{
			return this->_exitValue;
		};

		bool
		ProcessExecutor::
		execute(const core::String &executionPath, const ArgumentListType &argumentList)
		{
			//convert to char* array with terminating null element;
			const char **pArguments = new const char*[argumentList.size() + 1];
			pArguments[argumentList.size()] = 0;

			for (ArgumentListType::size_type index = 0; index < argumentList.size(); ++index)
			{
				pArguments[index] = argumentList[index].c_str();
			}

			bool normalExit = false;

			try
			{
				itksysProcess *processID = itksysProcess_New();
				itksysProcess_SetCommand(processID, pArguments);

				itksysProcess_SetWorkingDirectory(processID, executionPath.c_str());

				if (this->_SharedOutputPipes)
				{
					itksysProcess_SetPipeShared(processID, itksysProcess_Pipe_STDOUT, true);
					itksysProcess_SetPipeShared(processID, itksysProcess_Pipe_STDERR, true);
				}

				itksysProcess_Execute(processID);

				char *rawOutput = NULL;
				int outputLength = 0;

				while (true)
				{
					int dataStatus = itksysProcess_WaitForData(processID, &rawOutput, &outputLength, NULL);

					if (dataStatus == itksysProcess_Pipe_STDOUT)
					{
						map::core::String data(rawOutput, outputLength);
						this->InvokeEvent(map::events::ExternalProcessStdOutEvent(NULL, data));
					}
					else if (dataStatus == itksysProcess_Pipe_STDERR)
					{
						map::core::String data(rawOutput, outputLength);
						this->InvokeEvent(map::events::ExternalProcessStdErrEvent(NULL, data));
					}
					else
					{
						break;
					}
				}

				itksysProcess_WaitForExit(processID, 0);

				itksysProcess_State_e state = static_cast<itksysProcess_State_e>(itksysProcess_GetState(processID));

				normalExit = (state == itksysProcess_State_Exited);
				this->_exitValue = itksysProcess_GetExitValue(processID);
			}
			catch (...)
			{
				delete[] pArguments;
				throw;
			}

			delete[] pArguments;

			return normalExit;
		};

		bool
		ProcessExecutor::
		execute(const core::String &executionPath, const core::String &executableName, ArgumentListType argumentList)
		{
			core::String executableName_OS = getOSDependendExecutableName(executableName);

			argumentList.insert(argumentList.begin(), executableName_OS);

			return execute(executionPath, argumentList);
		};

		ProcessExecutor::
		ProcessExecutor()
		{
			this->_exitValue = 0;
			this->_SharedOutputPipes = false;
		};

		ProcessExecutor::
		~ProcessExecutor()
		{
		};

	}
}
