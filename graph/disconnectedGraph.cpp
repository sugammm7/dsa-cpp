#include<iostream>
#include<list>
#include<queue>
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

    void bfsHelper (int st, vector<bool> &vis) {
        queue<int> q;
        q.push(st);
        vis[st] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            list<int> neighbour = l[u];

            for(int v: neighbour) {
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }

    void bfs() {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                bfsHelper(i, vis);
                cout << endl;
            }
        }
    }

    void dfsHelper (int v, vector<bool> &vis) {
        vis[v] = true;
        cout << v << " ";

        list<int> neighbour = l[v];
        for (int u: neighbour) {
            if (!vis[u]) {
                dfsHelper(u, vis);
            }
        }
    }

    void dfs() {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfsHelper(i, vis);
                cout << endl;
            }
        }
    }
};

int main() {
    Graph graph(10);

    graph.addEdge(1, 6);
    graph.addEdge(6, 4);
    graph.addEdge(4, 3);
    graph.addEdge(4, 9);
    graph.addEdge(3, 7);
    graph.addEdge(3, 8);

    graph.addEdge(2, 5);
    graph.addEdge(2, 0);

    graph.bfs();

    return 0;
}