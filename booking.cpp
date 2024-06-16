#include "booking.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

void DonorBooking(const vector<string>& user) {
    string date, time;
    bool slotAvailable = false;

    while (!slotAvailable) {
        cout << "Enter date for donation (MM/DD/YYYY): ";
        cin >> date;
        cout << "Enter time for donation (e.g., 09:00 AM): ";
        cin >> time;

        if (!IsValidTime(time)) {
            cout << "Invalid time slot. Please choose a time between 09:00 AM and 04:00 PM." << endl;
            continue;
        }

        if (CheckSlotAvailability(date, time)) {
            slotAvailable = true;
            BookSlot(user, date, time);
        }
        else {
            cout << "The selected slot is already taken. Please choose another slot." << endl;
        }
    }
}

bool CheckSlotAvailability(const string& date, const string& time) {
    ifstream file("Bookings.dat");
    if (!file) {
        cerr << "Unable to open file Bookings.dat" << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string booked_date, booked_time;

        getline(ss, booked_date, ';');
        getline(ss, booked_time, ';');

        if (booked_date == date && booked_time == time) {
            return false;
        }
    }

    return true;
}

void BookSlot(const vector<string>& user, const string& date, const string& time) {
    ofstream file("Bookings.dat", ios::app);
    if (!file) {
        cerr << "Unable to open file Bookings.dat" << endl;
        return;
    }

    file << date << ';' << time << ';'
        << user[2] << ' ' << user[3] << ';' // Full name
        << user[4] << ';'                   // DOB
        << user[13] << ';'                  // Recent health condition
        << user[11] << endl;                // Location

    cout << "Booking successful!" << endl;
}

bool IsValidTime(const string& time) {
    regex time_format("^(09|10|11|12|01|02|03|04):[0-5][0-9] (AM|PM)$");
    if (regex_match(time, time_format)) {
        int hour = stoi(time.substr(0, 2));
        string period = time.substr(6, 2);
        if ((period == "AM" && hour >= 9 && hour <= 11) || (period == "PM" && hour >= 12 && hour <= 4)) {
            return true;
        }
    }
    return false;
}
