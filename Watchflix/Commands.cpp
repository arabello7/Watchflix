#include "pch.h"
#include "Commands.h"
#include <string>
#include <iostream>
using namespace std;

int goBack(string cmd) {
	if (cmd == "back") {
		return 1;
	}
	return 0;
}

// Loading movies, series, streams and user series from files
void loadFiles(Movie* m, int& mNum, Series* s, int& sNum, Stream* st, int& stNum, SerialPot* myS) {
	try {
		m->readFile(m, mNum);
		s->readFile(s, sNum);
		st->readFile(st, stNum);
		myS->readFile(s);
	}
	catch (string s) {
		cout << "> File not found: " << s << "!\n";
	}
	catch (...) {
		cout << "> File error!\n";
	}
}
