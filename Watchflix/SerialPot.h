#pragma once
#include "pch.h"
#include "Series.h"
#include <fstream>

class SerialPot {
private:
	int trackedSeries[100];
public:
	void setTrackedSeries(int, bool);
	int getTrackedSeries(int);
	void printData(Series*, int);
	// !przeci¹¿enie operatora
	void addSeries(int);
	// !przeci¹¿enie operatora
	void removeSeries(Series*, int);
	void saveFile(Series*, int);
	void readFile(Series*);
	void watchSeries(int, Series*);
	int seriesManager(Series*, int);
	int selectSeries(Series*, int);
	void whenFinishWatching(Series*, int);
};