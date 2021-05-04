#include <iostream>
#include <string>
#include <vector>
#include "inputhandler.h"
#include "filestuff.h"
#include "mixing.h"
using namespace std;

int main() {
   /* vector<int> current_date;
    current_date.push_back(3);
    current_date.push_back(5);
    current_date.push_back(2021);
    vector<int> a;
    a.push_back(25);
    a.push_back(1);
    a.push_back(2003);
    cout<<calculateAge(current_date,a); test 18,2795*/
    vector<Person> users;
    start(users, "bd");
    int switcher = 0;
    while(switcher != 7)
    {
        cout<<"1 - Add new user\n2 - Delete user\n3 - Find pair\n4 - Watch all users\n5 - Exit"<<endl;
        cin>>switcher;
        cin.ignore(322, '\n');
        if(switcher == 1) users.push_back(inputHandler(users.size()));
        else if(switcher == 2)
        {
            string name;
            cout<<"Enter SNP"<<endl;
            getline(cin,name);
            try {
                users.erase(findName(users, name));
            }
            catch (MyException& e)
            {
                cout<<"Incorrect SNP"<<endl;
            }
        }
        else if(switcher == 3)
        {
            auto p = inputHandler(users.size());
            //vector<Person> test;
            //start(test, "test");
            auto pair = findPair(p, users);
            info(pair);
            cout<<"Enter 1 to accept candidate, enter 2 to exit"<<endl;
            cin>>switcher;
            if(switcher == 1)
            {
                makeMeeting(p, pair);
            }
            else cout<<"Try to find your partner later"<<endl;
        }
        else if(switcher == 4)
        {
            for(int i = 0; i < users.size(); i++)
            {
                info(users[i]);
                cout<<"==========================================================================="<<endl;
            }
        }
        else if(switcher == 5) break;
    }
    end(users, "bd");
    return 0;
}
