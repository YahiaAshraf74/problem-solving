// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       
        int st = 0 , ed = n - 1 ,mid ; 
        while (st < ed ){
            mid = st + ((ed-st+1)>>1) ; 
            if(isBadVersion(mid)==false){
                st = mid ;
            }else {
                ed = mid - 1 ; 
            }
        }
        return st + 1 ; 
    }
};
