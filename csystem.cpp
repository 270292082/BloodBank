#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

void sleep(int millisecs) {
    this_thread::sleep_for(chrono::milliseconds(millisecs)); 
}

void TypeText(string msg, int milliseconds) {
    for (char c : msg) {
        cout << c << flush;
        sleep(milliseconds);
    }
    cout << endl;
}
