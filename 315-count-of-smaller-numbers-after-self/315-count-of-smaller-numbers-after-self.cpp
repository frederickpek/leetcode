#define LSOne(S) ((S) & -(S))

const int offset = 1e4 + 4;

class FenwickTree {
private:
	unordered_map<int, int> ft;
public:
	FenwickTree() {}

	int rsq(int j) {
		int sum = 0;
		for (; j; j -= LSOne(j))
			sum += ft[j];
		return sum;
	}

	int rsq(int i, int j) {
		return rsq(j) - rsq(i-1);
	}

	void update(int i, int v) {
		for (; i <= (2*offset); i += LSOne(i))
			ft[i] += v;
	}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& a) {
        FenwickTree ft;
        for (int i = a.size()-1; i>=0; --i) {
            int val = a[i] + offset;
            a[i] = ft.rsq(val - 1);
            ft.update(val, 1);
        }
        return a;
    }
};