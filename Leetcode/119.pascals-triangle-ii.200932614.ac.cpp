class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if (rowIndex >= 0) {
            res.push_back(1);
        }
        for (int j = 1; j <= rowIndex; j++) {
            res.push_back((double)res.back() * (double)(rowIndex - j + 1) / (double)j);
        }
        return res;
    }
};
