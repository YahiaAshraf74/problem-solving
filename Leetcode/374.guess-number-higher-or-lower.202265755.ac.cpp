// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int st = 1 , ed = n , mid; 
        while (st<=ed){
            mid = st + ((ed-st)>>1) ; 
            if (guess(mid) == 0)
                return mid;
            else if ( 0 > guess(mid)){
                ed = mid - 1 ; 
            }else{
                st = mid +1 ; 
            }
        }
        return -1 ; 
    }
};
