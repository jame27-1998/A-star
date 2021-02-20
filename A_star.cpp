#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>




using namespace std;
unordered_map<int,int> parent;
unordered_map<int,char> vertices;

void printpath(int i);


int main()
{

    vector<pair<int,int>> graph[10];

    graph[0].push_back({5,3});
    graph[0].push_back({1,6});

    graph[1].push_back({0,6});
    graph[1].push_back({2,3});
    graph[1].push_back({3,2});

    graph[2].push_back({1,3});
    graph[2].push_back({3,1});
    graph[2].push_back({4,5});

    graph[3].push_back({2,1});
    graph[3].push_back({1,2});
    graph[3].push_back({4,8});

    graph[4].push_back({9,5});
    graph[4].push_back({3,8});
    graph[4].push_back({8,5});
    graph[4].push_back({2,5});

    graph[9].push_back({8,3});
    graph[9].push_back({4,5});

    graph[8].push_back({9,3});
    graph[8].push_back({4,5});
    graph[8].push_back({7,2});
    graph[8].push_back({6,3});

    graph[7].push_back({5,7});
    graph[7].push_back({8,2});

    graph[6].push_back({5,1});
    graph[6].push_back({8,3});

    graph[5].push_back({0,3});
    graph[5].push_back({6,1});
    graph[5].push_back({7,7});


    unordered_map<int,int> h;
    h[0]=0;
    h[1]=8;
    h[2]=5;
    h[3]=7;
    h[4]=3;
    h[5]=6;
    h[6]=5;
    h[7]=3;
    h[8]=1;
    h[9]=0;

    
    unordered_map<int,int> visited;

    for(int i=0;i<=9;i++)
    {
        char a=i+65;
        vertices[i]=a;
        visited[i]=0;
    }

    
    set<pair<int,int>> mini;
    int distance;
    parent[0]=-1;
    

    mini.insert({h[0],0});
    pair<int,int>temp;
    visited[0]=1;
    while(mini.empty()==false)
    {
        temp=*mini.begin();
        mini.erase(mini.begin());
        distance=0;
        
        for(auto it=graph[temp.second].begin();it!=graph[temp.second].end();it++)
        {
            if(visited[it->first]!=1){
            distance=it->second+h[it->first];
            mini.insert({distance,it->first});
            visited[it->first]=1;
            parent[it->first]=temp.second;
            }
            distance=0;
        }

    }

    printpath(9);

    return 0;
}
void printpath(int i)
{
    if(i==-1)
     return ;

     cout<<vertices[i]<<" ";
     printpath(parent[i]);

}