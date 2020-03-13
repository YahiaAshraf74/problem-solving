class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0 , ed = nums.size() , mid ; 
        while (st<=ed){
            mid = st + ((ed-st)>>1) ; 
            if (nums[mid] == target){
                return mid ; 
            }else if (nums[mid] > target){
                ed = mid - 1 ; 
            }else {
                st = mid +1 ; 
            }
        }
        return -1 ; 
    }
};
