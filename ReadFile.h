#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class ReadFile
{
  public:
    ReadFile(string path);
    ~ReadFile();

    int GetLength();
    vector<double> GetVect();

    ifstream inputFile;
    vector<double> vect;
    int arrayLength;
    double* myArray;
};
