// ADMIN.CPP -> FILE
#include <bits/stdc++.h>
#include "admin.h"
using namespace std;

// vector to store instances of EMPData Class
std::vector<admin::EMPData> empl;
void admin::UI_mainBranding()
{
    cout << R"(

                  _   ______   _____    __  __    _____ 
                 (_) |  ____| |  __ \  |  \/  |  / ____|
                  _  | |__    | |  | | | \  / | | (___  
                 | | |  __|   | |  | | | |\/| |  \___ \ 
                 | | | |____  | |__| | | |  | |  ____) |
                 |_| |______| |_____/  |_|  |_| |_____/ 
        )"
         << endl;
}
// parameters - EID, FNAME , LNAME , SALARY
void admin::setter(int EID, string FN, string LN, string SL)
{
    EMPData *E = new (nothrow) EMPData;
    E->set_eid(EID);
    E->set_fname(FN);
    E->set_lname(LN);
    E->set_salary(SL);
    empl.push_back(*E);

    ofstream file;
    file.open("data/database.csv", ios::out | ios::app);
    //write to csv file
    if (alreadyExists(EID))
    {
        cout << "EMPLOYEE ID : " << EID << endl;
        cout << "ALREADY EXISTS...\n";
    }
    else
    {
        file << EID << "," << FN << "," << LN << "," << SL << endl;
    }
    file.close();
    delete E;
}
void admin::filereader()
{
    bool skipRow0 = true;
    ifstream file;
    file.open("data/database.csv", ios::in);

    int num;
    char delim = ',';
    vector<string> row;
    string line, word, temp;

    cout << "\n\n";
    while (getline(file, line))
    {
        if (skipRow0 == true)
        {
            skipRow0 = false;
            continue;
        }
        row.clear();
        stringstream ss(line);

        while (getline(ss, word, delim))
        {
            row.push_back(word);
        }
        cout << "-----------------------" << endl;
        cout << "| EMP ID     : " << row[0] << endl;
        cout << "| EMP NAME   : " << row[1] << " " << row[2] << endl;
        cout << "| EMP SALARY : " << row[3] << endl;
        cout << "-----------------------" << endl;
        row.clear();
    }
    file.close();
}
void admin::CSV_delete(int EID)
{
    // row skipper
    bool skipRow0 = true;
    // Open FIle pointers
    fstream fin, fout;

    // Open the existing file
    fin.open("data/database.csv", ios::in);

    // Create a new file to store the non-deleted data
    fout.open("data/databasenew.csv", ios::out);

    int readEID, count = 0, i;
    int index;
    char delim = ',';
    string line, word;
    vector<string> row;

    // Check if this record exists
    // If exists, leave it and
    // add all other data to the new file
    while (!fin.eof())
    {
        if (skipRow0 == true)
        {
            skipRow0 = false;
            continue;
        }
        // clear the vector
        row.clear();
        getline(fin, line);
        stringstream wordStream(line);

        while (getline(wordStream, word, delim))
        {
            row.push_back(word);
        }

        readEID = stoi(row[0]);

        // writing all records,
        // except the record to be deleted,
        // into the new file databasenew.csv
        // using fout pointer
        if (readEID != EID)
        {
            if (!fin.eof())
            {
                fout << row[0] << "," << row[1] << "," << row[2] << ",";
                fout << row[3] << endl;
            }
            row.clear();
        }
        else
        {
            count = 1;
        }
        if (fin.eof())
            break;
    }
    if (count == 1)
        cout << "Record Deleted\n";
    else
        cout << "Record Not Found\n";

    // Close the pointers
    fin.close();
    fout.close();

    // removing the existing file
    remove("data/database.csv");

    // renaming the new file with the existing file name
    rename("data/databasenew.csv", "data/database.csv");
}
bool admin::filesearcher(int searchEID)
{
    int eid;
    bool flag = false;
    bool skipRow0 = true;
    ifstream file;
    file.open("data/database.csv", ios::in);

    char delim = ',';
    vector<string> row;
    string line, word, temp;

    cout << "\n\n";
    while (getline(file, line))
    {
        if (skipRow0 == true)
        {
            skipRow0 = false;
            continue;
        }
        row.clear();
        stringstream ss(line);

        while (getline(ss, word, delim))
        {
            row.push_back(word);
        }
        eid = stoi(row[0]);
        if (eid == searchEID)
        {
            cout << "------------------" << endl;
            cout << "| EMP ID     : " << row[0] << endl;
            cout << "| EMP NAME   : " << row[1] << " " << row[2] << endl;
            cout << "| EMP SALARY : " << row[3] << endl;
            cout << "------------------" << endl;
            flag = true;
        }
        row.clear();
    }
    file.close();

    return flag;
}
bool admin::alreadyExists(int searchEID)
{
    bool skipRow0 = true;
    int eid;
    bool flag = false;
    ifstream file;
    file.open("data/database.csv", ios::in);

    char delim = ',';
    vector<string> row;
    string line, word, temp;

    while (getline(file, line))
    {
        if (skipRow0 == true)
        {
            skipRow0 = false;
            continue;
        }
        row.clear();
        stringstream ss(line);

        while (getline(ss, word, delim))
        {
            row.push_back(word);
        }
        eid = stoi(row[0]);
        if (eid == searchEID)
        {
            flag = true;
        }
        row.clear();
    }
    file.close();

    return flag;
}
// ------------------------------------
// ------------------------------------
void admin::adminMENU(string AdminName, string AdminPassword)
{
    adminData.resize(2);
    adminData[0] = AdminName;
    adminData[1] = AdminPassword;
    int choice;
    bool flag = true;
    while (flag)
    {
        cout << "1. ENTER NEW RECORD \n";
        cout << "2. GET ALL RECORD DATA \n";
        cout << "3. DELETE RECORD \n";
        cout << "4. SEARCH RECORD \n";
        cout << "OTHER -> EXIT \n";
        cout << "$" << adminData[0] << "$::";
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
        case 4:
            basicDET_SEARCH();
            break;
        default:
            flag = false;
            break;
        }
    }
}
void admin::basicDET_SET()
{
    int EID;
    string *FN = new (nothrow) string;
    string *LN = new (nothrow) string;
    string *SL = new (nothrow) string;
    // buffer clearer
    cin.sync();
    // e ID
    cout << "EMP ID     : ";
    cin >> EID;
    // clearing buffer
    cin.clear();
    cin.ignore();
    // first name
    cout << "FIRST NAME : ";
    getline(cin, *FN);
    // last name
    cout << "LAST NAME  : ";
    getline(cin, *LN);
    // salary
    cout << "SALARY     : ";
    getline(cin, *SL);
    // calls setter method
    admin::setter(EID, *FN, *LN, *SL);
    delete FN, LN, SL;

    cout << "-----------" << endl;
}
void admin::basicDET_GET()
{
    string passwd;
    cout << "CONFIRM PASSWORD TO ACCESS ALL DATA :: ";
    cin >> passwd;

    if (passwd == adminData[1])
        filereader();
}
void admin::basicDET_deleteEMP()
{
    int EID;
    cout << "Delete using EID :: ";
    cin >> EID;
    string passwd;
    cout << "CONFIRM PASSWORD TO DELETE DATA OF ";
    cout << "EMPLOYEE ID : " << EID;
    cin >> passwd;

    // calls deleter method
    if (passwd == adminData[1])
        CSV_delete(EID);
}
void admin::basicDET_SEARCH()
{
    int eid;
    cout << "SEARCH BY EID : ";
    cin >> eid;

    if (!filesearcher(eid))
    {
        cout << "NOT FOUND...\n";
    }
}