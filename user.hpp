#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include <string>
using namespace std;

struct users {
	string username = "N/A";
	string password = "N/A";
    string fname = "N/A";
    string lname = "N/A";
	string dob="N/A";
	string nationality="N/A";
	string ethnicity="N/A";
	string gender="N/A";
	vector<string> conditions;
	string blood_group="N/A";
	string phone="N/A";
	string email="N/A";
	string location="N/A";
	string last_donation="N/A";
	string category="N/A";
};

vector<string> GetUsers(string path="Donor_Registration.dat", char separator=',');
vector<string> GetInfo(string username, string fname="Donor_Registration.dat");

#endif
