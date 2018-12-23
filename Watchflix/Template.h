#pragma once
#include "pch.h"
#include <string>
using namespace std;

// Print data useful for selecting movie
// Using template I can pass any object type as argument
template <class T>
class Temp {
public:
	void printData(T* array, int n);
	int returnIndex(string searched, T* array, int num);
};