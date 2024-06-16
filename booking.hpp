#ifndef BOOKING_HPP
#define BOOKING_HPP

#include <vector>
#include <string>

void DonorBooking(const std::vector<std::string>& user);
bool CheckSlotAvailability(const std::string& date, const std::string& time);
void BookSlot(const std::vector<std::string>& user, const std::string& date, const std::string& time);
bool IsValidTime(const std::string& time);

#endif
