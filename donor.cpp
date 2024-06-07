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
    cout << "            \\  o  /\t\t\t" << CTHIN << "4. Exit" << CDEF << CRED << endl;
    cout << "             \\ o /\t\t\t" << endl;
    cout << "              \\ /\t\t\t" << endl;
    cout << "               *\t\t\t" << endl;
    cout << endl;
    cout << CDEF;
}

void DonorInit(users user) {
    DonorDisplay(user);

    while(true) {
        int choice;
        cout << "Select an option : ";
        cin >> choice;
    
        switch(choice) {
        case 1:
            TypeText("The blood is collected in a sterile bag, and time on the bed can take about 5 to 10 minutes.\nA unit of blood (around 470 ml) will be collected.\nThe needle is then removed and a bandage is applied.\nA plasma donation can take up to 90 minutes (includes registration, donation and recovery).\n", 10);
            break;
        case 2:
            TypeText("Donating blood is highly beneficial as it helps save lives and supports the healthcare system.\nBlood donations are crucial for emergency surgeries, cancer treatments, chronic illnesses, and traumatic injuries.\nBy donating, individuals contribute to maintaining an adequate blood supply, ensuring that patients receive the necessary transfusions promptly.\nMoreover, the act of donating blood can improve the donor's health by stimulating blood cell production and providing a free mini-health checkup, which can help detect potential health issues early.\nOverall, blood donation is a simple, selfless act that has a profound impact on the community and individual well-being.\n", 10);
            break;
        case 3:
            break;
        case 4:
            return;
        }
    }
}
