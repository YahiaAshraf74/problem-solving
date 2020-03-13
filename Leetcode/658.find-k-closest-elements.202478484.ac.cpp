class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int st = 0, ed = arr.size() - 1, mid;
		vector<int> ans;
		while (st <= ed) {
			mid = st + ((ed - st) >> 1);
			if (arr[mid] < x) {
				st = mid + 1;
			} else {
				ed = mid - 1;
			}
		}
		int sz = (int)arr.size() ;
		if (st == 0){
			for (int i = st ; i < sz && k ;i++)
				ans.push_back(arr[i]) ,--k ;
		}else if (st ==sz-1){
			for (int i = st ; i >=0 && k ; i--)
				ans.push_back(arr[i]) ,--k ;
		}else {
			for (int i = st, j = st - 1; k;) {
				if (((abs(arr[i] - x) < abs(arr[j] - x) && i <sz) || j == -1)) {
					ans.push_back(arr[i]);
					i++;
					k--;
				} else  {
					ans.push_back(arr[j]);
					j--;
					k--;
				}
			}
		}
		sort(ans.begin(),ans.end()) ;
		return ans;
	}
};
