SET(CPP_FILES 
)

SET(H_FILES 
include/mapArbitraryWarpImageFilter.h
include/mapEuclideanPairDistancePointMetric.h
include/mapIterativeInverseTransformToDisplacementFieldSource.h
include/mapNULLVectorAwareLinearInterpolateImageFunction.h
)

SET(TPP_FILES
include/mapArbitraryWarpImageFilter.txx
include/mapEuclideanPairDistancePointMetric.txx
include/mapIterativeInverseTransformToDisplacementFieldSource.txx
include/mapNULLVectorAwareLinearInterpolateImageFunction.tpp
)

SET(TEST_CPP_FILES
test/mapIterativeInverseTransformToDisplacementFieldSourceTest.cpp
test/mapITKTests.cpp
)