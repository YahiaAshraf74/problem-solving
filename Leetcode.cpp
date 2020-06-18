#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <complex>
#include <string>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <assert.h>

using namespace std;

class Solution {
public:
    bool checkIsIPv4(string s) {
        if(s.size() == 0)
            return false;
        for(char c : s)
            if(!(c>='0' && c<='9'))
                return false;
        int num = stoi(s);
        string num2 = to_string(num);
        return num >= 0 && num <= 255 && num2.size() == s.size() && s.size() > 0;
    }

    bool checkIsIPv6_(string s) {
        bool capital = false, small = false;
        for(char c : s){
            if(!(c>='0' && c<='9')){
                capital |= isupper(c);
                small |= islower(c);
            }
        }
        return s.size() > 0 && s.size() <= 4 && !(small && capital);
    }
    bool checkIsIPv6(string block) {
        string validIPv6Chars = "0123456789abcdefABCDEF";
        if (block.size() > 0 && block.size() <= 4) {
            for (int i = 0; i < block.size(); i++) {
                char c = block[i];
                if (validIPv6Chars.find(c) == string::npos)
                    return false;
            }
            return true;
        }
        return false;
    }

    string validIPAddress(string IP) {
        if (IP.size() < 7 || IP.size() > 39) // || (IP.find('.') != IP.end() && IP.find(':') != IP.end())
            return "Neither";
        bool isIPv4 = true, isIPv6 = true;
        if (IP.size() <= 15 && IP.find(".") != string::npos) { // IPv4
            isIPv6 = false;
            string delimiter = ".";
            int cntNum = 0, pos;
            while ((pos = IP.find(delimiter)) != string::npos) {
                isIPv4 &= checkIsIPv4(IP.substr(0, pos));
                IP.erase(0, pos + delimiter.length());
                cntNum++;
            }
            isIPv4 &= cntNum == 3 && checkIsIPv4(IP);
        } else if (IP.size() >= 15 && IP.find(":") != string::npos) { // IPv6
            isIPv4 = false;
            string delimiter = ":";
            int cntNum = 0, pos;
            while ((pos = IP.find(delimiter)) != string::npos) {
                isIPv6 &= checkIsIPv6(IP.substr(0, pos));
                IP.erase(0, pos + delimiter.length());
                cntNum++;
            }
            isIPv6 &= cntNum == 7 && checkIsIPv6(IP);
        }
        return (isIPv4) ? "IPv4" : (isIPv6) ? "IPv6" : "Neither";
    }
};
class Leetcode {
public:
    void solve(istream &cin, ostream &cout) {
        Solution sol;
        cout << sol.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334");
    }
};