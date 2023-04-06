#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "country.h"

int main() 
{
  // Read in File to count the number of lines
  std::ifstream countFile("data2.csv");
  std::string countLine;
  int numLines = 0;
  while (std::getline(countFile, countLine)) 
  {
    numLines++;
  }
  countFile.close();

  // Dynamically allocate memory for the array
  Country* data = new Country[numLines];

  // Declare Variables to hold in data
  std::string countryName;
  double epi2020, epi2022, epi10yr;
  // Declare variable to keep track of count in while loop
  int j = 0;

  // Read in File
  std::ifstream file("data2.csv");
  std::string line;
  // Reads and discard the first line as it is not needed
  std::getline(file, line);

  while (std::getline(file, line) && j < numLines)
  {
    std::stringstream ss(line);
    std::string field;
    data[j] = Country("N/A", epi2022, epi10yr, epi2020);
    for (int i = 1; i <= 20; i++) 
    {
      //Checks Which number of values have been read in
      std::getline(ss, field, ',');
      if (field.empty()) 
      {
        field = "0";
      }
      if(i == 5)
      {
        std::string name = field;
        data[j].setCountryName(name);
        //std::cout << "the Country name is : " << data[j].getCountryName() << std::endl;
      }
      else if(i == 15)
      {
        double newValue;
        std::istringstream iss(field);
        iss >> newValue;
        data[j].setEpi2022(newValue);
      }
      else if(i == 16)
      {
        double newValue;
        std::istringstream iss(field);
        iss >> newValue;
        data[j].setEpi2020(newValue);
      }
      else if(i == 17)
      {
        double newValue;
        std::istringstream iss(field);
        iss >> newValue;
        data[j].setEpi10year(newValue);
      }
    }
    //std::cout << data[j].getCountryName() << std::endl;
    j++;
  }

  file.close();

  for(int i = 0; i < numLines;i++)
  {
    std::cout << data[i].getCountryName() << " " << data[i].getEpi2022() << " ";
    std::cout << data[i].getEpi2022() << " " << data[i].getEpi10yr() << std::endl;
  }

  // Free dynamically allocated memory
  delete[] data;

  return 0;
}
 