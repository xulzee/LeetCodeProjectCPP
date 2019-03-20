//
// Created by xulzee on 2019/3/20.
//
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class Pool {
private:
    unordered_map<string, int> keyIndexMap;
    unordered_map<int, string> indexKeyMap;
    int size;

public:
    Pool() {
        size = 0;
    }

    void push(string key){
        if (keyIndexMap.find(key) == keyIndexMap.end()){
            keyIndexMap[key] = size;
            indexKeyMap[size] = key;
            size++;
        }
    }

    void pop(string key){ // 重要
        if (keyIndexMap.find(key) == keyIndexMap.end()){
            int deleteIndex = keyIndexMap[key];
            int lastIndex = --size;
            string lastKey = indexKeyMap[lastIndex];
            keyIndexMap[lastKey] = deleteIndex;
            indexKeyMap[deleteIndex] = lastKey;
            keyIndexMap.erase(key);
            indexKeyMap.erase(lastIndex);
        }
    }

    string getRandom(){
        if (size == 0){
            return nullptr;
        }
        int randomIndex = rand() % size; // 0~size-1
        return indexKeyMap[randomIndex];
    }
};
