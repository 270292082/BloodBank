#include <iostream>
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

void display(pages page) {
  
  switch(page) {
  case logo:
    cout << "-_____________________________-" << endl;
    cout << " ╲⟍                        ⟋ ╱" << endl;
    cout << "  ╲  ⟍                  ⟋   ╱" << endl;
    cout << "   ╲    ⟍            ⟋     ╱" << endl;
    cout << "    ╲      ⟍      ⟋       ╱" << endl;
    cout << "     ╲                   ╱" << endl;
    cout << "      ╲        ⤫        ╱" << endl;
    cout << "       ╲               ╱" << endl;
    cout << "        ╲      |      ╱" << endl;
    cout << "         ╲     |     ╱" << endl;
    cout << "          ╲    |    ╱" << endl;
    cout << "           ╲   |   ╱" << endl;
    cout << "            ╲  |  ╱" << endl;
    cout << "             ╲ | ╱" << endl;
    cout << "              ╲ ╱" << endl;
    cout << "               *" << endl;
    cout << endl;
    break;

  case intro:
    cout << "-_____________________________-\t\t" << endl;
    cout << " ╲⟍                        ⟋ ╱\t\tHelixire Lab" << endl;
    cout << "  ╲  ⟍                  ⟋   ╱\t\t" << endl;
    cout << "   ╲    ⟍            ⟋     ╱\t\t" << endl;
    cout << "    ╲      ⟍      ⟋       ╱\t\t" << endl;
    cout << "     ╲                   ╱\t\t" << endl;
    cout << "      ╲        ⤫        ╱\t\t" << endl;
    cout << "       ╲               ╱\t\t" << endl;
    cout << "        ╲      |      ╱\t\t\t" << endl;
    cout << "         ╲     |     ╱\t\t\t" << endl;
    cout << "          ╲    |    ╱\t\t\t" << endl;
    cout << "           ╲   |   ╱\t\t\t" << endl;
    cout << "            ╲  |  ╱\t\t\t" << endl;
    cout << "             ╲ | ╱\t\t\t" << endl;
    cout << "              ╲ ╱\t\t\tContact: 09 523 5733" << endl;
    cout << "               *\t\t\t" << endl;
    cout << endl;
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
