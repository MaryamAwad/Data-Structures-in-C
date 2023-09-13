#include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    //adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V){
    for(int v = 0; v < V; v++){
        cout<<"Adjacency List of Vertex "<< v << endl;
        for(auto neighbour: adj[v])
            cout<<neighbour<<" ";
            cout<<endl;
    }
}

void depthFirst(vector<int> adj[],int source){//013524
    stack<int> s;
    s.push(source);
    while(!s.empty()){
        int current = s.top();
        cout<<current<<" ";
        s.pop();
        for(auto neighbour: adj[current])
            s.push(neighbour);
    }
    cout<<endl;
}

void depthFirstRecurive(vector<int> adj[],int source){//024135
    cout<<source<<" ";
    for(auto neighbour: adj[source])
        depthFirstRecurive(adj, neighbour);
}

void breadthFirst(vector<int> adj[], int source){//021435
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int current = q.front();
        cout<<current<<" ";
        q.pop();
        for(auto neighbour: adj[current])
            q.push(neighbour);
    }
    cout<<endl;
}

bool haspathRecursive(vector<int> adj[], int source, int dest){//assuming an acyclic graph
    if (source==dest)
        return true;
    for(auto neighbour: adj[source])
        return haspathRecursive(adj, neighbour, dest);
    return false;
}

bool haspath(vector<int> adj[], int source, int dest){//assuming an acyclic graph
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int current = q.front();
        if (current == dest)
            return true;
        q.pop();
        for(auto neighbour: adj[current])
            q.push(neighbour);
    }
    return false;
}


int main(){
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);
    printGraph(adj, V);
    depthFirst(adj,0);
    depthFirstRecurive(adj, 0);
    cout<<endl;
    breadthFirst(adj,0);
    cout<<haspath(adj,0,4)<<endl;
    cout<<haspath(adj,5,4)<<endl;
    cout<<haspath(adj,2,1)<<endl;
    cout<<haspath(adj,1,5)<<endl;
    return 0;
}
