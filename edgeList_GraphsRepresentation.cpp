#include <bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int a, b;
};

class Graph {
    int v, e;
    Edge* edges;
    
    public:
    Graph(int v, int e) {
        this->v = v;
        this->e = e;
        edges = new Edge[e];
    }

    void addEdge(int index, int a, int b) {
        edges[index].a = a;
        edges[index].b = b;
    }

    void print() {
        for (int i{0}; i < e; i++) {
            cout << "(" << edges[i].a << " - " << edges[i].b << ")" << endl;
        }
    }

    ~Graph() { delete[] edges; }
};

int main() {
    int V = 4, E = 4;
    Graph g(V, E);

    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 5);

    g.print();

    return 0;
}
