class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
           //for inversing a decimal number, simply replace 2 by 10
            ans = ans * 2 + n % 2;
            n /= 2;
        }
        return ans;
    }
};
