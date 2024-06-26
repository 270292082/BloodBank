#include "booking.hpp"
#include "user.hpp"
#include "csystem.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include "ansi.hpp"

using namespace std;


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

    file.close();

    return true;
}

void BookSlot(const users& user, string date, string time) {
    ofstream file("Bookings.dat", ios::app);
    if (!file) {
        cerr << "Unable to open file Bookings.dat" << endl;
        return;
    }

    file << date << ';' << time << ';'
        << user.fname << ' ' << user.lname << ';' // Full name
        << user.dob << ';'                       // DOB
        << VecstrToString(user.conditions) << ';'                  // Recent health condition
        << user.location << endl;                // Location

    file.close();
    cout << "Booking successful!" << endl;
}

bool IsValidTime(const std::string& time) {
    // Regular expression to match the time format
    std::regex time_format(R"((0[1-9]|1[0-2]):[0-5][0-9] (AM|PM))");

    // Check if the time matches the format
    if (!std::regex_match(time, time_format)) {
        return false;
    }

    // Extract the hour and period
    int hour = std::stoi(time.substr(0, 2));
    std::string period = time.substr(6, 2);

    // Validate the hour based on the period
    if ((period == "AM" && hour >= 9 && hour <= 11) ||
        (period == "PM" && ((hour == 12) || (hour >= 1 && hour <= 4)))) {
        return true;
    }

    return false;
}

void FileCreate(){
    ofstream file("Bookings.dat");

    if (!file) {
        cout << CRED << "The file couldn't have been created!" << CDEF << endl;
        return;
    }


}

void DonorBooking(users& user) {
    string date, time;
    bool slotAvailable = false;

    while (!slotAvailable)
    {
        cout << "Enter date for donation (MM/DD/YYYY): ";
        cin.ignore();
        getline(cin, date);
        cout << "Enter time for donation (e.g., 09:00 AM): ";
        getline(cin, time);

        if (!IsValidTime(time)) {
            cout << "Invalid time slot. Please choose a time between 09:00 AM and 04:00 PM." << endl;
            continue;
        }

        FileCreate();

        if (CheckSlotAvailability(date, time)) {
            slotAvailable = true;
            BookSlot(user,date, time);
        }
        else {
            cout << "The selected slot is already taken. Please choose another slot." << endl;
        }
    }
}





