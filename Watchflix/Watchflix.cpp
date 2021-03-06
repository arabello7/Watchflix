// Watchflix.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>//
#include "Movie.h"
#include "Series.h"
#include "SerialPot.h"
#include "Stream.h"
#include "Advice.h"
#include "Time.h"
#include "Commands.h"
using namespace std;

// Tried to put it to another file
// Used for printing movies and serials
template <class T>
void printData(T* array, int n) {
	if (n <= 0) {
		cout << "<no titles here>\n";
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << "* " << array[i].getTitle() << " " << array[i].getRating() << " " << array[i].getAgeRestriction() << "+ \n";
		}
		cout << endl;
	}
}

// Managing basic commands
int getCommand(Movie* movies, int mNum, Series* series, int sNum, SerialPot* mySeries, Stream* streams, int stNum) {
	streams->printTracked(streams, stNum); // Reminder
	streams->showReminder(streams, stNum); // Playing stream

	string cmd;
	cout << "> Type command: ";
	cin >> cmd;

	if (cmd == "exit") return 0;
	// Not supported. Changing user - every user has its own preferences and list of series
	else if (cmd == "logout") {
		cout << "> Command not supported... BUY DLC at www.watchflix.com/dlc\n";
	}
	// Prints time in app
	else if (cmd == "time") {
		cout << "> Time in app: " << timeNow << " min\n";
	}
	// Skipping time in app
	else if (cmd == "wait") {
		int time;
		cin >> time;
		if (time > 0) {
			cout << "> Time passes by...\n";
			timeNow += time - 5;
		}
		else cout << "> Don't play with time. It's a dangerous thing!\n";
	}
	// Printing list of commands
	else if (cmd == "help") listCommands();
	// Printing all movies
	else if (cmd == "menu") {
		cout << "\n> Movies to select:\n";
		printData(movies, mNum);
		cout << "\n> Series to select:\n";
		printData(series, sNum);
		cout << "\n> Streams to select:\n";
		streams->printData(streams, stNum);
		giveAdvice1();
	}
	// Watching movies instantly
	else if (cmd == "watchmovie") {
		cout << "\n> Movies to select:\n";
		movies->sortByRating(movies, mNum);
		printData(movies, mNum);
		movies->selectMovie(movies, mNum);
	}
	// Adding to reminder
	else if (cmd == "trackstream") {
		cout << "\n> Streams to select:\n";
		streams->printData(streams, stNum);
		streams->selectStream(streams, stNum);
	}
	// Adding to myseries
	else if (cmd == "trackseries") {
		cout << "\n> Series to select:\n";
		series->printData(series, sNum);
		mySeries->selectSeries(series, sNum);
		mySeries->saveFile(series, sNum);
	}
	// Myseries: removing and watching
	else if (cmd == "myseries") {
		mySeries->seriesManager(series, sNum);
		mySeries->saveFile(series, sNum);
	}
	// Changing preferences
	else if (cmd == "chngpref") cout << "<changing preferences>\n";
	else {
		cout << "Wrong command, try again or type help\n";
	}
	// Adding some time from time to time
	timeNow += 5;
	getCommand(movies, mNum, series, sNum, mySeries, streams, stNum);
}

int main() {

	Movie* movies = new Movie[100];
	int moviesNum = 0; //liczba musi byc zapamietana

	int seriesNum = 0;
	Series* series = new Series[100];

	int streamNum = 0;
	Stream* streams = new Stream[20];

	SerialPot* mySeries = new SerialPot;

	// Loading database from files
	loadFiles(movies, moviesNum, series, seriesNum, streams, streamNum, mySeries);

	welcomeYou();
	getCommand(movies, moviesNum, series, seriesNum, mySeries, streams, streamNum);
	
	delete[] movies;
	delete[] series;
	delete[] mySeries;
	delete[] streams;

	return 0;
}