#pragma once
#include "pch.h"
#include "movie.h"
#include "SerialPot.h"
#include "Series.h"
#include "Stream.h"
#include <iostream>
#include <string>

int goBack(std::string );
void loadFiles(Movie*, int&, Series*, int&, Stream*, int&, SerialPot*);