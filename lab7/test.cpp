#include <iostream>
#include <string>
#include <vector>
#include "inputhandler.h"
#include "filestuff.h"
#include "mixing.h"
#include <assert.h>
using namespace std;
void test()
{
    vector<int> current_date;
    current_date.push_back(3);
    current_date.push_back(5);
    current_date.push_back(2021);
    vector<int> a;
    a.push_back(25);
    a.push_back(1);
    a.push_back(2003);
    double age = calculateAge(current_date,a);
    assert(abs(age - 18.3) < 0.1);
    vector<Person> users;
    start(users, "bd");
    assert(users.size() == 2);
    assert(users[0].SNP == "Vitaliy Tsal");
    assert(users[1].SNP == "Vladislav Sinotov");
    string name = "Vitaliy Tsal";
    auto p = findName(users, name);
    assert((*p).SNP == name);
    try {
        findName(users,"asd");
    }
    catch(MyException& e)
    {
        assert(e.getError() == "Not found");
    }
    string temp = "asd:qwe";
    auto splitted = split(temp, ':');
    assert(splitted[0] == "asd");
    assert(splitted[1] == "qwe");
    string date1 = "30:2:2000";
    vector<int> d;
    assert(validateDate(date1, d) == false);
    d.clear();
    string date2 = "30:1:2000";
    assert(validateDate(date2, d) == 1);
    vector<Person> testPerson;
    start(testPerson, "test");
    auto testPair = findPair(testPerson[0], users);
    assert(testPair.SNP == "Vitaliy Tsal");
    assert(testPair.id == 0);
    info(testPair);
    makeMeeting(testPerson[0], testPair);
    end(users, "testBd");
}

int main()
{
    test();
    cout<<"Tests passed"<<endl;
    return 0;
}