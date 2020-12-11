#pragma once
#include <bits/stdc++.h>
#include "data.h"
class admin : public EMPData
{
private:
    vector<EMPData> empl;
    vector<string> adminData;
    // parameters - EID, FNAME , LNAME , SALARY
    void setter(int, string, string, string);
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
    void UI_mainBranding();

public:
    void adminMENU(string, string);
    void basicDET_SET();
    void basicDET_GET();
    void basicDET_deleteEMP();
    void basicDET_SEARCH();
};