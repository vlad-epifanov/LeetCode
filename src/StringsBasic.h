

#pragma once
#include <string>
#include <vector>

#define EXPORT_SYM __declspec(dllexport)

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
