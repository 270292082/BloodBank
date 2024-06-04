#ifndef USER_HPP
#define USER_HPP

#include <string>
using namespace std;

struct users {
	string username = "N/A";
	string password = "N/A";
	string dob="N/A";
	string nationality="N/A";
	string ethnicity="N/A";
	string gender="N/A";
	string* conditions=nullptr;
	string blood_group="N/A";
	string phone="N/A";
	string email="N/A";
	string location="N/A";
	string last_donation="N/A";
	string category="N/A";
};

#endif
