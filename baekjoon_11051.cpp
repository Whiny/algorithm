#include<iostream>
#include<math.h>
using namespace std;

/*자연수 N과 정수 K가 주어졌을 때 이항 계수 
(N)
(K)를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

int main()
{
    int n, k;
    cin>>n>>k;
    int dp[1001][1001];
    
    for(int i = 0;i<=n;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            if(j==0||j==i)
                dp[i][j]=1;
            else
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%10007;
        }
    }
    cout<<dp[n][k];
    return 0;
}
