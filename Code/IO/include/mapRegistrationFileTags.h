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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/IO/include/mapRegistrationFileTags.h $
*/


#ifndef __MAP_REGISTRATION_FILE_TAGS_H
#define __MAP_REGISTRATION_FILE_TAGS_H


namespace map
{
	namespace tags
	{
		const char *const Registration = "Registration";
		const char *const RegistrationTag = "Tag";
		const char *const RegistrationTagName = "Name";
		const char *const MovingDimensions = "MovingDimensions";
		const char *const TargetDimensions = "TargetDimensions";
		const char *const InputDimensions = "InputDimensions";
		const char *const OutputDimensions = "OutputDimensions";
		const char *const Kernel = "Kernel";
		const char *const KernelID = "ID";
		const char *const StreamProvider = "StreamProvider";
		const char *const KernelType = "KernelType";
		const char *const direct = "direct";
		const char *const inverse = "inverse";
		const char *const Matrix = "Matrix";
		const char *const Offset = "Offset";
		const char *const Value = "Value";
		const char *const Column = "Column";
		const char *const Row = "Row";
		const char *const MatrixStr = "MatrixStr";
		const char *const OffsetStr = "OffsetStr";
		const char *const FieldPath = "FieldPath";
		const char *const NullVector = "NullVector";
		const char *const UseNullVector = "UseNullVector";

	}
}

#endif
