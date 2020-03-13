class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		string mp[27] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
				"....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
				"--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--",
				"--.." };
		unordered_set<string> codes;
		for (auto word : words) {
			string temp = "";
			for (auto ch : word) {
				temp += mp[ch - 'a'];
			}
			codes.insert(temp);
		}
		return codes.size();
	}
};

