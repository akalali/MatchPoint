SET(ALGORITHM_PROFILE_UID_Namespace "de.dkfz.matchpoint.common")
SET(ALGORITHM_PROFILE_UID_Name "Euler3DMattesMIMultiResAlgorithm.3D.default")
SET(ALGORITHM_PROFILE_UID_Version "1.1.0")

SET(ALGORITHM_PROFILE_Description "Simple 3D rigid (translation and euler angles) registration algorithm using mutual information as metric and a 3 level multi resolution approach.")
SET(ALGORITHM_PROFILE_Contact "Ralf Floca\; sbr@dkfz-heidelberg.de")

SET(ALGORITHM_PROFILE_DataType "Image")
SET(ALGORITHM_PROFILE_ResolutionStyle "3 (multi res)")
SET(ALGORITHM_PROFILE_DimMoving "3")
SET(ALGORITHM_PROFILE_ModalityMoving "any")
SET(ALGORITHM_PROFILE_DimTarget "3")
SET(ALGORITHM_PROFILE_ModalityTarget "any")
SET(ALGORITHM_PROFILE_Subject "any")
SET(ALGORITHM_PROFILE_Object "any")
SET(ALGORITHM_PROFILE_TransformModel "rigid")
SET(ALGORITHM_PROFILE_Metric "Mattes mutual information")
SET(ALGORITHM_PROFILE_TransformDomain "global")
SET(ALGORITHM_PROFILE_Optimization "Regular Step Gradient Descent")
SET(ALGORITHM_PROFILE_Keywords "basic" "pre initialization")
