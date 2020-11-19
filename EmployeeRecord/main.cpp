#include <bits/stdc++.h>
#include "admin.h"
using namespace std;

class RUNAPP_iEDM
{
private:
    // UserID and Password
    string uid, paswd;
    void adminCLASS(string AName)
    {
        admin SUDO;
        SUDO.adminMENU(uid);
    }
    bool get_loginDetails(string uid, string paswd)
    {
        string loginUID, loginPaswd, AdminStatus;

        bool flag = false;
        ifstream file;
        file.open("login.csv", ios::in);

        char delim = ',';
        vector<string> row;
        string line, word, temp;

        while (getline(file, line))
        {
            row.clear();
            stringstream ss(line);

            while (getline(ss, word, delim))
            {
                row.push_back(word);
            }
            loginUID = row[0];
            loginPaswd = row[1];
            AdminStatus = row[2];
            // check if the details match
            if (loginUID == uid && loginPaswd == paswd && AdminStatus == "admin")
            {
                flag = true;
            }
        }
        row.clear();
        file.close();

        return flag;
    }

public:
    void run()
    {
        bool flag = true;
        do
        {
            cout << "LOGIN\n\n\n";

            cout << "USER ID :: ";
            cin >> uid;
            cout << "PASSWORD ::";
            cin >> paswd;

            if (get_loginDetails(uid, paswd))
            {
                adminCLASS(uid);
                flag = false;
            }
            else
            {
                cout << "WRONG CREDENTIALS...\n";
                cout << "TRY AGAIN...\n";
                continue;
            }

        } while (flag);
    }
};
int main()
{
    RUNAPP_iEDM start;
    start.run();
    return 0;
}

//--------------------------------------------------
// DONT GO DOWN
// PLEASE
// REQUEST
//  |
// \/
// HELL DOWN THERE

/*
class admin : public EMPData
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

        ofstream file;
        file.open("database.csv", ios::out | ios::app);
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
    void filereader()
    {
        ifstream file;
        file.open("database.csv", ios::in);

        int num;
        char delim = ',';
        vector<string> row;
        string line, word, temp;

        cout << "DATA : \n";
        while (getline(file, line))
        {
            row.clear();
            stringstream ss(line);

            while (getline(ss, word, delim))
            {
                row.push_back(word);
            }
            num = stoi(row[0]);

            cout << "-----------------------" << endl;
            cout << "| EMP ID     : " << row[0] << endl;
            cout << "| EMP NAME   : " << row[1] << " " << row[2] << endl;
            cout << "| EMP SALARY : " << row[3] << endl;
            cout << "-----------------------" << endl;
            row.clear();
        }
        file.close();
    }
    void CSV_delete(int EID)
    {
        // Open FIle pointers
        fstream fin, fout;

        // Open the existing file
        fin.open("database.csv", ios::in);

        // Create a new file to store the non-deleted data
        fout.open("databasenew.csv", ios::out);

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
        remove("database.csv");

        // renaming the new file with the existing file name
        rename("databasenew.csv", "database.csv");
    }
    bool filesearcher(int searchEID)
    {
        int eid;
        bool flag = false;
        ifstream file;
        file.open("database.csv", ios::in);

        char delim = ',';
        vector<string> row;
        string line, word, temp;

        cout << "DATA : \n";
        while (getline(file, line))
        {
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
    bool alreadyExists(int searchEID)
    {
        int eid;
        bool flag = false;
        ifstream file;
        file.open("database.csv", ios::in);

        char delim = ',';
        vector<string> row;
        string line, word, temp;

        cout << "DATA : \n";
        while (getline(file, line))
        {
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
public:
    void adminMENU(string AdminName)
    {
        int choice;
        bool flag = true;
        while (flag)
        {
            cout << "1. ENTER NEW RECORD \n";
            cout << "2. GET ALL RECORD DATA \n";
            cout << "3. DELETE RECORD \n";
            cout << "4. SEARCH RECORD \n";
            cout << "OTHER -> EXIT \n";
            cout << "$" << AdminName << "$::";
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
    void basicDET_SET()
    {
        string *FN = new (nothrow) string;
        string *LN = new (nothrow) string;
        unsigned int *SL = new unsigned int;
        int EID;
        // buffer clearer
        cin.sync();
        // e ID
        cout << "EID : ";
        cin >> EID;
        // clearing buffer
        cin.clear();
        cin.ignore();
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
        setter(EID, *FN, *LN, *SL);
        delete FN, LN, SL;

        cout << "-----------" << endl;
    }
    void basicDET_GET()
    {
        string passwd;
        cout << "ENTER PASSWORD TO ACCESS ALL DATA :: ";
        cin >> passwd;

        if (passwd == "1234")
            filereader();
    }
    void basicDET_deleteEMP()
    {
        int EID;
        cout << "Delete using EID :: ";
        cin >> EID;
        // calls deleter method
        CSV_delete(EID);
    }
    void basicDET_SEARCH()
    {
        int eid;
        cout << "SEARCH BY EID : ";
        cin >> eid;

        if (!filesearcher(eid))
        {
            cout << "NOT FOUND...\n";
        }
    }
};
*/