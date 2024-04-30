class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector <int> answer(n);

        int left = 1, right = n;
        
        for(int i = 0; i < n; i++){
            if(k > 1){
                answer[i] = (k % 2 == 0) ? right-- : left++;
                k--;
            }
            else
                answer[i] = left++;
        }

        return answer;
    }
};
