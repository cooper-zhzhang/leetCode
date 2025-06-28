#include <iostream>
using namespace std;

const int MAXN = 1e5 + 5; // 最大数组大小
int tree[4 * MAXN]; // 线段树数组

// 构建线段树
void build(int node, int start, int end, int arr[]) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

// 区间查询
int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return 0;
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int left_query = query(2 * node, start, mid, l, r);
    int right_query = query(2 * node + 1, mid + 1, end, l, r);
    return left_query + right_query;
}

// 单点更新
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

int main() {
    int n;
    cin >> n; // 输入数组大小
    int arr[MAXN];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i]; // 输入数组
    }
    build(1, 1, n, arr); // 构建线段树
    int q;
    cin >> q; // 输入查询数量
    while (q--) {
        int type;
        cin >> type; // 查询类型
        if (type == 1) { // 单点更新
            int idx, val;
            cin >> idx >> val;
            update(1, 1, n, idx, val);
        } else if (type == 2) { // 区间查询
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}