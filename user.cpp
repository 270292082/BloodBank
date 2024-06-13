#include <iostream>
#include "ansi.hpp"
#include <vector>
#include <string>
#include <fstream>
#include "csystem.hpp"
using namespace std;


// Get the usernames and store them in a vector.
vector<string> GetUsers(string path="Registration.dat", char separator=';') {
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
vector<string> GetInfo(string username, string fname="Registration.dat") {
    ifstream file(fname);

    string raw_line;
    vector<string> baked_line;

    // Check if the username is the one we want.
    while(getline(file, raw_line)) {
        baked_line = StringSeparator(raw_line, ';'); 
        if (baked_line[0] == username) {
            break;
        }
    }

    // Return the informations of the user.
    return baked_line;
}

void DisplayFilteredUsers(vector<vector<string>> users_info) {

    for (int u=0; u<users_info.size(); u++) {
        cout << users_info[u][0] << " : " << endl;
        cout << " First Name : " << users_info[u][1] << endl;
        cout << " Last Name :" << users_info[u][2] << endl;
        for(int i=3; i<users_info[u].size(); i++) {
            cout << " " << users_info[u][i] << endl;
        }
        cout << endl;
    }
    
}



// Sort the user by a filter.
vector<vector<string>> GetFilteredUsers(vector<string> filters) {
    vector<string> usernames = GetUsers();
    vector<vector<string>> usrs_infos;
    vector<vector<string>> fltr_infos;

    // Collect all the users' info.
    for (string username : usernames) {
        usrs_infos.push_back(GetInfo(username));
    }
    
    // Iterate through all the users' infos.
    for(vector<string> usr_infos : usrs_infos) {
        vector<string> filtered;

        // Iterate through all the info of a user.
        for(string info : usr_infos) {
            // Iterate through the filters.
            for(string filter : filters) {
                
                // Check if the filter can be applied to this user, if yes, store it's username and name if not already stored & it's info.
                if (info == filter && filtered.size() == 0) {
                    filtered.push_back(usr_infos[0]);
                    filtered.push_back(usr_infos[2]);
                    filtered.push_back(usr_infos[3]);
                    filtered.push_back(info);

                } else if (info == filter) {
                    filtered.push_back(info);
                }
            }
        }

        // Save the informations only if they correspond to the filters.
        if (filtered.size()>0 && filtered.size() == filters.size()+3) {
            fltr_infos.push_back(filtered);
        }
    }

    return fltr_infos;

}

void DisplayUserInfoByName(vector<string> name) {
    name.push_back("Donor");
    vector<vector<string>> match = GetFilteredUsers(name);
    vector<vector<string>> baked_match;

    for(vector<string> usr : match) {
        baked_match.push_back(GetInfo(usr[0]));

    }
    for(vector<string> baked_usr : baked_match) {
        if (baked_usr[2] == name[0] && baked_usr[3] == name[1]) {
            cout << "First Name \t: " << baked_usr[2] << endl;
            cout << "Last Name \t: " << baked_usr[3] << endl;
            cout << "DOB \t\t: " << baked_usr[4] << endl;
            cout << "Nationality \t: " << baked_usr[5] << endl;
            cout << "Ethnicity \t: " << baked_usr[6] << endl;
            cout << "Gender \t\t: " << baked_usr[7] << endl;
            cout << "Blood Group \t: " << baked_usr[8] << endl;
            cout << "Phone \t\t: " << baked_usr[9] << endl;
            cout << "Email \t\t: " << baked_usr[10] << endl;
            cout << "Location \t: " << baked_usr[11] << endl;
            cout << "Conditions \t: " << baked_usr[13] << endl;
        } 
        cout << endl;
    }
}

vector<vector<string>> GetData(string path="Registration.dat") {
    ifstream file(path);
    vector<vector<string>> usrs;
    vector<string> usr_info;
    string raw_line;

    if (!file) {
        cout << CRED << "Couldn't open the database!" << CDEF << endl;
    }

    while(getline(file, raw_line)) {
        usr_info = StringSeparator(raw_line, ';');
        usrs.push_back(usr_info);
    }
    
    return usrs;
}

int ModifyData(string user) {
    // Need the write the functions for modifying the user data.
    return 0;

}
