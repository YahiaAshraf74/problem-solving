class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cnt = 1 , mx = 0 ; 
        if (nums.size() < 1 ) return 0 ; 
        for (int i = 0 ; i < nums.size()-1 ; i++ ) {
        	if (nums[i] < nums[i+1])
        		++cnt ; 
        	else {
        		mx = max (mx , cnt) ;
        		cnt = 1 ; 
        	}
        }
        mx = max (mx , cnt) ; 
        return mx ; 
    }
};
