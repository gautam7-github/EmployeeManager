#pragma once
#include <string>
using namespace std;
class EMPData
{
private:
    int eID;
    string fname;
    string lname;
    unsigned int salary;
    string dept;

public:
    //getter
    int get_eid();
    // setter
    void set_eid(int);
    // getter
    string get_fname();
    // setter
    void set_fname(string);
    // getter
    string get_lname();
    // setter
    void set_lname(string);
    // getter
    unsigned int get_salary();
    // setter
    void set_salary(unsigned int);
    // getter
};