SET(CPP_FILES 
 source/mapElxAlgorithmHelper.cpp
)

SET(H_FILES 
include/mapElxCLIRegistrationAlgorithmBase.h
include/mapElxParameterFileRegistrationAlgorithm.h
include/mapElxAlgorithmHelper.h
boxed/mapElxBSplineCLIRegistrationAlgorithm.h
)

SET(TPP_FILES
include/mapElxCLIRegistrationAlgorithmBase.tpp
include/mapElxParameterFileRegistrationAlgorithm.tpp
boxed/mapElxBSplineCLIRegistrationAlgorithm.tpp
)

SET(TEST_CPP_FILES
test/mapAlgorithmsElastixTests.cpp
test/mapElxParameterFileRegistrationAlgorithmTest.cpp
)