#include <iostream>
#include <vector>
#include "donor.hpp"
#include "receiver.hpp"
#include "user.hpp"
#include "display.hpp"
#include "csystem.hpp"
#include "ansi.hpp"
using namespace std;

string SelectUsername(vector<string> usernames, vector<string> info_name) {
    string val;

    bool valid = false;

    // Prevent a user to register with a username that already exist.
    while(!valid) {
        valid = true;

        // Take the username information from the user.
        cout << "Username : ";
        getline(cin, val);
     
        // Check if the username entered is already in the database.
        for(string username : usernames) {
            if (username == val) {
                cout << CRED << "This username already exist!\nPlease select another." << CDEF << endl;
                valid = false;
                break;
            }
        }
    }

    return val;
}

string SelectCategory() {
    string val;

    while (true) {
        cout << "Donor or Receiver : ";
        cin >> val;

        if (val == "Donor" || val == "Receiver") {
            return val;            
        }

        cout << CRED << "Please input a correct option." << CDEF << endl;
    }
}

string SelectConditions() {
    string val;

    cout << "Conditions (enter them with a coma between each ones, if you don't have any type 'none') : ";
    cin.ignore(1, '\n'); // clean the buffer.
    getline(cin, val);
    if (val=="") {
        val = "none";
    }

    return val;
} 

void StoreConfig(vector<string> info) {
    // Store the datas inside a text file.
    string msg="";
    for (int i=0; i<info.size(); i++) {
        msg+=info[i];
        if (i!=info.size()-1){
            msg+=';';
        }
    }
    msg+="\n";


    if (FileStore(msg)) {
        cout << "Account was successfully created!" << endl;
    }
    else {
        cout << CRED << "An error has occured, impossibility to access the database!" << CDEF << endl;
        return;
    }
}

vector<string> CollectUsrInfo() {
    vector<string> usernames = GetUsers();
    vector<string> info_name {"Password : ", "First Name : ", "Last Name : ", "Date of Birth [MM/DD/YYYY] : ", "Nationality : ", "Ethnicity : ", "Gender : ", "Blood Group : ", "Phone : ", "Email : ", "Physical Adress : ", "Donor or Receiver : "};
    vector<string> info;
    string val;

    cin.ignore(1, '\n'); // clean the buffer.

    // Prompt the user to choose his username.
    string username = SelectUsername(usernames, info_name); 
    info.push_back(username);

    // Collect the remaining user informations.
    for (int i=0; i<info_name.size()-1; i++) {
        cout << info_name[i];
        getline(cin, val);
        info.push_back(val);
    }

    // Prompt the user to choose his category.
    string category =  SelectCategory();
    info.push_back(category);

    //Prompt the user to specify his conditions.
    string raw_conditions = SelectConditions();
    info.push_back(raw_conditions);

    return info;
}


void DonorRegInit() {
    cout << CLEAR;
    Display(logo);
    string val;

    cout << "Please enter the needed informations in order to register." << endl;
    
    
    vector<string> info;
    
    info = CollectUsrInfo();


    // Store the datas in the user object (for now, only used in the display function).
    users user;
    user.username = info[0];
    user.password = info[1];
    user.fname = info[2];
    user.lname = info[3];
    user.dob = info[4];
    user.nationality = info[5];
    user.ethnicity = info[6];
    user.gender = info[7];
    user.blood_group = info[8];
    user.phone = info[9];
    user.email = info[10];
    user.location = info[11];
    user.category = info[12];
    user.conditions = StringSeparator(info[13], ';');

    StoreConfig(info);

    if (info[12] == "Donor") {
        DonorInit(user);
    } else {
        ReceiverInit(user);
    }
}
