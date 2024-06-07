class NumArray {
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }
    
    void update(int index, int val) {
        update(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return sumRange(0, 0, n - 1, left, right);
    }
    
private:
    vector<int> st;
    int n;
    
    void build(vector<int>& nums, int v, int tl, int tr) {
        if (tl == tr) {
            st[v] = nums[tl];
        } else {
            int tm = tl + (tr - tl) / 2;
            build(nums, 2 * v + 1, tl, tm);
            build(nums, 2 * v + 2, tm + 1, tr);
            st[v] = st[2 * v + 1] + st[2 * v + 2];
        }
    }
    
    void update(int v, int tl, int tr, int index, int val) {
        if (tl == tr) {
            st[v] = val;
        } else {
            int tm = tl + (tr - tl) / 2;
            if (index <= tm) {
                update(2 * v + 1, tl, tm, index, val);
            } else {
                update(2 * v + 2, tm + 1, tr, index, val);
            }
            st[v] = st[2 * v + 1] + st[2 * v + 2];
        }
    }
    
    int sumRange(int v, int tl, int tr, int left, int right) {
        if (left > right) return 0;
        if (left == tl && right == tr) return st[v];
        int tm = tl + (tr - tl) / 2;
        return sumRange(2 * v + 1, tl, tm, left, min(right, tm)) +
               sumRange(2 * v + 2, tm + 1, tr, max(left, tm + 1), right);
    }
};