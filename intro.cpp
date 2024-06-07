#include <iostream>
#include "user.hpp"
#include "donor_reg.hpp"
#include "ansi.hpp"
using namespace std;

void IntroDisplay() {
    cout << CRED;
    cout << endl;
    cout << "-_____________________________-\t\t _    _      _ _      _             _           _ " << endl;
    cout << " \\  o                     o  /\t\t| |  | |    | (_)    (_)           | |         | |" << endl;
    cout << "  \\   o                 o   /\t\t| |__| | ___| |___  ___ _ __ ___   | |     __ _| |__" << endl;
    cout << "   \\    o             o    /\t\t|  __  |/ _ \\ | \\ \\/ / | '__/ _ \\  | |    / _` | '_ \\" << endl;
    cout << "    \\     o         o     /\t\t| |  | |  __/ | |>  <| | | |  __/  | |___| (_| | |_) |" << endl;
    cout << "     \\      o     o      /\t\t|_|  |_|\\___|_|_/_/\\_\\_|_|  \\___|  |______\\__,_|_.__/" << endl;
    cout << "      \\       o o       /\t\t" << endl;
    cout << "       \\       o       /\t\t" << CTHIN << "1. Login" << CDEF << CRED << endl;
    cout << "        \\      o      /\t\t\t" << CTHIN << "2. Register" << CDEF << CRED << endl;
    cout << "         \\     o     /\t\t\t" << endl;
    cout << "          \\    o    /\t\t\t" << endl;
    cout << "           \\   o   /\t\t\t" << endl;
    cout << "            \\  o  /\t\t\tLocation: WA Building, 55 Wellesley Street East, Auckland" << endl;
    cout << "             \\ o /\t\t\tPhone: 0800 448 325" << endl;
    cout << "              \\ /\t\t\t" << endl;
    cout << "               *\t\t\t" << endl;
    cout << endl;
    cout << CDEF;
    return;

};

void Intro() {
    int choice;
    users user;
    IntroDisplay();
    cout << "Please select an option >> ";
    cin >> choice;

    switch (choice) {
    case 1:
        break;
    case 2:
        DonorRegInit();
        break;
    default:
        cout << "Please, choose a valid option." << endl;
        break;
    }
}









