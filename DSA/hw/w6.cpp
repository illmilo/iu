// Milena Kuznetsova m.kuznetsova@innopolis.university
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAX_EL = 1000+1;

// here we will return frequency and keys for each one
vector<pair<int, int>> countSort(vector<int>& m, int n) {
    vector<int> count(MAX_EL, 0);
    for (int i = 0; i < n; i++) count[m[i]]++;
    // now that we've counted, store everything in vector
    vector<pair<int, int>> freq;
    for (int i = 0; i < MAX_EL; i++) {
        if (count[i]) freq.push_back({count[i], i});
    }
    for (int i = 1; i < freq.size(); i++) {
        for (int j = i; j > 0 && freq[j - 1].first > freq[j].first; j--) {
            // swap
            pair<int, int> temp = freq[j];
            freq[j] = freq[j - 1];
            freq[j - 1] = temp;
        }
    }
    return freq;
}

void problemA() {
    int n; cin >> n;
    vector<int> m(n);
    vector<vector<int>> indicies(MAX_EL);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
        indicies[m[i]].push_back(i);
    }
    vector<pair<int, int>> sortedFreqList = countSort(m, n);
    for (const auto& p: sortedFreqList) {
        int key = p.second;
        for (int j: indicies[key]) {
            cout << key << ' ' << j << '\n';
        }
    }
}

void insertionSort(vector<pair<double, int>>& bucket) {
    for (int i = 1; i < bucket.size(); i++) {
        // ascending order
        for (int j = i; j > 0 && bucket[j - 1].first > bucket[j].first; j--) {
            swap(bucket[j - 1], bucket[j]);
        }
    }
}
 
void bucketSort(vector<pair<double, int>>& d) {
    int n = d.size();
    vector<vector<pair<double, int>>> bucket(n);
    
    // create bucket entries for each value
    for (int i = 0; i < n; i++) {
        int bi = min((int)(n * d[i].first), n - 1);
        bucket[bi].push_back(d[i]);
    }
    // sort each bucket
    for (int i = 0; i < n; i++) {
        insertionSort(bucket[i]);
    }
    // merge all buckets
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (const auto& p: bucket[i]) {
            d[idx++] = p;
        }
    }
}

void problemB() {
    int n; cin >> n;
    vector<pair<double, double>> v(n);
    // we will take square distance because we do not really need precise
    // distance
    vector<pair<double, int>> d(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        d[i] = {sqrt(v[i].first*v[i].first + v[i].second*v[i].second), i};
    }
    bucketSort(d);
    for (const auto& p: d) {
        int idx = p.second;
        printf("%.4lf %.4lf\n", v[idx].first, v[idx].second);
    }
}

int main() {
    // freopen("i.txt", "r", stdin);
    problemB();
    return 0;
}