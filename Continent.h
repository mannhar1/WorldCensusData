/*********************************
File: Continent.h
Project: CMSC 341 project 0
Author: Harrison Mann
Date: 9/11/16
Section: 04
E-mail: mannhar1@umbc.edu

Class to create a continent that is a child class of
the Country class.  Stores a vector of Countries that are
in that continent.



***********************************/


#ifndef CONTINENT_H
#define CONTINENT_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#include "Country.h"

class Continent : public Country
{

 public: 
  Continent();

  vector<Country> getCountriesInContinent() const;

  Country getHighestPopulation() const;

  Country getHighestGDPSpent() const;

  Country getHighestLiteracyRate() const;

  void setCountriesInContinent(vector<Country> inContinent);

  void setHighestPopulation(Country& highPop);

  void setHighestGDPSpent(Country& highGDP);
  
  void setHighestLiteracyRate(Country& highLit);


  friend ostream& operator<<(ostream& out, const Continent& continent);

 private:
  vector<Country> countriesInContinent;
  Country highestPopulation;
  Country highestGDPSpent;
  Country highestLiteracyRate;

};

#endif
