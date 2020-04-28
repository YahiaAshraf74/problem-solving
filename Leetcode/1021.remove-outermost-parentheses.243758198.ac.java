class Solution {
        public String removeOuterParentheses(String S) {
            StringBuilder nS = new StringBuilder(S);
            Stack<Character> st = new Stack<Character>() ;
            String ans = "" ;
            for(int i = 0 ;i < nS.length() ; i++){
                if(st.empty()){
                    st.push(nS.charAt(i)) ;
                }else if(st.sz() == 1 && nS.charAt(i) == ')' && st.peek() == '('){
                    st.pop() ;
                }else {
                    if(nS.charAt(i) == '(')
                        st.push(nS.charAt(i)) ;
                    else
                        st.pop() ;
                    ans += nS.charAt(i) ;

                }
            }
            return ans ;
        }
    }
