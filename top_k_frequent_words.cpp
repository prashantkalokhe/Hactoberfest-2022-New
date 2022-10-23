class Solution {
public:
    struct cmp{

    bool operator()(const pair<int, string> x, const pair<int, string> y){
        if(x.first== y.first) return x.second>y.second;
        return x.first< y.first;
    }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> v;
        unordered_map<string, int> m;
        for(int i=0; i<words.size(); i++){
            m[words[i]]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> p;
        for(auto it: m){
            p.push({it.second, it.first});
        }
        while(k--){
            v.push_back(p.top().second);
            p.pop();
        }
        
        return v;
    }
};
