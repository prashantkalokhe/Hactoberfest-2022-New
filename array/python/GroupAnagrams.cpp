class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string curr = "";
        int total_size = strs.size();
        
        
        map<string,vector<string>>groupAnagram;
        vector<vector<string>>ans;
        
        
        for(auto currS:strs){
            curr = currS;
            sort(curr.begin(),curr.end());
            groupAnagram[curr].push_back(currS);
        }
        for(auto var:groupAnagram){
            ans.push_back(var.second);
        }
        
        return ans;
    }
};