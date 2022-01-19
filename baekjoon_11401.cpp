#include<iostream>
using namespace std;

/*자연수 N과 정수 K가 주어졌을 때 이항 계수 
(N)
(K)를 1,000,000,007로 나눈 나머지를 구하는 프로그램을 작성하시오.*/

long mod = 1000000007;
long long int pow(long long int, long long int);
long long int modFact(long long int);
    
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin>>n>>k;
    
    cout<<(modFact(n)*pow((modFact(k)*modFact(n-k))%mod,mod-2))%mod;
    
    return 0;
}

long long int modFact(long long int a) //n! mod p
{
    if(a<=1)
        return 1;
    return (modFact(a-1)*a)%mod;
}

long long int pow(long long a, long long b) //분할정복 제곱 나머지
{
    if(b == 1) 
        return a;
    if(b%2 == 0) 
    {
        long long t =  pow(a, b/2);
        return (t*t)%mod;
    }
    else
        return (pow(a, b-1)*a)%mod;
}
