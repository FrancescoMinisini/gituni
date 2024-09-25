#include <iostream>
using namespace std;

void scambia(int a[], int v1, int  v2) {
    int appoggio;
    appoggio = a[v1];
    a[v1] = a[v2];
    a[v2] = appoggio;
}

int posmin(int a[], int p, int j) {
    int s = a[p];
    int posmin = p;
    for (int i = p + 1; i < j; i++) {
        if (s > a[i]) {
            s = a[i];
            posmin = i;
        }
    }
    return posmin;
}

void ordcresc(int a[], int n) {
    int p = 0;
    for (int i = 0; i < n; i++) {
        p = posmin(a, i, n);
        scambia(a, i, p);
    }
}

int main() {
    int n;
    int res;
    cout << "Inserisci la dimensione dell'array: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cout << "elemento numero " << i + 1 << ": ";
        cin >> a[i];
    }

    ordcresc(a, n);
    cout << endl << "{";
    for (int i = 0; i < n; i++) {
        cout << " " << a[i];
    }
    cout << " }" << endl;

    return 0;
}