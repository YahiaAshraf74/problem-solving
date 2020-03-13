class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();  
        for (int i = 1; i < size - 1; i++) {
            int mLeft = 0, mRight = 0;
            for (int j = i; j >= 0; j--) 
                mLeft = max(mLeft, height[j]);
            for (int j = i; j < size ; j++) 
                mRight = max(mRight, height[j]);
            ans += min(mLeft, mRight) - height[i];
        }
    return ans;
    
    }
};
