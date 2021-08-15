#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    priority_queue<double> left;
    priority_queue<double, vector<double>, greater<double>> right;
    double num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (left.size() < right.size())
        {
            if (num > right.top())
            {
                left.push(right.top());
                right.pop();
                right.push(num);
            }
            else
            {
                left.push(num);
            }
        }
        else if (left.size() > right.size())
        {
            if (num < left.top())
            {
                right.push(left.top());
                left.pop();
                left.push(num);
            }
            else
            {
                right.push(num);
            }
        }
        else
        {
            if (left.size() == 0)
            {
                left.push(num);
            }
            else if (num < left.top())
            {
                left.push(num);
            }
            else
            {
                right.push(num);
            }
        }
        if (left.size() > right.size())
        {
            cout << setprecision(1) << fixed << (double)left.top() << endl;
        }
        else if (right.size() > left.size())
        {
            cout << setprecision(1) << fixed << (double)right.top() << endl;
        }
        else
        {
            cout << setprecision(1) << fixed << (double)(left.top() + right.top()) / 2.0 << endl;
        }
    }
    return 0;
}