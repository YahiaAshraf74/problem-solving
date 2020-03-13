class Solution {
public:
    string reverseString(string s) {
    	int sz= (int)s.size();
        for (int i = 0; i<sz/2 ;i++){
        	swap(s[i],s[sz-i-1]) ; 
        }
        return s ; 
    }
};
