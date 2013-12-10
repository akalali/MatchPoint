SET(CPP_FILES 
source/mapITKOptimizerControlInterface.cpp
source/mapITKSVNLOptimizerControlInterface.cpp
source/mapArbitrarySVNLOptimizerPolicy.cpp
source/mapITKMetricControlInterface.cpp
source/mapITKSVMetricControlInterface.cpp
source/mapITKMVNLOptimizerControlInterface.cpp
source/mapITKMVMetricControlInterface.cpp
source/mapArbitraryMVNLOptimizerPolicy.cpp
)

SET(H_FILES 
include/mapArbitraryInterpolatorPolicy.h
include/mapArbitrarySVNLOptimizerPolicy.h
include/mapFixedInterpolatorPolicy.h
include/mapFixedSVNLOptimizerPolicy.h
include/mapITKImageRegistrationAlgorithm.h
include/mapITKImageRegistrationAlgorithmInterface.h
include/mapITKInterpolatorSetterInterface.h
include/mapITKImageToImageMetricSetterInterface.h
include/mapITKSVNLOptimizerControlBase.h
include/mapDefaultITKOptimizerControls.h
include/mapITKOptimizerControlInterface.h
include/mapITKSVNLOptimizerControlInterface.h
include/mapITKSVNLOptimizerSetterInterface.h
include/mapITKTransformSetterInterface.h
include/mapArbitraryImageToImageMetricPolicy.h
include/mapArbitraryTransformPolicy.h
include/mapFixedImageToImageMetricPolicy.h
include/mapFixedTransformPolicy.h
include/mapITKMetricControlInterface.h
include/mapITKSVMetricControlInterface.h
include/mapITKImageToImageMetricControlInterface.h
include/mapITKMetricControl.h
include/mapITKImageToImageMetricControlBase.h
include/mapITKMeanSquaresImageToImageMetric.h
include/mapITKMattesMutualInformationImageToImageMetric.h
include/mapITKCompareHistogramImageToImageMetric.h
include/mapITKCorrelationCoefficientHistogramImageToImageMetric.h
include/mapITKKappaStatisticImageToImageMetric.h
include/mapITKGradientDifferenceImageToImageMetric.h
include/mapITKMatchCardinalityImageToImageMetric.h
include/mapITKMeanSquaresHistogramImageToImageMetric.h
include/mapITKMutualInformationHistogramImageToImageMetric.h
include/mapITKMutualInformationImageToImageMetric.h
include/mapITKNormalizedCorrelationImageToImageMetric.h
include/mapITKNormalizedMutualInformationHistogramImageToImageMetric.h
include/mapITKAmoebaOptimizer.h
include/mapITKPowellOptimizer.h
include/mapITKRegularStepGradientDescentOptimizer.h
include/mapITKConjugateGradientOptimizer.h
include/mapITKFRPROptimizer.h
include/mapITKGradientDescentOptimizer.h
include/mapITKLBFGSBOptimizer.h
include/mapITKLBFGSOptimizer.h
include/mapITKOnePlusOneEvolutionaryOptimizer.h
include/mapITKQuaternionRgidTransformGradientDescentOptimizer.h
include/mapITKSPSAOptimizer.h
include/mapITKVersorRigid3DTransformOptimizer.h
include/mapITKVersorTransformOptimizer.h
include/mapSealedInterpolatorPolicy.h
include/mapSealedOptimizerPolicy.h
include/mapSealedImageToImageMetricPolicy.h
include/mapSealedTransformPolicy.h
include/mapITKSVNLOptimizerGetterInterface.h
include/mapITKInterpolatorGetterInterface.h
include/mapITKImageToImageMetricGetterInterface.h
include/mapITKTransformGetterInterface.h 
include/mapITKTransformModel.h
include/mapITKTranslationTransform.h
include/mapITKScaleTransform.h
include/mapITKAffineTransform.h
include/mapITKAzimuthElevationToCartesianTransform.h
include/mapITKCenteredAffineTransform.h
include/mapITKElasticBodyReciprocalSplineKernelTransform.h
include/mapITKElasticBodySplineKernelTransform.h
include/mapITKFixedCenterOfRotationAffineTransform.h
include/mapITKIdentityTransform.h
include/mapITKKernelTransform.h
include/mapITKScalableAffineTransform.h
include/mapITKScaleLogarithmicTransform.h
include/mapITKThinPlateR2LogRSplineKernelTransform.h
include/mapITKThinPlateSplineKernelTransform.h
include/mapITKVolumeSplineKernelTransform.h
include/mapITKCenteredEuler3DTransform.h
include/mapITKCenteredRigid2DTransform.h
include/mapITKCenteredSimilarity2DTransform.h
include/mapITKEuler2DTransform.h
include/mapITKEuler3DTransform.h
include/mapITKExhaustiveOptimizer.h
include/mapITKQuaternionRigidTransform.h
include/mapITKRigid2DTransform.h
include/mapITKRigid3DTransform.h
include/mapITKRigid3DPerspectiveTransform.h
include/mapITKScaleVersor3DTransform.h
include/mapITKSimilarity2DTransform.h
include/mapITKSimilarity3DTransform.h
include/mapITKVersorRigid3DTransform.h
include/mapITKVersorTransform.h
include/mapITKBSplineDeformableTransform.h
include/mapITKLinearInterpolateImageFunction.h
include/mapITKNearestNeighborInterpolateImageFunction.h
include/mapITKBSplineInterpolateImageFunction.h
include/mapITKComplexBSplineInterpolateImageFunction.h
include/mapITKWindowedSincInterpolateImageFunction.h
include/mapITKMVNLOptimizerControlInterface.h
include/mapITKPointSetToPointSetMetricControlBase.h
include/mapITKPointSetToPointSetMetricControlInterface.h
include/mapITKMVMetricControlInterface.h
include/mapITKPointSetToPointSetMetricSetterInterface.h
include/mapITKPointSetToPointSetMetricGetterInterface.h
include/mapITKMVNLOptimizerSetterInterface.h
include/mapITKMVNLOptimizerGetterInterface.h
include/mapITKMVNLOptimizerControlBase.h
include/mapArbitraryMVNLOptimizerPolicy.h
include/mapFixedMVNLOptimizerPolicy.h
include/mapArbitraryPointSetToPointSetMetricPolicy.h
include/mapFixedPointSetToPointSetMetricPolicy.h   
include/mapSealedPointSetToPointSetMetricPolicy.h
include/mapITKEuclideanDistancePointMetric.h
include/mapITKEuclideanPairDistancePointMetric.h
include/mapITKLevenbergMarquardtOptimizer.h
include/mapITKMultiResImageRegistrationAlgorithm.h
include/mapITKClosedFormRegistrationAlgorithm.h
include/mapITKLandmarkKernelRegistrationAlgorithm.h
include/mapITKPointSetRegistrationAlgorithm.h
include/mapITKPDEDeformableRegistrationAlgorithmBase.h
include/mapITKPDEDeformableRegistrationAlgorithm.h
include/mapITKMultiResPDEDeformableRegistrationAlgorithm.h
boxed/mapITKDemonsRegistrationAlgorithm.h
boxed/mapITKEuler3DICPRegistrationAlgorithmTemplate.h
boxed/mapITKEuler3DMattesMIMultiResRegistrationAlgorithmTemplate.h
boxed/mapITKEuler3DMattesMIRegistrationAlgorithmTemplate.h
boxed/mapITKEuler3DMSRegistrationAlgorithmTemplate.h
boxed/mapITKInitializedMultiResImageRegistrationAlgorithm.h
boxed/mapITKRigid2DClosedFormRegistrationAlgorithmTemplate.h
boxed/mapITKRigid2DICPRegistrationAlgorithmTemplate.h
boxed/mapITKRigid2DMattesMIRegistrationAlgorithmTemplate.h
boxed/mapITKRigid3DClosedFormRegistrationAlgorithmTemplate.h
boxed/mapTransMSRegistrationAlgorithmTemplate.h
boxed/mapTransMattesMIRegistrationAlgorithmTemplate.h
boxed/mapITKTransMattesMIMultiResRegistrationAlgorithmTemplate.h
boxed/mapITKFastSymmetricForcesDemonsRegistrationAlgorithm.h
boxed/mapITKPDEDemonsRegistrationAlgorithm.h
boxed/mapITKLevelSetMotionRegistrationAlgorithm.h
boxed/mapITKSymmetricForcesDemonsRegistrationAlgorithm.h
boxed/mapITKLevelSetMotionMultiResRegistrationAlgorithm.h
boxed/mapITKFastSymmetricForcesDemonsMultiResRegistrationAlgorithm.h
)

