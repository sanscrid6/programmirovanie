#include <string>
#include <vector>
#include <iostream>
#include "inputhandler.h"
using namespace std;

vector<string> split(const std::string& s, char delimiter)
{
    vector<std::string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

bool validateDate(string date, vector<int>& d)
{
    vector<string> temp = split(date, ':');
    if(temp.size() != 3) return false;
    for(size_t i = 0; i <temp.size(); i++)
    {
        for(size_t j = 0; j <temp[i].size(); j++)
        {
            if(!isdigit(temp[i][j]) && temp[i][j] != ':') return false;
        }
    }
    for(size_t i = 0; i < temp.size(); i++)
    {
        d.push_back(stoi(temp[i]));
    }
    if(d[2] > 2021) return false;
    if(d[1] == 2 && (d[0]<0 || d[0]>28)) return false;
    if((d[1] == 1 || d[1] == 3 || d[1] == 5 || d[1] == 7 || d[1] == 8 || d[1] == 10 || d[1] == 12) && (d[0]<0 || d[0]>31))
        return false;
    if((d[1] == 4 || d[1] == 6 || d[1] == 9 || d[1] == 11) && (d[0]<0 || d[0]>30)) return false;
    return true;
}

Person inputHandler(size_t id)
{
    bool check = false;
    string SNP;
    do {
        cout<<"Enter SNP"<<endl;
        getline(cin, SNP);
        check = false;
        for(size_t i = 0; i<SNP.size(); i++)
        {
            if (!isalpha(SNP[i]))
            {
                cout<<"Incorrect SNP"<<endl;
                check = true;
                break;
            }
        }

    } while(check);

    int sex;
    do {
        cout << "Enter sex(1 - male, 0 - female)" << endl;
        cin >> sex;
        cin.ignore(322, '\n');
        check = false;
        if (sex != 1 && sex != 0)
        {
            cout<<"Incorrect sex"<<endl;
            check = true;
        }

    }while(check);

    string date;
    vector<int> d;
    do{
        cout<<"Enter date"<<endl;
        getline(cin, date);
        if(!validateDate(date,d)) cout<<"Incorrect date"<<endl;
    } while(!validateDate(date, d));

    double height;
    do {
        string h;
        cout<<"Enter height"<<endl;
        cin>>h;
        cin.ignore(322, '\n');
        check = false;
        int dot = 0;
        if(h[0] == '-' || !isdigit(h[0]))
        {
            cout<<"Incorrect height"<<endl;
            check=true;
        }
        else
        {
            for(size_t i = 1; i<h.size(); i++)
            {
                if(h[i] == '.')
                {
                    dot++;
                }
                else if(dot > 0 && h[i] == '.')
                {
                    cout<<"Incorrect height"<<endl;
                    check = true;
                    break;
                }
                else if(!isdigit(h[i]))
                {
                    cout<<"Incorrect height"<<endl;
                    check = true;
                    break;
                }

            }
        }
    } while(check);

    double weight;
    do {
        string w;
        cout<<"Enter weight"<<endl;
        cin>>w;
        cin.ignore(322, '\n');
        check = false;
        int dot = 0;
        if(w[0] == '-' || !isdigit(w[0]))
        {
            check=true;
            cout<<"Incorrect weight"<<endl;
        }
        else
        {
            for(size_t i = 1; i<w.size(); i++)
            {
                if(w[i] == '.')
                {
                    dot++;
                }
                else if(dot > 0 && w[i] == '.')
                {
                    cout<<"Incorrect weight"<<endl;
                    check = true;
                    break;
                }
                else if(!isdigit(w[i]))
                {
                    cout<<"Incorrect weight"<<endl;
                    check = true;
                    break;
                }
            }
        }
    }while(check);

    cout<<"Enter your city"<<endl;
    string city;
    cin>>city;

    vector<string> interests;
    do {
        cout<<"Enter one of your interests(enter 0 to break)"<<endl;
        string str;
        cin>>str;
        if(str == "0") break;
        interests.push_back(str);
    }while(true);

    vector<string> badHabits;
    do {
        cout<<"Enter one of your bad habits(enter 0 to break)"<<endl;
        string str;
        cin>>str;
        if(str == "0") break;
        badHabits.push_back(str);
    }while(true);

    vector<string> info;
    do {
        cout<<"Enter one of your characters(enter 0 to break)"<<endl;
        string str;
        cin>>str;
        if(str == "0") break;
        info.push_back(str);
    }while(true);

    vector<string> partner;
    do {
        cout<<"Enter info about your ideal partner"<<endl;
        string str;
        cin>>str;
        if(str == "0") break;
        partner.push_back(str);
    }while(true);

    Person p(id, SNP, sex, d, height, weight, city, interests, badHabits, info, partner);
    return p;
}
