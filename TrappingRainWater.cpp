#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> height)
{
    int units = 0;

    // Brute Force

    // for (int i = 1; i < height.size(); i++)
    // {
    //     int left = 0;
    //     int right = 0;
    //     if ((i > 0 && i < height.size() - 1))
    //     {
    //         int p1 = i - 1, p2 = i + 1;
    //         while (p1 >= 0 || p2 < height.size())
    //         {
    //             if (p1 >= 0)
    //             {
    //                 left = max(left, height[p1]);
    //                 p1--;
    //             }
    //             if (p2 < height.size())
    //             {
    //                 right = max(right, height[p1]);
    //                 p2++;
    //             }
    //         }
    //         int totalUnits = min(left, right) - height[i];
    //         if (totalUnits > 0)
    //             units += totalUnits;
    //     }
    // }

    // Optimal Solution

    int pl = 0;
    int pr = height.size() - 1;
    int leftMax = 0, rightMax = 0;

    while (pl < pr)
    {
        if (height[pl] <= height[pr])
        {
            if (leftMax < height[pl])
                leftMax = height[pl];
            else if (leftMax - height[pl])
                units += leftMax - height[pl];
            pl++;
        }
        else
        {
            if (rightMax < height[pr])
                rightMax = height[pr];
            else if (rightMax - height[pr])
                units += rightMax - height[pr];
            pr--;
        }
    }

    return units;
}

int main()
{
    int n, x;
    cin >> n;
    vector<int> height;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        height.push_back(x);
    }

    cout << trap(height) << endl;

    return 0;
}