class Solution {
public:
    int minInsertions(string s) {
        stack<char>st;
        int ans=0;
        int i=0;

        while(i<s.length()){
            if(s[i]=='('){
                st.push(s[i]);
                i++;
            }
            else if(s[i]==')'){
                if(st.empty()){
                    if((i+1)<s.length()){
                        if(s[i+1]!=')'){
                            ans+=2;
                            i++;
                        }
                        else{
                            ans++;
                            i+=2;
                        }
                    }
                    else{
                        ans+=2;
                        i++;
                    }
                }
                else{
                    st.pop();
                    if((i+1)<s.length()){
                        if(s[i+1]!=')'){
                            ans+=1;
                            i++;
                        }
                        else
                            i+=2;
                    }
                    else{
                        ans++;
                        i++;
                    }
                }
            }
        }

        while(!st.empty()){
            ans+=2;
            st.pop();
        }
        
        return ans;
    }
};