class Solution {
public:
    string removeOuterParentheses(string s) {
        string ns = ""; 
        for(int i = 0 ; i < s.size() -1; i++){
            if(s[i] == '(' && s[i+1] == ')'){
                ns += s[i];
                ns += s[i+1] ;
            }
        }
        return ns ; 
    }
};
