#include<iostream>
using namespace std;

/*
1960년, IBM의 직원 Donald Wall은 피보나치 수열을 m으로 나눈 나머지가 주기를 이룬다는 것을 증명했다.

예를 들어, 피보나치 수열의 처음 10개를 11로 나눈 예는 다음과 같다.

n	1	2	3	4	5	6	7	8	9	10
F(n)	1	1	2	3	5	8	13	21	34	55
F(n) mod 11	1	1	2	3	5	8	2	10	1	0
나머지를 이용해서 만든 수열은 주기가 나타날 수 있다. k(m)을 반복하는 부분 수열의 길이라고 했을 때, k(11) = 10임을 알 수 있다.

Wall은 아래와 같은 여러 가지 성질도 증명했다.

m > 2인 경우에 k(m)은 짝수이다.
임의의 짝수 정수 n > 2에 대해서, k(m) = n인 m이 항상 존재한다.
k(m) ≤ m2 - 1
k(2n) = 3×2(n-1)
k(5n) = 4×5n
k(2×5n) = 6n
n > 2라면, k(10n) = 15×10(n-1)
m이 주어졌을 때, k(m)을 구하는 프로그램을 작성하시오.
*/

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int p, n, m, count;
    int a,b;
    cin>>p;
  
    for(int i=0;i<p;i++)
    {
        cin>>n>>m;
        a=1; b=1; count = 0;
        int temp;
        while(1)
        {
            temp = (a+b)%m;
            a=b;
            b=temp;
            count++;
            if(a==1 && b==1) //다시 처음으로 돌아와 주기를 다 돌았을 때 break;
                break;
        }
        cout<<n<<" "<<count<<"\n";
    }
    return 0;
}
