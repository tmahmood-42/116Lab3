#include "datasetsort.h"

DataSetSort::DataSetSort(Country* data, int size) 
{
  this->data = data;
  this->size = size;
}

void DataSetSort::selectionSort(int sortChoice) 
{
  for (int i = 0; i < size - 1; i++) 
  {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) 
    {
      if (compare(data[j], data[minIndex], sortChoice) < 0) 
      {
        minIndex = j;
      }
    }
    swap(data[i], data[minIndex]);
  }
}

void DataSetSort::mergeSort(int sortChoice) 
{
  mergeSortHelper(0, size - 1, sortChoice);
}

void DataSetSort::mergeSortHelper(int from, int to, int sortChoice) 
{
  if (from == to) 
  {
    return;
  }
  else if (from < to) 
  {
    int mid = (from + to) / 2;
    mergeSortHelper(from, mid, sortChoice);
    mergeSortHelper(mid + 1, to, sortChoice);
    merge(from, mid, to, sortChoice);
  }
}

void DataSetSort::merge(int from, int mid, int to, int sortChoice) 
{
  int n = to - from + 1;
  Country* temp = new Country[n];

  int i1 = from;
  int i2 = mid + 1;
  int j = 0;

  while (i1 <= mid && i2 <= to) 
  {
    if (compare(data[i1], data[i2], sortChoice) < 0) 
    {
      temp[j] = data[i1];
      i1++;
    }
    else 
    {
      temp[j] = data[i2];
      i2++;
    }
    j++;
  }

  while (i1 <= mid) 
  {
    temp[j] = data[i1];
    i1++;
    j++;
  }

  while (i2 <= to) 
  {
    temp[j] = data[i2];
    i2++;
    j++;
  }

  for (j = 0; j < n; j++) 
  {
    data[from + j] = temp[j];
  }

  delete[] temp;
}

void DataSetSort::swap(Country& a, Country& b) 
{
  Country temp = a;
  a = b;
  b = temp;
}

int DataSetSort::compare(Country a, Country b, int sortChoice) 
{
  switch (sortChoice) 
  {
    case 1:
      return a.getEpi2020() - b.getEpi2020();
    case 2:
      return a.getEpi10yr() - b.getEpi10yr();
    case 3:
      return a.getEpi2022() - b.getEpi2022();
    case 4:
      return a.getCountryName().compare(b.getCountryName());
    default:
      return 0;
  }
}
