/*
Two O(logn) time operations on an array
Let p(k) denote the largest power of two that divides k.

Essentially what we do is we try to seperate our array into partitions based on LSB. 
Index:  1  2  3  4  5  6  7  8  
LSB [[P(k)]]:    1  2  1  4  1  2  1  8

bit[i] contains the sum of the last LSB(i) elements ending at i
bit[6] stores the sum of arr[5..6]  (because LSB(6)=2 ie 2 is the largest nmber to divide 6)
bit[8] stores arr[1..8] (LSB is 8)
bit[12] stores arr[9..12] (LSB IS 4)
bit[3] stores arr[3..3]  (LSB IS 1)
*/

#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n) : n(n) {
        bit.assign(n + 1, 0);
    }

    // point update: add value to index i
    void update(int i, long long val) {
        while (i <= n) {
            bit[i] += val;
            i += i & -i;
        }
    }

    // prefix sum: sum of [1..i]
    long long query(int i) {
        long long s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    // range sum [l..r]
    long long range_query(int l, int r) {
        return query(r) - query(l - 1);
    }
};




/*The C implementation

#include <stdio.h>

#define MAXN 200000

int n;
long long bit[MAXN + 1];

void update(int i, long long val) {
    while (i <= n) {
        bit[i] += val;
        i += i & -i;
    }
}

long long query(int i) {
    long long s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

long long range_query(int l, int r) {
    return query(r) - query(l - 1);
}

int main() {
    n = 10;
    update(3, 5);
    update(7, 2);
    printf("%lld\n", range_query(1, 7)); // outputs 7
    return 0;
}
*/

