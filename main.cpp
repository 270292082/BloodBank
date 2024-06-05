#include <iostream>
#include "display.hpp"
#include "file.hpp"
#include <vector>
using namespace std;


int main() {
    Display(intro);
    vector<string> target = FileGetInfo("Miokat");

    for(string info : target) {
        cout << info << endl;
    }
}
