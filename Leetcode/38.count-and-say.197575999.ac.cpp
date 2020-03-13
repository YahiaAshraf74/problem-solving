class Solution {
public:
    string countAndSay(int n) {
    	string s = "1" , s1 ="1" ;
    	n--;
    	while (n--) {
    		s = s1 ,s1 = "" ;
    		int sz = (int)s.size() , cnt =1 ;
    		for (int i = 0 ; i < sz ; i++) {
    			while (s[i] == s[i+1]) 
    				i++,cnt++;
    			s1 += (cnt + '0') ;s1+= s[i];
                cnt=1 ; 
    		}
    	}
    	return s1 ;
    }
};
