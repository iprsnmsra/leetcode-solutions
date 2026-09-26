class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        nth_element(points.begin(), points.begin() + k, points.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
            }
        );
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};