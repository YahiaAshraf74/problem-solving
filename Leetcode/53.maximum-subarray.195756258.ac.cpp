#include <ios>
static auto fastInput = []() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMx = 0 , mx = nums[0]  ;
        for (int i=0 ;i< nums.size();i++){
        	curMx += nums[i] ;
        	mx = max (mx,curMx) ;
        	curMx  = max(curMx,0) ;
        }
        return mx ;
    }
};
