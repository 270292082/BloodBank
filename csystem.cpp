#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <fstream>
using namespace std;

void sleep(int millisecs) {
    this_thread::sleep_for(chrono::milliseconds(millisecs)); 
}

void TypeText(string msg, int milliseconds) {
    for (char c : msg) {
        cout << c << flush;
        sleep(milliseconds);
    }
    cout << endl;
}


// Separate a string with a separator.
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


// Store the informations inside a file.
int FileStore(string msg="", string path="Donor_Registration.dat") {
    ofstream file;  

    file.open(path, ios::app);

    if (!file) {
        cout << "Failed to open/create the file." << endl;
        return 1;
    }

    file << msg;

    file.close();
    return 0;
}
