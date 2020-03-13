#include <ios>
static auto fastInput = []() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
	 vector<int> sortArrayByParityII(vector<int>& A) {
		 int sz = (int)A.size() ;
		vector <int> ans(sz);
		ans.resize(sz) ;
		for (int i = 0 , j = 0 , k = 1; i < sz ; i++ ){
			if (A[i]%2==0){
				ans[j] = A[i] ;
				++++j ;
			}else {
				ans[k] = A[i] ;
				++++k ;
			}
		}
		return ans ;
	}
};
