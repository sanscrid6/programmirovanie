#include <string>
#include <vector>
#ifndef PERSON_H
#define PERSON_H
using namespace std;

struct Person
{
    size_t id;
    string SNP;
    int sex;
    vector<int> date;
    double height;
    double weight;
    string city;
    vector<string> interests;
    vector<string> badHabits;
    vector<string> info;
    vector<string> partner;

    Person(size_t id, string SNP, int sex, vector<int> date, double height, double weight, string city, vector<string> interests,
           vector<string> badHabits, vector<string> info, vector<string> partner)
    {
        this->id = id;
        this->SNP = SNP;
        this->sex = sex;
        this->date = date;
        this->city = city;
        this->height = height;
        this->weight = weight;
        this->interests = interests;
        this->badHabits = badHabits;
        this->info = info;
        this->partner = partner;
    }
    Person(){}
};
#endif //CLAB7_PERSON_H
