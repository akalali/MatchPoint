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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Algorithms/ITK/include/mapITKElasticBodyReciprocalSplineKernelTransform.h $
*/




#ifndef __MAP_ITK_ElasticBodyReciprocalSplineKernel_TRANSFORM_H
#define __MAP_ITK_ElasticBodyReciprocalSplineKernel_TRANSFORM_H

#include "mapITKTransformModel.h"
#include "mapITKUnaryTransformModel.h"
#include "itkElasticBodyReciprocalSplineKernelTransform.h"

namespace map
{
	namespace algorithm
	{
		namespace itk
		{

			/*!
			This class is the template specialization for the itk::ElasticBodyReciprocalSplineKernelTransform.
			@ingroup ITK
			@ingroup ITKTransformModel
			*/
			template<class TScalarType, unsigned int TDimensions>
			class ITKTransformModel< ::itk::ElasticBodyReciprocalSplineKernelTransform<TScalarType, TDimensions> >:
				public map::core::ITKUnaryTransformModel< ::itk::ElasticBodyReciprocalSplineKernelTransform, TScalarType, TDimensions>
			{
			public:
				typedef ITKTransformModel< ::itk::ElasticBodyReciprocalSplineKernelTransform<TScalarType, TDimensions> >  Self;
				typedef map::core::ITKUnaryTransformModel< ::itk::ElasticBodyReciprocalSplineKernelTransform, TScalarType, TDimensions>  Superclass;
				typedef ::itk::SmartPointer<Self>        Pointer;
				typedef ::itk::SmartPointer<const Self>  ConstPointer;

				itkTypeMacro(ITKTransformModel, ITKUnaryTransformModel);
				itkNewMacro(Self);

				typedef typename Superclass::TransformModelBasePointer        TransformModelBasePointer;

				typedef typename Superclass::ScalarType                       ScalarType;
				typedef typename Superclass::MatrixType                       MatrixType;
				typedef typename Superclass::OutputVectorType                 OutputVectorType;

				typedef typename Superclass::InverseTransformModelBaseType    InverseTransformModelBaseType;
				typedef typename Superclass::InverseTransformModelBasePointer InverseTransformModelBasePointer;

				typedef typename Superclass::InverseTransformModelType        InverseTransformModelType;
				typedef typename Superclass::InverseTransformModelPointer     InverseTransformModelPointer;

				typedef typename Superclass::TransformBaseType                TransformBaseType;
				typedef typename Superclass::TransformBasePointer             TransformBasePointer;
				typedef typename Superclass::InverseTransformBaseType         InverseTransformBaseType;
				typedef typename Superclass::InverseTransformBasePointer      InverseTransformBasePointer;

				typedef typename Superclass::TransformType                    TransformType;
				typedef typename Superclass::TransformPointer                 TransformPointer;
				typedef typename Superclass::InverseTransformType             InverseTransformType;
				typedef typename Superclass::InverseTransformPointer          InverseTransformPointer;

				virtual bool getAffineMatrixDecomposition(MatrixType &matrix, OutputVectorType &offset) const
				{
					return false;
				};

			protected:

				virtual InverseTransformModelPointer createInverse() const
				{
					//cause translation is an unary transform model the inverse model is equivalent to the model.
					InverseTransformModelPointer spNew = New().GetPointer();
					return spNew;
				};

				virtual TransformModelBasePointer createAnotherInstance() const
				{
					TransformModelBasePointer spNew = New().GetPointer();
					return spNew;
				};

				ITKTransformModel() {};

				virtual ~ITKTransformModel() {};

			private:
				ITKTransformModel(const Self &); //purposely not implemented
				void operator=(const Self &); //purposely not implemented
			};

		}
	}
}

#endif
