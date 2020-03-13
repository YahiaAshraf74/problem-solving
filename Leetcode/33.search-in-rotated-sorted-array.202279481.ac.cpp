class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0 , ed = nums.size() -1 , mid ; 
        while (st <=ed){
            mid = st + ((ed-st)>>1) ; 
            if (nums[mid] == target){
                return mid ;
            }else if(nums[mid] <= nums[ed]) {
                if (target > nums[mid] && target <= nums[ed] )
                    st = mid + 1 ; 
                else 
                    ed = mid - 1 ; 
            }else {
                if (target < nums[mid] && target >= nums[st])
                    ed = mid - 1 ;
                else 
                    st = mid + 1 ;
            }
        }
        return -1 ; 
    }
};
