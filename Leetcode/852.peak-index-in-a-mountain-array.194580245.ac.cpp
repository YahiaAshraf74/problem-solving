#include <ios>
static auto x = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A, int st = 0, int end = INT_MAX) {
  auto m = st + (min(end, (int)A.size() - 1) - st) / 2;
  if (A[m] > A[m - 1] && A[m + 1] > A[m]) 
      return peakIndexInMountainArray(A, m, min(end, (int)A.size() - 1));
  if (A[m] < A[m - 1] && A[m + 1] < A[m]) 
      return peakIndexInMountainArray(A, st, m);
  return m;
}
};
