#include <string>
#include <iostream>

using namespace std;
class Solution
{
    public:
    int vowelConsonantScore(string s)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int v =0;
        int c =0;
        for (char ch : s){
            if(ch>='a' && ch<= 'z'){
                if(ch =='a' || ch =='e' || ch == 'i' || ch =='u' || ch =='o')
                {
                    v++;
                }
                else{
                    c++;
                }
                    
                }
            }
        if (c == 0)return 0;
        return v / c ;
        }
};