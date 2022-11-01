#include <iostream>
using namespace std;

class DSU {
    int *parent, *Rank, totalSet;
public:
    DSU(int n) {
        totalSet = n;
        parent = new int[n + 1];
        Rank = new int[n + 1];
        // initialize parent and rank array...
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }
    ~DSU() {
        delete []parent;
        delete []Rank;
    }
    int Find(int x) {
        if (parent[x] == x)
            return x;
        else return parent[x] = Find(parent[x]); // path-compression...
    }
    void Union(int x, int y) {
        int u = Find(x);
        int v = Find(y);
        if (u != v) {
            if (Rank[u] > Rank[v])
                swap(u, v);
            this->parent[u] = v;
            if (Rank[u] == Rank[v])
                ++Rank[v];

            // if (Rank[u] == Rank[v])
            //     ++Rank[u];
            // if (Rank[u] < Rank[v])
            //     parent[u] = v;
            // else
            //     parent[v] = u;

            --totalSet;
        }
    }
    int countSet() {
        return totalSet;
    }
};
