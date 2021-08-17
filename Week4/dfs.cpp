#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <fstream>

using namespace std;

queue<int> q;

void dfs(int i, bool adjMat[][101], bool visited[], int n)
{
    visited[i] = true;
    cout << i << " ";
    for (int j = 1; j <= n; j++)
    {
        if (adjMat[i][j] && !visited[j])
        {
            dfs(j, adjMat, visited, n);
        }
    }
    q.push(i);
}

void bfs(int i, bool adjMat[][101], bool visited[], int n)
{
    queue<int> Q;
    Q.push(i);
    visited[i] = true;
    cout << i << " ";
    while (!Q.empty())
    {
        int top = Q.front();
        Q.pop();
        //q.push(top);
        for (int j = 1; j <= n; j++)
        {
            if (adjMat[top][j] && !visited[j])
            {
                Q.push(j);
                cout << j << " ";
                visited[j] = true;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    bool adjMat[n + 1][101];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adjMat[i][j] = 0;
        }
    }
    while (e--)
    {
        int x, y;
        cin >> x >> y;
        adjMat[x][y] = 1;
        adjMat[y][x] = 1;
    }
    bool visited[n + 1];
    for (int i = 1; i <= n; i++)
        visited[i] = false;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i, adjMat, visited, n);
    }
    cout << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}

