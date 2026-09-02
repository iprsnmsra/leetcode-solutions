#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;

class LFUCache {
    int cap;
    int min_freq;
    
    // Key -> {Value, Frequency}
    unordered_map<int, pair<int, int>> key_val;
    
    // Key -> Iterator to the node in the frequency list
    // This allows O(1) removal from the middle of a std::list
    unordered_map<int, list<int>::iterator> key_iter;
    
    // Frequency -> List of Keys (Front is MRU, Back is LRU)
    unordered_map<int, list<int>> freq_map;

public:
    LFUCache(int capacity) {
        cap = capacity;
        min_freq = 0;
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    int get(int key) {
        if (key_val.find(key) == key_val.end()) return -1;
      
        int val = key_val[key].first;
        int freq = key_val[key].second;
        
        freq_map[freq].erase(key_iter[key]);
        

        if (freq_map[freq].empty()) {
            freq_map.erase(freq); // Cleanup empty list
            if (min_freq == freq) min_freq++;
        }
        
 
        freq++;
        freq_map[freq].push_front(key); 
        
        // 4. Update metadata
        key_val[key].second = freq;
        key_iter[key] = freq_map[freq].begin();
        
        return val;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;

 
        if (get(key) != -1) {
            key_val[key].first = value;
            return;
        }
        

        if (key_val.size() >= cap) {

            int evict_key = freq_map[min_freq].back();
            freq_map[min_freq].pop_back();
            
            // Clean up empty list
            if (freq_map[min_freq].empty()) {
                freq_map.erase(min_freq);
            }
            
         
            key_val.erase(evict_key);
            key_iter.erase(evict_key);
        }

        min_freq = 1; // Reset min_freq to 1 for new item
        key_val[key] = {value, 1};
        freq_map[1].push_front(key);
        key_iter[key] = freq_map[1].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */