#include <bits/stdc++.h>
using namespace std;

int findTheMaxArea(vector<int> height)
{
    int maxArea = 0;

    // Brute Force

    // for (int i = 0; i < height.size(); i++)
    //     for (int j = i + 1; j < height.size(); j++)
    //         if (min(height[i], height[j]) * (j - i) > maxArea)
    //             maxArea = min(height[i], height[j]) * (j - i);

    // return maxArea;

    // Optimal Way

    int low = 0;
    int high = height.size() - 1;

    while (low < high)
    {
        int area = (min(height[low], height[high]) * (high - low));
        if (area > maxArea)
            maxArea = area;

        if (height[low] < height[high])
            low++;
        else
            high--;
    }

    return maxArea;
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

    int ans = findTheMaxArea(height);

    cout << ans << endl;

    return 0;
}
