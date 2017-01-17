/*********************************
File: Continent.cpp
Project: CMSC 341 project 0
Author: Harrison Mann
Date: 9/11/16
Section: 04
E-mail: mannhar1@umbc.edu

Class to create a continent that is a child class of 
the Country class.  Stores a vector of Countries that are
in that continent.  



***********************************/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Country.h"
#include "Continent.h"

Continent::Continent(){
  setPopulation(0);
}

vector<Country> Continent::getCountriesInContinent() const{
  return countriesInContinent;
}
Country Continent::getHighestPopulation() const{
  return highestPopulation;
}
Country Continent::getHighestGDPSpent() const{
  return highestGDPSpent;
}
Country Continent::getHighestLiteracyRate() const{
  return highestLiteracyRate;
}
void Continent::setCountriesInContinent(vector<Country> inContinent){
  countriesInContinent.clear();
  countriesInContinent = inContinent;
}
void Continent::setHighestPopulation(Country& highPop){
  highestPopulation.setName(highPop.getName());
  highestPopulation.setPopulation(highPop.getPopulation());
  highestPopulation.setLitRate(highPop.getLitRate());
  highestPopulation.setPrimComplFem(highPop.getPrimComplFem());
  highestPopulation.setPrimComplMale(highPop.getPrimComplMale());
  highestPopulation.setPrimComplTotal(highPop.getPrimComplTotal());
  highestPopulation.setEducationGDPSpent(highPop.getEducationGDPSpent());
  highestPopulation.setYouthLitRateFem(highPop.getYouthLitRateFem());
  highestPopulation.setYouthLitRateMale(highPop.getYouthLitRateMale());
}
void Continent::setHighestGDPSpent(Country& highGDP){
  highestGDPSpent.setName(highGDP.getName());
  highestGDPSpent.setPopulation(highGDP.getPopulation());
  highestGDPSpent.setLitRate(highGDP.getLitRate());
  highestGDPSpent.setPrimComplFem(highGDP.getPrimComplFem());
  highestGDPSpent.setPrimComplMale(highGDP.getPrimComplMale());
  highestGDPSpent.setPrimComplTotal(highGDP.getPrimComplTotal());
  highestGDPSpent.setEducationGDPSpent(highGDP.getEducationGDPSpent());
  highestGDPSpent.setYouthLitRateFem(highGDP.getYouthLitRateFem());
  highestGDPSpent.setYouthLitRateMale(highGDP.getYouthLitRateMale());

}
void Continent::setHighestLiteracyRate(Country& highLit){
  highestLiteracyRate.setName(highLit.getName());
  highestLiteracyRate.setPopulation(highLit.getPopulation());
  highestLiteracyRate.setLitRate(highLit.getLitRate());
  highestLiteracyRate.setPrimComplFem(highLit.getPrimComplFem());
  highestLiteracyRate.setPrimComplMale(highLit.getPrimComplMale());
  highestLiteracyRate.setPrimComplTotal(highLit.getPrimComplTotal());
  highestLiteracyRate.setEducationGDPSpent(highLit.getEducationGDPSpent());
  highestLiteracyRate.setYouthLitRateFem(highLit.getYouthLitRateFem());
  highestLiteracyRate.setYouthLitRateMale(highLit.getYouthLitRateMale());

}
ostream& operator<<(ostream& out, const Continent& continent){
  out << continent.getName() << endl;
  out << " Population: " << continent.getPopulation() << endl;

  out << " Country with the highest literacy rate: " << continent.getHighestLiteracyRate().getName() << " with a population of " << 
    continent.getHighestLiteracyRate().getPopulation() << " and a literacy rate of " << continent.getHighestLiteracyRate().getLitRate() << endl;

  out << " Country with the highest GDP expenditure on education: " << continent.getHighestGDPSpent().getName() << " with a population of " <<
    continent.getHighestGDPSpent().getPopulation() << " and a literacy rate of " << continent.getHighestGDPSpent().getLitRate() << endl;

  out << " Country with the highest population: " << continent.getHighestPopulation().getName() << " with a population of " <<
    continent.getHighestPopulation().getPopulation() << " and a literacy rate of " << continent.getHighestPopulation().getLitRate() << endl;

  return out;
}
