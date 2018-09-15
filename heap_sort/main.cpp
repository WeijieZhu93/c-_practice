#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;
namespace heap_sort {
    inline int left(int i) {
        return i << 1;
    }

    inline int right(int i) {
        return i << 1 | 1;
    }

    template<class T>
    void swap(T *a, int i, int j) {
        int c = a[i];
        a[i] = a[j];
        a[j] = c;
    }

    template<class T>
    void modify(T *a, int heap_size, int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l <= heap_size && a[l] > a[largest]) largest = l;
        if (r <= heap_size && a[r] > a[largest]) largest = r;
        if (largest != i) {
            swap(a, i, largest);
            modify(a, heap_size, largest);
        }
    }

    template<class T>
    void build_heap(T *a, int len) {
        for (int i = len / 2; i >= 1; i--) {
            modify(a, len, i);
        }
    }

    template <class T>
    void heap_sort(T *a, int len) {
        build_heap(a, len);
        for (int i = len; i > 1; i--) {
            swap(a, 1, i);
            build_heap(a, i - 1);
        }
    }
}

int a[100];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    heap_sort::heap_sort<int>(a, n);
    for (int i = 1; i <= n; i++) cout << a[i] << endl;
    return 0;
}
/*
10
7 5 8 3 2 1 9 10 4 6
*/
