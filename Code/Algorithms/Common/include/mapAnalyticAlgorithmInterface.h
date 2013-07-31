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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Algorithms/Common/include/mapAnalyticAlgorithmInterface.h $
*/




#ifndef __ANALYTIC_ALGORITHM_INTERFACE_H
#define __ANALYTIC_ALGORITHM_INTERFACE_H

/*! @namespace map The namespace map is used throughout the MatchPoint project to
mark code as components of this project
*/
namespace map
{
	namespace algorithm
	{
		namespace facet
		{
			/*! @class AnalyticAlgorithmInterface
			@brief This is the interface for analytic algorithms (not iterative)
			@ingroup AlgorithmFacets
			*/
			class AnalyticAlgorithmInterface
			{
			public:
				typedef AnalyticAlgorithmInterface Self;



			protected:
				AnalyticAlgorithmInterface() {};
				virtual ~AnalyticAlgorithmInterface() {};

			private:
				//No copy constructor allowed
				AnalyticAlgorithmInterface(const Self &source);
				void operator=(const Self &); //purposely not implemented

			};
		}
	}
}

#endif
