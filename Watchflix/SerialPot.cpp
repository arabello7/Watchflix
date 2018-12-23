#include "pch.h"
#include "SerialPot.h"
#include "Commands.h"
#include "Time.h"

void SerialPot::setTrackedSeries(int index, bool x) {
	trackedSeries[index] = x;
}

int SerialPot::getTrackedSeries(int i) {
	return trackedSeries[i];
}

// Printing series in users list
void SerialPot::printData(Series* s, int sNum) {
	for (int i = 0; i < sNum; i++) {
		if (getTrackedSeries(i) == 1) cout << s[i].getTitle() << " " << s[i].getWatchedEpisodes() << "/" << s[i].getNumOfEpisodes() << "\n";
	}
}

// !przeci¹¿enie operatora
void SerialPot::addSeries(int select) {
	if (getTrackedSeries(select) == 1) {
		cout << "> Already in your collection!\n"; //exception
	}
	else {
		setTrackedSeries(select, 1);
		cout << "> Added to your collection.\n";
	}
}

// !przeci¹¿enie operatora
void SerialPot::removeSeries(Series* s, int select) {
	setTrackedSeries(select, 0);
	s[select].setWatchedEpisodes(0);
	cout << "> Removed from your collection.\n";
}

void SerialPot::saveFile(Series* s, int sNum) { //nazwa pliku od nazwy usera //MOVIEFLIX v2
	ofstream file("Files/user-series.txt");
	if (!file.good()) {
		throw (string) "user-series.txt";
	}
	else {
		for (int i = 0; i < sNum; i++) {
			file << getTrackedSeries(i) << " " << s[i].getWatchedEpisodes() << "\n";
		}
		file.close();
	}
}

void SerialPot::readFile(Series* s) {
	ifstream file("Files/user-series.txt");
	if (!file.good()) {
		throw (string) "user-series.txt";
	}
	else {
		int i = 0;
		while (!file.eof()) {
			int episode, x;
			file >> x >> episode;
			setTrackedSeries(i, x);
			s[i].setWatchedEpisodes(episode);
			i++;
		}
		file.close();
	}
}

void SerialPot::watchSeries(int index, Series* s) {
	// Choosing next episode to play
	int episode = s[index].getWatchedEpisodes() + 1;
	if (s[index].getNumOfEpisodes() < episode) cout << "> You have finished watching this series!\n";
	else {
		cout << "> Watching now episode " << episode << "...\n";
		s[index].setWatchedEpisodes(episode);
		timePass(s[index].getDuration());
	}
}

void SerialPot::whenFinishWatching(Series* s, int sNum) {
	int time = 0;
	for (int i = 0; i < sNum; i++) {
		if (getTrackedSeries(i) == 1) {
			time += s[i].getDuration() * (s[i].getNumOfEpisodes() - s[i].getWatchedEpisodes());
		}
	}
	if (time > 0) cout << "> You have " << time << " minutes left before you finish watching :)\n";
}

// Watching or removing from user collection
int SerialPot::seriesManager(Series* s, int sNum) {
	printData(s, sNum); // Different printData than in Series class
	whenFinishWatching(s, sNum);
	cout << "> Use commands 'watch' or 'remove' with title of the series after\n";
	string cmd, title;
	cin >> cmd;
	if (goBack(cmd) == 1) return 0; //Back command
	cin >> title;

	// Looking for title in tracked series
	int index = s->returnIndex(title, s, sNum);
	if (index == -1 || getTrackedSeries(index) == 0) {
		cout << "> No such series in your list!\n";
	}
	else if (cmd == "watch") watchSeries(index, s);
	else if (cmd == "remove") removeSeries(s, index);
	else {
		cout << "Wrong command, try again or type 'back'\n";
	}
	seriesManager(s, sNum);
}

// Selecting series to add to user collection
int SerialPot::selectSeries(Series* s, int sNum) {
	cout << "> Type title to add to your list:\n";
	string title;
	cin >> title;

	if (goBack(title) == 1) return 0; // Back command

	int index = s->returnIndex(title, s, sNum);
	if (index == -1) cout << "> No such series in database!\n";
	else addSeries(index);
	selectSeries(s, sNum);
}