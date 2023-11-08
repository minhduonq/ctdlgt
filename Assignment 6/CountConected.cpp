#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node)
{
    visited[node] = true;
    for(int n : adj[node]) {
        if(!visited[n]) {
            dfs(n);
        }
    }
}

int countcpn() {
    int count = 0;
    for(int i = 1; i <= adj.size(); i++) {
        if(!visited[i]) {
            dfs(i);
            count++;
        }
    }
    return count;
}

int main()
{
    int m, n;
    cin >> n >> m;
    adj.resize(n+1);
    visited.resize(n+1, false);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int key = countcpn();
    cout << key;
}
