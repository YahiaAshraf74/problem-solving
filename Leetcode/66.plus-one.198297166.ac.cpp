class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz = (int)digits.size() -1 ;
        while ( digits[sz] ==9 ){
        	digits[sz] = 0 ;
        	--sz ;
        }
        if (sz==-1) {
        	digits.insert(digits.begin(),1) ;
        }
        else digits[sz] += 1 ;
        return digits ;
    }
};

