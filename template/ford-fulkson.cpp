class Network {
private:
    int size;
    int prev[MAX];
    bool augmentable(int, int);
public:
    int cap[MAX][MAX];
    void clear(int);
    int maxFlow(int, int);
};
void Network::clear(int n) {
    memset(cap, 0, sizeof(cap));
    size = n;
}
bool Network::augmentable(int s, int t) {
    queue<int> queue;
    memset(prev, -1, sizeof(prev));
    prev[s] = s;
    queue.push(s);
    while(!queue.empty()) {
        int p = queue.front(), i;
        queue.pop();
        for(i = 0; i < size; i++) {
            if(cap[p][i] > 0 && prev[i] == -1) {
                prev[i] = p;
                if(i == t) {
                    return true;
                } else {
                    queue.push(i);
                }
            }
        }
    }
    return false;
}
int Network::maxFlow(int s, int t) {
    int flow = 0, i;
    while(augmentable(s, t)) {
        int extend = INF;
        for(i = t; i != s; i = prev[i]) {
            if(extend > cap[prev[i]][i]) {
                extend = cap[prev[i]][i];
            }
        }
        for(i = t; i != s; i = prev[i]) {
            cap[prev[i]][i] -= extend;
            cap[i][prev[i]] += extend;
        }
        flow += extend;
    }
    return flow;
}
