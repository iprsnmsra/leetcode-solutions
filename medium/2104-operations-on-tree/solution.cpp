#include <vector>
#include <iostream>

using namespace std;

class LockingTree {
private:
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> locked_by; 

public:
    LockingTree(vector<int>& parent) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = parent.size();
        this->parent = parent;
        children.resize(n);
        locked_by.assign(n, 0);
    
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (locked_by[num] == 0) {
            locked_by[num] = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if (locked_by[num] == user) {
            locked_by[num] = 0;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {

        if (locked_by[num] != 0) {
            return false;
        }
        int curr = parent[num];
        while (curr != -1) {
            if (locked_by[curr] != 0) {
                return false;
            }
            curr = parent[curr];
        }
        bool has_locked_descendant = false;
        vector<int> q;
        q.push_back(num);
        
        int head = 0;
        while (head < q.size()) {
            int current_node = q[head++];
            
            for (int child : children[current_node]) {
                if (locked_by[child] != 0) {
                    has_locked_descendant = true;
                    locked_by[child] = 0;
                }
                q.push_back(child);
            }
        }
        if (has_locked_descendant) {
            locked_by[num] = user;
            return true;
        }
        
        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */