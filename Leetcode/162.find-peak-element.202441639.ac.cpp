class Solution {
public:
    bool check(vector<int> &v , int idx){
        if (v[idx] > v[idx+1] && v[idx] > v[idx-1])
            return true ; 
        return false ;
    }
    int findPeakElement(vector<int>& nums) {
        int st = 0 , ed = nums.size()-1 , mid ;
        if (nums[0] > nums[1])
            return 0;
        else if (nums[ed] > nums[ed-1])
            return ed ; 
        while (st<ed){
            mid = st + ((ed-st)>>1)  ;
            if (check(nums,mid))
                return mid ; 
            else if (nums[mid] < nums[mid+1]){
                st = mid + 1 ;
            }else if (nums[mid] < nums[mid-1]){
                ed = mid - 1 ; 
            }
        }
        return st ; 
    }
};
