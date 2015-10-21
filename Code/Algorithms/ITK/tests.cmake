SET(TEST_DATA_ROOT ${MatchPointTesting_SOURCE_DIR}/Data)
SET(TEMP ${MatchPointTesting_BINARY_DIR}/Temporary)

#-----------------------------------------------------------------------------
ADD_TEST(mapArbitraryImageToImageMetricPolicyTest ${MODULE_TESTS} mapArbitraryImageToImageMetricPolicyTest)
ADD_TEST(mapArbitraryInterpolatorPolicyTest ${MODULE_TESTS} mapArbitraryInterpolatorPolicyTest)
ADD_TEST(mapArbitraryMVNLOptimizerPolicyTest ${MODULE_TESTS} mapArbitraryMVNLOptimizerPolicyTest)
ADD_TEST(mapArbitraryPointSetToPointSetMetricPolicyTest ${MODULE_TESTS} mapArbitraryPointSetToPointSetMetricPolicyTest)
ADD_TEST(mapArbitrarySVNLOptimizerPolicyTest ${MODULE_TESTS} mapArbitrarySVNLOptimizerPolicyTest)
ADD_TEST(mapArbitraryTransformPolicyTest ${MODULE_TESTS} mapArbitraryTransformPolicyTest)
ADD_TEST(mapFixedImageToImageMetricPolicyTest ${MODULE_TESTS} mapFixedImageToImageMetricPolicyTest)
ADD_TEST(mapFixedInterpolatorPolicyTest ${MODULE_TESTS} mapFixedInterpolatorPolicyTest)
ADD_TEST(mapFixedITKImageRegistrationAlgorithmTest ${MODULE_TESTS} mapFixedITKImageRegistrationAlgorithmTest "${TEST_DATA_ROOT}/Algorithms/BrainProtonDensitySliceShifted13x17y.png" "${TEST_DATA_ROOT}/Algorithms/BrainProtonDensitySliceBorder20.png")
ADD_TEST(mapFixedMVNLOptimizerPolicyTest ${MODULE_TESTS} mapFixedMVNLOptimizerPolicyTest)
ADD_TEST(mapFixedPointSetToPointSetMetricPolicyTest ${MODULE_TESTS} mapFixedPointSetToPointSetMetricPolicyTest)
ADD_TEST(mapFixedSVNLOptimizerPolicyTest ${MODULE_TESTS} mapFixedSVNLOptimizerPolicyTest)
ADD_TEST(mapFixedTransformPolicyTest ${MODULE_TESTS} mapFixedTransformPolicyTest)
ADD_TEST(mapITKEuler3DICPRegistrationAlgorithmTemplateTest ${MODULE_TESTS} mapITKEuler3DICPRegistrationAlgorithmTemplateTest "${TEST_DATA_ROOT}/Algorithms/Landmarks_3D_Shifted13x17y5z.txt" "${TEST_DATA_ROOT}/Algorithms/Landmarks_3D.txt")
ADD_TEST(mapITKImageRegistrationAlgorithmTest ${MODULE_TESTS} mapITKImageRegistrationAlgorithmTest "${TEST_DATA_ROOT}/Algorithms/BrainProtonDensitySliceShifted13x17y.png" "${TEST_DATA_ROOT}/Algorithms/BrainProtonDensitySliceBorder20.png")
ADD_TEST(mapITKLandmarkKernelRegistrationAlgorithmTest ${MODULE_TESTS} mapITKLandmarkKernelRegistrationAlgorithmTest "${TEST_DATA_ROOT}/Algorithms/Landmarks_3D_Shifted13x17y5z.txt" "${TEST_DATA_ROOT}/Algorithms/Landmarks_3D.txt")
ADD_TEST(mapITKOptimizerControlInterfaceTest ${MODULE_TESTS} mapITKOptimizerControlInterfaceTest)
ADD_TEST(mapITKOptimizerControlTest ${MODULE_TESTS} mapITKOptimizerControlTest)
ADD_TEST(mapITKPointSetRegistrationAlgorithmTest ${MODULE_TESTS} mapITKPointSetRegistrationAlgorithmTest "${TEST_DATA_ROOT}/Algorithms/Landmarks_BrainProtonDensitySliceShifted13x17y.txt" "${TEST_DATA_ROOT}/Algorithms/Landmarks_BrainProtonDensitySliceBorder20.txt")
ADD_TEST(mapITKRigid2DClosedFormRegistrationAlgorithmTemplateTest ${MODULE_TESTS} mapITKRigid2DClosedFormRegistrationAlgorithmTemplateTest "${TEST_DATA_ROOT}/Algorithms/Landmarks_BrainProtonDensitySliceShifted13x17y.txt" "${TEST_DATA_ROOT}/Algorithms/Landmarks_BrainProtonDensitySliceBorder20.txt")
ADD_TEST(mapITKRigid2DICPRegistrationAlgorithmTemplateTest ${MODULE_TESTS} mapITKRigid2DICPRegistrationAlgorithmTemplateTest "${TEST_DATA_ROOT}/Algorithms/Landmarks_BrainProtonDensitySliceShifted13x17y.txt" "${TEST_DATA_ROOT}/Algorithms/Landmarks_BrainProtonDensitySliceBorder20.txt")
ADD_TEST(mapITKRigid3DClosedFormRegistrationAlgorithmTemplateTest ${MODULE_TESTS} mapITKRigid3DClosedFormRegistrationAlgorithmTemplateTest "${TEST_DATA_ROOT}/Algorithms/Landmarks_3D_Shifted13x17y5z.txt" "${TEST_DATA_ROOT}/Algorithms/Landmarks_3D.txt")
ADD_TEST(mapITKEuler3DMattesMIRegistrationAlgorithmTemplateTest ${MODULE_TESTS} mapITKEuler3DMattesMIRegistrationAlgorithmTemplateTest "${TEST_DATA_ROOT}/Algorithms/MatchPointLogo.mhd" "${TEST_DATA_ROOT}/Algorithms/MatchPointLogoShifted10x-16y-5z.mhd")
ADD_TEST(mapITKTransMattesMIMultiResRegistrationAlgorithmTest ${MODULE_TESTS} mapITKTransMattesMIMultiResRegistrationAlgorithmTest "${TEST_DATA_ROOT}/Algorithms/MatchPointLogo.mhd" "${TEST_DATA_ROOT}/Algorithms/MatchPointLogoShifted10x-16y-5z.mhd")
