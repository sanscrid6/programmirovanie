#include "mixing.h"

vector<Person>::iterator findName(vector<Person>& users, const string& key)
{
    for(auto it = users.begin(); it != users.end(); ++it)
    {
        if(it->SNP == key) return it;
    }
    throw MyException("Not found");
}



double calculateAge(vector<int> date1, vector<int> date2)
{
    int year = date1[2] - date2[2];
    int day = date1[0] - date2[0];
    int month = date1[1] - date2[1];
    if(day<0)
    {
        day = 31+day;
        month--;
    }
    if(month<0)
    {
        year--;
        month = 12+month;
    }
    double age = (double)(month*31 + day + year*365)/365;
    return age;
}

Person findPair(Person p, vector<Person>& users)
{
    vector<int> current_date;
    current_date.push_back(3);
    current_date.push_back(5);
    current_date.push_back(2021);
    vector<Characteristic> stats;
    Person partner;
    double max_perc = 0;
    int num = 0;
    for(int i = 0; i < p.partner.size(); i++)
    {
        auto temp = split(p.partner[i],':');
        for(int i = 0; i<temp[0].size(); i++)
        {
            temp[0][i] = tolower(temp[0][i]);
        }
        if(temp[0] == "height" || temp[0] == "weight" || temp[0] == "age")
        {
            auto values = split(temp[1],'-');
            stats.push_back(Characteristic(temp[0], values));
        }
        else if(temp[0] == "city" || temp[0] == "bad habits" || temp[0] == "interests" || temp[0] == "info")
        {
            auto values = split(temp[1],',');
            stats.push_back(Characteristic(temp[0], values));
        }
    }
    int partnerSex = p.sex == 0? 1: 0;
    for(int i = 0; i < users.size(); i++)
    {
        int counter = 0;
        int amount = 0;
        if(users[i].sex == partnerSex)
        {
            for(int j = 0; j < stats.size(); j++)
            {
                if(stats[j].name == "height")
                {
                    try
                    {
                        double less = stod(stats[j].values[0]);
                        double more = stod(stats[j].values[1]);
                        if(users[i].height <= more && users[i].height >= less)
                        {
                            counter++;
                        }
                        amount++;
                    }
                    catch (...)
                    {}
                }
                else if(stats[j].name == "weight")
                {
                    try
                    {
                        double less = stod(stats[j].values[0]);
                        double more = stod(stats[j].values[1]);
                        if(users[i].weight <= more && users[i].weight >= less)
                        {
                            counter++;
                        }
                        amount++;
                    }
                    catch(...)
                    {}
                }
                else if(stats[j].name == "age")
                {
                    try
                    {
                        double less = stoi(stats[j].values[0]);
                        double more = stoi(stats[j].values[1]);
                        double age =calculateAge(current_date,users[i].date);
                        if(age <= more && age >= less)
                        {
                            counter++;
                        }
                        amount++;
                    }
                    catch (...)
                    {}

                }
                else if(stats[j].name == "interests")
                {
                    for(int k = 0; k < stats[j].values.size(); k++)
                    {
                        for(int h = 0; h < users[i].interests.size(); h++)
                        {
                            if(stats[j].values[k] == users[i].interests[h]) counter++;
                            if(k == 0) amount++;
                        }
                    }
                }
                else if(stats[j].name == "bad habits")
                {
                    for(int k = 0; k < stats[j].values.size(); k++)
                    {
                        for(int h = 0; h < users[i].badHabits.size(); h++)
                        {
                            if(stats[j].values[k] == users[i].badHabits[h]) counter++;
                            if(k == 0) amount++;
                        }
                    }
                }
                else if(stats[j].name == "info")
                {
                    for(int k = 0; k < stats[j].values.size(); k++)
                    {
                        for(int h = 0; h < users[i].info.size(); h++)
                        {
                            if(stats[j].values[k] == users[i].info[h]) counter++;
                            if(k == 0) amount++;
                        }
                    }
                }
                else if(stats[j].name == "city")
                {
                    for(int k = 0; k < stats[j].values.size(); k++)
                    {
                        if(users[i].city == stats[j].values[k])
                        {
                            counter++;
                            break;
                        }
                    }
                    amount++;
                }
            }
        }
        if((double)counter/amount >= max_perc)
        {
            num = i;
            max_perc = (double)counter/amount;
        }
    }
    return users[num];
}

void info(const Person& p)
{
    vector<int> current_date;
    current_date.push_back(3);
    current_date.push_back(5);
    current_date.push_back(2021);
    cout<<"SNP is "<<p.SNP<<endl;
    string sex = p.sex == 1? "Male" : "Female";
    cout<<"Sex is "<<sex<<endl;
    cout<<"Age is "<< (int) calculateAge(current_date, p.date)<<endl;
    cout<<"Height is "<<p.height<<endl;
    cout<<"Weight is "<<p.weight<<endl;
    cout<<"City is "<<p.city<<endl;
    cout<<"Interests are:"<<endl;
    for(int i = 0; i<p.interests.size(); i++)
        cout<<p.interests[i]<<endl;
    cout<<"Bad habits are:"<<endl;
    for(int i = 0; i<p.badHabits.size(); i++)
        cout<<p.badHabits[i]<<endl;
    cout<<"Information about is:"<<endl;
    for(int i = 0; i<p.info.size(); i++)
        cout<<p.info[i]<<endl;
    cout<<"Info about partner is:"<<endl;
    for(int i = 0; i<p.partner.size(); i++)
        cout<<p.partner[i]<<endl;
}


void makeMeeting(Person p1, Person p2)
{
    ofstream p1Invitation;
    p1Invitation.open("Invitation");
    p1Invitation<<"Dear "<<p2.SNP<<". I am "<<p1.SNP<<",my ancet id is "<<p1.id<<". Do you want to meet with me at 12:12 at Friday."<<endl;
    p1Invitation.close();
}