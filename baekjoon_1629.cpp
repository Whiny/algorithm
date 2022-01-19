#include<iostream>
using namespace std;
/*자연수 A를 B번 곱한 수를 알고 싶다. 
단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.
A, B, C는 모두 2,147,483,647 이하의 자연수이다.*/

int mod;
long long pow(long long int, long long int);
    
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin>>n>>k>>mod;
    
    cout<<pow(n,k)%mod;
    
    return 0;
}

long long int pow(long long a, long long b) //분할정복 제곱
{
    if(b == 0)
        return 1;
    else if(b == 1)
        return a;

    if(b%2>0) //홀수일 때 b-1로 제곱
        return pow(a,b-1)*a;
    
    //짝수일 때 b를 반으로 나눠서 제곱
    long long half = pow(a,b/2); 
    half %= mod;
    return(half*half)%mod;
}

