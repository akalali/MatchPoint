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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Algorithms/ITK/include/mapITKImageRegistrationAlgorithm.h $
*/




#ifndef __ITK_IMAGE_REGISTRATION_ALGORITHM_H
#define __ITK_IMAGE_REGISTRATION_ALGORITHM_H

#include "mapContinuous.h"

#include "mapArbitraryTransformPolicy.h"
#include "mapIterativeRegistrationAlgorithm.h"
#include "mapImageRegistrationAlgorithmBase.h"
#include "mapMetaPropertyAlgorithmBase.h"
#include "mapMaskedRegistrationAlgorithmBase.h"
#include "mapITKImageRegistrationAlgorithmInterface.h"
#include "mapArbitraryInterpolatorPolicy.h"
#include "mapArbitraryImageToImageMetricPolicy.h"
#include "mapArbitrarySVNLOptimizerPolicy.h"
#include "mapArbitraryTransformPolicy.h"
#include "mapObserverSentinel.h"
#include "mapModificationTimeValidator.h"

#include "itkImageRegistrationMethod.h"
#include "itkSimpleFastMutexLock.h"

/*! @namespace map The namespace map is used throughout the MatchPoint project to
mark code as components of this project
*/
namespace map
{
	namespace algorithm
	{
		namespace itk
		{

			mapGenerateAlgorithmUIDPolicyMacro(DefaultITKImageRegistrationUIDPolicy, "de.dkfz.matchpoint", "ITKImageRegistrationAlgorithm.arbitrayDefault", "1.0.0");

