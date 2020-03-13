class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = 1, p1 = 0, p2 = 1, sz = (int) nums.size();
		if (sz == 0)
			return 0;
		while (p2 < sz) {
			if (nums[p2] != nums[p1]) {
                nums[p1+1] = nums[p2];
                ++p1;
				++len;
			}
            ++p2 ; 
		}
        if (len == 0)
			return 1;
		return len;
	}
};
