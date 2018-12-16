#include <iostream>
#include <string>
#include "ReadFile.h"

using namespace std;

class Sorting
{
  public:
    Sorting(string path);
    ~Sorting();

    int high;
    int low;
    double* array;
    string file;

    void SetLowHigh(double* array);
    int GetLow();
    int GetHigh();

    double* BubbleSort(int length);
    double* InsertionSort(int length);
    void QuickSort();
    double* QuickSort(double* array, int low, int high);
    double* SelectionSort(int length);
    int Partition(double* array, int low, int high);

    double* CreateArray();
    double* PrintArray(double* array, int length);
};
