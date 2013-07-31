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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Algorithms/Common/include/mapMultiResImageRegistrationAlgorithmBase.h $
*/




#ifndef __MULTI_RES_IMAGE_REGISTRATION_ALGORITHM_INTERFACE_H
#define __MULTI_RES_IMAGE_REGISTRATION_ALGORITHM_INTERFACE_H

#include "itkIndent.h"
#include "itkMultiResolutionPyramidImageFilter.h"
#include "itkConceptChecking.h"

#include "mapMultiResRegistrationAlgorithmBase.h"

/*! @namespace
*/
namespace map
{
	namespace algorithm
	{

		/*! @class MultiResImageRegistrationAlgorithmBase
		 *@brief This is the default implementation of the interface for image registration algorithms that implement a multi resolution approach.
		 *
		 * The resolution number and scaling is defined by schedules
		 * This base class allows depending on the used pyramide policy to set the pyramide types. (see ImagePyramideSetterInterface and ImagePyramideSetterInterface
		 * added by TPyramidesPolicy; e.g. ArbitraryImagePyramidePolicy)
		 *
		 *@ingroup AlgorithmFacets
		 *@template TMovingImage the type of the moving image
		 *@template TTargetImage the type of the target image
		 *@template TPyramidesPolicy Policy that defines how the image pyramides can be changed an what interfaces are offered by the base class.
		 */
		template<class TMovingImage, class TTargetImage, class TPyramidesPolicy >
		class MultiResImageRegistrationAlgorithmBase: public MultiResRegistrationAlgorithmBase, public TPyramidesPolicy
		{
		public:
			typedef TMovingImage MovingImageType;
			typedef TTargetImage TargetImageType;
			typedef TPyramidesPolicy PyramidesPolicyType;

			typedef MultiResImageRegistrationAlgorithmBase<MovingImageType, TargetImageType, TPyramidesPolicy > Self;
			typedef MultiResRegistrationAlgorithmBase Superclass;

			/** Type of pyramid schedule type */
			typedef typename Superclass::ScheduleType ScheduleType;

			typedef typename PyramidesPolicyType::TargetImagePyramideBaseType TargetImagePyramideBaseType;
			typedef typename PyramidesPolicyType::TargetImagePyramideBasePointer TargetImagePyramideBasePointer;
			typedef typename PyramidesPolicyType::MovingImagePyramideBaseType MovingImagePyramideBaseType;
			typedef typename PyramidesPolicyType::MovingImagePyramideBasePointer MovingImagePyramideBasePointer;

#ifdef ITK_USE_CONCEPT_CHECKING
			/** Begin concept checking */
			itkConceptMacro(MovingImageFitsPyramideCheck,
			                (::itk::Concept::SameType<TMovingImage, typename PyramidesPolicyType::MovingImageType>));
			itkConceptMacro(TargetImageFitsPyramideCheck,
			                (::itk::Concept::SameType<TTargetImage, typename PyramidesPolicyType::TargetImageType>));
			/** End concept checking */
#endif

			/*! @brief Returns the number of dimensions for the moving
			 information space.
			  @eguarantee strong
			 */
			DimensionCountType getMovingResolutionDimensions() const;

			/*! @brief Returns the number of dimensions for the target
			 information space.
			  @eguarantee strong
			 */
			DimensionCountType getTargetResolutionDimensions() const;


		protected:
			/*! @brief virtual destructor
			*/
			virtual ~MultiResImageRegistrationAlgorithmBase();

			MultiResImageRegistrationAlgorithmBase();

			/*! Methods invoked by derivated classes.  */
			virtual void PrintSelf(std::ostream &os, ::itk::Indent indent) const;

			/*! This member function is called by the interface if the moving image pyramide instance changes.
			* Two events will be invoked with this command: \n
			* - UnregisterAlgorithmComponentEvent
			* - RegisterAlgorithmComponentEvent
			* .
			* The first one is used when the current pyramide is going to be replaced. The event data in this case
			* is a void pointer to the current (soon outdated) object. The second event will be called when the new
			* image pyramide was set. In this case the event data is a pointer to the new pyramide.*/
			virtual void onMovingImagePyramideChange(const ::itk::EventObject &eventObject) = 0;
			void onMovingImagePyramideChangeHelper(const ::itk::EventObject &eventObject);

			/*! This member function is called by the interface if the target image pyramide instance changes.
			* Two events will be invoked with this command: \n
			* - UnregisterAlgorithmComponentEvent
			* - RegisterAlgorithmComponentEvent
			* .
			* The first one is used when the current pyramide is going to be replaced. The event data in this case
			* is a void pointer to the current (soon outdated) object. The second event will be called when the new
			* image pyramide was set. In this case the event data is a pointer to the new pyramide.*/
			virtual void onTargetImagePyramideChange(const ::itk::EventObject &eventObject) = 0;
			void onTargetImagePyramideChangeHelper(const ::itk::EventObject &eventObject);

		private:
			//No copy constructor allowed
			MultiResImageRegistrationAlgorithmBase(const Self &source);
			void operator=(const Self &); //purposely not implemented
		};

	}
}

#ifndef MatchPoint_MANUAL_TPP
#include "mapMultiResImageRegistrationAlgorithmBase.tpp"
#endif


#endif