			/*! @class ITKImageRegistrationAlgorithm
			@brief The class for an image registration algorithm based on ITK
			@ingroup Algorithms
			@ingroup ITK
			*/
			template < class TMovingImage, class TTargetImage,
			         class TIdentificationPolicy = DefaultITKImageRegistrationUIDPolicy,
			         class TInterpolatorPolicy = ArbitraryInterpolatorPolicy<TMovingImage, core::continuous::ScalarType>,
			         class TMetricPolicy = ArbitraryImageToImageMetricPolicy<TMovingImage, TTargetImage>,
			         class TOptimizerPolicy = ArbitrarySVNLOptimizerPolicy,
			         class TTransformPolicy = ArbitraryTransformPolicy<core::continuous::ScalarType, TMovingImage::ImageDimension, TTargetImage::ImageDimension>,
			         class TInternalRegistrationMethod = ::itk::ImageRegistrationMethod<TTargetImage, TMovingImage> >
			class ITKImageRegistrationAlgorithm : public IterativeRegistrationAlgorithm<TMovingImage::ImageDimension, TTargetImage::ImageDimension>,
				public ImageRegistrationAlgorithmBase<TMovingImage, TTargetImage>,
				public MaskedRegistrationAlgorithmBase<TMovingImage::ImageDimension, TTargetImage::ImageDimension>,
				public MetaPropertyAlgorithmBase,
				public ITKImageRegistrationAlgorithmInterface<TMovingImage, TTargetImage, typename TTransformPolicy::TransformScalarType, typename TInterpolatorPolicy::CoordRepType>,
				public TIdentificationPolicy,
        public TInterpolatorPolicy,
				public TMetricPolicy,
				public TOptimizerPolicy,
				public TTransformPolicy
			{
			public:
				typedef ITKImageRegistrationAlgorithm < TMovingImage, TTargetImage, TIdentificationPolicy, TInterpolatorPolicy, TMetricPolicy,
				        TOptimizerPolicy, TTransformPolicy, TInternalRegistrationMethod > Self;
				typedef IterativeRegistrationAlgorithm<TMovingImage::ImageDimension, TTargetImage::ImageDimension>  Superclass;
				typedef ITKImageRegistrationAlgorithmInterface<TMovingImage, TTargetImage, typename TTransformPolicy::TransformScalarType, typename TInterpolatorPolicy::CoordRepType> ITKRegistrationType;

				typedef ::itk::SmartPointer<Self>                                     Pointer;
				typedef ::itk::SmartPointer<const Self>                               ConstPointer;
				itkTypeMacro(ITKImageRegistrationAlgorithm, IterativeRegistrationAlgorithm);
				mapNewAlgorithmMacro(Self);

				typedef typename Superclass::UIDType UIDType;
				typedef typename Superclass::UIDPointer UIDPointer;

				typedef TInterpolatorPolicy   InterpolatorPolicyType;
				typedef TMetricPolicy         MetricPolicyType;
				typedef TOptimizerPolicy      OptimizerPolicyType;
				typedef TTransformPolicy      TransformPolicyType;
				typedef TIdentificationPolicy IdentificationPolicyType;

				typedef typename ITKRegistrationType::OptimizerBaseType OptimizerBaseType;
				typedef typename ITKRegistrationType::MetricBaseType MetricBaseType;
				typedef typename ITKRegistrationType::TransformBaseType TransformBaseType;
				typedef typename ITKRegistrationType::InterpolatorBaseType InterpolatorBaseType;

				typedef typename IterativeRegistrationAlgorithm<TMovingImage::ImageDimension, TTargetImage::ImageDimension>::OptimizerMeasureType OptimizerMeasureType;
				typedef ImageRegistrationAlgorithmBase<TMovingImage, TTargetImage> ImageRegistrationAlgorithmBaseType;

				typedef typename ImageRegistrationAlgorithmBaseType::TargetImageType TargetImageType;
				typedef typename ImageRegistrationAlgorithmBaseType::MovingImageType MovingImageType;
				typedef typename ImageRegistrationAlgorithmBaseType::MovingImageConstPointer MovingImageConstPointer;
				typedef typename ImageRegistrationAlgorithmBaseType::TargetImageConstPointer TargetImageConstPointer;

				typedef typename Superclass::MovingRepresentationDescriptorType MovingRepresentationDescriptorType;
				typedef typename Superclass::TargetRepresentationDescriptorType TargetRepresentationDescriptorType;

				typedef typename Superclass::RegistrationPointer RegistrationPointer;
				typedef typename Superclass::RegistrationType RegistrationType;
				typedef typename Superclass::FieldRepRequirement FieldRepRequirement;
				typedef typename Superclass::IterationCountType IterationCountType;

				typedef typename MetaPropertyAlgorithmBase::MetaPropertyPointer MetaPropertyPointer;
				typedef typename MetaPropertyAlgorithmBase::MetaPropertyNameType MetaPropertyNameType;
				typedef typename MetaPropertyAlgorithmBase::MetaPropertyVectorType MetaPropertyVectorType;

				// IterativeRegistrationAlgorithm
				/*! @eguarantee strong*/
				virtual bool isStoppable() const;

				/*! has the algorithm an iteration count?
				@eguarantee no fail
				@return Indicates if the algorithm can determin its current iteration count
				*/
				virtual bool hasIterationCount() const;

				/*! has the algorithm an maximum iteration count?
				@eguarantee no fail
				@return Indicates if the algorithm can determin its maximum iteration count
				*/
				virtual bool hasMaxIterationCount() const;

				/*! This function indicates of the optimizer of the iterative registration algorithm is
				* able to return its current metric/optimizer value(s)?
				@eguarantee no fail
				@return Indicates if the algorithm can determin its curent value.
				*/
				virtual bool hasCurrentOptimizerValue() const;

				virtual UIDPointer getUID() const;
				virtual map::core::String getAlgorithmProfile() const;
				virtual map::core::String getAlgorithmDescription() const;

				virtual typename FieldRepRequirement::Type isMovingRepresentationRequired() const;

				virtual typename FieldRepRequirement::Type isTargetRepresentationRequired() const;

				virtual bool isReusable() const;

			protected:
				ITKImageRegistrationAlgorithm();
				virtual ~ITKImageRegistrationAlgorithm();

				typedef TInternalRegistrationMethod InternalRegistrationMethodType;
				typedef typename Superclass::InterimRegistrationType InterimRegistrationType;
				typedef typename Superclass::InterimRegistrationPointer InterimRegistrationPointer;

				/*! @overwrite
				 * This default implementation does nothing.*/
				virtual void configureAlgorithm();

				// MetaPropertyAlgorithmBase

				/*! @reimplemented*/
				virtual void compileInfos(MetaPropertyVectorType &infos) const;

				/*! @reimplemented*/
				virtual MetaPropertyPointer doGetProperty(const MetaPropertyNameType &name) const;

				/*! @reimplemented*/
				virtual void doSetProperty(const MetaPropertyNameType &name, const MetaPropertyType *pProperty);

				// IterativeRegistrationAlgorithmInterface

				/*! @brief gets the registration result that has been computed in the last iteration.
				This result is limited by a region
				@pre pMovingRepresentation and pTargetRepresentation must not be null.
				@param [in] pMovingRepresentation Pointer to
				@eguarantee strong
				@return the interim registration result as smart pointer
				@retval a Registration object
				@sa Registration
				*/
				virtual InterimRegistrationPointer determineInterimRegistration(const MovingRepresentationDescriptorType *pMovingRepresentation,
				                                                                const TargetRepresentationDescriptorType *pTargetRepresentation) const;

				/*!
				* Returns the final registration
				@eguarantee strong
				*/
				virtual RegistrationPointer doGetRegistration() const;

				/*! Returns if the registration should be computed. The registration is outdated if doGetRegistration returns null
				* or the modification times of at least one policy is newer then the modification time of the registration.
				@eguarantee strong
				@return true if the registration should be (re)computed. False if the registration is uptodate.
				*/
				virtual bool registrationIsOutdated() const;

				virtual bool doStopAlgorithm();

				/*! This method should do all preparation tasks right before the algorithms execution. At the and of this method
				* the algorithm should be set up and ready to use.\n
				* The method delegates the main work of initialization to several sub methods. This sub methods serves as slots
				* that can be rewritten by a algorithm developer to alter certain aspects and keep the rest untouched.\n
				* The sequence of slot calls is: \n
				* - prepCheckValidity
				* - prepPrepareSubComponents
				* - prepAssembleSubComponents
				* - prepPerpareInternalInputData
				* - prepSetInternalInputData
				* - prepInitializeTransformation
				* - prepFinalizePreparation
				* @remark If you want to change the execution style, then overwrite runAlgorithm().
				@remark If you want to alter settings of optimzer, metric or interpolator depending on
				the resolution level use the method doInterLevelSetup()
				@remark configureAlgorithmByMetaProperties is called after preCheckValidity and before prepPerpareSubComponent.
				@eguarantee strong
				*/
				virtual void prepareAlgorithm();

				/*! This method is the slot to check if all internal components and input data are properly set.
				* @remark The default implementation checks transform, interpolator, optimizer, metric, pyramides, moving and target image.
				* overload this method to alter the validity check.
				* @remark It is assumed that the implementation of this method throws an exception if the algorithm is not be configured
				* correctly.*/
				virtual void prepCheckValidity();

				/*! This method is the slot where sub components can be configured before(!) they are set to the
				* internal registration method.
				* @remark The default implementation just calls the preparation methods of the component policies.*/
				virtual void prepPrepareSubComponents();

				/*! This method is the slot where sub components are set to the internal registration method.
				* @remark The default implementation just calls the preparation methods of the component policies.*/
				virtual void prepAssembleSubComponents();

				/*! This method is the slot for internal preprocessing of input data. This method should
				* be reimplemented if you want to prepare the input data before they go into the internal
				* registration method. E.g. blurring or normalizing the moving and target image before registration.
				* @remark The default implementation does nothing. Thus the public input data will be the data used by the
				* internal algorithm.
				* @remark Implementations of this method should work on _spInternalMoving and _spInternalTargetImage. In the default
				* implementation of prepSetInternalInputData() these member will be passed to the internal algorithm.
				@eguarantee strong
				*/
				virtual void prepPerpareInternalInputData();

				/*! This method is the slot for passing relevant input data to the internal algorithm or its components.
				* @remark The default implementation passes _spInternalMoving and _spInternalTargetImage, sets the schedules, the fixed image region of the registration and the metric masks.
				@eguarantee strong
				*/
				virtual void prepSetInternalInputData();

				/*! This method is a slot that is used for the initialization of the transformation model used
				* by the internal registration algorithm.
				* @remark By default it just sets the initial transformation parameter for the internal registration methods to the current values of the transform.
				@eguarantee strong
				*/
				virtual void prepInitializeTransformation();

				/*! This method is the slot for final steps in the preperation process
				* @remark The default implementation calls the prepareAfterAssembly methods of the sub component policies.
				@eguarantee strong
				*/
				virtual void prepFinalizePreparation();

				/*! This method should just execute the iteration loop.
				* @remark If you want to change the initialization or the finalization, then overwrite prepareAlgorithm() or finalizeAlgorithm().
				* @return Indicates of the registration was successfully determined (e.g. could be
				* false if an iterative algorithm was stopped prematurely by the user).
				* @eguarantee strong
				*/
				virtual bool runAlgorithm();

				/*! This method should do all the finalization work (e.g. generating the registration based on the iteration results).
				* @remark If you want to change the initialization or the iteration, then overwrite prepareAlgorithm() or runAlgorithm().
				@eguarantee strong
				*/
				virtual void finalizeAlgorithm();

				typedef typename TransformPolicyType::TransformType::TransformBaseType::ParametersType TransformParametersType;

				/*! Gets the member variable _currentTransformParameters secured via _currentIterationLock.
				@return Copy of the current transform parameters.
				*/
				TransformParametersType getCurrentTransformParameters() const;

				/*! Sets the member variable _currentTransformParameters secured via _currentIterationLock.
				@param [in] Reference to the new current parameters.
				*/
				void setCurrentTransformParameters(const TransformParametersType &param);

				/*! return the optimizer value(s) of the current iteration step.
				Will be called by getCurrentOptimizerValue() if hasCurrentValue() returns true.
				@eguarantee strong
				@return current measure
				*/
				virtual OptimizerMeasureType doGetCurrentOptimizerValue() const;

				/*! Methods invoked by derivated classes.  */
				virtual void PrintSelf(std::ostream &os, ::itk::Indent indent) const;

				/*! @eguarantee strong*/
				virtual IterationCountType doGetCurrentIteration() const;

				/*! @brief gets the maximum number of the algorithm's iterations
				@eguarantee strong
				@return returns the algorithm's maximum iterations count
				*/
				virtual IterationCountType doGetMaxIterations() const;

				/*! Offers access to the internal registration method */
				InternalRegistrationMethodType &getInternalRegistrationMethod();

				/*!Pointer to the moving image used by the algorithm internally. This is used to allow the algorithm
				* or its derived classes to modify the moving image with out changing the public moving image pointer.
				* The variable is set by prepareAlgorithm() to _spMovingImage before calling prepPerpareInternalInputData().
				* (e.g.: An algorithm always normalizes an image before registration. Then the algorithm can use the prepPerpareInternalInputData()
				* function to manipulate _spInternalMovingImage before it is used by prepareAlgorithm() to set the internal algorithm)*/
				MovingImageConstPointer _spInternalMovingImage;

				/*!Pointer to the target image used by the algorithm internally. This is used to allow the algorithm
				* or its derived classes to modify the target image with out changing the public target image pointer.
				* The variable is set by prepareAlgorithm() to _spTargetImage before calling prepPerpareInternalInputData().
				* (e.g.: An algorithm always normalizes an image before registration. Then the algorithm can use the prepPerpareInternalInputData()
				* function to manipulate _spInternalTargetImage before it is used by prepareAlgorithm() to set the internal algorithm)*/
				TargetImageConstPointer _spInternalTargetImage;

				/*! The count if the iterations, since starting the registration algorithm the last time.
				* 0 indicates that no iteration has been processed yet.*/
				IterationCountType _currentIterationCount;

				/*! The lock is used to manage the access to the member variable _currentIterationCount.*/
				mutable ::itk::SimpleFastMutexLock _currentIterationLock;

				/*! The current parameters of the registration transform. Will be set in every iteration step*/
				TransformParametersType _currentTransformParameters;

				/*! The parameters of the registration transform of the last successfull registration determiniation. Will be set by finalizeAlgorithm()*/
				TransformParametersType _finalizedTransformParameters;

				/*! Smartpointer to the finalized registration. Will be set by finalizeAlgorithm()*/
				typename RegistrationType::Pointer _spFinalizedRegistration;

			private:
				typename InternalRegistrationMethodType::Pointer _internalRegistrationMethod;

				mutable core::ObserverSentinel::Pointer _onIterationObserver;
				mutable core::ObserverSentinel::Pointer _onGeneralOptimizerObserver;
				mutable core::ObserverSentinel::Pointer _onGeneralMetricObserver;
				mutable core::ObserverSentinel::Pointer _onGeneralInterpolatorObserver;
				mutable core::ObserverSentinel::Pointer _onGeneralTransformObserver;

				/*! This member function is called by the observer of the optimizer, when ever a IterationEvent is invoked.*/
				void onIterationEvent(::itk::Object *caller, const ::itk::EventObject &eventObject);

				/*! This member function is called by the observer of the optimizer for all kind of events. It serves as a pass through.*/
				void onGeneralOptimizerEvent(::itk::Object *caller, const ::itk::EventObject &eventObject);

				/*! This member function is called by the observer of the metric for all kind of events. It serves as a pass through.*/
				void onGeneralMetricEvent(::itk::Object *caller, const ::itk::EventObject &eventObject);

				/*! This member function is called by the observer of the interpolator for all kind of events. It serves as a pass through.*/
				void onGeneralInterpolatorEvent(::itk::Object *caller, const ::itk::EventObject &eventObject);

				/*! This member function is called by the observer of the transform for all kind of events. It serves as a pass through.*/
				void onGeneralTransformEvent(::itk::Object *caller, const ::itk::EventObject &eventObject);

				/*! This member function is called by the observer of the transform for all kind of events. It serves as a pass through.*/
				void onGeneralRegistrationMethodEvent(::itk::Object *caller, const ::itk::EventObject &eventObject);

				/*! This member function is called by the optimizer policy if the optimizer instance changes.*/
				void onOptimizerChange(const ::itk::EventObject &eventObject);

				/*! This member function is called by the metric policy if the metric instance changes.*/
				void onMetricChange(const ::itk::EventObject &eventObject);

				/*! This member function is called by the interpolator policy if the interpolator instance changes.*/
				void onInterpolatorChange(const ::itk::EventObject &eventObject);

				/*! This member function is called by the transform policy if the transform model instance changes.*/
				void onTransformChange(const ::itk::EventObject &eventObject);

				ITKImageRegistrationAlgorithm(const Self &source);
				void operator=(const Self &); //purposely not implemented
			};

		}
	}
}

#ifndef MatchPoint_MANUAL_TPP
#include "mapITKImageRegistrationAlgorithm.tpp"
#endif

#endif
