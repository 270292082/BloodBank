#include <iostream>
#include "user.hpp"
#include "donor.hpp"
#include "ansi.hpp"
#include "csystem.hpp"
using namespace std;


void ReceiverDisplay(users user) {
    cout << CLEAR;
    cout << CRED;
    cout << endl;
    cout << "-_____________________________-\t\t _    _      _ _      _             _           _ " << endl;
    cout << " \\  o                     o  /\t\t| |  | |    | (_)    (_)           | |         | |" << endl;
    cout << "  \\   o                 o   /\t\t| |__| | ___| |___  ___ _ __ ___   | |     __ _| |__" << endl;
    cout << "   \\    o             o    /\t\t|  __  |/ _ \\ | \\ \\/ / | '__/ _ \\  | |    / _` | '_ \\" << endl;
    cout << "    \\     o         o     /\t\t| |  | |  __/ | |>  <| | | |  __/  | |___| (_| | |_) |" << endl;
    cout << "     \\      o     o      /\t\t|_|  |_|\\___|_|_/_/\\_\\_|_|  \\___|  |______\\__,_|_.__/" << endl;
    cout << "      \\       o o       /\t\t" << endl;
    cout << "       \\       o       /\t\t" << CTHIN << "Welcome back " << user.fname << "!" << CDEF << CRED << endl;
    cout << "        \\      o      /\t\t\t" << CTHIN << "You are a Receiver." << CDEF << CRED << endl;
    cout << "         \\     o     /\t\t\t" << CTHIN << "1. Access Donor's informations." << CDEF << CRED << endl;
    cout << "          \\    o    /\t\t\t" << CTHIN << "2. Access Donors with Filters." << CDEF << CRED << endl;
    cout << "           \\   o   /\t\t\t" << CTHIN << "3. Managing informations." << CDEF << CRED << endl;
    cout << "            \\  o  /\t\t\t" << CTHIN << "4. Exit" << CDEF << CRED << endl;
    cout << "             \\ o /\t\t\t" << endl;
    cout << "              \\ /\t\t\t" << endl;
    cout << "               *\t\t\t" << endl;
    cout << endl;
    cout << CDEF;
}


void ReceiverInit(users user) {
    ReceiverDisplay(user);

    while(true) {
        int choice;
        cout << "Select an option : ";
        cin >> choice;
        string raw_filter;
        vector<string> filter {"Donor"};
        vector<vector<string>> users;


        switch(choice) {
        case 1:
            users = GetFilteredUsers(filter); 
            DisplayFilteredUsers(users);
            break;
        case 2:
            cout << "Specify your filters separating them with a coma: ";
            cin.ignore(1, '\n'); // clean the buffer.
            getline(cin, raw_filter);

            filter = StringSeparator(raw_filter, ',');
            users = GetFilteredUsers(filter);
            DisplayFilteredUsers(users);
            break;
        case 3:
            ModifyData(&user);
            cout << CLEAR;
            if (user.category == "Receiver") {
                ReceiverDisplay(user);
            } else {
                DonorInit(user);
                return;
            }
            break;
        case 4:
            return;
        default:
            cout << CRED << "Please choose a valid option!" << CDEF << endl;
            break;
        }
        
    }
}
