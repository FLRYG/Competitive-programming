#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool topological_sort(vector<vector<int>> &G, vector<int> &res) {
    int N=G.size();
    vector<int> indegree(N);
    for(int i=0;i<N;i++) for(auto e:G[i]) indegree[e]++;

    queue<int> que;
    for (int i=0;i<N;i++) if(indegree[i]==0) que.push(i);

    while(!que.empty()){
        int v=que.front(); que.pop();
        for(auto e:G[v]){
            indegree[e]--;
            if(indegree[e]==0) que.push(e);
        }
        res.push_back(v);
    }

    if(res.size()==N) return true;
    else return false;
}


int main(){
    
    
    return 0;
}
