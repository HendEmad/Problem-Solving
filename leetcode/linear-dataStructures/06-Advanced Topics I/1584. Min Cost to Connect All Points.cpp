#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n), components(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
            components[i] = 1;
        }
    }
    
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                components[rootY] += components[rootX];
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                components[rootX] += components[rootY];
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
                components[rootX] += components[rootY];
            }
        }
    }
    
    int getComponents(int x) {
        return components[find(x)];
    }
    
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> components;
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> dist(n, vector<int>(n));
        
        // Compute Manhattan distance between each pair of points
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                dist[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                dist[j][i] = dist[i][j]; // Symmetric matrix
            }
        }
        
        // Kruskal's algorithm to find MST
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                edges.push_back({dist[i][j], {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        
        UnionFind uf(n);
        int minCost = 0, numEdges = 0;
        for (const auto& edge : edges) {
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            if (uf.find(u) != uf.find(v)) {
                uf.unite(u, v);
                minCost += weight;
                numEdges++;
                if (numEdges == n - 1) break; // MST has n - 1 edges
            }
        }
        
        return minCost;
    }
};
