#include<iostream>
#include<vector>
using namespace std;

/*크기가 N*N인 행렬 A가 주어진다. 
이때, A의 B제곱을 구하는 프로그램을 작성하시오. 
수가 매우 커질 수 있으니, A^B의 각 원소를 1,000으로 나눈 나머지를 출력한다.
(2 ≤ N ≤  5, 1 ≤ B ≤ 100,000,000,000)*/

typedef vector<vector<int>> Matrix;
int n;

Matrix powMat(const Matrix &a, const Matrix &b)//행렬 곱셈
{
    Matrix mat(n,vector<int>(n));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                mat[i][j]+=a[i][k]*b[k][j];
            }
            mat[i][j]%=1000; //수가 너무 커지니 나머지 계산
        }
    }
    return mat;
}

Matrix func(const Matrix &a, long long b)//분할정복을 이용한 제곱
{
    if(b==1)
        return a;
    if(b%2==0) //b가 짝수일 때 a^(b/2) * a^(b/2)
    {
        Matrix temp = func(a,b/2);
        return powMat(temp, temp);
        
    }
    else  //b가 홀수일 때 (a^(b-1))*a
    {
        Matrix temp = func(a,b-1);
        return powMat(temp,a);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    
    long long b;
    cin>>n>>b;
    
    Matrix a(n,vector<int>(n));
    Matrix result(n,vector<int>(n));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    result = func(a,b);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<result[i][j]%1000<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
