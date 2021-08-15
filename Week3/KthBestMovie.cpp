#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int x;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (pq.size() < k)
        {
            pq.push(x);
        }
        else if (x > pq.top())
        {
            pq.pop();
            pq.push(x);
        }
    }
    cout << pq.top();
}