SET(TPP_FILES
include/mapITKImageRegistrationAlgorithm.tpp
include/mapITKImageRegistrationAlgorithmInterface.tpp
include/mapITKSVNLOptimizerControlBase.tpp
include/mapITKMVNLOptimizerControlBase.tpp
include/mapArbitraryInterpolatorPolicy.tpp
include/mapArbitraryImageToImageMetricPolicy.tpp
include/mapArbitraryTransformPolicy.tpp
include/mapFixedInterpolatorPolicy.tpp
include/mapFixedImageToImageMetricPolicy.tpp
include/mapFixedSVNLOptimizerPolicy.tpp
include/mapFixedTransformPolicy.tpp
include/mapITKImageToImageMetricControlBase.tpp
include/mapSealedInterpolatorPolicy.tpp
include/mapSealedOptimizerPolicy.tpp
include/mapSealedImageToImageMetricPolicy.tpp
include/mapSealedTransformPolicy.tpp
include/mapITKBSplineDeformableTransform.tpp
include/mapITKPointSetToPointSetMetricControlBase.tpp
include/mapFixedMVNLOptimizerPolicy.tpp  
include/mapArbitraryPointSetToPointSetMetricPolicy.tpp
include/mapFixedPointSetToPointSetMetricPolicy.tpp
include/mapSealedPointSetToPointSetMetricPolicy.tpp
include/mapITKPointSetRegistrationAlgorithm.tpp
include/mapITKPointSetRegistrationAlgorithmInterface.tpp
include/mapITKMultiResImageRegistrationAlgorithm.tpp  
include/mapITKClosedFormRegistrationAlgorithm.tpp
include/mapITKLandmarkKernelRegistrationAlgorithm.tpp
include/mapITKPointSetRegistrationAlgorithm.tpp
include/mapITKPDEDeformableRegistrationAlgorithmBase.tpp
include/mapITKPDEDeformableRegistrationAlgorithm.tpp
include/mapITKMultiResPDEDeformableRegistrationAlgorithm.tpp
boxed/mapITKDemonsRegistrationAlgorithm.tpp
boxed/mapITKEuler3DMattesMIMultiResRegistrationAlgorithmTemplate.tpp
boxed/mapITKEuler3DMattesMIRegistrationAlgorithmTemplate.tpp
boxed/mapITKEuler3DMSRegistrationAlgorithmTemplate.tpp
boxed/mapITKTransMattesMIMultiResRegistrationAlgorithmTemplate.tpp
boxed/mapITKInitializedMultiResImageRegistrationAlgorithm.tpp
boxed/mapITKRigid2DMattesMIRegistrationAlgorithmTemplate.tpp
boxed/mapITKFastSymmetricForcesDemonsRegistrationAlgorithm.tpp
boxed/mapITKPDEDemonsRegistrationAlgorithm.tpp
boxed/mapITKLevelSetMotionRegistrationAlgorithm.tpp
boxed/mapITKSymmetricForcesDemonsRegistrationAlgorithm.tpp
boxed/mapITKLevelSetMotionMultiResRegistrationAlgorithm.tpp
boxed/mapITKFastSymmetricForcesDemonsMultiResRegistrationAlgorithm.tpp
)

