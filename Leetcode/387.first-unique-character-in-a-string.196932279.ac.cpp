class Solution {
public:
	int firstUniqChar(string s) {
		int freq[26] = { 0 }, ans = -1;
		for(char ch : s) {
			freq[ch-'a']++;
		}
		for(char ch : s){
			if (freq[ch-'a'] == 1 ) return ans+1 ; 
			++ans ; 
		}
		return -1 ; 
	}
};
