/**
*** Dijkstra algorithm
*** Author: Gustavo Monteiro Alves - GustavoMA
**/

// (node, weight)
vii adj_list[MAX_N];
int dist[MAX_N];

priority_queue<ii, vii, greater<ii>> PQ;
void Dijkstra(int start) {
    PQ.push(ii(0,start));
    dist[start] = 0;
    while(!PQ.empty()) {
        ii node = PQ.front();
        PQ.pop();
        int v = node.sc;
        if (node.fi > dist[v]) continue;
        for (int i = 0; i < (int) adj_list[v].size(); i++) {
            int u = adj_list[v][i].fi;
            int d = adj_list[v][i].sc;
            if (dist[v] + d < dist[u]) {
                dist[u] = dist[v] + d;
                PQ.push(ii(dist[u], u));
            }
        }
    }
}
