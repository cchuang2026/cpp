#include <cstdio>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;
#include "molecules.h"

int main() {
    int n, l, u;
    cout<<"start to read sample input..."<<endl; 
    freopen("sample1.in", "r", stdin);
    int a = scanf("%d %d %d", &n, &l, &u);
    assert(3 == a);
    std::vector<int> w(n);
    for (int i = 0; i < n; i++)
        assert(1 == scanf("%d", &w[i]));
    std::vector<int> result = find_subset(l, u, w);
    
    
    printf("%d\n", (int)result.size());
    for (int i = 0; i < (int)result.size(); i++)
        printf("%d%c", result[i], " \n"[i == (int)result.size() - 1]);
}
