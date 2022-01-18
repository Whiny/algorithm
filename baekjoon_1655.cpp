#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

/*백준이는 동생에게 "가운데를 말해요" 게임을 가르쳐주고 있다. 
백준이가 정수를 하나씩 외칠때마다 동생은 지금까지 백준이가 말한 수 중에서 중간값을 말해야 한다. 
만약, 그동안 백준이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.
예를 들어 백준이가 동생에게 1, 5, 2, 10, -99, 7, 5를 순서대로 외쳤다고 하면, 동생은 1, 1, 2, 2, 2, 2, 5를 차례대로 말해야 한다. 
백준이가 외치는 수가 주어졌을 때, 동생이 말해야 하는 수를 구하는 프로그램을 작성하시오.*/

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, a;
    cin>>n;
    priority_queue<int, vector<int>, less<int>> maxHeap; //최솟값부터 가운데 값 저장할 힙
    priority_queue<int, vector<int>, greater<int>> minHeap; //가운데 값 다음부터 최댓값까지 저장할 
    maxHeap.push(-10001);
    minHeap.push(10001);
    
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(i==0)
            maxHeap.push(a);
        else
        {
            if(i%2==1) //홀수번째일 때, minHeap에 저장
            {
                minHeap.push(a);
            }
            else //짝수번째일 때, maxHeap에 저장
            {
                maxHeap.push(a);
            }
        }
        if(maxHeap.top()>minHeap.top()) //각각의 Heap의 Top을 비교하여 maxHeap의 탑보다 minHeap의 탑이 더 클 경우 둘을 바꿈
        {
            int maxTop, minTop;
            maxTop = maxHeap.top();
            minTop = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(maxTop);
        }
        
        cout<<maxHeap.top()<<"\n";
    }
    return 0;
}
