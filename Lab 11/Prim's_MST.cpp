#include<iostream>
#include<vector>
using namespace std;

int minimum_key(vector<int>&key,vector<bool> &mstSet){
    int min_distance=INT_MAX;
    int min_vertex;
    for(int i=0;i<key.size();i++){
        if(mstSet[i]==false && key[i]<min_distance){
            min_distance=key[i];
            min_vertex=i;
        }
}
return min_vertex;
}

void Prims_algorithm(vector<vector<int>>&graph,int start_vertex){
vector<int>parent(graph.size());//storing parent of each vertex
vector<int>key(graph.size(),INT_MAX);//storing distances
vector<bool>mstSet(graph.size(),false);//tracking the vertices icluded in MST

key[start_vertex]=0;
parent[start_vertex]=-1;//no parent

for(int j=0;j<graph.size()-1;j++){
    int u=minimum_key(key,mstSet);
    mstSet[u]=true;//mark the vertex u as included in MST
    for(int vertex=0;vertex<key.size();vertex++){
        if(graph[u][vertex]!=0 && mstSet[vertex]==false && graph[u][vertex]<key[vertex]){
            //update distance and parent if there is a short distance
            parent[vertex]=u;
            key[vertex]=graph[u][vertex];
        }
    }
     
}
int minimum_wire_cost=0;
cout<<"Street  "<<"wire cost"<<endl;
for(int j=1;j<graph.size();j++){
    cout<<parent[j]<<"--"<<j<<"    "<<graph[j][parent[j]]<<endl;
    minimum_wire_cost+=graph[j][parent[j]];

}
cout<<"minimum wire cost is "<<minimum_wire_cost;

}
int main(){
    vector<vector<int>> Adjacency_matrix={{0,3,0,0,0,1},
                                         {3,0,2,1,10,0},
                                         {0,2,0,3,0,5},
                                         {0,1,3,0,5,0},
                                         {0,10,0,5,0,4},
                                         {1,0,5,0,4,0}};

    Prims_algorithm(Adjacency_matrix,0);


return 0;
}






