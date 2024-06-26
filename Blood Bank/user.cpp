#include <iostream>
#include "display.hpp"
#include "ansi.hpp"
#include "reg.hpp"
#include <vector>
#include <string>
#include <fstream>
#include "csystem.hpp"
using namespace std;


struct users {
	string username = "N/A";
	string password = "N/A";
    string fname = "N/A";
    string lname = "N/A";
	string dob="N/A";
	string nationality="N/A";
	string ethnicity="N/A";
	string gender="N/A";
	vector<string> conditions;
	string blood_group="N/A";
	string phone="N/A";
	string email="N/A";
	string location="N/A";
	string last_donation="N/A";
	string category="N/A";
};


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


// Get all the users informations.
vector<vector<string>> GetUsersInfo(string path="Registration.dat") {
    
    ifstream file(path);
    string raw_line;
    vector<string> baked_line;
    vector<vector<string>> result;

    if (!file) {
        cout << CRED << "Could not open the file!" << CDEF << endl;
        return result;
    }

    while(getline(file, raw_line)) {
        baked_line = StringSeparator(raw_line);
        result.push_back(baked_line);
    }

    return result;
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
        if (filtered.size()>0) {
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

// Get the data of the client database file and store it as a vector.
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

// Allow the user to modify his data.
int ModifyData(users* user) {
    cout << CLEAR;
    Display(logo);
    vector<vector<string>> usrs = GetData();
    vector<string> new_info = CollectUsrInfo();
    int usr_line;
    string msg;


    // Look the line of the user.
    for(int c=0; c<usrs.size(); c++) {
        if (usrs[c][0] == (*user).username) {
            usr_line = c;
            break;
        }
    }

    // Replace the line in the config by the new info.
    usrs[usr_line] = new_info;


    // Transform the freshly new data into the config format.
    for(vector<string> usr : usrs) {
        int usr_size = usr.size();
        for(int i=0; i<usr_size; i++) {
            msg+=usr[i];
            if (i != usr_size) {
                msg+=';';
            }
        }
        msg+="\n";
    }



    // Store the data into the config file.
    if(!FileStore(msg, true)) {
        cout << CRED << "Data couldn't be modified!" << CDEF << endl;
        return -1;
    }

    cout << "Data successfully updated!" << endl;


    // Modify the user object borrowed.
    (*user).username = new_info[0];
    (*user).password = new_info[1];
    (*user).fname = new_info[2];
    (*user).lname = new_info[3];
    (*user).dob = new_info[4];
    (*user).nationality = new_info[5];
    (*user).ethnicity = new_info[6];
    (*user).gender = new_info[7];
    (*user).blood_group = new_info[8];
    (*user).phone = new_info[9];
    (*user).email = new_info[10];
    (*user).location = new_info[11];
    (*user).category = new_info[12];
    (*user).conditions = StringSeparator(new_info[13], ';');

    return 1;

}

void DisplayBloodData(string path="Bookings.dat") {
    ifstream file(path);
    string raw_line;
    vector<string> info = {"Date\t\t: ", "Time\t\t: ", "Full Name\t: ", "Date of Birth\t: ", "Conditions\t: ", "Location\t: "};
    int step=0;

    if (!file) {
        return;
    }

    while(getline(file, raw_line)) {
        for (string words: StringSeparator(raw_line)) {
            cout << info[step] << words << endl;
            step++;
        }  
    }
    
}
