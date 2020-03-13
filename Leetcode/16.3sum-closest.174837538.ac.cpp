class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int difference=INT_MAX , sum = 0 , temp = 0 ;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int j = i+1, k = nums.size()-1;
            while(j<k){
                temp = nums[i]+nums[j]+nums[k] ; 
                if(temp==target)
                    return target;
                else if(abs(temp-target)<difference){
                    difference=abs(temp-target);
                    sum = temp ; 
                }
                if(temp<target)
                    j++;
                else
                    k--;
            }
        }
        return sum;
    }
};
