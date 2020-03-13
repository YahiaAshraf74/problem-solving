class Solution {
public:
	int reverse(int x) {
		int sign = -1, lastDigit;
		long long ans = 0;
		while (x) {
			lastDigit = x % 10;
			ans = ans * 10 + lastDigit;
			x /= 10;
		}
		if (ans > INT_MAX || ans < INT_MIN)
			return 0;
		return (int)ans;

	}
};
