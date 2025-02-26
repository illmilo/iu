// Milena Kuznetsova m.kuznetsova@innopolis.university

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// pair string word int frequency
struct Pair {
    string word;
    int frequency;

    Pair() : word(""), frequency(0) {}
    Pair(string k, int v) : word(k), frequency(v) {}
};

class MapADT {
public:
    virtual ~MapADT() = default;
    virtual int sizeOf() = 0;
    virtual bool isEmpty() = 0;
    virtual void put(string key) = 0;
    virtual Pair get(string key) = 0;
    virtual void remove(string key) = 0;
};

// hash function
int hashCode(const string& key) {
    int hash = 0;
    for (char c : key) {
        hash += c;
    }
    return hash;
}

class HashMap : public MapADT {
private:
    vector<vector<Pair>> hashTable;
    vector<string> allKeys;
    int capacity;
    int size;

public:
    HashMap(int c) : capacity(c), size(0) {
        hashTable.resize(capacity);
    }

    void put(string key) override {
        int hash = hashCode(key) % capacity;
        // if (hash < 0) hash *= -1;

        // let's find if this word is already in keys
        // to do so, call for the hash and let's iterate over it
        bool found = false;
        for (auto& p: hashTable[hash]) {
            if (p.word == key) {
                p.frequency++;
                found = true;
                break;
            }
        }
        // not found => create this key
        if (!found) {
            hashTable[hash].push_back({key, 1});
            allKeys.push_back(key);
            size++; // increment actual size
        }
    }

    Pair get(string key) override {
        int hash = hashCode(key) % capacity;
        if (hash < 0) hash *= -1;

        for (Pair &p : hashTable[hash]) {
            if (p.word == key) {
                return p;
            }
        }
        // specific output for not found
        return {"", 0};
    }
    
    vector<Pair> getAllPairs() {
        vector<Pair> result;
        for (auto& k : allKeys) {
            result.push_back(get(k));
        }
        return result;
    }
    // must be useless tbh
    void remove(string key) override {
    }

    int sizeOf() override {
        return size;
    }

    bool isEmpty() override {
        return size == 0;
    }
};

// find an array of first K elements
// im taking my solution from week 1
void bubbleSort(vector<Pair>& a) {
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 1; i < a.size(); i++) {
            if (a[i - 1].frequency < a[i].frequency) {  // Sort in descending order
                swap(a[i - 1], a[i]);
                swapped = true;
            }
        }
    }
}

// find top K frequent words
vector<Pair> getTopK(int k, vector<Pair> values) {
    int n = values.size();
    bubbleSort(values);
    return vector<Pair>(values.begin(), values.begin() + k);
}

void problemA() {
    int n, k;
    cin >> n >> k;
    HashMap hashMap(n);
    
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        hashMap.put(word);
    }
    
    vector<Pair> uniqueWords = hashMap.getAllPairs();
    vector<Pair> result = getTopK(k, uniqueWords);
    // cout << result[k-1].word << endl;
    cout << result[k-1].word << endl;
}

void problemB() {
    // first hashmap
    int n; cin >> n;
    string* a = new string[n];
    HashMap hashMapA(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        hashMapA.put(a[i]);
    }
    
    // second hashmap
    int m; cin >> m;
    HashMap hashMapB(m);
    string* b = new string[m];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        hashMapB.put(b[i]);
    }
    int k = 0;  // counter
    string res = "";
    // check all of the unique words
    for (auto p: hashMapA.getAllPairs()) {
        // if doesn't appear
        if (hashMapB.get(p.word).frequency == 0) {
            k++;
            res += p.word + "\n";
            // result.push_back(p.word);
        }
    }
    cout << k << '\n';
    cout << res;
    
    delete[] a;
    delete[] b;
}

int main() {
    // freopen("i.txt", "r", stdin);
    problemB();
    return 0;
}
