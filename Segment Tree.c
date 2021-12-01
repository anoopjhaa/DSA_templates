#include <bits/stdc++.h>
#define foi(i,a,b) for(long long i=a; i<b; i++)
#define fod(i,a,b) for(long long i=a; i>=b; i--)
#define ll long long
#define endl "\n"
using namespace std;

class SegmentTree {
	vector<int> seg;

public:
	SegmentTree(int n) {
		seg.resize(4 * n + 1);
	}


	void build(int idx, int low, int high, vector<int> &arr) {
		if (low == high) {
			seg[idx] = arr[low];
			return;
		}
		int mid = (low + high) / 2;
		build(2 * idx + 1, low, mid, arr);
		build(2 * idx + 2, mid + 1, high, arr);
		seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
	}

	int query(int idx, int low, int high, vector<int> &arr, int l, int r) {
		if (high < l || r < low) return INT_MAX; // no overlap
		if (l <= low && high <= r) return seg[idx]; // complete overlap
		int mid = (low + high) / 2;
		int left = query(2 * idx + 1, low, mid, arr, l, r);
		int right = query(2 * idx + 2, mid + 1, high, arr, l, r);
		return min(left, right);
	}

	void update(int idx, int low, int high, int updateIdx, int updateVal) {
		if (low == high) {
			seg[idx] = updateVal;
			return;
		}
		int mid = (low + high) / 2;
		if (updateIdx <= mid) update(2 * idx + 1, low, mid, updateIdx, updateVal);
		else update(2 * idx + 2, mid + 1, high, updateIdx, updateVal);
		seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
	}
};

void solve() {
	int n, q; cin >> n >> q;
	SegmentTree sg(n);
	vector<int> v(n);
	foi(i, 0, n) cin >> v[i];
	sg.build(0, 0, n - 1, v);
	while (q--) {
		int ch; cin >> ch;
		if (ch == 1) {
			// query
			int l, r; cin >> l >> r;
			cout << sg.query(0, 0, n - 1, v, l, r) << endl;
		} else {
			// update
			int upos, uval; cin >> upos >> uval;
			sg.update(0, 0, n - 1, upos, uval);
			v[upos] = uval;
		}
	}

}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// ll t; cin >> t;
	// while (t--) {
	solve();
	// }
}
