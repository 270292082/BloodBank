#include <string>
#include <vector>
using namespace std;

void sleep(int millisecs);
void TypeText(string msg, int milliseconds);

vector<string> StringSeparator(string raw_msg, char separator=',');
int FileStore(string msg="", bool format=false, string path="Registration.dat");
