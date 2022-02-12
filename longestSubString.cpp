#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    map<char, int> characters;
    string ans = "";
    string res = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (characters.count(s[i]) == 0)
        {
            res = res + s[i];
            characters.insert({s[i], i});
        }
        else
        {
            characters.clear();
            characters.insert({s[i], i});
            if (ans.length() < res.length())
                ans = res;
            res = s[i];
        }
    }

    (res.length() > ans.length()) ? cout << res << endl : cout << ans << endl;

    return 0;
}