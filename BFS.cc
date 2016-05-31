#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int V;
    list <int> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    void BFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[this->V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::BFS(int s){
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    queue <int> q;
    visited[s] = true;
    q.push(s);
    list <int >::iterator i;
    while(!q.empty()){
        s = q.front();
        cout<<s<<" ";
        q.pop();
        for(i=adj[s].begin();i!=adj[s].end();i++){
            if(!visited[*i]){
                visited[*i]=true;
                q.push(*i);
            }
        }
    }
}


int main(){
    Graph *G = new Graph(8);
    G->addEdge(1,2);
    G->addEdge(1,3);
    G->addEdge(2,4);
    G->addEdge(2,5);
    G->addEdge(3,6);
    G->addEdge(3,7);
    G->addEdge(4,5);
    G->addEdge(5,8);
    G->addEdge(6,8);
    G->addEdge(7,8);
    G->BFS(1);
    return 0;
}
