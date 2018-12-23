#ifndef Movie_H
#define Movie_H
#include <iostream>
#include <string>
using namespace std;

class Movie {
private:	//! settery trzeba dac
	string title;
	float rating;
	int duration;
	int ageRestriction;
	// Data for preferations //MOVIEFLIX v2
	string famousActors[5];
	float percOfLaugh;
	float percOfViolence;
	float percOfRealism;
public:
	void setTitle(string);
	string getTitle();
	void setRating(float);
	float getRating();
	void setDuration(int);
	int getDuration();
	void setAgeRestriction(int);
	int getAgeRestriction();

	void sortByRating(Movie*, int);
	int selectMovie(Movie*, int);
	virtual void readFile(Movie*, int&);
	int returnIndex(string, Movie*, int);
};

#endif //Movie_H