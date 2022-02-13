#include <bits/stdc++.h>
using namespace std;

bool backSpaceCompare(string s, string t)
{
    // brute force

    // stack<char> string1;
    // stack<char> string2;

    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (s[i] == '#' && string1.size() > 0)
    //         string1.pop();
    //     else if (s[i] != '#')
    //         string1.push(s[i]);
    // }

    // for (int i = 0; i < t.size(); i++)
    // {
    //     if (t[i] == '#' && string2.size() > 0)
    //         string2.pop();
    //     else if (t[i] != '#')
    //         string2.push(t[i]);
    // }

    // if (string1.size() != string2.size())
    //     return false;

    // int length = string1.size();
    // for (int i = 0; i < length; i++)
    // {
    //     if (string1.top() == string2.top())
    //     {
    //         string1.pop();
    //         string2.pop();
    //     }
    //     else
    //         return false;
    // }
    // return true;

    // Optimal Solution
    int s1 = s.length() - 1;
    int s2 = t.length() - 1;
    int skip1 = 0;
    int skip2 = 0;
    while (s1 >= 0 || s2 >= 0)
    {
        if (s1 >= 0 && s[s1] == '#')
        {
            while (s1 >= 0 && (s[s1] == '#' || skip1 > 0))
            {
                if (s[s1] != '#')
                    skip1--;
                else
                    skip1++;
                s1--;
            }
        }

        if (s2 >= 0 && t[s2] == '#')
        {
            while (s2 >= 0 && (t[s2] == '#' || skip2 > 0))
            {
                if (t[s2] != '#')
                    skip2--;
                else
                    skip2++;
                s2--;
            }
        }

        if (s1 < 0 && s2 < 0)
            return true;

        if (s1 < 0 || s2 < 0 || s[s1] != t[s2])
            return false;
        s1--;
        s2--;
    }
    return true;
}

int main()
{

    string s, t;
    cin >> s >> t;

    cout << backSpaceCompare(s, t) << endl;

    return 0;
}