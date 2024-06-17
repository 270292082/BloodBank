#ifndef BOOKING_HPP
#define BOOKING_HPP

#include <string>
#include "user.hpp"
using namespace std;

void DonorBooking(users& user);
bool CheckSlotAvailability(const std::string& date, const std::string& time);
void BookSlot(const users& user, string date, string time);
bool IsValidTime(const std::string& time);

#endif