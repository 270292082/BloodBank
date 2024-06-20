#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "intro.hpp"
#include "csystem.hpp"
#include "display.hpp"
#include "donor.hpp"
#include "receiver.hpp"
#include "ansi.hpp"
#include "admin.hpp"
using namespace std;

// check if a username exists in the file
bool UsernameExists(const string& username) {
    ifstream file("Registration.dat");
    if (!file) {
        cerr << "Unable to open file Registration.dat" << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string file_username;

        // Read username from file
        getline(ss, file_username, ';');

        // Compare with input username
        if (file_username == username) {
            return true;
        }
    }

    return false;
}

//  fucntion to check login username and password in file
bool CheckLogin(const string& username, const string& password) {
    ifstream file("Registration.dat");
    if (!file) {
        cerr << "Unable to open file Registration.dat" << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string file_username, file_password;

        // Read username and password from the file
        getline(ss, file_username, ';');
        getline(ss, file_password, ';');

        // Compare with input username and password
        if (file_username == username && file_password == password) {
            return true;
        }
    }

    return false;
}

// Function to handle user login
void Login() {
    cout << CLEAR;
    Display(logo);
    string username, password;
    int attempts = 0;

    cout << "Please enter the information in order to login." << endl;
    cout << "Enter username: ";
    cin >> username;

    if (username == "admin") {
        AdminInit();
        return;
    }

    if (!UsernameExists(username)) {
        cout << "No username, Please try again." << endl;
        Intro();
    }

    // Allow up to 3 attempts to login
    while (attempts < 3) {
        cout << "Enter password: ";
        cin >> password;

        // Check login credentials
        if (CheckLogin(username, password)) {
            cout << "Login successful!" << endl;
            vector<string> usr_info = GetInfo(username);

            users usr;
            usr.username = usr_info[0];
            usr.password = usr_info[1];
            usr.fname = usr_info[2];
            usr.lname = usr_info[3];
            usr.dob = usr_info[4];
            usr.nationality = usr_info[5];
            usr.ethnicity = usr_info[6];
            usr.gender = usr_info[7];
            usr.blood_group = usr_info[8];
            usr.phone = usr_info[9];
            usr.email = usr_info[10];
            usr.location = usr_info[11];
            usr.category = usr_info[12];
            usr.conditions = StringSeparator(usr_info[13]);

            if (usr.category == "Donor") {
                DonorInit(usr);
            } else if (usr.category == "Receiver") {
                ReceiverInit(usr);
            } else {
                cout << CRED << "The user info is incorrect in the config file!\nPlease contact your Administrator." << CDEF << endl;
            }
            return;
        }
        else {
            cout << "Invalid username or password." << endl;
            attempts++;
        }
    }

    cout << "Too many failed attempts. Exiting..." << endl;
}
