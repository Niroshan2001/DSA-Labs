#include<iostream>
#include<vector>

using namespace std;
//find the city with minimum time
int find_minimum_time(vector<int>& time,vector<bool>& visited){
   
    int min_time=INT_MAX;
    int min_city=-1;
    for(int i=0;i<time.size();i++){
        if(time[i]<min_time&& (!visited[i])){
            min_time=time[i];
            min_city=i;
        }
    }

    return min_city;
}

vector<int> dijkstra(vector<vector<int>> graph,int source_city){
    int num_cities=graph.size();
     // set min time is infinity 
    vector<int> time(num_cities,INT_MAX);
    //set min time of source city is 0;
    time[source_city]=0;
    vector<bool>visited(num_cities,false);

    for(int j=0;j<num_cities;j++){
        int current_City=find_minimum_time(time,visited);
        visited[current_City]=true;
        for(int neighbour=0;neighbour<num_cities;neighbour++){
            // check whether neighbour is not visited and path for current city to neighbour
            if(!visited[neighbour]&&graph[current_City][neighbour]!=0){
                //relaxing
                if(time[current_City]+graph[current_City][neighbour]<time[neighbour]){
                    time[neighbour]=time[current_City]+graph[current_City][neighbour];
                }
            }
        }
    }
    //return time vector with shortest time from source city.
    return time;

}

int main(){
    vector<vector<int>>Adjacency_matrix={{0,10,0,0,15,5},
                              {10,0,10,30,0,0},
                              {0,10,0,12,5,0},
                              {0,30,12,0,0,20},
                              {15,0,5,0,0,0},
                              {5,0,0,20,0,0}
                            };

 int source_city=0;
 vector<int>shortest_time=dijkstra(Adjacency_matrix,source_city);
 int sum=0;
 //print the shotest time from source city to other cities.
 for(int k=0;k<shortest_time.size();k++){
    cout<<"shortest time from city "<<source_city<<" to city "<<k<<" is "<<shortest_time[k]<<endl;
    sum+=shortest_time[k];
 }
 int average_time=sum/(Adjacency_matrix.size()-1);
 cout<<"Average time from city "<<source_city<<" is "<<average_time<<endl;
 return 0;  
}


