#pragma once
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class FileNotFoundException {
private:
	string filename;
public:
	void getFileName(string f);
	string printMessage();
};
/*
// To distinguish when catching several exceptions - usunac?
class MoviesNotFoundException : public FileNotFoundException {};

class UserSeriesNotFoundException : public FileNotFoundException {};

class SeriesNotFoundException : public FileNotFoundException {};

class StreamsNotFoundException : public FileNotFoundException {};
*/