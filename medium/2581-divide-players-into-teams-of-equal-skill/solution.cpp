class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = skill.size();
        long long total_sum = 0;
        int freq[1001] = {0};
        for (int s : skill) {
            total_sum += s;
            freq[s]++;
        }
        int total_teams = n / 2;
        if (total_sum % total_teams != 0) {
            return -1;
        }

        int target_skill = total_sum / total_teams;
        long long total_chemistry = 0;
        for (int s : skill) {
            int partner = target_skill - s;
            if (partner < 1 || partner > 1000 || freq[s] != freq[partner]) {
                return -1;
            }

            total_chemistry += (long long)s * partner;
        }
        return total_chemistry / 2;
    }
};