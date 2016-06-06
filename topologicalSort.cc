#include<iostream>
#include<stack>
#include<list>
#include<exception>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    void topologicalSort();
    void topologicalSortUtil(bool visited[], int pos, stack<int> &st);
    ~Graph(){
        cout<<"\nDeleted!";
    }
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
    try{
        cout<<"\nEntered";
        adj[u].push_back(v);
        cout<<"\nAdded";
    }
    catch(exception& e){
        cout<<"\nException: "<<e.what();
    }
}

void Graph::topologicalSort(){
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            topologicalSortUtil(visited,i,st);
        }
    }
    cout<<"\n";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void Graph:: topologicalSortUtil(bool visited[], int pos, stack<int> &st){
    visited[pos] = true;
    list<int>::iterator i;
    for(i=adj[pos].begin();i!=adj[pos].end();++i){
        if(!visited[*i]){
            topologicalSortUtil(visited, *i,st);
        }
    }
    st.push(pos);
}

int main(){
    Graph *G = new Graph(6);
    G->addEdge(5,0);
    G->addEdge(5,2);
    G->addEdge(2,3);
    G->addEdge(3,1);
    G->addEdge(4,0);
    G->addEdge(4,1);
    G->topologicalSort();
    delete G;
    return 0;
}
