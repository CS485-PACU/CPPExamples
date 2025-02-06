//***************************************************************************
// File name:  ExampleClass.cpp
// Author:     Chadd Williams
// Date:       3/13/2017
// Class:      CS485
// Assignment: STL Example
// Purpose:    Demonstrate how to use STL and template programming
//***************************************************************************
#include "../include/ExampleClass.h"

// Don't use global constants!
// const std::string CTOR_NAME = "ctor";

// initialize static constants that are part of the class
const std::string ExampleClass::CTOR_NAME = "ctor";

//***************************************************************************
// Constructor: Default Constructor
//
// Description: Initializes data members to default values
//              Display message that the ctor was called
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
ExampleClass::ExampleClass () : mKey(-1), mSecretData("unknown"), CTOR_MSGS(true)
{
  // set constant after : above

  if (CTOR_MSGS)
  {
    std::cout << CTOR_NAME << *this << std::endl;
  }
}

//***************************************************************************
// Constructor: ExampleClass
//
// Description: Initializes data members to the given values
//              Display message that the ctor was called
//
// Parameters:  key - int to use for mKey
//              secreteData - string to use for mSecretData
//
// Returned:    None
//***************************************************************************
ExampleClass::ExampleClass (int key, std::string secretData, bool bMsg) :
  mKey(key), mSecretData(secretData), CTOR_MSGS(bMsg)
{
  if (CTOR_MSGS)
  {
    std::cout << CTOR_NAME +"(int, std::string, bool = true)" << *this << std::endl;
  }
}

//***************************************************************************
// Constructor: Copy Constructor
//
// Description: Copy the given object into the new object
//              Display message that the ctor was called
//
// Parameters:  rcData - the object to copy
//
// Returned:    None
//***************************************************************************
ExampleClass::ExampleClass (const ExampleClass &rcData) :
  mKey (rcData.mKey), mSecretData (rcData.mSecretData), CTOR_MSGS(rcData.CTOR_MSGS)
{
  if (CTOR_MSGS)
  {
    std::cout << "c" + CTOR_NAME << *this << std::endl;
  }
}

//***************************************************************************
// Destructor:  ~ExampleClass
//
// Description: print a message to state the dtor was called
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
ExampleClass::~ExampleClass ()
{
  if (CTOR_MSGS)
  {
    std::cout << "dtor" << *this << std::endl;
  }
}

//***************************************************************************
// Function:    operator=
//
// Description: Copy assignment operator
//
// Parameters:  rcData - the data to copy
//
// Returned:    The current object
//***************************************************************************
ExampleClass & ExampleClass::operator=(ExampleClass cData)
{
  std::swap (this->mKey, cData.mKey);
  std::swap (this->mSecretData, cData.mSecretData);


  return *this;
}

//***************************************************************************
// Function:    operator>
//
// Description: Compare the keys of the two ExampleClasses
//
// Parameters:  rcData - the RHS
//
// Returned:    true if this > RHS. False otherwise
//***************************************************************************
bool ExampleClass::operator>(const ExampleClass &rcData) const
{
  return mKey > rcData.mKey;
}

//***************************************************************************
// Function:    operator<
//
// Description: Compare the keys of the two ExampleClasses
//
// Parameters:  rcData - the RHS
//
// Returned:    true if this < RHS. False otherwise
//***************************************************************************
bool ExampleClass::operator<(const ExampleClass &rcData) const
{
  return mKey < rcData.mKey;
}

//***************************************************************************
// Function:    operator==
//
// Description: Compare the keys of the two ExampleClasses
//
// Parameters:  rcData - the RHS
//
// Returned:    true if this == RHS. False otherwise
//***************************************************************************
bool ExampleClass::operator==(const ExampleClass &rcData) const
{
  return mKey == rcData.mKey;

}

//***************************************************************************
// Function:    operator>=
//
// Description: Compare the keys of the two ExampleClasses
//
// Parameters:  rcData - the RHS
//
// Returned:    true if this >= RHS. False otherwise
//***************************************************************************
bool ExampleClass::operator>=(const ExampleClass &rcData) const
{
  return mKey >= rcData.mKey;
}

//***************************************************************************
// Function:    operator<=
//
// Description: Compare the keys of the two ExampleClasses
//
// Parameters:  rcData - the RHS
//
// Returned:    true if this <= RHS. False otherwise
//***************************************************************************
bool ExampleClass::operator<=(const ExampleClass &rcData) const
{
  return mKey <= rcData.mKey;
}

//***************************************************************************
// Function:    operator<<
//
// Description: Write the object to the stream
//
// Parameters:  rcOut - the stream to write to
//              rcData - the object to write
//
// Returned:    the output stream
//***************************************************************************
std::ostream& operator<<(std::ostream &rcOut, const ExampleClass &rcData)
{
  // local constant only used in this function
  const std::string SEPERATOR = ":";
  const int EVEN_STEP = 2;

  rcOut << rcData.mKey << SEPERATOR ;

  // no constants necessary for
  // 0
  // -1
  // or 1
  for (int index = 0; index <= rcData.mSecretData.length() - 1; index += 1)
  {
    rcOut << rcData.mSecretData.at(index);
  }

  // make the constant EVEN_STEP so the reader will very 
  // clearly know why I am incrementing by 2
  for (int index = 0; index < rcData.mSecretData.length(); index += EVEN_STEP)
  {
    rcOut << rcData.mSecretData.at(index);
  }

  return rcOut;
}