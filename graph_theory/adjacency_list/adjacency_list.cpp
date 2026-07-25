#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;//n is the number of nodes in the graph
    cin >> n >> m;
    //m is the number of instruct to tell u which are connected
    vector<vector<int>> adjlist(n+5);

    //we do one based
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a>>b;

        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    
}