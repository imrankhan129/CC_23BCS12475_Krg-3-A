#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> tree;
    int n;

    SegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }

    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = (start + end) / 2;
        build(nums, 2 * node + 1, start, mid);
        build(nums, 2 * node + 2, mid + 1, end);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    void update(int idx, int val, int node, int start, int end) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(idx, val, 2 * node + 1, start, mid);
        else
            update(idx, val, 2 * node + 2, mid + 1, end);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int left, int right, int node, int start, int end) {
        if (right < start || end < left) return 0;
        if (left <= start && end <= right) return tree[node];

        int mid = (start + end) / 2;

        return query(left, right, 2 * node + 1, start, mid) +
               query(left, right, 2 * node + 2, mid + 1, end);
    }

    void update(int idx, int val) {
        update(idx, val, 0, 0, n - 1);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, n - 1);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    SegmentTree st(nums);

    cout << "Sum [1,3] = " << st.query(1, 3) << endl;

    st.update(2, 10);

    cout << "After update index 2 to 10" << endl;
    cout << "Sum [1,3] = " << st.query(1, 3) << endl;

    return 0;
}
