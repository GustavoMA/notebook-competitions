/**
*** Floyd Marshall algorithm
*** Author: Gustavo Monteiro Alves - GustavoMA
*** Matrix of adj. starting from 1 to n
**/

int m_adj[MAX_N][MAX_N];

void pre_process(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1 ; j <= n; j++) {
            m_adj[i][j] = (i == j) ? 0 : INF;
        }
    }
}

void floyd_marshall(int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j<= n; j++)
                m_adj[i][j] = min(m_adj[i][j], m_adj[i][k] + m_adj[k][j]);
}
