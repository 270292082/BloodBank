#include <iostream>
#include <string>
#include "user.hpp"
using namespace std;

void IntroDisplay(users user) {
    if (user.username == "N/A") {
        cout << endl;
        cout << "-_____________________________-\t\t _    _      _ _      _             _           _ " << endl;
        cout << " \\  o                     o  /\t\t| |  | |    | (_)    (_)           | |         | |" << endl;
        cout << "  \\   o                 o   /\t\t| |__| | ___| |___  ___ _ __ ___   | |     __ _| |__" << endl;
        cout << "   \\    o             o    /\t\t|  __  |/ _ \\ | \\ \\/ / | '__/ _ \\  | |    / _` | '_ \\" << endl;
        cout << "    \\     o         o     /\t\t| |  | |  __/ | |>  <| | | |  __/  | |___| (_| | |_) |" << endl;
        cout << "     \\      o     o      /\t\t|_|  |_|\\___|_|_/_/\\_\\_|_|  \\___|  |______\\__,_|_.__/" << endl;
        cout << "      \\       o o       /\t\t" << endl;
        cout << "       \\       o       /\t\t1. Login" << endl;
        cout << "        \\      o      /\t\t\t2. Register" << endl;
        cout << "         \\     o     /\t\t\t" << endl;
        cout << "          \\    o    /\t\t\t" << endl;
        cout << "           \\   o   /\t\t\t" << endl;
        cout << "            \\  o  /\t\t\tLocation: WA Building, 55 Wellesley Street East, Auckland" << endl;
        cout << "             \\ o /\t\t\tP hone: 0800 448 325" << endl;
        cout << "              \\ /\t\t\t" << endl;
        cout << "               *\t\t\t" << endl;
        cout << endl;
        return;
    }

    cout << endl;
    cout << "-_____________________________-\t\t _    _      _ _      _             _           _ " << endl;
    cout << " \\  o                     o  /\t\t| |  | |    | (_)    (_)           | |         | |" << endl;
    cout << "  \\   o                 o   /\t\t| |__| | ___| |___  ___ _ __ ___   | |     __ _| |__" << endl;
    cout << "   \\    o             o    /\t\t|  __  |/ _ \\ | \\ \\/ / | '__/ _ \\  | |    / _` | '_ \\" << endl;
    cout << "    \\     o         o     /\t\t| |  | |  __/ | |>  <| | | |  __/  | |___| (_| | |_) |" << endl;
    cout << "     \\      o     o      /\t\t|_|  |_|\\___|_|_/_/\\_\\_|_|  \\___|  |______\\__,_|_.__/" << endl;
    cout << "      \\       o o       /\t\t" << endl;
    cout << "       \\       o       /\t\tWelcome back " << user.username << "!" << endl;
    cout << "        \\      o      /\t\t\tYou are a " << user.category << "." << endl;
    cout << "         \\     o     /\t\t\t" << endl;
    cout << "          \\    o    /\t\t\t" << endl;
    cout << "           \\   o   /\t\t\t" << endl;
    cout << "            \\  o  /\t\t\tLocation: WA Building, 55 Wellesley Street East, Auckland" << endl;
    cout << "             \\ o /\t\t\tP hone: 0800 448 325" << endl;
    cout << "              \\ /\t\t\t" << endl;
    cout << "               *\t\t\t" << endl;
    cout << endl;
};

void Intro() {
    int choice;
    users user;
    IntroDisplay(user);
    cout << "Please select an option >> ";
    cin >> choice;

    switch (choice) {
    case 1:
        break;
    case 2:
        break;
    default:
        cout << "Please, choose a valid option." << endl;
        break;
    }
}









