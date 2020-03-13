class Solution {
public:
    bool validPalindrome(string s) {
        bool first = true ; 
        for(int i = 0;i<s.size()/2;i++){
            if(s[i] != s[s.size()-i-1] && first){
                first = false ; 
            }else if(s[i] != s[s.size()-i-1]){
                return false ; 
            }
        }
        return true ;
    }
};
