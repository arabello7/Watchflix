#include "pch.h"
#include "Stream.h"
#include "Time.h"
#include "Commands.h"
#include <iostream>
#include <fstream>

int timeNow;

void Stream::setTrackedStreams(int index, bool x) {
	trackedStreams[index] = x;
}

int Stream::getTrackedStreams(int index) {
	return trackedStreams[index];
}

void Stream::setTitle(string t) {
	title = t;
}

void Stream::setStart(int s) {
	start = s;
}

void Stream::setFinish(int f) {
	finish = f;
}

void Stream::readFile(Stream* st, int& stNum) {
	ifstream file("Files/streams.txt");
	if (!file.good()) {
		throw (string) "streams.txt";
	}
	else {
		int i = 0;
		while (!file.eof()) {
			string t;
			int start, fin;
			file >> t >> start >> fin;
			Stream s;
			s.setTitle(t);
			s.setStart(start);
			s.setFinish(fin);
			st[i] = s;
			i++;
		}
		stNum = i; // Saving number of streams
		file.close();
	}
}

// Printing streams that are still available in current time
void Stream::printData(Stream* st, int stNum) {
	for (int i = 0; i < stNum; i++) {
		if (timeNow < st[i].finish) {
			if (timeNow > st[i].start) cout << "* " << st[i].title << " now streaming\n";
			else cout << "* " << st[i].title << " in " << st[i].start - timeNow << " min\n";
		}
	}
}

// Reminder which prints streams choosen in trackstream
void Stream::printTracked(Stream*st, int stNum) {
	for (int i = 0; i < stNum; i++) {
		if (getTrackedStreams(i) == 1 && st[i].finish > timeNow) {
			cout << "> Reminder: " << st[i].title << " in " << st[i].start - timeNow << " min\n";
		}
	}
}

// Adding stream to tracking list (reminder)
void Stream::addStream(int index) {
	setTrackedStreams(index, 1);
	cout << "> Added to your tracked list\n";
}

// Playing stream when it's right time for it and player is not busy
void Stream::showReminder(Stream* st, int stNum) {
	for (int i = 0; i < stNum; i++) {
		if (getTrackedStreams(i) == 1) {
			if (st[i].start <= timeNow && st[i].finish > timeNow) {
				cout << "> Playing " << st[i].title << " stream...\n";
				timePass(st[i].finish - timeNow);
				setTrackedStreams(i, 0);
			}
		}
	}
}

// Selecting stream to track (uses addStream)
int Stream::selectStream(Stream* st, int stNum) {
	cout << "> Type stream to track:\n";
	string title;
	cin >> title;

	if (goBack(title) == 1) return 0; // Back command

	int check = 0;
	for (int i = 0; i < stNum; i++) {
		if (title == st[i].title && (st[i].finish - timeNow > 0)) {
			addStream(i);
			check++;
		}
	}
	if (check == 0) cout << "> No such stream in database! Try again or type 'back'\n";
	selectStream(st, stNum);
}