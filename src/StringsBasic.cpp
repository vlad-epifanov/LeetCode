

#include "StringsBasic.h"
#include <cassert>
#include <stack>


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

int BulbSwitcher::minFlips(const string& target)
{
    // count all the changes
    char prevC = '0';
    int counter = 0;
    for (auto curC : target) {
        if (prevC != curC) {
            counter++;
            prevC = curC;
        }
    }
    return counter;
}

/************************************************************************************/
// Straightforward - Stack
// O(n) + O(n)

bool areMatching(char cl, char cr)
{
    return (cl == '{' && cr == '}') || (cl == '[' && cr == ']') || (cl == '(' && cr == ')');
}

bool BalanceChecker::isValid(string& s)
{
    std::stack<char> brackets;
    for (char c: s) {
        if (!brackets.empty() && areMatching(brackets.top(), c)) {
            brackets.pop();
        } else {
            brackets.push(c);
        }
    }
    return brackets.empty();
}

/************************************************************************************/

int MinStepToAnagram::minSteps(const string& s, const string& t)
{
    if ((s.size() != t.size())) 
        return -1;
    if (s.empty())
        return 0;
    vector<int> sCache(26,0);
    vector<int> tCache(26,0);

    for (auto c : s)
        sCache[c-'a']++;
    for (auto c : t)
        tCache[c-'a']++;

    int steps = 0;
    for (int i = 0; i < 26; i++) {
        steps += std::abs(sCache[i] - tCache[i]);
    }

    return steps / 2;
}


/************************************************************************************/