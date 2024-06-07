#include <iostream>
#include "ansi.hpp"
#include "user.hpp"
#include "csystem.hpp"
using namespace std;


void DonorDisplay(users user) {
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
    cout << "        \\      o      /\t\t\t" << CTHIN << "You are a " << user.category << "." << CDEF << CRED << endl;
    cout << "         \\     o     /\t\t\t" << CTHIN << "1. Procedure to donate blood" << CDEF << CRED << endl;
    cout << "          \\    o    /\t\t\t" << CTHIN << "2. Benefit of blood donation" << CDEF << CRED << endl;
    cout << "           \\   o   /\t\t\t" << CTHIN << "3. Managing informations" << CDEF << CRED << endl;
    cout << "            \\  o  /\t\t\t" << endl;
    cout << "             \\ o /\t\t\t" << endl;
    cout << "              \\ /\t\t\t" << endl;
    cout << "               *\t\t\t" << endl;
    cout << endl;
    cout << CDEF;
}

void DonorInit(users user) {
    DonorDisplay(user);
}
