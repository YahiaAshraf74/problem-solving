class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> nums_1 = nums, ans;
        sort(nums_1.begin(), nums_1.end());

        int  nums_left = 0, nums_right = nums.size() - 1;
        bool bool_1 = true, bool_2 = true;

        while (nums_left < nums_right) {
            if (nums_1[nums_left] + nums_1[nums_right] < target) {
                ++nums_left;
            } else if (nums_1[nums_left] + nums_1[nums_right] > target) {
                --nums_right;
            } else {
                break;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (bool_1 && nums[i] == nums_1[nums_left]) {
                ans.push_back(i);
                bool_1 = false;
            } else if (bool_2 && nums[i] == nums_1[nums_right]) {
                ans.push_back(i);
                bool_2 = false;
            }

            if (ans.size() == 2) {
                break;
            }
        }
        return ans;
    }
};
