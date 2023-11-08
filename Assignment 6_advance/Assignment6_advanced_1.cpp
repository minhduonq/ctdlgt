//minium spanning tree Kruskal
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

struct Edge
{
    int u, v, d;
    bool operator<(const Edge& other) const {
        return d < other.d;
    }

};

/**find parent func**/
int findParent(int v, vector<int>& parent)
{
    if(parent[v]==v) {
        return v;
    }
    return parent[v]=findParent(parent[v], parent);
}

void unionSets(int a, int b, vector<int>& parent)
{
    a = findParent(a, parent);
    b = findParent(b, parent);
    if(a!=b) {parent[b] = a;}
}

/*int main()
{
    ifstream input("connection.txt");
    ofstream output("connection.out");

    int n, m;
    input >> n >> m;
    vector<Edge> edges;
    vector<int> parent(n+1);
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for(int i =0; i < m; i++) {
        int u, v, d;
        input >> u >> v >> d;
        edges.push_back({u, v, d});
    }
    sort(edges.begin(), edges.end());
    int totalCost = 0;
    vector<Edge> result;
    for(const Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        if(findParent(u, parent) != findParent(v, parent)) {
            totalCost += edge.v;
            result.push_back(edge);
            unionSets(v, v, parent);
            }
    }
    //In ra ket qua
    output << totalCost << endl;
    for (const Edge& edge : result) {
        output << edge.u << " " << edge.v << " " << edge.d << endl;
    }

    input.close();
    output.close();

    return 0;

}*/
int main() {
    ifstream input("connection.txt");
    ofstream output("connection.out");

    int n, m;
    input >> n >> m;

    vector<Edge> edges;
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int u, v, d;
        input >> u >> v >> d;
        edges.push_back({u, v, d});
    }

    sort(edges.begin(), edges.end());

    int totalCost = 0;
    vector<Edge> result;

    for (const Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        if (findParent(u, parent) != findParent(v, parent)) {
            totalCost += edge.d;
            result.push_back(edge);
            unionSets(u, v, parent);
        }
    }

    output << "Total cost: " << totalCost << endl;
    for (const Edge& edge : result) {
        output << edge.u << " " << edge.v << " " << edge.d << endl;
    }

    input.close();
    output.close();

    return 0;
}
