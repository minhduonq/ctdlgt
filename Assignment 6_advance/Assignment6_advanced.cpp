#include<iostream>
#include<stack>
#include<vector>
#include<fstream>
using namespace std;
vector<int> adj[9999];
int visited[9999];
stack<int> st;


void topo(int node)
{
    visited[node]= 1;
    for(int i = 0; i < adj[node].size(); i++) {
        int adjacent = adj[node][i];
        if(visited[adjacent]==0) {
            topo(adjacent);
        }
    }
    st.push(node);
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i = 1; i <=n; i++) {
        if(visited[i]==0) {
            topo(i);
        }
    }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
