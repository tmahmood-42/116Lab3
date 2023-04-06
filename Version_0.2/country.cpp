#include "country.h"
#include <iostream>

Country::Country()
{
  countryName = "";
  epi2022 = 0;
  epi10yr = 0;
  epi2020 - 0;
}
Country::Country(std::string n, double e22, double e10, double e20)
{
  countryName = n;
  epi2022 = e22;
  epi10yr = e10;
  epi2020 = e20;
  
}

/***
* Mutators(Setters)
***/

void Country::setCountryName(std::string new_name) 
{
    countryName = new_name;
}
void Country::setEpi2022(double new_epi_2022)
{
    epi2022 = new_epi_2022;
}
void Country::setEpi2020(double new_epi_2020)
{
    epi2020 = new_epi_2020;
}

void Country::setEpi10year(double new_epi_10_year)
{
    epi10yr = new_epi_10_year;
}


/***
* Accessors(Getters)
***/
std::string Country::getCountryName() const
{
    return countryName;
}

int Country::getEpi2022() const
{
    return epi2022;
}

int Country::getEpi2020() const
{
    return epi2020;
}
int Country::getEpi10yr() const
{
    return epi10yr;
}