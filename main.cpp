#include <iostream>
#include <fstream>
#include <chrono>
#include "Sorting.h"

using namespace std;

int main (int argc, char **argv)
{
  if(argc > 1)
  {
    string inputFile = argv[1]; //grabs second command line argument as a file name
    Sorting sort(inputFile);
    ReadFile rf(inputFile);

    //Bubble Sort Outputs
    cout<<"Bubble Sort"<<endl;
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    sort.BubbleSort(rf.GetLength());
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    auto bubbleDuration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
    cout << bubbleDuration << endl;

    //Insertion Sort Outputs
    cout<<"Insertion Sort"<<endl;
    chrono::high_resolution_clock::time_point t3 = chrono::high_resolution_clock::now();
    sort.InsertionSort(rf.GetLength());
    chrono::high_resolution_clock::time_point t4 = chrono::high_resolution_clock::now();
    auto insertionDuration = chrono::duration_cast<chrono::microseconds>(t4 - t3).count();
    cout << insertionDuration << endl;

    //Selection Sort Outputs
    cout<<"Selction Sort"<<endl;
    chrono::high_resolution_clock::time_point t5 = chrono::high_resolution_clock::now();
    sort.SelectionSort(rf.GetLength());
    chrono::high_resolution_clock::time_point t6 = chrono::high_resolution_clock::now();
    auto selectionDuration = chrono::duration_cast<chrono::microseconds>(t6 - t5).count();
    cout << selectionDuration << endl;;

    //Quick Sort Outputs
    cout<<"Quick Sort"<<endl;
    chrono::high_resolution_clock::time_point t7 = chrono::high_resolution_clock::now();
    sort.QuickSort();
    chrono::high_resolution_clock::time_point t8 = chrono::high_resolution_clock::now();
    auto quickDuration = chrono::duration_cast<chrono::microseconds>(t8 - t7).count();
    cout << quickDuration << endl;
  }

  else
  {
    cout<<"Please make sure your file name is your second command line argument"<<endl;
  }
}
