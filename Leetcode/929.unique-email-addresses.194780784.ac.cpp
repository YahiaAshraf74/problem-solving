#include <ios>
static auto fastInput = []() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> ans;
		for (string &email : emails) {
			int at = email.find('@');
			string name = email.substr(0, at);
			string domain = email.substr(at);
			name.erase( remove_if(name.begin(), name.end(),
							[]( char c ) {return c == '.';}),
					name.end());
			ans.insert(name.erase(name.find('+')) + domain);
		}
		return ans.size();
	}
};
