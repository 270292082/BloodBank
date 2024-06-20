#include <iostream>
#include "user.hpp"
#include "ansi.hpp"
#include "csystem.hpp"
using namespace std;


void AdminDisplay() {
    cout << CRED;
    cout << endl;
    cout << "-_____________________________-\t\t _    _      _ _      _             _           _ " << endl;
    cout << " \\  o                     o  /\t\t| |  | |    | (_)    (_)           | |         | |" << endl;
    cout << "  \\   o                 o   /\t\t| |__| | ___| |___  ___ _ __ ___   | |     __ _| |__" << endl;
    cout << "   \\    o             o    /\t\t|  __  |/ _ \\ | \\ \\/ / | '__/ _ \\  | |    / _` | '_ \\" << endl;
    cout << "    \\     o         o     /\t\t| |  | |  __/ | |>  <| | | |  __/  | |___| (_| | |_) |" << endl;
    cout << "     \\      o     o      /\t\t|_|  |_|\\___|_|_/_/\\_\\_|_|  \\___|  |______\\__,_|_.__/" << endl;
    cout << "      \\       o o       /\t\t" << endl;
    cout << "       \\       o       /\t\t" << CTHIN << "ADMINISTRATOR ACCESS GRANTED!" << CDEF << CRED << endl;
    cout << "        \\      o      /\t\t\t" << CTHIN << "With big power comes great responsabilities." << CDEF << CRED << endl;
    cout << "         \\     o     /\t\t\t" << CTHIN << "1. View the clients informations" << CDEF << CRED << endl;
    cout << "          \\    o    /\t\t\t" << CTHIN << "2. View blood testing reports" << CDEF << CRED << endl;
    cout << "           \\   o   /\t\t\t" << CTHIN << "3. Edit clients informations" << CDEF << CRED << endl;
    cout << "            \\  o  /\t\t\t" << CTHIN << "4. Exit" << CDEF << CRED << endl;
    cout << "             \\ o /\t\t\t" << endl;
    cout << "              \\ /\t\t\t" << endl;
    cout << "               *\t\t\t" << endl;
    cout << endl;
    cout << CDEF;
}

void AdminInit() {
    cout << CLEAR;
    AdminDisplay();

    while(true) {
        int choice;
        cout << "Select an option : ";
        cin >> choice;
        users usr;
    
        switch(choice) {
        case 1:
            DisplayFilteredUsers(GetUsersInfo());
            break;
        case 2:
            DisplayBloodData();
            break;
        case 3:
            cout << "Which client info do you want to modify?" << endl;
            cout << ">> ";
            cin >> usr.username;
            ModifyData(&usr);
            cout << CLEAR;
            AdminDisplay();
            break;
        case 4:
            return;
        default:
            cout << CRED << "Please choose a valid option!" << CDEF << endl;
            break;
        }
        
    }
}
