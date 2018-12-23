#pragma once
#include <string>
using namespace std;

class Stream {
private:
	string title;
	int start;
	int finish;
	int trackedStreams[20];
public:
	void setTrackedStreams(int, bool);
	int getTrackedStreams(int);
	void setTitle(string);
	void setStart(int);
	void setFinish(int);
	void readFile(Stream*, int&);
	void printData(Stream*, int);
	void printTracked(Stream*, int);
	void addStream(int);
	void showReminder(Stream*, int);
	int selectStream(Stream*, int);
};