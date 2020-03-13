class Solution {
public:
	int strStr(string haystack, string needle) {
		int szHay = haystack.size(), szNeedle = needle.size();
		int p1 = 0, p2 = 0, idx = -1;
		if (szNeedle == 0 || haystack == needle)
			return 0;
		if (szNeedle > szHay)
			return -1;
		while (p1 < szHay-szNeedle+1){
			idx = p1 ;
			while (haystack[p1] == needle[p2] && p2 <= szNeedle-1){
				++p1;
				++p2 ;
			}
			if (p2 == szNeedle){
				return idx ;
			}
			p1 = idx ;
			++p1 ;
            p2 = 0 ; 
		}
		return -1 ;
	}
};
