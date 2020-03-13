class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int cnt = 1 , majIdx = 0 ; 
        for (int i = 1 ; i< nums.size();i++){
            if (nums[i] == nums[majIdx])
                ++cnt;
            else 
                --cnt;
            if (!cnt)
                majIdx = i , cnt = 1;
        }
        return nums[majIdx] ;
	}
};
