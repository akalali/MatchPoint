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
// Subversion HeadURL: $HeadURL: http://sidt-hpc1/dkfz_repository/NotMeVisLab/SIDT/MatchPoint/trunk/Code/Algorithms/ITK/include/mapITKVersorTransformOptimizer.h $
*/




#ifndef __ITK_VERSOR_TRANSFORM_OPTIMIZER_H
#define __ITK_VERSOR_TRANSFORM_OPTIMIZER_H

#include "mapITKOptimizerControl.h"
#include "mapITKSVNLOptimizerControlBase.h"
#include "itkVersorTransformOptimizer.h"

namespace map
{
	namespace algorithm
	{
		namespace itk
		{

			/*!
			This class is the template specialization for the itk::VersorTransformOptimizer.
			@ingroup ITK
			@ingroup OptimizerControl
			*/
			template<>
			class ITKOptimizerControl< ::itk::VersorTransformOptimizer> : public ITKSVNLOptimizerControlBase< ::itk::VersorTransformOptimizer>
			{
			public:
				typedef ITKOptimizerControl< ::itk::VersorTransformOptimizer> Self;
				typedef ITKSVNLOptimizerControlBase< ::itk::VersorTransformOptimizer> Superclass;
				typedef ::itk::SmartPointer<Self>         Pointer;
				typedef ::itk::SmartPointer<const Self>   ConstPointer;

				itkTypeMacro(ITKOptimizerControl, ITKSVNLOptimizerControlBase);
				itkNewMacro(Self);

				typedef Superclass::ConcreteOptimizerType ConcreteOptimizerType;
				typedef ConcreteOptimizerType::Pointer ConcreteOptimizerPointer;

			protected:
				virtual ~ITKOptimizerControl() {};
				ITKOptimizerControl() {};

			private:
				//No copy constructor allowed
				ITKOptimizerControl(const Self &source);
				void operator=(const Self &); //purposely not implemented

			public:
				virtual bool isStoppable() const
				{
					return true;
				};

				virtual bool hasIterationCount() const
				{
					return true;
				};

				virtual bool hasMaxIterationCount() const
				{
					return true;
				};

				virtual bool canMinimize() const
				{
					return true;
				};

				virtual bool canMaximize() const
				{
					return true;
				};

				virtual bool getMinimize() const
				{
					return _spOptimizer->GetMinimize();
				};

				virtual bool getMaximize() const
				{
					return _spOptimizer->GetMaximize();
				};

				virtual void setMinimize(bool minimize)
				{
					_spOptimizer->SetMinimize(minimize);
				};

				virtual void setMaximize(bool maximize)
				{
					_spOptimizer->SetMaximize(maximize);
				};

				virtual bool hasCurrentValue() const
				{
					return true;
				};

			protected:

				virtual bool doStop()
				{
					_spOptimizer->StopOptimization();
					return true;
				};

				virtual IterationCountType doGetCurrentIteration() const
				{
					return _spOptimizer->GetCurrentIteration();
				};

				virtual IterationCountType doGetMaxIterations() const
				{
					return _spOptimizer->GetNumberOfIterations();
				};

				virtual SVNLMeasureType doGetCurrentMeasure() const
				{
					return _spOptimizer->GetValue();
				};

				virtual void copyProperties(const ConcreteOptimizerType *source, ConcreteOptimizerType *destination) const
				{
					Superclass::copyProperties(source, destination);

					destination->SetMaximize(source->GetMaximize());
					destination->SetMaximumStepLength(source->GetMaximumStepLength());
					destination->SetMinimumStepLength(source->GetMinimumStepLength());
					destination->SetRelaxationFactor(source->GetRelaxationFactor());
					destination->SetNumberOfIterations(source->GetNumberOfIterations());
					destination->SetGradientMagnitudeTolerance(source->GetGradientMagnitudeTolerance());
				};

				virtual Superclass::Pointer doCloneControl() const
				{
					Pointer spClone = Self::New();
					Superclass::Pointer spResult = spClone.GetPointer();
					return spResult;
				};
			};

			typedef ITKOptimizerControl< ::itk::VersorTransformOptimizer> VersorTransformOptimizerControl;

		}
	}
}

#endif
