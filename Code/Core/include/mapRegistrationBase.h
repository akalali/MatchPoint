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

#ifndef __REGISTRATION_BASE_H
#define __REGISTRATION_BASE_H

#include "itkObject.h"

#include "mapString.h"
#include "mapMacros.h"
#include "mapMAPCoreExports.h"

/*! @namespace map The namespace map::core is for the library of MatchPoint
*/
namespace map
{
	namespace core
	{

		/* forward declaration (see mapRegistrationManipulator.h)*/
		class RegistrationBaseManipulator;

		/*! @class RegistrationBase
		@brief Base class for registration. Does not have input and
		output dimensions.

		This class is the base class for the registration. Only
		Registration inherits from this.
		  @remark this class create an unique RegistrationID automatically and adds it to the tags.
		@ingroup Registration
		*/
		class MAPCore_EXPORT RegistrationBase: public itk::Object
		{
		public:
			using Self = RegistrationBase;
			using Superclass = itk::Object;
			using Pointer = itk::SmartPointer<Self>;
			using ConstPointer = itk::SmartPointer<const Self>;

			itkTypeMacro(RegistrationBase, itk::Object);


			/*! @brief Gets the number of moving dimensions
			@eguarantee no fail
			*/
			virtual unsigned int getMovingDimensions() const = 0;

			/*! @brief Gets the number of target dimensions
			@eguarantee no fail
			*/
			virtual unsigned int getTargetDimensions() const = 0;

			/*! typedefs used for the TagMap
			*/
			using TagType = String;
			using ValueType = String;
			typedef std::map<TagType, ValueType> TagMapType;

			/*!
			@eguarantee no fail
			@return is the target representation limited
			@retval true if target representation is limited. Thus it is not(!) guaranteed that all inverse mapping operations
			will succeed. Transformation(inverse kernel) covers only a part of the target space.
			@retval false if target representation is not limited. Thus it is guaranteed that all inverse mapping operations will succeed.
			*/
			virtual bool hasLimitedTargetRepresentation() const = 0;

			/*!
			@eguarantee no fail
			@return is the moving representation limited
			@retval true if moving representation is limited. Thus it is not(!) guaranteed that all direct mapping operations
			will succeed. Transformation(direct kernel) covers only a part of the moving space.
			@retval false if moving representation is not limited. Thus it is guaranteed that all direct mapping operations will succeed.
			*/
			virtual bool hasLimitedMovingRepresentation() const = 0;

			/*! @brief returns the tags associated with this registration
			@eguarantee no fail
			@return a TagMapType containing tags
			*/
			const TagMapType& getTags() const;

			/*! @brief returns the tag value for a specific tag
			@eguarantee strong
			@return the success of the operation
			*/
			bool getTagValue(const TagType& tag, ValueType& value) const;

			/*! @brief convinience function that retrieves the registration UID from the tags and returns it.
			@eguarantee strong
			@return the registration UID.
			*/
			ValueType getRegistrationUID() const;


			friend class RegistrationBaseManipulator;

		protected:
			RegistrationBase();
			~RegistrationBase() override;

			TagMapType _tags;

			/*! Checks the current tags and adds a registration UID if missing
			@eguarantee strong
			*/
			void ensureRegistrationUID();

			/*! @Sets the tags of a registration by replacing the existing tag map with the passed one.
			 * @remark If tags do not contain the tag "RegistrationUID" the old UID will automatically be added.
			 * If it is present it stays untouched. If you define your own UID ensure that it is unique.
			@eguarantee strong
			*/
			virtual void setTagValues(const RegistrationBase::TagMapType& tags);

			virtual RegistrationBase::TagMapType& getTagValues();

			/*! Methods invoked by itk::LightObject::Print().  */
			void PrintSelf(std::ostream& os, itk::Indent indent) const override;

		private:
			//No copy constructor allowed
			RegistrationBase(const Self& source) = delete;
			void operator=(const Self&) = delete;  //purposely not implemented

		};

	}  // namespace core

	namespace tags
	{
		const char* const AlgorithmUID = "AlgorithmUID";
		const char* const RegistrationUID = "RegistrationUID";
	}
}  // namespace map

#endif
