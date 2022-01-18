#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, K;
    cin>>N>>K;
    
    int WV[101][2] = {0,};
    int dp[100001]={0,};
    
    for(int i=0;i<N;i++)
    {
        cin>>WV[i][0]>>WV[i][1];
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=K;j>=WV[i][0];j--)
        {
            dp[j] = max(dp[j],dp[j-WV[i][0]]+WV[i][1]);
            //갯수 i, 무게 j일때 최대 가치합
        }
    }
    cout<<dp[K];
    return 0; 
}
