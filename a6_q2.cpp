#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int find(int i) { return (parent[i] == i) ? i : (parent[i] = find(parent[i])); }
    void unite(int x, int y) {
        int s1 = find(x), s2 = find(y);
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) parent[s1] = s2;
            else if (rank[s1] > rank[s2]) parent[s2] = s1;
            else parent[s2] = s1, rank[s1]++;
        }
    }
};


double connectionCost(const string &a, const string &b) {
    return (a[0] + b[0]) / 2.0;
}

bool comparator(vector<double> &a, vector<double> &b) { return a[2] < b[2]; }

double kruskalsMST(int V, vector<vector<double>> &edges, vector<pair<int,int>> &usedEdges) {
    sort(edges.begin(), edges.end(), comparator);
    DSU dsu(V);
    double cost = 0;
    int count = 0;

    for (auto &e : edges) {
        int x = (int)e[0], y = (int)e[1];
        double w = e[2];
        if (dsu.find(x) != dsu.find(y)) {
            dsu.unite(x, y);
            cost += w;
            usedEdges.push_back({x, y});
            if (++count == V - 1) break;
        }
    }
    return cost;
}


int main() {
    vector<string> dept = {"CSE", "IT", "VLSI", "ETC", "EE", "CIVIL", "ME", "ARCH", "MBA"};

    
    vector<pair<string, string>> connections = {
        {"CSE", "IT"}, {"CSE", "VLSI"}, {"IT", "VLSI"}, {"IT", "ETC"},
        {"ETC", "EE"}, {"EE", "ME"}, {"EE", "CIVIL"}, {"EE", "ARCH"}, {"ARCH", "MBA"}
    };

    vector<vector<double>> edges;
    for (auto &c : connections) {
        // this was the tricky part to get indices of departments
        int u = find(dept.begin(), dept.end(), c.first) - dept.begin();
        int v = find(dept.begin(), dept.end(), c.second) - dept.begin();
        edges.push_back({(double)u, (double)v, connectionCost(c.first, c.second)});
    }

    vector<pair<int,int>> mstEdges;
    double minCost = kruskalsMST(dept.size(), edges, mstEdges);

    cout << "Minimum cost to connect all departments: " << minCost << "\n\n";
    cout << "Edges used in MST:\n";
    for (auto &p : mstEdges)
        cout << dept[p.first] << " - " << dept[p.second] << endl;

    return 0;
}
