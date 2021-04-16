#include "../include/StringOperations.h"

using namespace std;

vector<string> StringOperations::split (string s, char delimiter) {
    size_t pos_start = 0, pos_end, delim_len = 1;
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

void StringOperations::trimRight(string &str)
{
	if (str.empty())
		return;
 
	string::const_iterator ch = str.end() - 1;
	while (' ' == *ch || '\r' == *ch || '\n' == *ch || '\t' == *ch || '\f' == *ch)
	{
		str.erase(str.find_last_not_of(*ch) + 1);
		ch = str.end() - 1;
	}
}