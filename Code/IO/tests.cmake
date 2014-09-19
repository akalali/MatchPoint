SET(TEST_DATA_ROOT ${MatchPointTesting_SOURCE_DIR}/Data)

SET(TEMP ${MatchPointTesting_BINARY_DIR}/Temporary)
SET(EXAMPLES_DATA_ROOT "${MatchPoint_SOURCE_DIR}/Examples/Data")

#-----------------------------------------------------------------------------
IF(NOT UNIX)
	ADD_TEST(mapMatrixModelBasedKernelWriterTest ${MODULE_TESTS} mapMatrixModelBasedKernelWriterTest)
ENDIF(NOT UNIX)
ADD_TEST(mapMatrixModelBasedKernelLoaderTest ${MODULE_TESTS} mapMatrixModelBasedKernelLoaderTest)
IF(NOT UNIX)
ADD_TEST(mapRegistrationFileWriterTest ${MODULE_TESTS} mapRegistrationFileWriterTest "${TEMP}" "${TEST_DATA_ROOT}/Core")
ENDIF(NOT UNIX)
ADD_TEST(mapRegistrationFileReaderTest ${MODULE_TESTS} mapRegistrationFileReaderTest "${TEST_DATA_ROOT}/Core")
ADD_TEST(mapNullRegistrationKernelWriterTest ${MODULE_TESTS} mapNullRegistrationKernelWriterTest)
ADD_TEST(mapExpandingFieldKernelWriterTest ${MODULE_TESTS} mapExpandingFieldKernelWriterTest "${TEMP}" "${TEST_DATA_ROOT}/Core")
ADD_TEST(mapExpandingFieldKernelLoaderTest ${MODULE_TESTS} mapExpandingFieldKernelLoaderTest "${TEMP}" "${TEST_DATA_ROOT}/Core")
ADD_TEST(mapInvertingFieldKernelWriterTest ${MODULE_TESTS} mapInvertingFieldKernelWriterTest "${TEMP}" "${TEST_DATA_ROOT}/Core")
ADD_TEST(mapInvertingFieldKernelLoaderTest ${MODULE_TESTS} mapInvertingFieldKernelLoaderTest "${TEMP}" "${TEST_DATA_ROOT}/Core")