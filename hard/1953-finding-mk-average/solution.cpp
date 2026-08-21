#include <vector>
#include <iostream>

using namespace std;

class MKAverage {
private:
    int m, k, sz, pos;
    vector<int> arr; 
    vector<int> bit_count;    
    vector<long long> bit_sum;

    void update(int idx, int val) {
        long long sum_val = 1LL * idx * val;
        for (; idx <= 100000; idx += idx & -idx) {
            bit_count[idx] += val;
            bit_sum[idx] += sum_val;
        }
    }
    long long get_k_sum(int req_k) {
        int curr = 0;
        long long sum = 0;
    
        for (int step = 131072; step > 0; step >>= 1) {
            int next = curr + step;
            if (next <= 100000 && bit_count[next] < req_k) {
                curr = next;
                req_k -= bit_count[curr];
                sum += bit_sum[curr];
            }
        }
        sum += 1LL * req_k * (curr + 1);
        return sum;
    }

public:
    MKAverage(int m, int k) : m(m), k(k), sz(0), pos(0), arr(m), bit_count(100005, 0), bit_sum(100005, 0) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    void addElement(int num) {
        if (sz == m) {
            update(arr[pos], -1);
            sz--;
        }
        arr[pos] = num;
        pos = (pos + 1) % m;
        update(num, 1);
        sz++;
    }
    
    int calculateMKAverage() {
        if (sz < m) return -1;
        long long top_sum = get_k_sum(m - k);
        long long bot_sum = get_k_sum(k);
        
        return (top_sum - bot_sum) / (m - 2 * k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */