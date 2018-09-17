//
// Created by apple on 2018/9/17.
//
#include <unordered_map>
#include <list>
using namespace std;
#ifndef LRUCACHE_H
#define LRUCACHE_H

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {

        if (m.count(key)) {
            d.remove(key);
            d.push_front(key);
            return m[key];
        }
        return -1;
    }

    void put(int key, int value) {
        if (d.size() == capacity && m.count(key) ==0) {
            auto it = d.back();
            m.erase(it);
            d.remove(it);
            d.push_front(key);
            m.insert({key, value});
        } else if (m.count(key)>0) {
            d.remove(key);
            d.push_front(key);
            m[key] = value;
        } else {
            d.push_front(key);
            m.insert({key, value});
        }
    }
private:
    int capacity;
    unordered_map<int, int> m;
    list<int> d;
};
#endif
