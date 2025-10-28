#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    typedef pair<int, string> P; // (weight, node)

    vector<string> shortestPath(string src, string dest, vector<tuple<string,string,int>> edges) {
       
        unordered_map<string, vector<pair<string,int>>> adj;
        for (auto &edge : edges) {
            string u, v; int w;
            tie(u, v, w) = edge;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // undirected
        }

      
        unordered_map<string, int> dist;
        unordered_map<string, string> parent;
        for (auto &edge : edges) {
            string u, v; int w;
            tie(u, v, w) = edge;
            dist[u] = INT_MAX;
            dist[v] = INT_MAX;
        }

        if (dist.find(src) == dist.end() || dist.find(dest) == dist.end()) {
            cout << "\n Invalid location name entered.\n";
            return {};
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, src});
        dist[src] = 0;
        parent[src] = "";

        while (!pq.empty()) {
            P top = pq.top();
            pq.pop();
            int d = top.first;
            string node = top.second;

            if (d > dist[node]) continue;

            for (auto &p : adj[node]) {
                string ngh = p.first;
                int w = p.second;

                if (dist[node] + w < dist[ngh]) {
                    dist[ngh] = dist[node] + w;
                    parent[ngh] = node;
                    pq.push({dist[ngh], ngh});
                }
            }
        }

        
        vector<string> path;
        string cur = dest;
        if (dist.find(dest) == dist.end() || dist[dest] == INT_MAX) {
            cout << "\n No path found between " << src << " and " << dest << ".\n";
            return {};
        }

        while (cur != "") {
            path.push_back(cur);
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());

        cout << "\n Shortest distance: " << dist[dest] << "\n";
        return path;
    }
};

int main() {
    Solution sol;

    
    vector<tuple<string,string,int>> edges = {
        {"IT","EE",5}, {"EE","IC",5}, {"IC","LectureHallComplex",3},
    {"LectureHallComplex","ClockTower",26}, {"IT","ParadeGround",3},
    {"ParadeGround","IHall",1}, {"IHall","GuestHouse",3},
    {"GuestHouse","ClockTower",10}, {"ClockTower","AlumniHall",4},
    {"AlumniHall","2ndGate",6}, {"IC","SNT",7}, {"LectureHallComplex","SNT",4},
    {"SNT","BEModelSchool",10}, {"BEModelSchool","Williams",10},
    {"Williams","2ndGate",20}, {"IT","Library",7}, {"Library","H14",7},
    {"H14","McDonalds",7}, {"McDonalds","Richardson",5},
    {"Richardson","Amenities",1}, {"Amenities","1stGate",15},
    {"IT","EE",5}, {"EE","IC",5}, {"IC","LectureHallComplex",3},
    {"LectureHallComplex","ClockTower",26}, {"IT","ParadeGround",3},
    {"ParadeGround","IHall",1}, {"IHall","GuestHouse",3},
    {"GuestHouse","ClockTower",10}, {"ClockTower","AlumniHall",4},
    {"AlumniHall","2ndGate",6}, {"IC","SNT",7}, {"LectureHallComplex","SNT",4},
    {"SNT","BEModelSchool",10}, {"BEModelSchool","Williams",17},
    {"Williams","2ndGate",20}, {"IT","Library",7}, {"Library","H14",7},
    {"H14","McDonalds",7}, {"McDonalds","Richardson",5},
    {"Richardson","Amenities",1}, {"Amenities","1stGate",15},
    {"GuestHouse","1stGate",7}, {"1stGate","2ndGate",30},
    {"Williams","3rdGate",10}, {"3rdGate","2ndGate",30},
    {"IT","NetajiBhaban",7}, {"NetajiBhaban","Amenities",3},
    {"Amenities","RabindranathStatue",3},
    {"RabindranathStatue","1stGate",12}, {"NetajiBhaban","GuestHouse",6},
    {"BEModelSchool","BidishaLake",5}, {"BidishaLake","Gym",7}, {"Gym","Williams",9},

   
    {"Gym","Neemlake",10},
    {"Neemlake","StaterHall",3},
    {"StaterHall","H-9",7},
    {"BidishaLake","Oval",2},
    {"Oval","ClockTower",4},
    {"ClockTower","Hospital",5},
    {"Library","ThousandSitterHostel",5},
    {"Williams","Neemlake",4},
    {"AlumniHall","H-9",3}
    };

    
    set<string> locations;
    for (auto &edge : edges) {
        string u, v; int w;
        tie(u, v, w) = edge;
        locations.insert(u);
        locations.insert(v);
    }

    cout << "🏫 AVAILABLE LOCATIONS IN CAMPUS MAP:\n";
    cout << "--------------------------------------\n";
    int count = 1;
    for (auto &loc : locations) {
        cout << setw(2) << count++ << ". " << loc << "\n";
    }
    cout << "--------------------------------------\n";

    
    string from, to;
    cout << "Enter starting location: ";
    getline(cin, from);
    cout << "Enter destination location: ";
    getline(cin, to);

    
    vector<string> path = sol.shortestPath(from, to, edges);

    if (!path.empty()) {
        cout << "\n Shortest path from " << from << " to " << to << ":\n";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }

    return 0;
}
