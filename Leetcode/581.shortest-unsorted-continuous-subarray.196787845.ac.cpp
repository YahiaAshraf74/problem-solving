class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		int sz = (int) nums.size();
		int s = 0, e = sz - 1, mx , mn ;
		for (s = 0; s < sz - 1; s++) {
			if (nums[s] > nums[s + 1])
				break;
		}
		if (s == sz-1) return 0 ; 
		for (e = sz - 1; e > 0; e--) {
			if (nums[e] < nums[e - 1])
				break;
		}
		mx = nums[s] , mn = nums[s] ;
		for (int i = s + 1 ; i <= e; i++) {
			mx = max(mx, nums[i]);
			mn = min(mn, nums[i]);
		}
		for (int i = 0; i < s; i++) {
			if (nums[i] > mn) {
				s = i;
				break;
			}
		}
		for (int i = sz - 1; i > e ; i--) {
			if (nums[i] < mx) {
				e = i;
				break;
			}
		}
		return e-s+1 ;
	}
};
