#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<string> answer;

        for (const string& query : queries) {
            
            for (const string& dict_word : dictionary) {
                int diff = 0;
                
                for (int i = 0; i < query.length(); ++i) {
                    if (query[i] != dict_word[i]) {
                        diff++;
                    }
              
                    if (diff > 2) {
                        break;
                    }
                }

                if (diff <= 2) {
                    answer.push_back(query);

                    break; 
                }
            }
        }

        return answer;
    }
};