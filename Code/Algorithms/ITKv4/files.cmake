SET(CPP_FILES 
source/mapArbitraryObjectToObjectOptimizerPolicy.cpp
source/mapITKObjectToObjectMetricControlInterface.cpp
source/mapITKObjectToObjectOptimizerControlInterface.cpp
)

SET(H_FILES 
include/mapArbitraryObjectToObjectMetricPolicy.h
include/mapArbitraryObjectToObjectOptimizerPolicy.h
include/mapFixedObjectToObjectMetricPolicy.h
include/mapFixedObjectToObjectOptimizerPolicy.h
include/mapITKImageRegistrationV4Algorithm.h
include/mapITKImageRegistrationV4AlgorithmInterface.h
include/mapITKObjectToObjectMetricControlBase.h
include/mapITKObjectToObjectMetricControlInterface.h
include/mapITKObjectToObjectMetricGetterInterface.h
include/mapITKObjectToObjectMetricSetterInterface.h
include/mapITKObjectToObjectOptimizerControlBase.h
include/mapITKObjectToObjectOptimizerControlInterface.h
include/mapITKObjectToObjectOptimizerGetterInterface.h
include/mapITKObjectToObjectOptimizerSetterInterface.h
include/mapSealedObjectToObjectMetricPolicy.h
include/mapSealedObjectToObjectOptimizerPolicy.h
)

SET(TPP_FILES
include/mapArbitraryObjectToObjectMetricPolicy.tpp
include/mapFixedObjectToObjectMetricPolicy.tpp
include/mapFixedObjectToObjectOptimizerPolicy.tpp
include/mapITKImageRegistrationV4Algorithm.tpp
include/mapITKImageRegistrationV4AlgorithmInterface.tpp
include/mapITKObjectToObjectMetricControlBase.tpp
include/mapITKObjectToObjectOptimizerControlBase.tpp
include/mapSealedObjectToObjectMetricPolicy.tpp
include/mapSealedObjectToObjectOptimizerPolicy.tpp
)

SET(TEST_CPP_FILES
)