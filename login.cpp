#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "intro.hpp"

using namespace std;

// check if a username exists in the file
bool usernameExists(const string& Donor_username) {
    ifstream Donor_file("Donor_Registration.dat");
    if (!Donor_file) {
        cerr << "Unable to open file Donor_Registration.dat" << endl;
        return false;
    }

    string line;
    while (getline(Donor_file, line)) {
        stringstream ss(line);
        string file_username;

        // Read username from file
        getline(ss, file_username, ',');

        // Compare with input username
        if (file_username == Donor_username) {
            return true;
        }
    }

    return false;
}

//  fucntion to check login username and password in file
bool checkLogin(const string& Donor_username, const string& Donor_password) {
    ifstream Donor_file("Donor_Registration.dat");
    if (!Donor_file) {
        cerr << "Unable to open file Donor_Registration.dat" << endl;
        return false;
    }

    string line;
    while (getline(Donor_file, line)) {
        stringstream ss(line);
        string file_username, file_password;

        // Read username and password from the file
        getline(ss, file_username, ',');
        getline(ss, file_password, ',');

        // Compare with input username and password
        if (file_username == Donor_username && file_password == Donor_password) {
            return true;
        }
    }

    return false;
}

// Function to handle user login
void login() {
    string username, password;
    int attempts = 0;

    cout << "Enter username: ";
    cin >> username;

    if (!usernameExists(username)) {
        cout << "No username, Please try again." << endl;
        Intro();
    }

    // Allow up to 3 attempts to login
    while (attempts < 3) {
        cout << "Enter password: ";
        cin >> password;

        // Check login credentials
        if (checkLogin(username, password)) {
            cout << "Login successful!" << endl;
            return;
        }
        else {
            cout << "Invalid username or password." << endl;
            attempts++;
        }
    }

    cout << "Too many failed attempts. Exiting..." << endl;
}