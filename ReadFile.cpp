#include <iostream>
#include "ReadFile.h"
#include <sstream>

using namespace std;

ReadFile::ReadFile(string path)
{
  ifstream file(path);
  string line;

  getline(file, line);
  arrayLength = stoi(line);

  for(int i = 0; i < arrayLength; ++i)
  {
    while(getline(file, line))
    {
      vect.push_back(stoi(line));
    }
  }
}

ReadFile::~ReadFile()
{

}

int ReadFile::GetLength()
{
  return arrayLength;
}

vector<double> ReadFile::GetVect()
{
  return vect;
}
