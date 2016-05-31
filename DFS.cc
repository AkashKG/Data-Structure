#include<iostream>
#include<stack>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    void DFS(int s);
    ~Graph(){
    //    cout<<"Deleted";
    }
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
   // cout<<"\nAdded!";
    adj[u].push_back(v);
}

void Graph::DFS(int s){
   // cout<<"Entered DFS!\n";
    bool *visited = new bool[V];
    for(int i=0;i<V;++i){
        visited[i]=false;
    }
    stack <int> st;
    visited[s]=true;
    st.push(s);
    list <int>::iterator i;
    while(!st.empty()){
        s = st.top();
        cout<<s<<" ";
        st.pop();
        for(i = adj[s].begin();i!=adj[s].end();++i){
            if(!visited[*i]){
                visited[*i]=true;
     //           cout<<"["<<*i<<"]\n";
                st.push(*i);
            }
        }
    }
}

int main(){
    Graph *G = new Graph(8);
    G->addEdge(1,2);
    G->addEdge(1,3);
    G->addEdge(3,4);
    G->addEdge(4,2);
    G->DFS(1);
    delete G;
    return 0;
}
