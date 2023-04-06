#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "country.h"


int main() 
{
  // Declare Array
  Country* data[9];
  // Declare Variables to hold in data
  std::string countryName;
  double epi2020, epi2022, epi10yr;
  // Declare variable to keep track of count in while loop
  int j = 0;

  // Read in File
  std::ifstream file("data.csv");
  std::string line;
  // Reads and discard the first line as it is not needed
  std::getline(file, line);

  while (std::getline(file, line))
  {
    std::stringstream ss(line);
    std::string field;
    data[j] = new Country("", epi2022, epi10yr, epi2020);
    for (int i = 1; i <= 20; i++) 
    {
      //Checks Which number of values have been read in
      std::getline(ss, field, ',');
      if(i == 5)
      {
        data[j]->setCountryName(field);
      }
      else if(i == 15)
      {
        double newValue = std::stof(field);
        data[j]->setEpi2022(newValue);
      }
      else if(i == 16)
      {
        double newValue = std::stof(field);
        data[j]->setEpi2020(newValue);
      }
      else if(i == 17)
      {
        double newValue = std::stof(field);
        data[j]->setEpi10year(newValue);
      }
      
    }
    j++;
  }

  file.close();

  for(int i = 0; i < 9;i++)
  {
    std::cout << data[i]->getCountryName() << " " << data[i]->getEpi2022() << " ";
    std::cout << data[i]->getEpi2022() << " " << data[i]->getEpi10yr() << std::endl;
  }

  return 0;
}




/*
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename = "filename.csv";
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        return 1;
    }

    // skip first line
    string line;
    getline(file, line);

    // read remaining lines
    while (getline(file, line)) {
        // process line here
        cout << line << endl;
    }

    file.close();
    return 0;
}
*/


/*
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream file("data.csv"); // open the CSV file
    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    vector<vector<string>> data; // 2D vector to store the CSV data
    string line, field;
    while (getline(file, line)) { // read each line of the file
        vector<string> row; // vector to store each row of data
        stringstream ss(line); // convert the line into a stringstream
        while (getline(ss, field, ',')) { // split each line into fields
            row.push_back(field); // add each field to the row vector
        }
        data.push_back(row); // add each row to the data vector
    }

    // create an array to store the specified fields
    vector<vector<string>> result(data.size(), vector<string>(4));

    for (int i = 1; i < data.size(); i++) { // start from 1 to skip the header row
        // extract the specified fields and add them to the result array
        result[i-1][0] = data[i][4]; // country name
        result[i-1][1] = data[i][15]; // epi2020
        result[i-1][2] = data[i][16]; // epi2022
        result[i-1][3] = data[i][17]; // tenYrChange

        // replace missing or corrupted values with 0
        for (int j = 1; j < 4; j++) {
            if (result[i-1][j] == "" || result[i-1][j] == "n/r") {
                result[i-1][j] = "0";
            }
        }
    }

    // print the result array
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
*/

/*
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "country.h"

int main()
{
  //Declare Array
  Country data[50];
  int i = 0;
  
  //Declare Variables To Set Into Array
  double epi2020, epi2022, epi10year;
  std::string countryName;
  std::string line;
  
  //Read in CSV File
  std::ifstream file("data.csv");

  // Reads and discard the first line of headers
  std::getline(file, line);

  
  while (std::getline(file, line)) 
  {
    std::stringstream ss(line);

    std::string epi2020_str, epi2022_str, epi10year_str;

    // Extract the countryName
    for (int i = 0; i < 5; i++) 
    {
      std::getline(ss, countryName, ',');
    }
    //std::getline(ss, countryName, ',');
    
    // Extract the epi2022
    for (int i = 6; i < 15; i++) 
    {
      std::getline(ss, epi2022_str, ',');
    }
    std::getline(ss, epi2022_str, ',');
    //epi2022 = std::stod(epi2022_str);

    // Extract the epi2020
    for (int i = 15; i < 16; i++) 
    {
      std::getline(ss, epi2020_str, ',');
    }
    std::getline(ss, epi2020_str, ',');
    //epi2020 = std::stod(epi2020_str);

    // Extract the epi10year
    for (int i = 16; i < 17; i++) 
    {
      std::getline(ss, epi10year_str, ',');
    }
    std::getline(ss, epi10year_str, ',');
    //epi10year = std::stod(epi10year_str);

    data[i] = Country(countryName, epi2022, epi10year, epi2020);

    data[i].setCountryName(countryName);
    data[i].setEpi2022(epi2022 = std::stod(epi2022_str));
    data[i].setEpi2020(epi2020);
    data[i].setEpi10year(epi10year = std::stod(epi10year_str));

    //increments array
    i++;
  }

  for(i = 0;i < 50;i++)
  {
    std::cout << data[i].getCountryName() << " " << data[i].getEpi10yr() << std::endl;
  }
  

  
  return 0;
  
}

*/