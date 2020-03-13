class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> mp;
		int num = 0;
		mp['I'] = 1, mp['V'] = 5, mp['X'] = 10, mp['L'] = 50, mp['C'] = 100, mp['D'] =
				500, mp['M'] = 1000;
		for (int i = 0; i < (int) s.size() ; i++) {
			if (mp[s[i]] < mp[s[i + 1]]) {
				num += mp[s[i+1]] - mp[s[i]] ;
				i++ ;
			}else
				num += mp[s[i]] ;
		}
		return num;
	}
};
