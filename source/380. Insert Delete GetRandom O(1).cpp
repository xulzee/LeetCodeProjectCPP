// @Time    : 2019/4/20 0:17
// @Author  : xulzee
// @Email   : xulzee@163.com
// @Software: CLion

#include <unordered_map>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class RandomizedSet {
public:
    int size;
    unordered_map<int, int> dataIndexMap;
    unordered_map<int, int> indexDataMap;

    /** Initialize your data structure here. */
    RandomizedSet() {
        size = 0;
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool res = false;
        if (dataIndexMap.find(val) == dataIndexMap.end()) {
            dataIndexMap[val] = size;
            indexDataMap[size] = val;
            size++;
            res = true;
        }
        return res;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool res = false;
        if (dataIndexMap.find(val) != dataIndexMap.end()) {
            int deleteIndex = dataIndexMap[val];
            int lastIndex = --size;
            dataIndexMap[indexDataMap[lastIndex]] = deleteIndex;
            indexDataMap[deleteIndex] = indexDataMap[lastIndex];
            dataIndexMap.erase(val);
            indexDataMap.erase(lastIndex);
            res = true;
        }
        return res;
    }

    /** Get a random element from the set. */
    int getRandom() {
        if (size == 0) {
            return 0;
        }
        int randomIndex = rand() % size;
        return indexDataMap[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
    shared_ptr<RandomizedSet> test(new RandomizedSet());
    cout << test.get()->insert(1) << endl;
    cout << test.get()->remove(2) << endl;
    cout << test.get()->insert(2) << endl;
    cout << test.get()->getRandom() << endl;
    cout << test.get()->remove(1) << endl;
    cout << test.get()->insert(2) << endl;
    cout << test.get()->getRandom() << endl;
}