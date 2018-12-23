#include "pch.h"
#include "Movie.h"
#include "Time.h"
#include "Commands.h"
#include "Time.h"
#include <fstream>
using namespace std;

void Movie::setTitle(string t) {
	title = t;
}

string Movie::getTitle() {
	return title;
}

void Movie::setRating(float r) {
	rating = r;
}

float Movie::getRating() {
	return rating;
}

void Movie::setDuration(int d) {
	duration = d;
}

int Movie::getDuration() {
	return duration;
}

void Movie::setAgeRestriction(int a) {
	ageRestriction = a;
}

int Movie::getAgeRestriction() {
	return ageRestriction;
}

// Selecting movie to watch now
int Movie::selectMovie(Movie* m, int mNum) {
	string title;
	cout << "Type title to watch:\n";
	cin >> title;
	
	if (goBack(title) == 1) return 0; //Back command

	int index = m->returnIndex(title, m, mNum);
	if (index == -1) {
		cout << "> No such movie in database!\n";
		selectMovie(m, mNum);
	}
	else {
		cout << "> Now playing " << title << "...\n";
		//Sleep(m[index].getDuration() * 40);
		timePass(m[index].getDuration()); // Changing app time
	}
	selectMovie(m, mNum);
}

void Movie::readFile(Movie* movies, int& n) {
	ifstream file("Files/movies.txt");
	if (!file.good()) {
		throw (string) "movies.txt";
	}
	else {
		int i = 0;
		while (!file.eof()) {
			Movie m;
			string t;
			float r;
			int d, a;
			file >> t >> r >> d >> a;
			m.setTitle(t);
			m.setRating(r);
			m.setDuration(d);
			m.setAgeRestriction(a);
//			file >> m.percOfLaugh; //MOVIEFLIX v2
//			file >> m.percOfRealism;
//			file >> m.percOfViolence;
			movies[i] = m;
			i++;
		}
		n = i;
		file.close();
	}
}

// Returns index of the movie in array by title
int Movie::returnIndex(string searched, Movie* array, int num) {
	for (int i = 0; i < num; i++) {
		if (array[i].getTitle() == searched) {
			return i;
		}
	}
	return -1;
}

// Sorting movies by rating
void Movie::sortByRating(Movie* m, int mNum) {
	for (int i = 0; i < mNum; i++)
		for (int j = 0; j < mNum - 1; j++) {
			if (m[j].getRating() < m[j + 1].getRating())
				swap(m[j], m[j + 1]);
		}
}