SET(TEST_CPP_FILES
test/mapAlgorithmsITKTests.cpp
test/mapITKOptimizerControlInterfaceTest.cpp
test/mapITKOptimizerControlTest.cpp
test/mapFixedSVNLOptimizerPolicyTest.cpp
test/mapArbitrarySVNLOptimizerPolicyTest.cpp
test/mapFixedInterpolatorPolicyTest.cpp
test/mapArbitraryInterpolatorPolicyTest.cpp
test/mapFixedImageToImageMetricPolicyTest.cpp
test/mapArbitraryImageToImageMetricPolicyTest.cpp
test/mapFixedTransformPolicyTest.cpp
test/mapArbitraryTransformPolicyTest.cpp
test/mapITKImageRegistrationAlgorithmTest.cpp
test/mapFixedITKImageRegistrationAlgorithmTest.cpp
test/mapITKTransformTestHelper.h
test/mapITKAffineTransformTest.cpp
test/mapITKCenteredRigid2DTransformTest.cpp
test/mapArbitraryMVNLOptimizerPolicyTest.cpp
test/mapFixedMVNLOptimizerPolicyTest.cpp
test/mapArbitraryPointSetToPointSetMetricPolicyTest.cpp
test/mapFixedPointSetToPointSetMetricPolicyTest.cpp
test/mapITKPointSetRegistrationAlgorithmTest.cpp
test/mapITKRigid2DICPRegistrationAlgorithmTemplateTest.cpp
test/mapITKEuler3DICPRegistrationAlgorithmTemplateTest.cpp
test/mapITKRigid2DClosedFormRegistrationAlgorithmTemplateTest.cpp
test/mapITKRigid3DClosedFormRegistrationAlgorithmTemplateTest.cpp
test/mapITKLandmarkKernelRegistrationAlgorithmTest.cpp
test/mapITKEuler3DMattesMIRegistrationAlgorithmTemplateTest.cpp
)