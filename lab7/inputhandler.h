#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "person.h"
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
using namespace std;

vector<string> split(const std::string& s, char delimiter);

bool validateDate(string date, vector<int>& d);

Person inputHandler(size_t id);


#endif
