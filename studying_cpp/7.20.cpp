// KMP算法复习
#include <iostream>
#include <string>

using namespace std;

int nex[1000];

void getnext (string s)
{
    int i, j, m;
    j  = -1;
    i = 0;
    m = s.size();
    nex[0] = -1;
    while (i < m)
    {
        int a;
        if (j == -1 || s[i] == s[j])
        {
            ++i;
            ++j;
            nex[a] = j;
        }
        else j = nex[j];
    }
}

void kmp (string s, string d)
{
    int n, m, j, i, k;
    n = s.size();
    m = d.size();
    i = 0; j = 0;
    while (i < n && j < m)
    {
        if (s[i] == d[j] || j == -1)
        {
            j++; i++;
        }
        else j = nex[j];
    }
    if (j >= m) k = i - m;
    else k = -1;
    cout << k + 1 << endl;
}