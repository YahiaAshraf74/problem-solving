class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	int p1 = 0 , p2 = 1 ;
    	while (p2 != nums.size()){
    		if (nums[p1] != 0 ) p1++ , p2++ ;
    		else if (nums[p2] == 0 ) p2++;
    		else {
    			swap(nums[p1],nums[p2]) ;
    			p1++ ;
    			p2++ ;
    		}
    	}
    }
};
