#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
	unordered_map<int, int> parent;
	vector<int> rank;
	int n;
public:
	Solution() {
		rank.resize(n, 0);
	}

	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	void unionSet(int x, int y) {
		int xRoot = find(x);
		int yRoot = find(y);
		if (xRoot != yRoot) {
			parent[yRoot] = xRoot;
			if (rank[xRoot] > rank[yRoot]) {
				rank[xRoot] += rank[yRoot];
			} else {
				rank[yRoot] += rank[xRoot];
			}
		}
	}

	vector<int> shortestDistanceAfterQueries(vector<vector<int>>& queries) {
		int n = queries.size();
		vector<int> answer(n);
		for (int i = 0; i < n; ++i) {
			unionSet(queries[i][0], queries[i][1]);
			answer[i] = find(0) == find(n - 1) ? 1 : 0;
		}
		return answer;
	}
};

int main() {
//	int n = 5;
	vector<vector<int>> queries = {{2, 4}, {0, 2}, {0, 4}};
	Solution obj;
	vector<int> answer = obj.shortestDistanceAfterQueries(queries);
	for (int i = 0; i < (int) answer.size(); ++i) {
		cout << answer[i] << " ";
	}
	cout << endl;
	return 0;
}

