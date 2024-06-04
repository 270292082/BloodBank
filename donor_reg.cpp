#include <iostream>
#include "intro.hpp"
#include "user.hpp"
#include "display.hpp"
#include <vector>
#include "ansi.hpp"
using namespace std;


void DonorRegDisplay() {
    Display(logo);
    string info_name[] = {"Username : ", "Password : ", "First Name : ", "Last Name : ", "Date of Birth : ", "Nationality : ", "Ethnicity : ", "Gender : ", "Blood Group : ", "Phone : ", "Email : ", "Physical Adress : ", "Donor or Receiver? : "};
    vector<string> info;
    string val;

    cout << "Please enter the needed informations in order to register." << endl;

    // Collect the user informations.
    for (int i=0; i<sizeof(info_name)/sizeof(string); i++) {
        cout << info_name[i];
        cin >> val;
        info.push_back(val);
    }

    // Store the datas in the user object.
    users user;
    user.username = info[0];
    user.password = info[1];
    user.fname = info[2];
    user.lname = info[3];
    user.dob = info[4];
    user.nationality = info[5];
    user.ethnicity = info[6];
    user.gender = info[7];
    user.blood_group = info[8];
    user.phone = info[9];
    user.email = info[10];
    user.location = info[11];
    user.category = info[12];
    IntroDisplay(user);

}
