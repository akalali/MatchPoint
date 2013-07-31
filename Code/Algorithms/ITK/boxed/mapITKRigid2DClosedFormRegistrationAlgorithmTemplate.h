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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Algorithms/ITK/boxed/mapITKRigid2DClosedFormRegistrationAlgorithmTemplate.h $
*/


#ifndef __MAP_RIGID_2D_CLOSED_FORM_REGISTRATION_ALGORITHM_H
#define __MAP_RIGID_2D_CLOSED_FORM_REGISTRATION_ALGORITHM_H

#include "mapITKClosedFormRegistrationAlgorithm.h"

#include "mapITKRigid2DTransform.h"


namespace map
{
	namespace algorithm
	{
		namespace boxed
		{


			mapGenerateAlgorithmUIDPolicyMacro(DefaultITKRigid2DClosedFormRegistrationAlgorithmUIDPolicy, "de.dkfz.matchpoint", "ITKRigid2DClosedFormRegistrationAlgorithm.default", "1.0.0");

			/** @brief Boxing of a closed form 2D rigid registration algorithm
			 @ingroup Boxed
			*/
			template < class TPointSet = core::continuous::Elements<2>::InternalPointSetType,
			         class TIdentificationPolicy = DefaultITKRigid2DClosedFormRegistrationAlgorithmUIDPolicy >
			struct ITKRigid2DClosedFormRegistrationAlgorithmTemplate
			{
public:
				//optional
				typedef ::itk::Rigid2DTransform< map::core::continuous::ScalarType> TransformType;

				//default typdefs
				typedef map::algorithm::itk::ITKClosedFormRegistrationAlgorithm<TPointSet, TPointSet, TransformType, TIdentificationPolicy> Type;
				typedef typename Type::Pointer Pointer;
			};
		}
	}
}


#endif
