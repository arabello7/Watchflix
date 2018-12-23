#include "pch.h"
#include "Series.h"
#include <iostream>
#include <fstream>
using namespace std;

int Series::getNumOfEpisodes() {
	return numOfEpisodes;
}

void Series::setNumOfEpisodes(int n) {
	numOfEpisodes = n;
}

int Series::getWatchedEpisodes() {
	return watchedEpisodes;
}

void Series::setWatchedEpisodes(int num) {
	watchedEpisodes = num;
}

//@override
void Series::printData(Series* array, int n) {
	if (n <= 0) {
		cout << "<no titles here>\n"; //exception
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << "* " << array[i].getTitle() << " " << array[i].getRating() << " " << array[i].getAgeRestriction() << "+ \n";
		}
		cout << endl;
	}
}

//@override
void Series::readFile(Series* series, int& n) {
	ifstream file("Files/series.txt");
	if (!file.good()) {
		throw (string) "series.txt";
	}
	else {
		int i = 0;
		while (!file.eof()) {
			Series s;
			string t;
			float r;
			int d, a, num;
			file >> t >> r >> d >> a >> num;
			s.setTitle(t);
			s.setRating(r);
			s.setDuration(d);
			s.setAgeRestriction(a);
			s.setNumOfEpisodes(num);
//			file >> m.percOfLaugh; //MOVIEFLIX v2
//			file >> m.percOfRealism;
//			file >> m.percOfViolence;
			series[i] = s;
			i++;
		}
		n = i; // Saving number of series
		file.close();
	}
}

// Finding index of series in array using title
int Series::returnIndex(string searched, Series* array, int num) {
	for (int i = 0; i < num; i++) {
		if (array[i].getTitle() == searched) {
			return i;
		}
	}
	return -1;
}