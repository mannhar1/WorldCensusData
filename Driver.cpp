/*********************************
File: Driver.cpp
Project: CMSC 341 project 0
Author: Harrison Mann
Date: 9/12/16
Section: 04
E-mail: mannhar1@umbc.edu

This is the file that initiates the program.  
It takes the 2 text files and uses the information in both
files to determine stats about Continents and countries.


***********************************/



#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "Continent.h"
#include "Country.h"

vector<Continent> readFromFiles(const char* stats,const char* continents){

  ifstream infile;
  infile.open(stats, ios_base::in);

  int lineCount = 0;
  string line;
  
  while(getline(infile, line)){
    lineCount++;
  }//this while loop counts how many lines are in the stats file to determine the number of countries
  
  const int numStatsTracked = 9;//name, pop, litRate, etc...

  vector< vector<string> > allStats(lineCount - 1, vector<string>(numStatsTracked));
  //creates a 2D vector which will eventually store all of the stats in string form
  //we do lineCount - 1 because the first line of this file isnt statistics for a country

  infile.clear();
  infile.seekg(0, ios::beg);//returns to the top of the file

  string headerLine;
  getline(infile, headerLine);//this skips over the first line in the stats file because its not a country

  int countryCounter = 0;//this will incriment with each iteration of the while loop so that the new info is added to the correct vector
  
  while(getline(infile, line)){
    for (int i = 0; i < numStatsTracked; i++){
      string singleStat;
      if (i == 0){
	int tabIndex = line.find("\t");
	singleStat = line.substr(0,tabIndex);
	line.erase(0, tabIndex + 2);//delete one extra spot because there are 2 tabs separating the first 2 statistics instead of just 1.
      }else if (i == 8){
	int spaceIndex = line.find(" ");
	singleStat = line.substr(0,spaceIndex);//special case for the last statistic because it is followed by a space isntead of a tab
      }else{
	int tabIndex = line.find("\t");
	singleStat = line.substr(0,tabIndex);
	line.erase(0, tabIndex + 1);
      }
      if (singleStat.compare("N/A") == 0){
	singleStat = "-1";
      }
      allStats[countryCounter][i] = singleStat;
      
    }
    countryCounter++;
  }//this while loop initializes all of the values of the 2d vector created above, so after this while loop runs, all of the statistics are now separate strings
  //and they are designated to their countries vector.



  infile.close();//all of the statistics have been moved to my 2d vector so i no longer need to use this file


  infile.open(continents, ios_base::in);//opening the second file
  
  int continentCounter = 0;//need to find the number of continents so we can create the world vector
  
  while(getline(infile, line)){
    //in this while loop i will count the number of lines in the file that list a new continent name

    int spaceIndex = line.find(" ");

    if (spaceIndex != -1){//the only lines with spaces are the ones that give continent names
      continentCounter++;
    }
  }


  vector<Continent> wholeWorld(continentCounter);//creates the continent vector with enough space for the number of continents in the file

  vector<int> numCountriesPerCont(continentCounter);//creates an int vector that I will fill with the number of countries in each continent


  infile.clear();
  infile.seekg(0, ios::beg);//returns to the top of the file


  continentCounter = 0;//resets continentCounter so it can be used again
  
  while(getline(infile, line)){//finds the number of countries listed in each continent and assigns that number to the corresponding spot on numCountriesPerCont
    int lastSpaceIndex = line.find_last_of(" ");

    if (lastSpaceIndex != -1){
      string numCountriesStr = line.substr(lastSpaceIndex + 1);//creates the substring including only the number of countries in each continent.

      int numCountries = atoi(numCountriesStr.c_str());
      numCountriesPerCont[continentCounter] = numCountries;//converts the substring into an integer and then adds it to its respective spot on numCountriesPerCont

      continentCounter++;
    }
  }
  

  infile.clear();
  infile.seekg(0, ios::beg);//returns to the top of the file



  
  for (int i = 0; i < continentCounter; i++){
    Continent eachCont;//at the top of this loop, a new continent is created and will be filled out with its data by the end of the loop
    vector<Country> CountryVect(numCountriesPerCont[i]);
    for (int j = 0; j < numCountriesPerCont[i] + 1; j++){//this loops through the file of country names as many times as there are countries in each continent
      if (j == 0){
	string currentLine;//this case catches the lines of the file that have continent names instead of country names so they are dealt with separately
	string continentName;
	getline(infile, currentLine);
	int spaceIndex = currentLine.find(" ");
	continentName = currentLine.substr(0, spaceIndex);//sets a name to the continent being worked on
	eachCont.setName(continentName);
      }else{
	string currentLine;
	getline(infile, currentLine);//looks at the next country in the list to search for its counterpart in the 2d vector allStats
	for (int k = 0; k < lineCount - 1; k++){
	  if(currentLine.compare(allStats[k][0]) == 0){//this compares the names of the countries in the new list to those in allStats
	    //when it finds a match, it creates the country that was found in the continent, plugs in its data from allStats, and adds it to the country vector
	    Country eachCountry;

	    
	    eachCountry.setName(allStats[k][0]);
	    eachCountry.setPopulation(atol(allStats[k][1].c_str()));
	    eachCountry.setLitRate(atof(allStats[k][2].c_str()));
	    eachCountry.setPrimComplFem(atof(allStats[k][6].c_str()));//all of the data is set to floats, longs, or strings appropriately
	    eachCountry.setPrimComplMale(atof(allStats[k][5].c_str()));
	    eachCountry.setPrimComplTotal(atof(allStats[k][4].c_str()));
	    eachCountry.setEducationGDPSpent(atof(allStats[k][3].c_str()));
	    eachCountry.setYouthLitRateFem(atof(allStats[k][7].c_str()));
	    eachCountry.setYouthLitRateMale(atof(allStats[k][8].c_str()));
	    
	    eachCont.setPopulation(eachCont.getPopulation() + eachCountry.getPopulation());//this adds the population of the country to the total continents pop
	    
	    if (eachCountry.getPopulation() > eachCont.getHighestPopulation().getPopulation()){
	      eachCont.setHighestPopulation(eachCountry);
	    }//this checks if the current country has a higher population than any other in the continent
	    if (eachCountry.getLitRate() > eachCont.getHighestLiteracyRate().getLitRate()){
	      eachCont.setHighestLiteracyRate(eachCountry);
	    }//this checks if the current country has a higher literacy rate than any other in the continent
	    if (eachCountry.getEducationGDPSpent() > eachCont.getHighestGDPSpent().getEducationGDPSpent()){
	      eachCont.setHighestGDPSpent(eachCountry);
	    }//this checks if the current country has a higher education gdp spent than any other in the continent

	    CountryVect[j - 1] = eachCountry;//this adds the country to the country vector for this continent
	    	    
	  }
	}
      }
    }
    eachCont.setCountriesInContinent(CountryVect);//assigns the country vector to its continent
    wholeWorld[i] = eachCont;//adds the completed continent to the continent vector
  }

  return wholeWorld;//completed world

}


int main(){

  vector<Continent> world;

  world = readFromFiles("2013WorldBankEducationCensusData.txt", "CountriesContinents.txt");

  for (int i = 0; i < world.size(); i++){
    cout << world[i];
  }
  
  return 0;
}

