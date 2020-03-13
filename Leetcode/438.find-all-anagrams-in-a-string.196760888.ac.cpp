class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector <int> ans , cntS(26,0) , cntP(26,0);
        int szP = p.size() , szS = s.size(); 
		for (int i = 0 ; i<szP; i++){
			cntP[p[i]-'a']++;
			cntS[s[i]-'a']++;
		}
        if (cntS==cntP) ans.push_back(0) ; 
		for (int i = szP;i<szS;i++){
			cntS[s[i]-'a']++;
			cntS[s[i-szP]-'a']--;
			if (cntS == cntP ) ans.push_back(i-szP+1) ;
		}
 		return ans ;
	}
};
