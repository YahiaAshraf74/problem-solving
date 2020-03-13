#include <ios>
static auto fastInput = []() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> res;
		int sz =(int)nums.size() ;
		for (int i = 0; i < sz; ++i) {
			int idx = abs(nums[i]) - 1;
			if (nums[idx] > 0)
				nums[idx] *= -1;
		}
		for (int i = 0; i <sz; ++i) {
			if (nums[i] > 0)
				res.push_back(i + 1);
		}
		return res;
	}
};
