class Solution {
public:
	 bool isPowerOfThree(int n) {
    // 1162261467 is 3^19,  3^20 will overflow int32.
    return (n > 0 && 1162261467 % n == 0);
  }
};
