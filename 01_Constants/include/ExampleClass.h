//***************************************************************************
// File name:  ExampleClass.h
// Author:     Chadd Williams
// Date:       3/13/2017
// Class:      CS485
// Assignment: STL Example
// Purpose:    Demonstrate how to use STL and template programming
//***************************************************************************

#pragma once
#include <string>
#include <iostream>


class ExampleClass
{
public:

  ExampleClass ();
  ExampleClass (int key, std::string secretData, bool bMsg = true);
  ExampleClass (const ExampleClass &rcData);
  ~ExampleClass ();


  ExampleClass& operator=(ExampleClass cData);


  bool operator>(const ExampleClass &rcData) const;
  bool operator<(const ExampleClass &rcData) const;
  bool operator==(const ExampleClass &rcData) const;
  bool operator>=(const ExampleClass &rcData) const;
  bool operator<=(const ExampleClass &rcData) const;
  
  friend std::ostream& operator<<(std::ostream &rcOut, 
    const ExampleClass &rcData);

private:
  int mKey;
  std::string mSecretData;

  // constant used in many functions
  // private because no outside classes
  // need to use this
  //
  // set per object in the ctor
  const bool CTOR_MSGS;

  // constant used in many functions
  // private because no outside classes
  // need to use this
  // static because we want to set this
  // for ALL OBJECTS of this class
  //
  // must initialize in ExampleClass.cpp
  // if this is not an integral or enumeration type
  static const std::string CTOR_NAME;
};