#include <bits/stdc++.h>
using namespace std;

int *findSum(int A[], int n, int k)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (A[i] + A[j] == k)
            {
                int *arr = new int[2]{i, j};
                return arr;
            }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int A[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    int *ans = findSum(A, n, k);
    cout << ans[0] << " " << ans[1] << endl;
    delete[] ans;

    return 0;
}
