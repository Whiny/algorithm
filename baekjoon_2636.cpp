#include<iostream>
#include<queue>
#include <cstring>
using namespace std;

struct pos
{
  int x,y;  
};

int n,m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int map[100][100];
bool check[100][100];

bool noCheeze() //치즈 없는지 확인
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(map[i][j]==1)
                return false;
        }
    }
    return true;
}

int countCheeze() //남아있는 치즈 갯수 확인
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(map[i][j]==1)
                count++;
        }
    }
    return count;
}

void clearCheeze() //치즈 없애기 BFS 사용
{
    memset(check, false, sizeof(check));
    queue<pos> q;
    q.push({0,0}); //0,0부터 시작
    check[0][0] = true;
    while(!q.empty())
    {
        pos temp = q.front();
        q.pop();
        
        for(int i=0;i<4;i++) //4방향 체크
        {
            pos next = temp;
            next.x += dx[i];
            next.y += dy[i];
            
            if(next.x<0||next.y<0||next.x>=n||next.y>=m||check[next.x][next.y])
                continue;
            if(map[next.x][next.y]==0)//옆에 치즈가 없다면 큐에 추가
                q.push(next);
            else //옆에 치즈가 있다면 녹임
                map[next.x][next.y] = 0;
            
            check[next.x][next.y]=true;
        }
    }
}

int main()
{
    cin>>n>>m;
    int number;
    int _time = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>map[i][j];
        }
    }
    
    while(1)
    {
        if(noCheeze())
            break;
        number = countCheeze();
        clearCheeze();
        _time++;
    }
    cout<<_time<<"\n"<<number;
    return 0;
}
