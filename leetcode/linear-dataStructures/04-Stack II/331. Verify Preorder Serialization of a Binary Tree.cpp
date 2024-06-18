// Time complexity = O(n), space complexity = O(1)
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();
        if(n == 0)
            return true;

        if(preorder[0]=='#' && n == 1)
            return true;
        if(preorder[0]=='#' && n > 1)
            return false;
        
        int cnt = 1;
        bool next = true;

        for(int i = 0; i<n; i++){
            if(preorder[i] == ','){
                next = true;
                continue;
            }

            if(cnt-1 < 0)
                return false;

            if(preorder[i] == '#'){
                cnt--;
            }
            else{
                if(next)
                    cnt++;
                next = false;
            }

        }

        return (cnt == 0);
    }
};