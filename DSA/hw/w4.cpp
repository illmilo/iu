    // Milena Kuznetsova m.kuznetsova@innopolis.university
#include <iostream>

using namespace std;

// literally binary search
int karySearch(int* a, int n, int x, int k) {
    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = l + (r - l) / k; // just instead of 2 we divide by k

        if (a[mid] == x) return mid;
        if (a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }

    return -1;  // Not found
}

void problemA() {
    int n, k;
    cin >> n >> k;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << karySearch(a, n, x, k) << endl;
    }

    delete[] a;
}

struct Pair {
    int score;
    string name;
};

Pair* merge(Pair* a1, int n1, Pair* a2, int n2) {
    // two pointers for each array
    int l = 0, r = 0, i = 0;
    Pair* res = new Pair[n1 + n2];
    while (l < n1 && r < n2) {
        if (a1[l].score < a2[r].score) {
            res[i++] = a1[l++];
        }
        else {
            res[i++] = a2[r++];
        }
    }

    while (l < n1) res[i++] = a1[l++];
    while (r < n2) res[i++] = a2[r++];

    return res;
}

Pair* mergeSort(Pair* a, int n) {
    if (n == 1) {
        return a;   // depth of recursion
    }
    int mid = n / 2;

    Pair* a1 = mergeSort(a, mid);
    Pair* a2 = mergeSort(a + mid, n - mid);

    return merge(a1, mid, a2, n - mid);
}

void problemB() {
    int n; cin >> n;
    Pair* a = new Pair[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i].score >> a[i].name;
    }

    Pair* res = mergeSort(a, n);
    // for (int i = 0; i < n; i++) 
    //     cout << res[i].score << ' ' << res[i].name << endl;
    int balance = (n) / 2;
    cout << res[balance].name << endl;
}

int main() {
    // freopen("i.txt", "r", stdin);
    problemB();

    return 0;
}
