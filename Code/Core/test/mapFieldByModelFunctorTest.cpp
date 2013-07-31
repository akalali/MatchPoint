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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Core/test/mapFieldByModelFunctorTest.cpp $
*/

#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif

#include "mapFieldByModelFunctor.h"
#include "litCheckMacros.h"
#include "litTransformFieldTester.h"

#include "mapITKScaleTransform.h"

#include "itkImageRegionIterator.h"

namespace map
{
	namespace testing
	{

		int mapFieldByModelFunctorTest(int, char* [])
		{
			PREPARE_DEFAULT_TEST_REPORTING;

			typedef core::functors::FieldByModelFunctor<3, 3> FunctorType;


			//Model kernel generation
			typedef algorithm::itk::ITKTransformModel< itk::ScaleTransform<core::continuous::ScalarType, 3> > ScaleTransformType;

			FunctorType::TransformModelType::Pointer spModel = ScaleTransformType::New().GetPointer();

			FunctorType::InFieldRepresentationType::SpacingType spacing(0.5);
			FunctorType::InFieldRepresentationType::PointType origin;
			origin.Fill(0);
			FunctorType::InFieldRepresentationType::SizeType size;
			size.fill(2);
			FunctorType::TransformModelType::ParametersType params(3);
			params.fill(2.0);
			spModel->getTransform()->SetParameters(params);

			FunctorType::InFieldRepresentationType::Pointer spInRep = FunctorType::InFieldRepresentationType::New();
			spInRep->setSize(size);
			spInRep->setSpacing(spacing);
			spInRep->setOrigin(origin);

			FunctorType::Pointer spFunc = FunctorType::New(*spModel, spInRep);


			CHECK(spFunc.IsNotNull());

			CHECK(spModel == spFunc->getTransformModel());

			FunctorType::Pointer spFuncAnother = dynamic_cast<FunctorType *>(spFunc->CreateAnother().GetPointer());
			CHECK(spFuncAnother->getTransformModel() == spFunc->getTransformModel());
			CHECK(spFuncAnother->getInFieldRepresentation() == spFunc->getInFieldRepresentation());
			CHECK(spFuncAnother->GetNameOfClass() == spFunc->GetNameOfClass());

			// test generateField

			FunctorType::FieldPointer spField = NULL;
			CHECK_NO_THROW(spField = spFunc->generateField());
			CHECK(spField.IsNotNull());

			lit::TransformFieldTester<FunctorType::FieldType, FunctorType::TransformModelType::TransformBaseType> tester;
			tester.setReferenceTransform(spModel->getTransform());
			tester.setActualField(spField);
			tester.setCheckThreshold(0.0);

			CHECK_TESTER(tester);

			RETURN_AND_REPORT_TEST_SUCCESS;
		}
	} //namespace testing
} //namespace map
