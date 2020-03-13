class Solution {
public:
    bool isAnagram(string s, string t) {
    	int freq[1<<8]={0} ;
    	if (s.size() != t.size()) return false ;
    	for (int i=0 ; i< (int)s.size();i++){
    		freq[s[i]-'a']++;
    	}
    	for (int i=0 ; i< (int)s.size();i++){
			if (--freq[t[i]-'a'] < 0 )
				return false ;
		}
    	return true ;
    }
};
