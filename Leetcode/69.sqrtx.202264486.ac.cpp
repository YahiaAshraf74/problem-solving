int x = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();
class Solution {
public:
    int mySqrt(int x) {
    	int st =0 , ed = x , mid ;
    	if (x==0 || x==1) return x ;
    	while (st <= ed ) {
    		mid = st+((ed-st)>>1);
    		if (mid == x/mid ) return mid ;
    		if (mid > (x/mid) )  ed = mid -1 ;
    		else   st = mid+1  ;
    	}
    	return st-1 ;
    }
};
