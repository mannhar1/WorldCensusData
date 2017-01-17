/*********************************
File: Country.h
Project: CMSC 341 project 0
Author: Harrison Mann
Date: 9/11/16
Section: 04
E-mail: mannhar1@umbc.edu

Country class that stores information about the country.
There are methods for accessing and modifying each statistic.



***********************************/


#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
using namespace std;

class Country
{
 
 public: 
  Country();

  string getName() const;
  
  long getPopulation() const;

  float getLitRate() const;

  float getPrimComplFem() const;
  
  float getPrimComplMale() const;

  float getPrimComplTotal() const;

  float getEducationGDPSpent() const;

  float getYouthLitRateFem() const;

  float getYouthLitRateMale() const;

  

  void setName(string newName);

  void setPopulation(long newPopulation);

  void setLitRate(float litRate);

  void setPrimComplFem(float PrimComplFem);

  void setPrimComplMale(float PrimComplMale);

  void setPrimComplTotal(float PrimComplTotal);

  void setEducationGDPSpent(float eduGDPSpent);

  void setYouthLitRateFem(float youthLitRateF);

  void setYouthLitRateMale(float youthLitRateM);


 private: 
  string name;
  long population;
  float literacyRate;
  float PrimaryCompletionFemale;
  float PrimaryCompletionMale;
  float PrimaryCompletionTotal;
  float educationGDPSpent;
  float youthLitRateFem;
  float youthLitRateMale;

};

#endif
