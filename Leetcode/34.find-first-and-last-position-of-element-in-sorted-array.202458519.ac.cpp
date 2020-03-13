class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int st = 0 , ed = nums.size() -1,mid ; 
        vector<int> ans(2) ;
        ans[0] = -1 , ans[1] = -1 ; 
        bool isFound = false ; 
        while (st<=ed){
            mid = st + ((ed-st)>>1) ; 
            if (nums[mid]==target){
                isFound = true  ;  
                break ; 
            }else if (nums[mid] > target ){
                ed = mid -1 ; 
            }else {
                st = mid + 1 ; 
            }
        }
        if (!isFound)
            return  ans ; 
        st = 0 , ed = nums.size() - 1 ; 
        while (st < ed ){
            mid = st + ((ed-st)>>1) ; 
            if (nums[mid] > target){
                ed = mid - 1 ;
            }else if (nums[mid] < target){
                st = mid +1 ; 
            }else {
                ed = mid  ;
            }
        }
        ans[0] = st ;
        st = 0 , ed = nums.size() - 1 ; 
        while (st < ed ){
            mid = st + ((ed-st+1)>>1) ; 
            if (nums[mid] < target){
                st = mid +1 ;
            }else if (nums[mid] > target){
                 ed = mid -1 ;
            }else {
                st = mid  ;
            }
        }
        ans[1] = st ; 
        return ans; 
    }
};
