#include <iostream>
#include "vector.h"
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
    stl::Vector<int> a;
    cout<<a.size()<<endl;
    cout<<a.capacity()<<endl;
    for (int i=0;i<10;i++) a.push_back(i);
    stl::Vector<int> b  = stl::Vector<int>(a);
    for (int i=0;i<a.size();i++) cout<<a[i]<<endl;
    for (int i=0;i<b.size();i++) cout<<b[i]<<endl;
    cout<<*a.begin()<<endl;
    return 0;
}