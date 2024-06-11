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
                
                // Check if the filter can be applied to this user, if yes, store it's username if not already stored & it's info.
                if (info == filter && filtered.size() == 0) {
                    filtered.push_back(usr_infos[0]);
                    filtered.push_back(info);

                } else if (info == filter) {
                    filtered.push_back(info);
                }
            }
        }

        fltr_infos.push_back(filtered);
    }

    return fltr_infos;

}
