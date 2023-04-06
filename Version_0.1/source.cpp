#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "country.h"

int main()
{
  //Declare Array of Pointers To Store Countrys
  Country* array[182];
  //Variables to Hold Data Read In
  double epi2020, epi2022, epi10year;
  std::string countryName;
  //Count To Keep Track of how Many Countries read In
  int count = 0;

  std::ifstream file("data.csv");

  
  //Checks if File is valid
  if (!file.is_open()) 
  {
      std::cerr << "Failed to open file.\n";
      return 1;
  }
  

  // Keeps track of array storage in while loop
  int i = 0;

  std::string line;
  // Reads and discard the first line as it is not needed
  std::getline(file, line);
  
  // Reads all Lines after the first line and sets them into array
  while (std::getline(file, line)) 
  {
      std::stringstream ss(line);

      std::string epi2020_str, epi2022_str, epi10year_str;

      // Read and store the 15th value from each line
      std::getline(ss, epi2022_str, ',');
      if (epi2022_str.empty()) {
          epi2022_str = "0";
      }
      std::cout << epi2022_str << std::endl;
      
      for (int j = 1; j < 16; j++) 
      {
          std::getline(ss, epi2020_str, ',');
      }
      // Read and store the 16th value
      std::getline(ss, epi2020_str, ',');
      if (epi2020_str.empty()) {
          epi2020_str = "0";
      }
      
      for (int j = 1; j < 17; j++) 
      {
          std::getline(ss, epi10year_str, ',');
      }
      // Read and store the 17th value
      std::getline(ss, epi10year_str, ',');
      if (epi10year_str.empty()) {
          epi10year_str = "0";
      }
      
      //After reading them in, It converts them to Double to store 
      try {
          epi2022 = std::stod(epi2022_str);
          epi2020 = std::stod(epi2020_str);
          epi10year = std::stod(epi10year_str);
      } catch (std::invalid_argument& e) {
          std::cerr << "Invalid input: " << e.what() << std::endl;
          // Handle the error by skipping this line or setting a default value
          continue;
      }
    /*
      //After reading them in, It converts them to Double to store 
      epi2022 = std::stod(epi2022_str);
      epi2020 = std::stod(epi2020_str);
      epi10year = std::stod(epi10year_str);
      */
      // Adds Data to Array
      array[i] = new Country(" ", epi2020, epi2022, epi10year); 
                
      // Set the name, and EPI's

      array[i]->setCountryName(countryName);
      array[i]->setEpi2022(epi2022);
      array[i]->setEpi2020(epi2020);
      array[i]->setEpi10year(epi10year);
      i++;
  }
  
  // Close file
  file.close();
  

  for (int i = 0; i < 10; i++)
  {
    std::cout << array[i]->getCountryName();
    std::cout << std::endl;
  }

  return 0;
  
}

/*
    For Loop To Set Variables Manually

   for (int i = 0; i < 10; i++)
    {
      
      std::cout << "Enter the Name: ";
      std::cin >> userCountryName;    
      if(userCountryName == "0")
      {
        break;
      }
      std::cout << "Enter the EPI 2022: ";
      std::cin >> userEpi2022;
      std::cout << "Enter the EPI 2020: ";
      std::cin >> userEpi2020;
      std::cout << "Enter the EPI 10 Year Change: ";
      std::cin >> userEpi10year;
                
      // Create a new Country instance and add it to the shelter array
      array[i] = new Country(" ", userEpi2020, userEpi2022, userEpi10year); 
                
      // Set the name, and EPI's

      array[i]->setCountryName(userCountryName);
      array[i]->setEpi2022(userEpi2022);
      array[i]->setEpi2020(userEpi2020);
      array[i]->setEpi10year(userEpi10year);
      
      count++;
    }
*/