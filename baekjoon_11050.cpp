#include<iostream>
#include<math.h>
using namespace std;

/*자연수 N과 정수 K가 주어졌을 때 
이항 계수 (N)
         (K) 를 구하는 프로그램을 작성하시오. */


int factorial(int);

int main()
{
    int n, k, binoCoef;
    cin>>n>>k;
    binoCoef = factorial(n)/(factorial(k)*factorial(n-k)); //이항계수: n!/(k!*(n-k)!)
    cout<<binoCoef;
}

int factorial(int num)
{
    if(num==1||num==0)
        return 1;
    else
        return factorial(num-1)*num;
}
