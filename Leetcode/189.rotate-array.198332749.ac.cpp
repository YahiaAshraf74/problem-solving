class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		vector<int> temp(nums);
		int sz = (int) nums.size();
		for (int i = 0; i < sz; i++)
			nums[(i + k) % sz] = temp[i];

	}
};
