#pragma once
#include "typedefs.h"

// used only for quick copy-paste to LeetCode - avoid in production!
using namespace std;

/***************************************
1) Defanging an IP Address
https://leetcode.com/problems/defanging-an-ip-address/

Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
***************************************/

class EXPORT_SYM IP4Defang {
public:
    std::string defangIPaddr(const std::string& address);
};


/***************************************
2) Maximum Nesting Depth of the Parentheses
***************************************/
class NestingDepth {
public:
    int maxDepth(const std::string& s);
};

/***************************************
3) Bulb Switcher IV
https://leetcode.com/problems/bulb-switcher-iv/

There is a room with n bulbs, numbered from 0 to n-1, arranged in a row from left to right. Initially all the bulbs are turned off.
Your task is to obtain the configuration represented by target where target[i] is '1' if the i-th bulb is turned on and is '0' if it is turned off.
You have a switch to flip the state of the bulb, a flip operation is defined as follows:

Choose any bulb (index i) of your current configuration.
Flip each bulb from index i to n-1.
When any bulb is flipped it means that if it is 0 it changes to 1 and if it is 1 it changes to 0.

Return the minimum number of flips required to form target.

Example 1:

Input: target = "10111"
Output: 3
Explanation: Initial configuration "00000".
flip from the third bulb:  "00000" -> "00111"
flip from the first bulb:  "00111" -> "11000"
flip from the second bulb:  "11000" -> "10111"
We need at least 3 flip operations to form target.
***********************************************************************/

class BulbSwitcher {
public:
    int minFlips(const string& target);
};

/***************************************
 * 4) Balanced brackets
 * https://leetcode.com/problems/valid-parentheses/
***********************************************************************/

class BalanceChecker {
public:
    bool isValid(string s);
};