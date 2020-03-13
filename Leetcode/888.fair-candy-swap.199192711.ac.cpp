class Solution {
public:
    vector<int> fairCandySwap(vector<int> A, vector<int> B) {
        int sumA = 0, sumB = 0;
        for(int num : A) 
            sumA += num;
        bool set[100001] = {};
        for(int num : B) 
            sumB += num,set[num] = true;
        int diff = (sumA - sumB) >> 1;
        for(int num : A) {
            int temp = num - diff;
            if(temp > 0 && temp < 100001 && set[temp]) {
                return {num, temp};
            }
        }
    }
};
