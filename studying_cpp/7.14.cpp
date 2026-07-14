// KMP 算法
#include <iostream>
#include <string>
using namespace std;

void getNEXT(string a)
{
    int j = 0,k = -1;
    int next[0] = -1;
    while(j < a.size() - 1)
    {
        if(k == -1 || a[j] == a[k])
            next[++j] = ++k;
        else k = next[k];
    }
}

int next[1000];

void kmp(string s, string a)
{
    int n, m, j, i, k;
    n = s.size(); m = a.size();
    i = 0; j = 0;
    while(i < n && j <m)
    {
        if(s[i] == a[j] || j == -1)
        {
            ++i; ++j;
        }
        else j = next[j];
    }
    if(j >= m)
        k = i - m;
    else
        k = -1;
    cout << k + 1 << endl;
}