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


#ifndef __MAP_ITK_RIGID2D_MATTES_MI_REGISTRATION_ALGORITHM_TEMPLATE_H
#define __MAP_ITK_RIGID2D_MATTES_MI_REGISTRATION_ALGORITHM_TEMPLATE_H

#include "mapITKInitializedImageRegistrationAlgorithm.h"

#include "mapITKRegularStepGradientDescentOptimizer.h"
#include "mapITKMattesMutualInformationImageToImageMetric.h"
#include "mapITKRigid2DTransform.h"
#include "mapITKLinearInterpolateImageFunction.h"

#include "mapFixedImageToImageMetricPolicy.h"
#include "mapFixedInterpolatorPolicy.h"
#include "mapFixedSVNLOptimizerPolicy.h"
#include "mapFixedTransformPolicy.h"
#include "mapSealedImagePyramidesPolicy.h"
#include "mapNoComponentInitializationPolicy.h"



namespace map
{
  namespace algorithm
  {
    namespace boxed
    {

      mapGenerateAlgorithmUIDPolicyMacro(DefaultRigid2DMattesMIRegistrationAlgorithmUIDPolicy,
                                         "de.dkfz.matchpoint", "Rigid2DMattesMIRegistrationAlgorithm.default", "1.1.0", "");

      template < class TMovingImage, class TTargetImage = TMovingImage,
                 typename TUIDPolicy = DefaultRigid2DMattesMIRegistrationAlgorithmUIDPolicy,
                 class TInterpolatorPolicy =
                 SealedFixedInterpolatorPolicyMacro< ::itk::LinearInterpolateImageFunction<TTargetImage, ::map::core::continuous::ScalarType> >
                 >
      class ITKRigid2DMattesMIRegistrationAlgorithm :
        public algorithm::boxed::ITKInitializedImageRegistrationAlgorithm < TMovingImage, TTargetImage,
        TUIDPolicy,
        TInterpolatorPolicy,
        SealedFixedImageToImageMetricPolicyMacro< ::itk::MattesMutualInformationImageToImageMetric<TMovingImage, TTargetImage> >,
        SealedFixedSVNLOptimizerPolicyMacro< ::itk::RegularStepGradientDescentOptimizer >,
        SealedFixedTransformPolicyMacro< ::itk::Rigid2DTransform<::map::core::continuous::ScalarType> > >
      {
      public:
        typedef ITKRigid2DMattesMIRegistrationAlgorithm < TMovingImage, TTargetImage, TUIDPolicy,
                TInterpolatorPolicy > Self;

        typedef typename algorithm::boxed::ITKInitializedImageRegistrationAlgorithm < TMovingImage,
                TTargetImage,
                TUIDPolicy,
                TInterpolatorPolicy,
                SealedFixedImageToImageMetricPolicyMacro< ::itk::MattesMutualInformationImageToImageMetric<TMovingImage, TTargetImage> >,
                SealedFixedSVNLOptimizerPolicyMacro< ::itk::RegularStepGradientDescentOptimizer >,
                SealedFixedTransformPolicyMacro< ::itk::Rigid2DTransform<::map::core::continuous::ScalarType> > >
                Superclass;

        typedef ::itk::SmartPointer<Self>                                     Pointer;
        typedef ::itk::SmartPointer<const Self>                               ConstPointer;

        itkTypeMacro(ITKRigid2DMattesMIRegistrationAlgorithm, ITKImageRegistrationAlgorithm);
        mapNewAlgorithmMacro(Self);

        typedef ::itk::Array<double> ParametersType;

        typedef typename Superclass::MetaPropertyType MetaPropertyType;
        typedef typename Superclass::MetaPropertyPointer MetaPropertyPointer;
        typedef typename Superclass::MetaPropertyNameType MetaPropertyNameType;
        typedef typename Superclass::MetaPropertyVectorType MetaPropertyVectorType;

      protected:
        ITKRigid2DMattesMIRegistrationAlgorithm();
        virtual ~ITKRigid2DMattesMIRegistrationAlgorithm();

        virtual void configureAlgorithm();

        virtual void compileInfos(MetaPropertyVectorType& infos) const;

        virtual MetaPropertyPointer doGetProperty(const MetaPropertyNameType& name) const;

        virtual void doSetProperty(const MetaPropertyNameType& name, const MetaPropertyType* pProperty);

      private:

        ITKRigid2DMattesMIRegistrationAlgorithm(const Self& source);  //purposely not implemented
        void operator=(const Self&);  //purposely not implemented
      };

    }
  }
}

#ifndef MatchPoint_MANUAL_TPP
#include "mapITKRigid2DMattesMIRegistrationAlgorithmTemplate.tpp"
#endif

#endif
