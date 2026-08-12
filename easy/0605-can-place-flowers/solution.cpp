#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int size = flowerbed.size();
        int i = 0;
        while (i < size && n > 0) {
            
            if (flowerbed[i] == 1) {
                i += 2;
                
            } else if (i == size - 1 || flowerbed[i + 1] == 0) {
                n--;
                i += 2;
                
            } else {

                i += 3;
            }
        }
        return n <= 0;
    }
};