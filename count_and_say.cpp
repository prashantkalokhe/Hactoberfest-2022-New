class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        n--;
        // if(n==1) return ans;
        int c;
        while(n--){
            string temp="";
            c=1;
            for(int i=0; i<ans.length()-1; i++){
                if(ans[i]==ans[i+1]) c++;
                else{
                    temp+= to_string(c) + ans[i];
                    c=1;
                }
            }
                    temp+= to_string(c) + ans[ans.length()-1];
                    c=1;
            ans= temp;
            
        }
        return ans;
    }
};

