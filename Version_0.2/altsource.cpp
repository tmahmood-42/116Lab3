#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

const int NUM_FIELDS = 20; // Number of fields in each line

int main() {
    std::ifstream file("data.csv");
    std::string line;

    // Ignore first line
    std::getline(file, line);

    // Initialize array of pointers to string
    std::string* fields[NUM_FIELDS];

    // Read in each line and store fields in array of pointers
    while (std::getline(file, line)) {
        // Split line by commas
        std::stringstream ss(line);
        std::string token;
        int count = 0;
        while (std::getline(ss, token, ',')) {
            // Allocate memory for string and copy token into it
            fields[count] = new std::string(token);
            count++;
        }

        // Do something with fields array, for example:
        // Print the values to the console
        for (int i = 0; i < NUM_FIELDS; i++) {
            std::cout << *fields[i] << ",";
        }
        std::cout << std::endl;

        // Free memory allocated for strings
        for (int i = 0; i < NUM_FIELDS; i++) {
            delete fields[i];
        }
    }

    return 0;
}




/*#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


int main()
{
  std::cout << "WTF" << std::endl;
  std::string line;
  std::ifstream file("data.csv");

  //Checks if File is valid
  if (!file.is_open()) 
  {
      std::cerr << "Failed to open file.\n";
      return 1;
  }

  // Ignore first line
  std::getline(file, line);

  while (std::getline(file, line)) 
  {
    // Split line by commas
     std::stringstream ss(line);
      std::string fifteenthValue;
      int columnCount = 0;
      while (std::getline(ss, fifteenthValue, ',')) 
      {
          columnCount++;
          // Ignore first column and last 3 columns
          if (columnCount++ == 1 || columnCount++ > 17) 
          {
              continue;
          }
          // Only store the 15th value
          if (columnCount++ == 15) 
          {
              std::string epi2022_str = fifteenthValue;
              std::cout << epi2022_str << std::endl;
          }
      }
  }
  
  return 0;
  
}*/
