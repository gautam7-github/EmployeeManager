#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "data.h"
using namespace std;
class admin
{
private:
    vector<EMPData> empl;
    // parameters - EID, FNAME , LNAME , SALARY
    void setter(int EID, string FN, string LN, unsigned int SL)
    {
        EMPData *E = new (nothrow) EMPData;
        E->set_eid(EID);
        E->set_fname(FN);
        E->set_lname(LN);
        E->set_salary(SL);

        empl.push_back(*E);
        delete E;
    }
    void getter()
    {
        int looper = 0;
        vector<EMPData>::iterator IT;
        for (IT = empl.begin(); IT != empl.end(); IT++)
        {
            cout << "EMPLOYEE -> " << looper + 1 << endl;
            cout << "EMPLOYEE ID: " << IT->get_eid() << endl;
            cout << "FIRST NAME : " << IT->get_fname() << endl;
            cout << "LAST NAME  : " << IT->get_lname() << endl;
            cout << "SALARY     : " << IT->get_salary() << endl;
            cout << "-------------------" << endl;
            looper++;
        }
    }
    void deleter(string findN1, string findN2)
    {
        bool pos = true;
        vector<EMPData>::iterator T;
        T = empl.begin();
        while (T != empl.end())
        {
            if (T->get_fname() == findN1 && T->get_lname() == findN2)
            {
                empl.erase(T);
                pos = false;
                break;
            }
            T++;
        }
        if (pos)
            cout << "NOT FOUND..." << endl;
    }

public:
    void adminMENU()
    {
        int choice;
        bool flag = true;
        while (flag)
        {
            cout << "SET , GET , EXIT" << endl;
            cout << "WHAT ? " << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                basicDET_SET();
                break;
            case 2:
                basicDET_GET();
                break;
            case 3:

                basicDET_deleteEMP();
                break;
            default:
                flag = false;
                break;
            }
        }
    }
    void basicDET_SET()
    {
        string *FN = new (nothrow) string;
        string *LN = new (nothrow) string;
        unsigned int *SL = new unsigned int;
        int *EiD = new (nothrow) int;
        // buffer clearer
        cin.sync();
        // first name
        cout << "FNAME : ";
        getline(cin, *FN);
        // last name
        cout << "LNAME : ";
        getline(cin, *LN);
        // salary
        cout << "SLRY  : ";
        cin >> *SL;
        // calls setter method
        setter(*EiD, *FN, *LN, *SL);
        delete FN, LN, SL;

        cout << "-----------" << endl;
    }
    void basicDET_GET()
    {
        getter();
    }
    void basicDET_deleteEMP()
    {
        string fname, lname;
        cout << "ENTER NAME TO REMOVE (FULL) : ";
        cin >> fname >> lname;
        // calls deleter method
        deleter(fname, lname);
    }
};
int main()
{
    admin SUDO;
    SUDO.adminMENU();
    return 0;
}