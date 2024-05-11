class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long sz = 0;
        // first calculate total decoded length size
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z') sz++;
            else sz *= (long long)(s[i] - '0');
        }
        // after that size if "string.length"x ,then do k %= (string.length());
        // where , 2 <= x <= 9
        for(int i = s.size()-1 ; i >= 0 ; i--){
            if(s[i] >= 'a' && s[i] <= 'z'){
                if(k == sz || k == 0) return string(1,s[i]);
                sz--;
            }
            else{
                int n = (s[i] - '0');
                sz /= n;
                k %= sz;
            }
        }

        return "";
    }
};