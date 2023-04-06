#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <chrono>
#include "country.h"
#include "datasetsort.h"

//Function to read in CSV file and Return Data From Array
Country* readCountryDataFromFile(const std::string& fileName, int& numLines); 

int main() 
{
  using namespace std::chrono;
  
  int numLines = 0;
  int criteriaChoice, sortChoice;
  
  Country* data = readCountryDataFromFile("data2.csv", numLines);

  /*for(int i = 0; i < numLines;i++)
  {
    std::cout << data[i].getCountryName() << " " << data[i].getEpi2022() << " ";
    std::cout << data[i].getEpi2022() << " " << data[i].getEpi10yr() << std::endl;
  }*/
  
  /*
    Sorting Portion
  */

  std::cout << "Which sorting algorithm do you want to use?" << std::endl;
  std::cout << "1. Selection sort" << std::endl;
  std::cout << "2. Merge sort" << std::endl;
  std::cin >> sortChoice;

  std::cout << "Which criteria do you want to sort the data by?" << std::endl;
  std::cout << "Note that Program will Output from Least to Greatest" << std::endl;
  std::cout << "1. EPI 2020" << std::endl;
  std::cout << "2. EPI 10 Year Change" << std::endl;
  std::cout << "3. EPI 2022" << std::endl;
  std::cout << "4. Country Name (A-Z)" << std::endl;
  std::cin >> criteriaChoice;

  DataSetSort dataSet(data, numLines-1);

  // Start timing
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  high_resolution_clock::time_point t2;
  
  // Sort the data using the chosen algorithm and criteria
  if (sortChoice == 1)
  {
      dataSet.selectionSort(criteriaChoice);
      // End timing
      high_resolution_clock::time_point t2 = high_resolution_clock::now();
  }
  else if (sortChoice == 2)
  {
      dataSet.mergeSort(criteriaChoice);
      // End timing
      high_resolution_clock::time_point t2 = high_resolution_clock::now();
  }

  // End timing
  //high_resolution_clock::time_point t2 = high_resolution_clock::now();
    
  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
  //Keeps track of and Outputs Time
  std::cout << std::endl;
  std::cout << "It takes " << time_span.count() << " seconds to sort the array with Merge Sort.";
  std::cout << std::endl;

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
  
  // Set the column widths
  const int colWidth = 35;
  const int colWidthNumber = 10;
    
  // Output the table header
  std::cout << std::setw(colWidth) << std::left << "Country Name"
      << std::setw(colWidthNumber) << std::left << "EPI 2022"
      << std::setw(colWidthNumber) << std::left << "EPI 2020"
      << std::setw(colWidthNumber) << std::left << "EPI 10-Year Change" << std::endl;
    
  // Output each row of data
  for (int i = startIdx; i < endIdx; i++)
  {
    std::cout << std::setw(colWidth) << std::left << data[i].getCountryName()
        << std::setw(colWidthNumber) << std::left << data[i].getEpi2022()
        << std::setw(colWidthNumber) << std::left << data[i].getEpi2020()
        << std::setw(colWidthNumber) << std::left << data[i].getEpi10yr() << std::endl;
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
  while (std::getline(countFile, countLine)) 
  {
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

  while (std::getline(file, line) && j < numLines)
  {
    std::stringstream ss(line);
    std::string field;
    data[j] = Country("N/A", epi2022, epi10yr, epi2020);
    for (int i = 1; i <= 20; i++) 
    {
      //Checks Which number of values have been read in
      //to determine when to set each value
      std::getline(ss >> std::ws, field, ',');
      if (field.empty()) {
        field = "0";
      }
      if (i == 5) 
      {
        std::string name = field.substr(1, field.length() - 2); // remove quotation marks
        data[j].setCountryName(name);
      } 
      else if (i == 15) 
      {
        double newValue;
        std::istringstream iss(field);
        iss >> newValue;
        data[j].setEpi2022(newValue);
      } 
      else if (i == 16) 
      {
        double newValue;
        std::istringstream iss(field);
        iss >> newValue;
        data[j].setEpi2020(newValue);
      } 
      else if (i == 17) 
      {
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

