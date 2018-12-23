#ifndef Series_H
#define Series_H
#include "movie.h"
#include <iostream>
#include <string>
using namespace std;

class Series : public Movie {
private:
	int numOfEpisodes;
	int watchedEpisodes = 0;
public:
	int getNumOfEpisodes();
	void setNumOfEpisodes(int);
	int getWatchedEpisodes();
	void setWatchedEpisodes(int);
	void readFile(Series*, int&);
	void printData(Series*, int);
	int returnIndex(string, Series*, int);
};

#endif