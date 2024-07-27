/*
Problem Name: Planets Queries II
Problem Link: https://cses.fi/problemset/task/1160/
Idea:
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;

int kthDescendant(int u, int k, int LOG, vector<vector<int>> &descendant) {
    for(int i = LOG-1; i >= 0; i--) {
        if(k & (1 << i)) {
            u = descendant[u][i];
        }
    }
    return u;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
        int n, q;
        cin >> n >> q;
        vector<int> child(n);
        vector<int> before[n];
        for(int i = 0; i < n; i++) {
            cin >> child[i];
            child[i]--;
            before[child[i]].push_back(i);
        }

        vector<int> cycle_id(n, -2);
        vector<map<int, int>> cycles;
        for(int u = 0; u < n; u++) {
            if(cycle_id[u] != -2){continue;}
            int now = u;
            cycle_id[now] = -3;
            vector<int> path{now};
            while(cycle_id[child[now]] == -2) {
                now = child[now];
                cycle_id[now] = -3;
                path.push_back(now);
            }
            bool cycle_started = false;
            map<int, int> cycle;
            for(auto u : path) {
                if(u == child[now]) {
                    cycle_started = true;
                }
                if(cycle_started) {
                    cycle[u] = (int)cycle.size();
                    cycle_id[u] = (int)cycles.size();
                }else cycle_id[u] = -1;
            }
            if(cycle.size())cycles.push_back(cycle);
        }

        vector<int> cycle_dist(n, 0);
        for(int p = 0; p < n; p++) {
            if(cycle_id[p] != -1 || cycle_id[child[p]] == -1){continue;}
            cycle_dist[p] = 1;
            queue<int> q;
            q.push(p);
            while(!q.empty()) {
                int v = q.front();
                q.pop();
                for(int i = 0; i < (int)before[v].size(); i++) {
                    int u = before[v][i];
                    cycle_dist[u] = cycle_dist[v] + 1;
                    q.push(u);
                }
            }
        }

        int LOG = (int)ceil(log2(n));
        LOG++; // For checking if the 2 vertex lay on the same component or not
        vector<vector<int>> descendant(n, vector<int>(LOG));
        for(int i = 0; i < n; i++) {
            descendant[i][0] = child[i];
        }
        for(int k = 1; k < LOG; k++) {
            for(int u = 0; u < n; u++) {
                descendant[u][k] = descendant[descendant[u][k-1]][k-1];
            }
        }

        while(q--) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            if(cycle_id[descendant[u][LOG-1]] != cycle_id[descendant[v][LOG-1]]) {
                cout << "-1\n";
                {continue;}
            }
            if(cycle_id[u] == -1 && cycle_id[v] == -1) {
                if(cycle_dist[u] < cycle_dist[v]) {
                    cout << "-1\n";
                }else {
                    int diff = cycle_dist[u] - cycle_dist[v];
                    cout << (kthDescendant(u, diff, LOG, descendant) == v ? diff : -1) << "\n";
                }
            }else {
                if(cycle_id[u] != -1 && cycle_id[v] == -1) {
                    cout << "-1\n";
                }else {
                    int dist = cycle_dist[u];
                    int u_root = kthDescendant(u, dist, LOG, descendant);

                    map<int, int> &cycle = cycles[cycle_id[u_root]];
                    int u_idx = cycle[u_root];
                    int v_idx = cycle[v];
                    int diff = (u_idx <= v_idx) ? v_idx - u_idx : (int)cycle.size() - (u_idx - v_idx);
                    cout << dist + diff << "\n";
                }
            }
        }
    }
    return 0;
}