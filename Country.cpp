/*********************************
File: Country.cpp
Project: CMSC 341 project 0
Author: Harrison Mann
Date: 9/11/16
Section: 04
E-mail: mannhar1@umbc.edu

Country class that stores information about the country.
There are methods for accessing and modifying each statistic.



***********************************/


#include <iostream>
#include <string>

using namespace std;

#include "Country.h"

Country::Country(){
  setPopulation(0);
  setLitRate(0);
  setEducationGDPSpent(0);
}

string Country::getName() const{
  return name;
}
long Country::getPopulation() const{
  return population;
}
float Country::getLitRate() const{
  return literacyRate;
}
float Country::getPrimComplFem() const{
  return PrimaryCompletionFemale;
}
float Country::getPrimComplMale() const{
  return PrimaryCompletionMale;
}
float Country::getPrimComplTotal() const{
  return PrimaryCompletionTotal;
}
float Country::getEducationGDPSpent() const{
  return educationGDPSpent;
}
float Country::getYouthLitRateFem() const{
  return youthLitRateFem;
}
float Country::getYouthLitRateMale() const{
  return youthLitRateMale;
}


void Country::setName(string newName){
  name = newName;
}
void Country::setPopulation(long newPopulation){
  population = newPopulation;
}
void Country::setLitRate(float litRate){
  literacyRate = litRate;
}
void Country::setPrimComplFem(float PrimComplFem){
  PrimaryCompletionFemale = PrimComplFem;
}
void Country::setPrimComplMale(float PrimComplMale){
  PrimaryCompletionMale = PrimComplMale;
}
void Country::setPrimComplTotal(float PrimComplTotal){
  PrimaryCompletionTotal = PrimComplTotal;
}
void Country::setEducationGDPSpent(float eduGDPSpent){
  educationGDPSpent = eduGDPSpent;
}
void Country::setYouthLitRateFem(float youthLitRateF){
  youthLitRateFem = youthLitRateF;
}
void Country::setYouthLitRateMale(float youthLitRateM){
  youthLitRateMale = youthLitRateM;
}
