#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>

class Country{
public:
  Country();
  Country(std::string n, double e22, double e10, double e20);

  void setCountryName(std::string new_name);
  void setEpi2022(double new_epi_2022);
  void setEpi2020(double new_epi_2020);
  void setEpi10year(double new_epi_10_year);

  std::string getCountryName() const;
  double getEpi2022() const;
  double getEpi2020() const;
  double getEpi10yr() const;

private:
  std::string countryName;
  double epi2022;
  double epi10yr;
  double epi2020;
};

#endif