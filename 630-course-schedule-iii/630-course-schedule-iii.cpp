class Solution {
public:
    int scheduleCourse(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](auto &a, auto &b) {return a[1] < b[1]; });
        
        int frontier = 0;
        priority_queue<int> pq;
        for (auto p : v) {
            int dur = p[0];
            int end = p[1];
            if (frontier + dur <= end) {
                frontier += dur;
                pq.emplace(dur);
                continue;
            }
            if (pq.empty() || pq.top() <= dur) continue;
            frontier += dur - pq.top();
            pq.pop();
            pq.emplace(dur);
        }
        
        return (int)pq.size();
    }
};