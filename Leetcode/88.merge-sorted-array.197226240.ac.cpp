class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return ; 
		int sz= nums1.size() , sz1 = nums2.size() ; 
        while (sz1--){
            nums1.pop_back() ; 
        }
        nums1.insert( nums1.end(), nums2.begin(), nums2.end() );
        sort(nums1.begin(),nums1.end());
	}
};
