#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> adj[1001];
int dist[1001];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int child : adj[node]) {
            if(dist[child] == -1) {
                dist[child] = dist[node] + 1;
                q.push(child);
            }
        }
    }
}

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for(int i = 1; i <= n; i++) {
        dist[i] = -1;
    }
    bfs(X);
    cout << dist[Y] << endl;
    return 0;
}
