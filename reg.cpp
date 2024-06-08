#include <iostream>
#include <vector>
#include "donor.hpp"
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
        cout << info_name[0];
        getline(cin, val);
     
        // Check if the username entered is already in the database.
        for(string username : usernames) {
            if (username == val) {
                cout << CRED << "This username already exist!\nPlease select another." << CDEF << endl;
                valid = false;
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

vector<string> SelectConditions() {
    string val;
    vector<string> empty;

    cout << "Conditions (enter them with a space between each ones, if you don't have any type 'none') : ";
    getline(cin, val);

    if (val == "none") {
        return empty; 
    }

    return StringSeparator(val, ' ');
} 

void DonorRegInit() {
    Display(logo);
    vector<string> info_name {"Username : ", "Password : ", "First Name : ", "Last Name : ", "Date of Birth [MM/DD/YYYY] : ", "Nationality : ", "Ethnicity : ", "Gender : ", "Blood Group : ", "Phone : ", "Email : ", "Physical Adress : ", "Donor or Receiver : "};
    vector<string> info;
    string val;
    vector<string> usernames = GetUsers();

    cout << "Please enter the needed informations in order to register." << endl;
    
    cin.ignore(1, '\n'); // clean the buffer.
    
    
    // Prompt the user to choose his username and store it into the database.
    string username = SelectUsername(usernames, info_name); 
    info.push_back(username);


    // Collect the remaining user informations.
    for (int i=1; i<info_name.size()-1; i++) {
        cout << info_name[i];
        getline(cin, val);
        info.push_back(val);
    }

    // Prompt the user to choose his category, and store it into the database.
    string category =  SelectCategory();
    info.push_back(category);


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
    user.conditions = SelectConditions();


    // Store the datas inside a text file.
    string msg = "";
    for (int i=0; i<info.size(); i++) {
        msg+=info[i]+";";
    }
    msg+="\n";
    
    if (FileStore(msg)) {
        cout << "Account was successfully created!" << endl;
    }
    else {
        cout << CRED << "An error has occured, impossibility to access the database!" << CDEF << endl;
    }

    if (category == "Donor") {
        DonorInit(user);
    } else {
        // redirect to the Receiver init.
    }
}
