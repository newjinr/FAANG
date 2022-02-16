#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    map<char, int> characters;

    int p1 = 0;
    int p2 = 0;
    int longest;

    while (p2 < s.length())
    {
        if (characters.count(s[p2]) != 0 && p1 <= characters[s[p2]])
            p1 = ++characters[s[p2]];
        characters[s[p2]] = p2;
        longest = max(longest, p2 - p1 + 1);
        p2++;
    }

    return longest;
}

int main()
{
    string s;
    cin >> s;

    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}