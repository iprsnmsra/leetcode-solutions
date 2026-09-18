class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        bool x_overlap = (rec1[0] < rec2[2]) && (rec2[0] < rec1[2]);
        bool y_overlap = (rec1[1] < rec2[3]) && (rec2[1] < rec1[3]);
        return x_overlap && y_overlap;
    }
};