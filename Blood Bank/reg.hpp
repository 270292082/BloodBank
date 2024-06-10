#ifndef REG_HPP
#define REG_HPP

#include <string>
#include <vector>
using namespace std;

string SelectUsername(vector<string> usernames, vector<string> info_name);
string SelectCategory();
string SelectConditions();
void StoreConfig(vector<string> info);
void DonorRegInit();


#endif
