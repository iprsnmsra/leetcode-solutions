#include <vector>
#include <iostream>

using namespace std;


struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
    
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    int size;

    vector<Node*> map; 

    Node* head;
    Node* tail;

    void addNode(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    void removeNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

   
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }
        Node* popTail() {
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }

public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
  
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

    
        map.resize(10001, nullptr);
        
    
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (map[key] == nullptr) return -1;
        
        Node* node = map[key];
        moveToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (map[key] != nullptr) {
           
            Node* node = map[key];
            node->val = value;
            moveToHead(node);
        } else {
          
            Node* newNode = new Node(key, value);
            map[key] = newNode;
            addNode(newNode);
            size++;
            
           
            if (size > capacity) {
                Node* tailNode = popTail();
                map[tailNode->key] = nullptr; 
                delete tailNode;            
                size--;
            }
        }
    }
};