class Solution {
public:
	bool same(char c1, char c2) {
		return ((c1 == ')' && c2 == '(') || (c1 == '}' && c2 == '{')
				|| (c1 == ']' && c2 == '['));
	}
	bool isValid(string s) {
		int sz = (int) s.size();
		if (sz & 1)
			return false;
		map<char, bool> mp;
		mp['('] = mp['{'] = mp['['] = true;
		mp[')'] = mp['}'] = mp[']'] = false;
		stack<char> stk;
		for (int i = 0; i < sz; i++) {
			if (mp[s[i]])
				stk.push(s[i]);
			else if (!stk.empty()){
				if (same(s[i],stk.top())) {
					stk.pop();
				} else {
					return false;
				}
			}
		}
		return stk.empty();
	}
};
