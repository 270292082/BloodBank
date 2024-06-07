#include <iostream>
#include <vector>
#include "intro.hpp"
#include "donor.hpp"
#include "user.hpp"
#include "display.hpp"
#include "file.hpp"
#include "ansi.hpp"
using namespace std;


void DonorRegInit() {
    Display(logo);
    string info_name[] = {"Username : ", "Password : ", "First Name : ", "Last Name : ", "Date of Birth [MM/DD/YYYY] : ", "Nationality : ", "Ethnicity : ", "Gender : ", "Blood Group : ", "Phone : ", "Email : ", "Physical Adress : ", "Donor or Receiver : "};
    vector<string> info;
    string val;

    vector<string> usernames = GetUsers();

    cout << "Please enter the needed informations in order to register." << endl;

    
    cin.ignore(1, '\n'); // clean the buffer.

    bool username_valid = false;
    
    // Prevent a user to register with a username that already exist.
    while(!username_valid) {
        username_valid = true;

        // Take the username information from the user.
        cout << info_name[0];
        getline(cin, val);
     
        // Check if the username entered is already in the database.
        for(string username : usernames) {
            if (username == val) {
                cout << "This username already exist!" << endl;
                cout << "Please select another!" << endl;
                username_valid = false;
            }
        }
    }


    // Push the username inside the database.
    info.push_back(val);

    // Collect the remaining user informations.
    for (int i=1; i<sizeof(info_name)/sizeof(string); i++) {
        cout << info_name[i];
        getline(cin, val);
        info.push_back(val);
    }

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
    DonorInit(user);

    // Store the datas inside a text file.
    string msg = "";
    for (int i=0; i<info.size(); i++) {
        msg+=info[i]+";";
    }
    msg+="\n";
    
    if (FileStore("Donor_Registration.dat", msg)) {
        cout << "The datas were successfully collected!" << endl;
    }


}
