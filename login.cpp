#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "intro.hpp"

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
    string username, password;
    int attempts = 0;

    cout << "Enter username: ";
    cin >> username;

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
            return;
        }
        else {
            cout << "Invalid username or password." << endl;
            attempts++;
        }
    }

    cout << "Too many failed attempts. Exiting..." << endl;
}
