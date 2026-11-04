#include <vector>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // Optimization: Fast I/O execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (n == 1) return 0;

        int num_edges = edges.size();

        // 1. Forward Star Graph Representation (Absolute Zero Heap Fragmentation)
        vector<int> head(n, -1), to(num_edges), weight(num_edges), nxt(num_edges);
        for (int i = 0; i < num_edges; ++i) {
            int u = edges[i][0];
            to[i] = edges[i][1];
            weight[i] = edges[i][2];
            nxt[i] = head[u];
            head[u] = i;
        }

        // 2. Flattened 1D Distance Array mapping 2D state (Node, Consecutive Count)
        int state_space = n * (k + 1);
        vector<int> dist(state_space, 2e9); // 2 billion safely avoids overflow but exceeds max path length

        // 3. Raw 64-Bit Packed Priority Queue (Min-Heap)
        // Format: [32 bits: Distance] [16 bits: Node (u)] [16 bits: Count (c)]
        priority_queue<uint64_t, vector<uint64_t>, greater<uint64_t>> pq;

        int start_idx = 0 * (k + 1) + 1;
        dist[start_idx] = 0;
        
        // Pack start state: d = 0, u = 0, c = 1
        pq.push(1ULL); // (0 << 32) | (0 << 16) | 1

        while (!pq.empty()) {
            uint64_t state = pq.top();
            pq.pop();

            // 4. Hardware-Aligned Bit Extraction
            int d = state >> 32;
            int u = (state >> 16) & 0xFFFF;
            int c = state & 0xFFFF;

            // Lazy deletion skip
            if (d > dist[u * (k + 1) + c]) continue;

            // Target reached optimally
            if (u == n - 1) return d;

            char char_u = labels[u];

            // 5. Contiguous Edge Sweep
            for (int e = head[u]; e != -1; e = nxt[e]) {
                int v = to[e];
                int w = weight[e];
                
                // Determine new sequence count based on label matching
                int nc = (char_u == labels[v]) ? (c + 1) : 1;

                if (nc <= k) {
                    int nd = d + w;
                    int idx = v * (k + 1) + nc;

                    // Relaxation
                    if (nd < dist[idx]) {
                        dist[idx] = nd;
                        // Pack Next State: [nd] [v] [nc]
                        uint64_t next_state = ((uint64_t)nd << 32) | ((uint64_t)v << 16) | nc;
                        pq.push(next_state);
                    }
                }
            }
        }

        return -1; // Unreachable under constraint k
    }
};