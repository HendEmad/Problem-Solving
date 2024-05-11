class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int sz=hours.size(),len=0;
        for(int i=0;i<sz;i++){
           int t=0,nt=0;
           for(int j=i;j<sz;j++){
                if(hours[j]>8)
                    t++;
                else
                    nt++;  
                if(nt<t)
                    len=max(len,j-i+1);
            }
        }
            return len;
    }
};