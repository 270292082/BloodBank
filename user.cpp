#include <vector>
#include <string>
#include <fstream>
using namespace std;


// Get the usernames and store them in a vector.
vector<string> GetUsers(string path="Donor_Registration.dat", char separator=';') {
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
