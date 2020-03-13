class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	unordered_set<int > freq ;
    	for (auto num : nums){
    		if (freq.count(num)) return true ;
    		freq.insert(num) ; 
    	}
    	return false ;
    }
};
