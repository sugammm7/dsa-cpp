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
    }

    bool cycleDetectionHelper(int v, vector<bool> &rec, vector<bool> &vis) {
        rec[v] = true;
        vis[v] = true;

        list<int> neighbour = l[v];

        for (int vertex: neighbour) {
            if (!vis[vertex]) {
                if(cycleDetectionHelper(vertex, rec, vis)) {
                    return true;
                };
            } else {
                if (rec[vertex]) {
                    return true;
                }
            }
        }

        rec[v] = false;
        return false;
    }

    bool cycleDetection () {
        vector<bool> vis(V, false);
        vector<bool> rec(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (cycleDetectionHelper(i, rec, vis)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 3);
    graph.addEdge(3, 2);
    graph.addEdge(2, 4);
    // graph.addEdge(2, 1);

    cout << graph.cycleDetection();

    return 0;
}