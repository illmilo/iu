// Milena Kuznetsova m.kuznetsova@innopolis.university
#include <iostream>
#include <string>

using namespace std;

struct Triple
{
    int *s;
    int *f;
    int *p;
};

// sort by ends
Triple merge(Triple *a1, int s1, Triple *a2, int s2)
{
    Triple res;
    res.s = new int[s1 + s2];
    res.f = new int[s1 + s2];
    res.p = new int[s1 + s2];

    int l = 0, r = 0, i = 0; // indicies for both parts and res triple
    while (l < s1 && r < s2)
    {
        if (a1->f[l] < a2->f[r])
        {
            res.s[i] = a1->s[l];
            res.p[i] = a1->p[l];
            res.f[i++] = a1->f[l++];
        }
        else
        {
            res.s[i] = a2->s[r];
            res.p[i] = a2->p[r];
            res.f[i++] = a2->f[r++];
        }
    }
    while (l < s1)
    {
        res.s[i] = a1->s[l];
        res.p[i] = a1->p[l];
        res.f[i++] = a1->f[l++];
    }
    while (r < s2)
    {
        res.s[i] = a2->s[r];
        res.p[i] = a2->p[r];
        res.f[i++] = a2->f[r++];
    }
    return res;
}

Triple mergeSort(int *s, int *f, int *p, int n)
{
    if (n == 1)
    {
        return {s, f, p};
    }

    // divide
    int mid = n / 2;
    Triple toMid = mergeSort(s, f, p, mid);
    Triple fromMid = mergeSort(s + mid, f + mid, p + mid, n - mid);

    return merge(&toMid, mid, &fromMid, n - mid);
}

void problemA()
{
    int n;
    cin >> n;
    int *s = new int[n];
    int *f = new int[n];
    int *p = new int[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        cin >> f[i];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    // sort by ends
    Triple triple = mergeSort(s, f, p, n);

    // use dp to find the most profitable subarray
    // store profits for each step
    int *dp = new int[n];
    fill(dp, dp + n, 0);
    // start from the latest
    for (int i = n - 1; i >= 0; i--)
    {
        int lastEnd = triple.f[i];
        int s = triple.p[i]; // max profit sum
        int j = i + 1;
        for (int j = i + 1; j < n; j++)
        {
            // make sure that the max profit subarray starts after the current meeting
            if (triple.s[j] >= lastEnd)
            {
                s = max(s, triple.p[i] + dp[j]);
            }
        }
        dp[i] = s;
    }
    cout << *max_element(dp, dp + n) << endl;
    delete[] s;
    delete[] f;
    delete[] p;
    delete[] dp;
}

void problemB()
{
    int n, m;
    cin >> n >> m;
    int **c = new int *[n];
    // store maximums
    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        c[i] = new int[m];
        dp[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = c[i][j];
            // edges
            // starting point
            if (i == 0 && j == 0)
                continue;
            // left
            else if (j == 0)
                dp[i][j] += dp[i - 1][j];
            // top
            else if (i == 0)
                dp[i][j] += dp[i][j - 1];
            // common case
            else
                dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // cout min
    cout << dp[n - 1][m - 1] << endl;

    // reconstructing path
    string path = "";
    int i = n - 1, j = m - 1;
    while (i != 0 || j != 0) {
        path = to_string(c[i][j]) + " " + path;
        if (i == 0) j--;
        else if (j == 0) i--;
        else if (dp[i - 1][j] < dp[i][j - 1]) i--;
        else j--;
    }
    cout << c[0][0] << " " << path << endl;
    // cout << c[0][0];
    // for (int i = path.size() - 1; i >= 0; i--)
    //     cout << path[i];

    // cout << endl;

    for (int i = 0; i < n; i++) {
        delete[] c[i];
        delete[] dp[i];
    }
    delete[] c;
    delete[] dp;
}

int main() {
    // freopen("i.txt", "r", stdin);
    problemB();
    return 0;
}