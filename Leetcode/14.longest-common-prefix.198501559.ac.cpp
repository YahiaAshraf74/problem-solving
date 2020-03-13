class Solution {
public:
	void getCommonPrefix(string& s1, string& s2) {
		string temp = "";
		for (int i = 0; (i < min((int)s1.size(),(int)s2.size())); i++) {
			if (s1[i] != s2[i])
				break;
			temp += s1[i];
		}
		s1 = temp;
	}
	string longestCommonPrefix(vector<string>& s) {
		if (s.empty())
			return "";
		string prefix = s[0];
		for (int i = 1; i < (int)s.size(); i++) {
			getCommonPrefix(prefix , s[i]);
		}
		return prefix ;
	}
};
