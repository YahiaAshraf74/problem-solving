class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
        unordered_map<int, int> freq;
		if (nums1.empty() || nums2.empty()) 
			return res;
		for (auto n : nums1) 
			freq[n]++;
		
		for (auto n : nums2) 
			if (freq.find(n) != freq.end() && --freq[n] >= 0) 
				res.push_back(n);
			
		
		return res;
	}
};
