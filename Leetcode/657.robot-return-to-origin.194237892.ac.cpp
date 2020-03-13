class Solution {
public:
	bool judgeCircle(string moves) {
		int cmap[26] = { 0 };
		for (const auto &c : moves)
			cmap[c - 'A']++;
		return cmap['U' - 'A'] == cmap['D' - 'A']
				&& cmap['L' - 'A'] == cmap['R' - 'A'];
	}
};
