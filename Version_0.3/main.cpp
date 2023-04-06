#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <chrono>
#include "country.h"
#include "datasetsort.h"

Country* readCountryDataFromFile(const std::string& fileName, int& numLines); 

int main() 
{
  int numLines= 0;
  Country* data = readCountryDataFromFile("data2.csv", numLines);

  /*for(int i = 0; i < numLines;i++)
  {
    std::cout << data[i].getCountryName() << " " << data[i].getEpi2022() << " ";
    std::cout << data[i].getEpi2022() << " " << data[i].getEpi10yr() << std::endl;
  }*/
  
  /*
    Sorting Portion
  */

  int sortChoice;
    std::cout << "Which sorting algorithm do you want to use?" << std::endl;
    std::cout << "1. Selection sort" << std::endl;
    std::cout << "2. Merge sort" << std::endl;
    std::cin >> sortChoice;

    int criteriaChoice;
    std::cout << "Which criteria do you want to sort the data by?" << std::endl;
    std::cout << "1. Country Name" << std::endl;
    std::cout << "2. EPI 2020" << std::endl;
    std::cout << "3. EPI 2022" << std::endl;
    std::cout << "4. EPI 10-year change" << std::endl;
    std::cin >> criteriaChoice;

    DataSetSort dataSet(data, numLines);

    // Start timing
    auto start = std::chrono::high_resolution_clock::now();
  
    // Sort the data using the chosen algorithm and criteria
    if (sortChoice == 1)
    {
        dataSet.selectionSort(criteriaChoice);
    }
    else if (sortChoice == 2)
    {
        dataSet.mergeSort(criteriaChoice);
    }

    // End timing
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Sorting took " << duration.count() << " ms" << std::endl;

    int outputChoice;
    std::cout << "Where do you want to output the results?" << std::endl;
    std::cout << "1. Top 10" << std::endl;
    std::cout << "2. Middle 10" << std::endl;
    std::cout << "3. Bottom 10" << std::endl;
    std::cin >> outputChoice;

    int startIdx, endIdx;
    if (outputChoice == 1)
    {
        startIdx = 0;
        endIdx = 10;
    }
    else if (outputChoice == 2)
    {
        startIdx = numLines/2 - 5;
        endIdx = numLines/2 + 5;
    }
    else if (outputChoice == 3)
    {
        startIdx = numLines - 10;
        endIdx = numLines;
    }
  
    for (int i = startIdx; i < endIdx; i++)
    {
        std::cout << data[i].getCountryName() << " " << data[i].getEpi2022() << " ";
        std::cout << data[i].getEpi2020() << " " << data[i].getEpi10yr() << std::endl;
    }

  // Delete array to free memory
  delete[] data;

  return 0;
}


Country* readCountryDataFromFile(const std::string& fileName, int& numLines) 
{
  // Read in File to count the number of lines
  std::ifstream countFile(fileName);
  std::string countLine;
  while (std::getline(countFile, countLine)) {
    numLines++;
  }
  countFile.close();

  // Initialize a Dynamically allocated array
  Country* data = new Country[numLines];

  // Declare Variables to hold in data
  std::string countryName;
  double epi2020, epi2022, epi10yr;
  // Declare variable to keep track of count for array in while loop
  int j = 0;

  // Read in File
  std::ifstream file(fileName);
  std::string line;
  // Reads and discard the first line as it is not needed
  std::getline(file, line);

  while (std::getline(file, line) && j < numLines) {
    std::stringstream ss(line);
    std::string field;
    data[j] = Country("N/A", epi2022, epi10yr, epi2020);
    for (int i = 1; i <= 20; i++) {
      //Checks Which number of values have been read in
      //to determine when to set each value
      std::getline(ss >> std::ws, field, ',');
      if (field.empty()) {
        field = "0";
      }
      if (i == 5) {
        std::string name = field.substr(1, field.length() - 2); // remove quotation marks
        data[j].setCountryName(name);
      } else if (i == 15) {
        double newValue;
        std::istringstream iss(field);
        iss >> newValue;
        data[j].setEpi2022(newValue);
      } else if (i == 16) {
        double newValue;
        std::istringstream iss(field);
        iss >> newValue;
        data[j].setEpi2020(newValue);
      } else if (i == 17) {
        double newValue;
        std::istringstream iss(field);
        iss >> newValue;
        data[j].setEpi10year(newValue);
      }
    }
    j++;
  }

  file.close();

  return data;
}

