#include "pch.h"
#include "Advice.h"
#include <iostream>
using namespace std;

void welcomeYou() {
	cout << "Welcome to MOVIEFLIX: command-based app for watching movies!\n\n";
//	cout << "Type login or signup\n"; //MOVIEFLIX v2
	cout << "Useful commands: menu / watchmovie / trackstream / trackseries / myseries / time / logout / exit\n";
	cout << "Use them in turns with 'back' command to move through interface\n";
	cout << "You can type 'help' for more information\n\n";
}

void giveAdvice1() {
	cout << "\n> Now use: watchmovie / trackseries / myseries / trackstream\n";
}

void listCommands() {
	cout << "menu - menu appears with all staff \nwatchmovie - you can choose movie to watch now\n";
	cout << "trackstream - select stream that you will get notifications about and will play in right time";
	cout << "\ntrackseries - select series to put on your watching list\n";
	cout << "myseries - shows list of your tracked series. You either watch or manage them\n";
	cout << "chngpref <unavailable> - change your settings used to find best movies for you\n";
	cout << "time - shows current time in app [in minutes]\nwait - use it with number as minutes to skip time";
	cout << "logout <unavailable> - go to welcome screen and change user \nexit - leave the app\n";
}