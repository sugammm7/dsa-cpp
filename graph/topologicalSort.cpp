#include<iostream>
#include<list>
#include<vector>
#include<stack>
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

    void topoSortHelper (int src, vector<bool> &vis, stack<int> &s) {
        vis[src] = true;
        list<int> neighbour = l[src];

        for (int v: neighbour) {
            if (!vis[v]) {
                topoSortHelper(v, vis, s);
            }
        }

        s.push(src);
    }

    void topoSort () {
        vector<bool> vis(V, false);
        stack<int> s;

        for (int i = 0; i < V; i++) {
            topoSortHelper(i, vis, s);
        }

        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        } 
    }
};

int main() {
    Graph graph(6);

    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(5, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 1);

    graph.topoSort();

    return 0;
}