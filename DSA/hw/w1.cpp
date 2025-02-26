// Milena Kuznetsova m.kuznetsova@innopolis.university
#include <iostream>

using namespace std;

void insertSort(int a[1000000], int n) {
	for (int i = 1; i < n; i++) {
        int temp = a[i];
        int j = i - 1;
        for (j = i - 1; j >= 0 && a[j] > temp; j--) // while elements on the left are greater
            a[j + 1] = a[j]; // slide them all to the right to leave space for temp
        a[j + 1] = temp; // add the least element to the right
    }
}

void p1() {
    int a[1000000];
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    insertSort(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
}

struct Position {
    int score;
    char nickname[1000];
};

void bubbleSort(Position a[], int n) {
	bool swapped = true; // trace changes
	while (swapped) {    // when nothing's changed, stop
		swapped = false;
		for (int i = 1; i < n; i++) {
			if (a[i-1].score > a[i].score) {
                Position temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
				swapped = true;
			}
		}
	}
}

void p2() {
    int n, k;
    cin >> n >> k;
    k = min(n, k);
    Position board[100]; // best results only
    for (int i = 0; i < k; i++) { // create initial board
            cin >> board[i].nickname >> board[i].score;
    }
    // bubble sort initial board
    bubbleSort(board, k);
    for (int i = k; i < n; i++) {
        Position candidate;
        cin >> candidate.nickname >> candidate.score;
        bool slide = false;
        Position prev; // to save prev position in inner loop
        for (int j = k - 1; j >= 0; j--) {
            if (slide) {
                Position temp = board[j];
                board[j] = prev;
                prev = temp;
            }
            else if (candidate.score > board[j].score) {
                slide = true;
                prev = board[j];
                board[j] = candidate;
            }
        }
    }
    for (int i = k - 1; i >= 0; i--) {
        cout << board[i].nickname << ' ' << board[i].score << '\n';
    }
}

int main() {
    // freopen("i.txt", "r", stdin);
    p1();
    return 0;
}