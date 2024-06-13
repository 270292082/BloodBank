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

vector<string> GetUsers(string path="Registration.dat", char separator=',');
vector<string> GetInfo(string username, string fname="Registration.dat");
vector<vector<string>> GetFilteredUsers(vector<string> filters);
void DisplayFilteredUsers(vector<vector<string>> users_info);
void DisplayUserInfoByName(vector<string> name);
vector<vector<string>> GetData(string path="Registration.dat");

#endif
