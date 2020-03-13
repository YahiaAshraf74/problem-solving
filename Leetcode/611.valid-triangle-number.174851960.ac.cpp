class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        sort(nums.rbegin(), nums.rend());
        int n = nums.size();
        int ans = 0;
        for (int c = 0; c < n-2; ++c) {        
            int l = c + 1;
            int r = n - 1;
            while (l < r) {
                if (nums[r] + nums[l] > nums[c]) {
                    ans += (r - l);
                    ++l;
                } else {
                    --r;
                }
            }
        }
        
        return ans;
    }
};
