class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> set(2001, -1);
		for (auto& edge: edges) {
			int x = find(set, edge[0]), y = find(set, edge[1]);
			if (x == y) return edge;
			set[x] = y;
		}

		return {};
    }
private:
	int find(vector<int>& root, int x) {
		int y = x;
		while (root[y] != -1) {
			y = root[y];
		}
		int t, h = y;
		y = x;
		while (root[y] != -1) {
			t = root[y];
			root[y] = h;
			y = t;
		}

		return h;
	}
};

class SolutionII {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0), candA, candB;
        // step 1, check whether there is a node with two parents
        for (auto &edge:edges) {
            if (parent[edge[1]] == 0)
                parent[edge[1]] = edge[0]; 
            else {
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = 0;
            }
        } 
        // step 2, union find
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (auto &edge:edges) {
            if (edge[1] == 0) continue;
            int u = edge[0], v = edge[1], pu = root(parent, u);
            // Now every node only has 1 parent, so root of v is implicitly v
            if (pu == v) {
                if (candA.empty()) return edge;
                return candA;
            }
            parent[v] = pu;
        }
        return candB;
    }
private:
    int root(vector<int>& parent, int k) {
        if (parent[k] != k) 
            parent[k] = root(parent, parent[k]);
        return parent[k];
    }
};
