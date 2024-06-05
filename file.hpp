#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include <vector>
using namespace std;

int FileStore(string name, string msg="");
vector<string> FileGetInfo(string username, string fname="Donor_Registration.dat");

#endif
