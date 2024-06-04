#include <iostream>
#include "intro.hpp"
#include "ansi.hpp"
using namespace std;

enum pages {
    logo,
    intro,
    donor,
    donor_reg,
    login,
    recipient,
    recipient_reg,
    admin,
    booking
};


// Redirect to the function that will display the correct page.
void Display(pages page) {

    switch (page) {
    case logo:
        cout << CRED;
        cout << "-_____________________________-" << endl;
        cout << " \\  o                     o  /" << endl;
        cout << "  \\   o                 o   /" << endl;
        cout << "   \\    o             o    /" << endl;
        cout << "    \\     o         o     /" << endl;
        cout << "     \\      o     o      /" << endl;
        cout << "      \\       o o       /" << endl;
        cout << "       \\       o       /" << endl;
        cout << "        \\      o      /" << endl;
        cout << "         \\     o     /" << endl;
        cout << "          \\    o    /" << endl;
        cout << "           \\   o   /" << endl;
        cout << "            \\  o  /" << endl;
        cout << "             \\ o /" << endl;
        cout << "              \\ /" << endl;
        cout << "               *" << endl;
        cout << endl;
        cout << CDEF;
        break;

    case intro:
        Intro();
        break;


    case donor:
        break;
    case donor_reg:
        break;
    case login:
        break;
    case recipient:
        break;
    case recipient_reg:
        break;
    case admin:
        break;
    case booking:
        break;

    }
}
