#include <iostream>
#include "Sorting.h"

using namespace std;

Sorting::Sorting(string path)
{
  file = path;
}

Sorting::~Sorting()
{

}

double* Sorting::BubbleSort(int length)
{
  double *myArray = CreateArray();
  for (int i = 0; i < length; ++i)
	{
		double temp = 0;
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (myArray[j] > myArray[j+1])
			{
				temp = myArray[j+1];
				myArray[j+1] = myArray[j];
				myArray[j] = temp;
			}
		}
	}
  return(myArray);
}

double* Sorting::InsertionSort(int length)
{
  double *myArray = CreateArray();
  for (int i = 0; i < length; ++i)
  {
    double key = myArray[i];

    int j;
    j = i - 1;

    while (j >= 0 && myArray[j] > key)
    {
      myArray[j + 1] = myArray[j];
      j--;

    }
    myArray[j + 1] = key;
  }
  return(myArray);
}

double* Sorting::SelectionSort(int length)
{
  double *myArray = CreateArray();
  int minIndex;
  double temp;
  for(int i = 0; i < length - 1; ++i)
  {
    minIndex = i;
    for(int j = i + 1; j < length; ++j)
    {
      if(myArray[j] < myArray[minIndex])
      {
        minIndex = j;
      }
    }

    temp = myArray[i];
    myArray[i] = myArray[minIndex];
    myArray[minIndex] = temp;
  }
  return(myArray);
}

void Sorting::SetLowHigh(double* array)
{
  high = array[-1];
  low = array[0];
}

int Sorting::GetLow()
{
  return low;
}

int Sorting::GetHigh()
{
  return high;
}

void Sorting::QuickSort()
{
  double *myArray = CreateArray();
  SetLowHigh(myArray);
  QuickSort(myArray, GetLow(), GetHigh());
}

double* Sorting::QuickSort(double* array, int low, int high)
{
  if(low < high)
  {
    int part = Partition(array, low, high);

    QuickSort(array, low, part - 1);
    QuickSort(array, part + 1, high);
  }
}

int Sorting::Partition(double* array, int low, int high)
{
  int pivot = array[high];
  int i = low - 1;
  int temp;

  for(int j = low; j <= high - 1; ++j)
  {
    if(array[j] <= pivot)
    {
      i++;
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  temp = array[i + 1];
  array[i + 1] = array[high];
  array[high] = temp;

  return(i + 1);
}

double* Sorting::CreateArray()
{
  ReadFile* rf = new ReadFile(file);
  vector<double> temp = rf->GetVect();
  array = new double[rf->GetLength()];

  for(int i = 0; i < rf->GetLength(); ++i)
  {
    array[i] = temp[i];
  }
  return array;
}

double* Sorting::PrintArray(double* array, int length)
{
  for(int i = 0; i < length; ++i)
  {
    cout<<array[i]<<" ";
  }
}
