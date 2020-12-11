#include <iostream>
#include <string>
#include "data.h"
using namespace std;
// methods - getter and setter
int EMPData::get_eid()
{
    return eID;
}
void EMPData::set_eid(int Eid)
{
    this->eID = Eid;
}
string EMPData::get_fname()
{
    return fname;
}
void EMPData::set_fname(string Fname)
{
    this->fname = Fname;
}
string EMPData::get_lname()
{
    return lname;
}
void EMPData::set_lname(string Lname)
{
    this->lname = Lname;
}
string EMPData::get_salary()
{
    return salary;
}
void EMPData::set_salary(string Salary)
{
    this->salary = Salary;
}