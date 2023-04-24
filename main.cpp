//
//  main.cpp
//  QoD#8
//
//  Created by Farida Sherif on 24/04/2023.
//
#include <iostream>

using namespace std;

int ribbon(int n, int a, int b, int c);

int main()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    cout << ribbon(n, a, b, c);
}


int ribbon(int n, int a, int b, int c)
{
    // initialize the array to act similar to the wieghts in the knapsack problem
    int arr[4] = {0, a, b, c};

    int T[4][n+1];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            T[i][j] = 0;
        }
    }
    // we check whether we can cut another piece or not like (include or not include the item in the knapsack)
    
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == arr[i])
                T[i][j] = max(T[i][j], 1);
            
            else if (j > arr[i])
            {
                if (T[i][j - arr[i]] > 0)
                    T[i][j] = max(T[i][j], T[i][j - arr[i]] + 1);
                T[i][j] = max(T[i][j], T[i-1][j]);
            }
            else
                T[i][j] = T[i-1][j];
            
        }
    }
    return T[3][n];
}
/*
 time complexity O(n)
 space complexity O(n)
 */
