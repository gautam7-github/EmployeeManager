#pragma once
#include <bits/stdc++.h>
#include "data.h"
class admin : public EMPData
{
private:
    vector<EMPData> empl;
    // parameters - EID, FNAME , LNAME , SALARY
    void setter(int, string, string, unsigned int);
    void filereader();
    // parameter - EID to delete employee
    // data in record
    void CSV_delete(int);
    // parameter - EID to serach employee
    // data in record
    bool filesearcher(int);
    // parameter - EID to check if employee
    // already exists in record
    bool alreadyExists(int);
    // ------------------------------------
    // ------------------------------------
public:
    void adminMENU(string);
    void basicDET_SET();
    void basicDET_GET();
    void basicDET_deleteEMP();
    void basicDET_SEARCH();
};