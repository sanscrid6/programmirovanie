#include "filestuff.h"
void start(vector<Person>& users, string name) {
    ifstream in;
    in.open(name+".txt");
    string s;
    while (!in.eof()) {
        string temp;
        string name;
        string city;
        getline(in ,temp);
        if(in.eof()) break;
        getline(in, temp);
        int id = stoi(temp);
        getline(in, name);
        getline(in, temp);
        int sex = stoi(temp);
        vector<int> date;
        getline(in, temp);
        validateDate(temp, date);
        getline(in, temp);
        double height = stod(temp);
        getline(in, temp);
        double weight = stod(temp);
        getline(in, city);
        vector<string> interests;
        do {
            getline(in, temp);
            if(temp != "interests") interests.push_back(temp);
        } while(temp != "interests");
        vector<string> badHabits;
        do {
            getline(in, temp);
            if(temp != "bad habits") badHabits.push_back(temp);
        } while(temp != "bad habits");
        vector<string> info;
        do {
            getline(in, temp);
            if(temp != "info") info.push_back(temp);
        } while(temp != "info");
        vector<string> partner;
        do {
            getline(in, temp);
            if(temp != "partner") partner.push_back(temp);
        } while(temp != "partner");
        users.emplace_back(Person(id, name, sex, date, height, weight, city, interests, badHabits, info, partner));
    }
    in.close();
}
void end(vector<Person>& users, string name)
{
    ofstream of;
    of.open(name + ".txt");
    for(auto it = users.begin(); it!=users.end(); ++it) {
        of<<endl;
        of<<it->id<<endl;
        of<<it->SNP<<endl;
        of<<it->sex<<endl;
        of<<it->date[0]<<":"<<it->date[1]<<":"<<it->date[2]<<endl;
        of<<it->height<<endl;
        of<<it->weight<<endl;
        of<<it->city<<endl;
        for(int i = 0 ; i<it->interests.size(); i++) of<<it->interests[i]<<endl;
        of<<"interests"<<endl;
        for(int i = 0 ; i<it->badHabits.size(); i++) of<<it->badHabits[i]<<endl;
        of<<"bad habits"<<endl;
        for(int i = 0 ; i<it->info.size(); i++) of<<it->info[i]<<endl;
        of<<"info"<<endl;
        for(int i = 0 ; i<it->partner.size(); i++) of<<it->partner[i]<<endl;
        of<<"partner"<<endl;
    }
    of.close();
}