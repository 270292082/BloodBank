#ifndef REG_HPP
#define REG_HPP

#include <string>
#include <vector>
using namespace std;

string SelectUsername(vector<string> usernames, vector<string> info_name);
string SelectCategory();
string SelectConditions();
void StoreConfig(vector<string> info);
vector<string> CollectUsrInfo(string username, vector<string> info_name);
void DonorRegInit();


#endif
