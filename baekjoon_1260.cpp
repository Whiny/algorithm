#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

/*
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 
정점 번호는 1번부터 N번까지이다.

입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 
다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 
어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. 
V부터 방문된 점을 순서대로 출력하면 된다.
*/

void dfs(vector<int> graph[], int v, bool check[]) //그래프, 시작 번호, 체크 배열
{
    stack<int> st;
    st.push(v);
    check[v] = true;
    cout<<v<<" ";
    while(!st.empty())
    {
        int current_node = st.top();
        st.pop();
        //while문의 조건이 !st.empty()여서 모두 돌았을 때 다음 노드가 없으면 끝내기 위해
        for(int i=0;i<graph[current_node].size();i++)
        {
            int next_node=graph[current_node][i];
            if(check[next_node]==false)
            {
                cout<<next_node<<" ";
                check[next_node]=true;
                st.push(current_node);
                //st.pop()을 했기 때문에 다시 넣어줌
                st.push(next_node);
                break;
            }
        }
    }
    cout<<"\n";
}

void bfs(vector<int> graph[], int v, bool check[]) //그래프, 시작 번호, 체크 배열
{
    queue<int> qu;
	  qu.push(v);
    check[v] = true;
    
    while(!qu.empty())
    {
        int temp=qu.front();
        qu.pop();
        cout<<temp<<" ";
        
        for(int i=0;i<graph[temp].size();i++)
        {
            int current_node=graph[temp][i];
            if(check[current_node]==false) //전부 true 이면 다 돌았기에 while문 끝남
            {
                check[current_node] = true;
                qu.push(current_node);
            }
        }
    }
}

int main()
{
    int n, m, v; 
    //n: 정점의 갯수, m: 간선의 갯수, v: 탐색 시작할 정점의 번호
    cin>>n>>m>>v;
    vector<int> *graph = new vector<int>[n+1];
    bool check[n+1];
    fill(check,check+n+1,false);
    
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b); //입력받은 두개의 노드를 연결
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++) //정점의 다음 노드를 찾을 때 순차적으로 접근해야하기에 정렬을 해야함
    {
        sort(graph[i].begin(), graph[i].end());
    }
    
    dfs(graph, v, check);
    fill(check,check+n+1,false); //체크 비워주기
    bfs(graph, v, check);
    return 0;
}
