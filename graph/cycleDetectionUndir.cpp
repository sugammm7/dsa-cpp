#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge (int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool cycleDetectionHelper(int v, int par, vector<bool> &vis) {
        vis[v] = true;

        list<int> neighbour = l[v];

        for (int u: neighbour) {
            if (!vis[u]) {
                if(cycleDetectionHelper(u, v, vis)) {
                    return true;
                };
            } else {
                if (u != par) {
                    return true;
                }
            }
        }

        return false;
    }

    bool cycleDetection () {
        vector<bool> vis(V, false);

        return cycleDetectionHelper(0, -1, vis);
    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0,1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    // graph.addEdge(2, 3);
    graph.addEdge(2, 4);

    cout << graph.cycleDetection();

    return 0;
}