#include<iostream>
#include<list>
#include<vector>
#include<queue>
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

    bool isbipartite () {
        queue<int> q;
        vector<int> color(V, -1);

        q.push(0);
        color[0] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            list<int> neighbour = l[curr];

            for (int v: neighbour) {
                if (color[v] == -1) {
                    color[v] = !color[curr];
                    q.push(v);
                } else {
                    if (color[curr] == color[v]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(0, 3);
    graph.addEdge(0, 2);

    cout << graph.isbipartite();

    return 0;
}