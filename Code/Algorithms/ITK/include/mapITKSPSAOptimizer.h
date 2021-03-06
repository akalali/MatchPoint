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
// @version $Revision$ (last changed revision)
// @date    $Date$ (last change date)
// @author  $Author$ (last changed by)
// Subversion HeadURL: $HeadURL$
*/




#ifndef __ITK_SPSA_OPTIMIZER_H
#define __ITK_SPSA_OPTIMIZER_H

#include "mapITKOptimizerControl.h"
#include "mapITKSVNLOptimizerControlBase.h"
#include "itkSPSAOptimizer.h"

namespace map
{
	namespace algorithm
	{
		namespace itk
		{

			/*!
			This class is the template specialization for the itk::SPSAOptimizer.
			@ingroup ITK
			@ingroup OptimizerControl
			*/
			template<>
			class ITKOptimizerControl< ::itk::SPSAOptimizer> : public
				ITKSVNLOptimizerControlBase< ::itk::SPSAOptimizer>
			{
			public:
				typedef ITKOptimizerControl< ::itk::SPSAOptimizer> Self;
				typedef ITKSVNLOptimizerControlBase< ::itk::SPSAOptimizer> Superclass;
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
				ITKOptimizerControl(const Self& source);
				void operator=(const Self&);  //purposely not implemented

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
					return _spOptimizer->GetMaximumNumberOfIterations();
				};

				virtual SVNLMeasureType doGetCurrentMeasure() const
				{
					/*! @remark The SPSA does not calculate the exact curent value while optimizing. Thus calling this function will cost one
					 * extra metric evaluation!*/
					return _spOptimizer->GetValue();
				};

				virtual void copyProperties(const ConcreteOptimizerType* source,
											ConcreteOptimizerType* destination) const
				{
					Superclass::copyProperties(source, destination);

					destination->SetSa(source->GetSa());
					destination->SetSc(source->GetSc());
					destination->SetA(source->GetA());
					destination->SetAlpha(source->GetAlpha());
					destination->SetGamma(source->GetGamma());
					destination->SetMaximize(source->GetMaximize());
					destination->SetNumberOfPerturbations(source->GetNumberOfPerturbations());
					destination->SetStateOfConvergenceDecayRate(source->GetStateOfConvergenceDecayRate());
					destination->SetMinimumNumberOfIterations(source->GetMinimumNumberOfIterations());
					destination->SetMaximumNumberOfIterations(source->GetMaximumNumberOfIterations());
					destination->SetTolerance(source->GetTolerance());
				};

				virtual Superclass::Pointer doCloneControl() const
				{
					Pointer spClone = Self::New();
					Superclass::Pointer spResult = spClone.GetPointer();
					return spResult;
				};
			};

			typedef ITKOptimizerControl< ::itk::SPSAOptimizer> SPSAOptimizerControl;

		}
	}
}

#endif
