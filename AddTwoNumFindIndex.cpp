#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    // Brute Force

    // for (int i = 0; i < nums.size(); i++)
    //     for (int j = i + 1; j < nums.size(); j++)
    //         if (nums[i] + nums[j] == target)
    //         {
    //             vector<int> ans = {i, j};
    //             return ans;
    //         }

    // Optimized Version

    map<int, int> map;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        if (map.count(nums[i]) != 0)
        {
            ans.push_back(map.at(nums[i]));
            ans.push_back(i);
            return ans;
        }
        else
            map.insert({(target - nums[i]), i});
    }
    return ans;
}

int main()
{
    int n, k, x;
    cin >> n >> k;
    vector<int> initalValues;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        initalValues.push_back(x);
    }

    vector<int> ans = twoSum(initalValues, k);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
