#include "pch.h"
#include "Time.h"
#include <iostream>
#include <windows.h>
using namespace std;

void timePass(int minutes) {
	Sleep(minutes * 40);
	cout << minutes << " minutes passed...\n";
	timeNow += minutes;
	cout << "> Time spend in app: " << timeNow << endl;
}
