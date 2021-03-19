#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// // グラフ、頂点の入次数、頂点数を受け取り、そのトポロジカルソートを記録した配列を返す関数
// vector<int> topological_sort(vector<vector<int>> &G, vector<int> &indegree, int V) {
//     // トポロジカルソートを記録する配列
//     vector<int> sorted_vertices;

//     // 入次数が0の頂点を発見したら、処理待ち頂点としてキューに追加する
//     queue<int> que;
//     for (int i = 0; i < V; i++) {
//         if (indegree[i] == 0) {
//             que.push(i);
//         }
//     }

//     // キューが空になるまで、操作1~3を繰り返す
//     while (que.empty() == false) {
//         // キューの先頭の頂点を取り出す
//         int v = que.front();
//         que.pop();

//         // その頂点と隣接している頂点の入次数を減らし、0になればキューに追加
//         for (int i = 0; i < G[v].size(); i++) {
//             int u = G[v][i];
//             indegree[u] -= 1;
//             if (indegree[u] == 0) que.push(u);
//         }
//         // 頂点vを配列の末尾に追加する 
//         sorted_vertices.push_back(v);
//     }

//     // トポロジカルソートを返す
//     return sorted_vertices;
// }

bool topological_sort(vector<vector<int>> &G, vector<int> &res) {
    int N=G.size();
    vector<int> indegree(N);
    for(int i=0;i<N;i++) for(auto e:G[i]) indegree[e]++;

    queue<int> que;
    for (int i=0;i<N;i++) if(indegree[i]==0) que.push(i);

    while(!que.empty()){
        int v=que.front(); que.pop();
        for(auto e:G[v]){
            if(indegree[e]==0) return false;
            indegree[e]--;
            if(indegree[e]==0) que.push(e);
        }
        res.push_back(v);
    }

    return true;
}


int main(){
    
    
    return 0;
}
