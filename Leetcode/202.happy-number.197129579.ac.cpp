class Solution {
public:
	bool isHappy(int n) {
		int happynum = 0;
		unordered_set<int> st;
		st.insert(n);
		while (true) {
			while (n) {
				happynum += (n % 10) * (n % 10);
				n /= 10;
			}
			if (happynum == 1)
				return true;
			if (st.count(happynum) > 0)
				return false;
			st.insert(happynum);
			n = happynum;
			happynum = 0 ;
		}
	}
};
