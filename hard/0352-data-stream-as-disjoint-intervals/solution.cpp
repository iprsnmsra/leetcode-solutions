#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class SummaryRanges {
private:

    map<int, int> intervals;

public:
    SummaryRanges() {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    
    void addNum(int value) {

        auto it = intervals.upper_bound(value);
  
        auto start_it = (it == intervals.begin()) ? intervals.end() : prev(it);
        
   
        if (start_it != intervals.end() && start_it->second >= value) {
            return;
        }

        bool mergePrev = (start_it != intervals.end() && start_it->second == value - 1);
        bool mergeNext = (it != intervals.end() && it->first == value + 1);

        if (mergePrev && mergeNext) {
            start_it->second = it->second;
            intervals.erase(it);
        } else if (mergePrev) {

            start_it->second = value;
        } else if (mergeNext) {
            int next_end = it->second;
            intervals.erase(it);
            intervals[value] = next_end;
        } else {
            // Case: Isolated new interval
            intervals[value] = value;
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        // Simply traverse the map which is already sorted by key (start)
        for (const auto& entry : intervals) {
            result.push_back({entry.first, entry.second});
        }
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */