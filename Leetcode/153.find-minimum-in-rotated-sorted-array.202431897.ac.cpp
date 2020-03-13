class Solution {
public:
    bool check (vector<int> &v , int idx ){
        if (idx == 0 && v[idx] < v[idx+1])
            return true;
        if (idx== v.size()-1 && v[idx] < v[idx-1])
            return true; 
        if (v[idx] < v[idx+1] && v[idx] < v[idx-1])
            return true ;
        return false ;
    }
    int findMin(vector<int>& nums) {
        int st = 0 , ed = nums.size() - 1 , mid ; 
        while (st < ed){
            mid = st + ((ed-st)>>1) ; 
            if (nums[mid] < nums[ed]){
                if (check(nums,mid))
                    return nums[mid] ; 
                ed = mid - 1 ; 
            }else {
                if (check(nums,mid))
                    return nums[mid] ; 
                st = mid + 1 ; 
            }
        }
        return nums[st] ; 
    }
};
