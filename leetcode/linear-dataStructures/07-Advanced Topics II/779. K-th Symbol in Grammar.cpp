class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0; // Base case
        
        // Calculate the position of k in the (n-1)th row
        int mid = pow(2, n - 1) / 2;
        
        // If k is in the first half of the row, the result is the same as in the (n-1)th row
        if (k <= mid) {
            return kthGrammar(n - 1, k);
        } else {
            // If k is in the second half of the row, the result is the complement of the symbol in the (n-1)th row
            return 1 - kthGrammar(n - 1, k - mid);
        }
    }
};
