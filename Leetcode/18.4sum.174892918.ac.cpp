class Solution {
public: 
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        std::sort(a.begin(), a.end());
        set<vector<int>> set;
        for (int i = 0; i + 3 < a.size(); i++) {
            for (int j = i + 1; j + 2 < a.size(); j++) {
                for (int k = j + 1, l = a.size() - 1; k < l; ) {
                    int sum = a[i] + a[j] + a[k] + a[l];
                    if (sum == target) {
                        set.insert(vector<int>({ a[i], a[j], a[k], a[l] }));
                        k++;
                        l--;
                    }
                    else if (sum < target) {
                        k++;
                    }
                    else {
                        l--;
                    }
                }
            }
        }
        vector<vector<int>> res;
        for (auto group : set) {
            res.push_back(group);
        }

        return res;
    }
};
