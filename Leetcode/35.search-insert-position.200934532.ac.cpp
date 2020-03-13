class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0 , ed = (int)nums.size()-1 ;
        while (st <= ed){
        	int mid = (st+ed+1)/2;
        	if (nums[mid] > target) {
        		ed = mid-1 ;
        	}else if (nums[mid]<target){
        		st = mid+1 ;
        	}else{
        		return mid ;
        	}
        }
        return st ;
    }
};
