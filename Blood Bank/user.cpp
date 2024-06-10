#include <vector>
#include <string>
#include <fstream>
#include "csystem.hpp"
using namespace std;


// Get the usernames and store them in a vector.
vector<string> GetUsers(string path="Donor_Registration.dat", char separator=',') {
    ifstream file(path);
    vector<string> users;

    string raw_line;
    string username;

    // Get the username of every lines.
    while(getline(file, raw_line)) {
        username="";
        for(char c : raw_line) {
            if (c == separator) {
                break;
            }
            username+=c;
        }
        users.push_back(username); 
    } 

    return users;
}

// Get the information on a user.
vector<string> GetInfo(string username, string fname="Donor_Registration.dat") {
    ifstream file(fname);

    string raw_line;
    vector<string> baked_line;

    // Check if the username is the one we want.
    while(getline(file, raw_line)) {
        baked_line = StringSeparator(raw_line); 
        if (baked_line[0] == username) {
            break;
        }
    }

    // Return the informations of the user.
    return baked_line;
}
