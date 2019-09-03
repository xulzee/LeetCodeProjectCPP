//
// Created by liuze.xlz on 2019-08-19.
//
#include "utils.h"

struct Node {
    int key, value;
    Node *next, *prev;

    Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
};

class DoubleList {
public:
    explicit DoubleList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void AddNodeToHead(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        ++size;
    }

    void Remove(Node *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        delete node;
        --size;
    }

    Node *RemoveLastNode() {
        if (tail->prev == head) {
            return nullptr;
        }
        Node *node = tail->prev;
        node->next->prev = node->prev;
        node->prev->next = node->next;
        --size;
        return node;
    }

    int GetSize() {
        return size;
    }


private:
    Node *head, *tail; //virtual node
    int size;
};

class LRUCache1 {
public:
    explicit LRUCache1(int capacity) : capacity(capacity) {
        cache = new DoubleList();
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        int value = map[key]->value;
        put(key, value);
        return value;
    }

    void put(int key, int value) {
        Node *node = new Node(key, value);
        if (map.find(key) != map.end()) {
            cache->Remove(map[key]);
            cache->AddNodeToHead(node);
            map[key] = node;
        } else {
            if (cache->GetSize() == capacity) {
                Node *last_node = cache->RemoveLastNode();
                map.erase(last_node->key);
            }
            cache->AddNodeToHead(node);
            map[key] = node;
        }
    }

private:
    DoubleList *cache;
    unordered_map<int, Node *> map;
    int capacity;
};

class LRUCache {
public:
    explicit LRUCache(int capacity) {
        capacity_ = capacity;
    }

    int get(int key) {
        if (map_.find(key) == map_.end()) {
            return -1;
        }
        // push front
        pair<int, int> key_value = *map_[key];
        cache_.erase(map_[key]);
        cache_.push_front(key_value);
        map_[key] = cache_.begin();
        return cache_.front().second;
    }

    void put(int key, int value) {
        if (map_.find(key) == map_.end()) {
            if (map_.size() >= capacity_){
                map_.erase(cache_.back().first);
                cache_.pop_back();
            }
            cache_.push_front(make_pair(key, value));
            map_[key] = cache_.begin();
        } else {
            cache_.erase(map_[key]);
            cache_.push_front(make_pair(key, value));
            map_[key] = cache_.begin();
        }

    }

private:
    int capacity_;
    list<pair<int, int>> cache_;
    unordered_map<int, list<pair<int, int>>::iterator> map_;
};

int main(){
    auto test = new LRUCache(10);
    test->put(1,1);
    test->put(2,2);
    test->put(3,3);
    test->get(1);
}