// -----------------------------------------------------------------------
// MatchPoint - DKFZ translational registration framework
//
// Copyright c German Cancer Research Center DKFZ,
// Software development for Integrated Diagnostics and Therapy SIDT.
// ALL RIGHTS RESERVED.
// See mapCopyright.txt or
// http://www.dkfz.de/en/sidt/projects/MatchPoint/copyright.html
//
// This software is distributed WITHOUT ANY WARRANTY; without even
// the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
// PURPOSE.  See the above copyright notices for more information.
//
//------------------------------------------------------------------------




#ifndef __MAP_REGISTRATION_INFO_H
#define __MAP_REGISTRATION_INFO_H

#include "mapIInformationSpaceConnector.h"
#include "mapIProblemStatementAssociated.h"

#include <memory>
#include <list>

namespace iro
{

		/** Class that specifies a way to map information from one information space to an other.
     * It may contain, if available, the transformation info for discrete data
     * (e.g. pixel images; inverse mapping; getDiscreteTransformation)
     * and continuous data (e.g. point sets; direct mapping, getContinousTransformation).
     * @remark The transformation infos in this class always have the same moving and target
     * information space as well as the same problem statement association.
     * @tparam TInformationSpaceTraits The traits of the information space used with the registration info.
     * @tparam TProblemStatementTraits The traits of the problem statement used with the registration info.
     * @tparam TTransformationInfoTraits The traits of the transformation info used with the registration info.*/
    template <typename TInformationSpaceTraits, typename TProblemStatementTraits, typename TTransformationInfoTraits>
    class RegistrationInfo: public IInformationSpaceConnector<TInformationSpaceTraits>, public IProblemStatementAssociated<TProblemStatementTraits>
		{
    public:
      typedef RegistrationInfo<TInformationSpaceTraits, TProblemStatementTraits, TTransformationInfoTraits> Self;
      using Pointer = ::std::shared_ptr<Self>;
      using ConstPointer = ::std::shared_ptr<const Self>;

      using ConnectorInterface = IInformationSpaceConnector<TInformationSpaceTraits>;
      using ConstISPointer = typename ConnectorInterface::ConstISPointer;

      using ProblemAssociatedInterface = IProblemStatementAssociated<TProblemStatementTraits>;
      using ProblemComplianceInterface = typename ProblemAssociatedInterface::ProblemComplianceInterface;
      using ConstProblemPointer = typename ProblemAssociatedInterface::ConstProblemPointer;

      using ConstTransformationInfoPointer = typename TTransformationInfoTraits::ConstPointer;
      using TransformationInfoPointer = typename TTransformationInfoTraits::Pointer;
      using TransformationInfoType = typename TTransformationInfoTraits::Type;

      /*! Implementation of abstract member. See documentation in interface.
      * @see IInformationSpaceConnector*/
      ConstISPointer getMovingIS() const override;

      /*! Implementation of abstract member. See documentation in interface.
      * @see IInformationSpaceConnector*/
      ConstISPointer getTargetIS() const override;

      /** Returns the const pointer to the associated problem statement.
      * Pointer may be null, if no statement is defined.*/
      ConstProblemPointer getAssociatedProblemStatement() const override;

      /*! Returns the transformation for continuous data types.
       * If no transformation is defined for the data type, NULL will be returned.*/
      ConstTransformationInfoPointer getContinuousTransformation() const;

      /*! Returns the transformation for discrete data types.
       * If no transformation is defined for the data type, NULL will be returned.*/
      ConstTransformationInfoPointer getDiscreteTransformation() const;

      /*! Sets the transformation info of the registration info instance for discrete and continuous data types.
       * @remark You may set a NULL pointer if one data representation has no transformation.
       * @pre Both transformations must have the same moving and target information space and must be
       * associated with the same problem statement.
       * @pre The continous transformation info must have a continuous data representation.
       * @pre The discrete transformation info must have a discrete data representation.
       * @param [in] continuous Pointer to the transformation info for continuous data types.
       * @param [in] discrete Pointer to the transformation info for discrete data types.
       * @exception ::iro::exceptions::InvalidArgument: one of the preconditions is violated.*/
      void setTransformations(ConstTransformationInfoPointer continuous, ConstTransformationInfoPointer discrete);

      /* Clones the content of the RegistrationInfo and returns it as
      * non const pointer. It can be used to alter the info and
      * update the knowledge base of the ontology.
      */
      Pointer clone() const;

			~RegistrationInfo() override;
			RegistrationInfo();

    protected:
      /*! Implementation of abstract member. This implementation checks the associated
      * problem statement for compliance. See also documentation in interface.
      * @see IProblemComplianceChecker*/
			bool doCheckProblemCompliance(const ProblemComplianceInterface* pProblemCompliance) const override;

      ConstTransformationInfoPointer _continuous;
      ConstTransformationInfoPointer _discrete;
      ConstISPointer _movingIS;
      ConstISPointer _targetIS;
      ConstProblemPointer _associatedProblem;

    private:
			RegistrationInfo(const Self&); //not implemented by purpose
			Self& operator=(const Self&); //not implemented by purpose
		};
} // end namespace iro

#ifndef MatchPoint_MANUAL_TPP
#include "mapRegistrationInfo.tpp"
#endif

#endif
