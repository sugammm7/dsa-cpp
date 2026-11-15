#include<iostream>
#include<list>
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

    void print() {
        for (int i = 0; i < V; i++) {
            cout << i << " : ";
            list<int> neighbour = l[i];
            for (int v: neighbour) {
                cout << v << ", ";
            } 
            cout << endl;
        }
    }

    void bfs() {
        vector<bool> vis(V, false);
        queue<int> q;

        q.push(0);
        vis[0] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            list<int> neighbour = l[v];
            for (int u: neighbour) {
                if (!vis[u]) {
                    vis[u] = true;
                    q.push(u);
                }
            }
        }
    }
};

int main() {
    Graph graph(5);

    graph.addEdge(0,1);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);

    graph.bfs();

    return 0;
}