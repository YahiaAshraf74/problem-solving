class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	 int missing = (int)nums.size();
		for (int i = 0; i <(int)nums.size() ; i++) 
			missing ^= (i ^ nums[i]);
		
		return missing;
    }
};
