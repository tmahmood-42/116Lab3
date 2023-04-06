#ifndef DATASETSORT_H
#define DATASETSORT_H

#include "country.h"

class DataSetSort 
{
public:
  DataSetSort(Country* data, int size);
  void selectionSort(int sortChoice);
  void mergeSort(int sortChoice);

private:
  Country* data;
  int size;
  void mergeSortHelper(int from, int to, int sortChoice);
  void merge(int from, int mid, int to, int sortChoice);
  //Private member functions used for Selection Sort
  void swap(Country& a, Country& b);
  int compare(Country a, Country b, int sortChoice);
};

#endif