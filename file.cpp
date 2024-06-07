#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<string> StringSeparator(string raw_msg, char separator=';') {
    vector<string> baked_msg;
    string word;

    // Read and Split the characters with the separator.
    for (char c : raw_msg) {
        if (c == separator) {
            baked_msg.push_back(word);
            word = "";
            continue;
        }
        word+=c;
    }

    return baked_msg;
}

int FileStore(string name, string msg="") {
    ofstream file;  

    file.open(name, ios::app);

    if (!file) {
        cout << "Failed to open/create the file." << endl;
        return 1;
    }

    file << msg;

    file.close();
    return 0;
}

vector<string> FileGetInfo(string username, string fname="Donor_Registration.dat") {
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
