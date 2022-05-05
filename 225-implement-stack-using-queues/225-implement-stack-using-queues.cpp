class MyStack {
private:
    queue<int> q;
public:
    bool empty() { return q.empty(); }
    void push(int x) { q.emplace(x); }
    
    int pop() {
        int n = q.size();
        for (int i = 0; i < n-1; ++i) {
            q.emplace(q.front());
            q.pop();
        }
        int ans = q.front(); q.pop();
        return ans;
    }
    
    int top() {
        int ans = -1;
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            ans = q.front();
            q.emplace(q.front());
            q.pop();
        }
        return ans;
    }
};
