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




#ifndef __MAP_SIMPLE_INFORMATION_ENTITY_H
#define __MAP_SIMPLE_INFORMATION_ENTITY_H

#include <memory>
#include "mapDataRepresentation.h"
#include "mapInformationEntityTraits.h"
#include "mapOntologyString.h"

#include "mapMAPOntologySimpleExports.h"

namespace iro
{
  namespace scenario
  {

    /*! @class SimpleInformationEntity
     * @brief Simple specific implementation of an InformationEntity
     * Uses a string type to store the UID.
     * @ingroup Simple*/
    class MAPOntologySimple_EXPORT SimpleInformationEntity
    {
    public:
      using Self = SimpleInformationEntity;
      using UIDType = ::iro::String;
      using DataRepresentationType = DataRepresentation::Type;

      using Pointer = std::shared_ptr<Self>;
      using ConstPointer = std::shared_ptr<const Self>;

       /*! returns the UID of the statement.*/
      const UIDType& getUID() const;
      void setUID(const UIDType& uid);

      const DataRepresentationType& getDataRepresentation() const;
      void setDataRepresentation(const DataRepresentationType& rep);

      virtual ~SimpleInformationEntity();
      SimpleInformationEntity();

      bool operator == (const Self& is) const;

      /** Clones the content of the information entity and returns it as
      * non const pointer. It can be used to alter the entity and
      * update the knowledge base of the ontology.
      */
      Pointer clone() const;

    protected:
      UIDType _uid;
      DataRepresentationType _dataRep{DataRepresentation::Discrete};

    private:
      SimpleInformationEntity(const Self&) = delete; //not implemented by purpose
      Self& operator=(const Self&) = delete; //not implemented by purpose
    };

    /*! @struct SimpleEntityIdentificationPolicy
    * @brief Policy used in the information entity traits to check if the passed entity has a given UID.
    * @ingroup Simple
    */
    struct SimpleEntityIdentificationPolicy
    {
      using UIDType = ::iro::scenario::SimpleInformationEntity::UIDType;
      static bool identifyEntity(const ::iro::scenario::SimpleInformationEntity& pEntity, const UIDType& uid)
      {
        return pEntity.getUID() == uid;
      };
    };

    using SimpleInformationEntityTraits = InformationEntityTraits<::iro::scenario::SimpleInformationEntity, SimpleEntityIdentificationPolicy>;

  } // end namespace scenario

} // end namespace iro

#endif
