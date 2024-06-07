#include <iostream>
#include "display.hpp"
#include "file.hpp"
#include "user.hpp"
#include <vector>
using namespace std;


int main() {
    //Display(intro);
    vector<string> target = GetUsers();

    for(string info : target) {
        cout << info << endl;
    }
}
