class Solution {
public:
	int numJewelsInStones(string J, string S) {
		/*
		 * 	unordered_set is O(1) in average and O(n) in worth case,
		 *  but set is O(log n) in average and worth case.
		 *	that's why use
		 */
		int res = 0;
		unordered_set<char> setJ(J.begin(), J.end());
		for (char s : S)
			if (setJ.find(s) != setJ.end())
				res++;
		return res;
	}
};
