#include <iostream>
#include "display.hpp"
#include "receiver.hpp"
#include "user.hpp"
using namespace std;

int main() {

    vector<string> name {"Thomas", "Wongsokarto"};
    DisplayUserInfoByName(name);

    /*
    vector<string> filter = {"Donor"};

    vector<vector<string>> user_data = GetFilteredUsers(filter);
    DisplayFilteredUsers(user_data);
    */
}

