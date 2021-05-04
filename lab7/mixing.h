#ifndef MIXING_H
#define MIXING_H
#include <exception>
#include <iostream>
#include <fstream>
#include <vector>
#include "person.h"
#include "inputhandler.h"
using namespace std;

class MyException: public exception
{
    string error;
public:
    MyException(const string& er){error = er;}
    string getError(){return error;}
};

struct Characteristic
{
    string name;
    vector<string> values;
    Characteristic(const string& name, const vector<string>& values)
    {
        this->name = name;
        this->values = values;
    }
};

double calculateAge(vector<int> date1, vector<int> date2);

vector<Person>::iterator findName(vector<Person>& users, const string& key);

Person findPair(Person p, vector<Person>& users);

void info(const Person& p);

void makeMeeting(Person p1, Person p2);

#endif
