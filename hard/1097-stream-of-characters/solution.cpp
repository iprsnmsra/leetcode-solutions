#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring> 

using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;

        memset(children, 0, sizeof(children));
    }
};

class StreamChecker {
    TrieNode* root;
    string stream; 
    int max_word_len; 

public:
    StreamChecker(vector<string>& words) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        root = new TrieNode();
        max_word_len = 0;

        for (const string& word : words) {
            TrieNode* node = root;
            max_word_len = max(max_word_len, (int)word.length());
            
            for (int i = word.length() - 1; i >= 0; i--) {
                int idx = word[i] - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
            node->isEnd = true;
        }
    }
    
    bool query(char letter) {
        stream += letter;
        
        TrieNode* node = root;
        int len = stream.length();
        for (int i = len - 1; i >= 0 && (len - i) <= max_word_len; i--) {
            int idx = stream[i] - 'a';

            if (!node->children[idx]) {
                return false;
            }
            
            // Move to child
            node = node->children[idx];
            
            // If we found a word ending here, return true
            if (node->isEnd) {
                return true;
            }
        }
        
        return false;
    }
};