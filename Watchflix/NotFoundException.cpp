#include "Headers/pch.h"
#include "Headers/NotFoundException.h"
#include <iostream>
using namespace std;

void FileNotFoundException::getFileName(string f) {
	filename = f;
}

string FileNotFoundException::printMessage() {
	return "File " + filename + " not found!\n";
}

/*
// To distinguish when catching several exceptions - usunac?
class MoviesNotFoundException : public FileNotFoundException {};

class UserSeriesNotFoundException : public FileNotFoundException {};

class SeriesNotFoundException : public FileNotFoundException {};

class StreamsNotFoundException : public FileNotFoundException {};
*/