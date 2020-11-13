

#include "StringsBasic.h"
#include <cassert>

using namespace std;

string IP4Defang::defangIPaddr(const string& address)
{
	//Assumption: input is valid IPv4
	std::string result;
	for (char c : address) {
		if (c == '.') {
			result.append("[.]");
		} else {
			result.push_back(c);
		}
	}
	return result;
}

int NestingDepth::maxDepth(const std::string& s)
{
	int curD = 0;
	int maxD = 0;
	for (auto c : s) {
		if (c == '(') {
			curD++;
		} else if (c == ')') {
			curD--;
		}
		if (curD > maxD) {
			maxD = curD;
		}
	}
	assert(curD == 0);
	return maxD;
}

