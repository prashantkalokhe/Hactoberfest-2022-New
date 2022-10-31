/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 */
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
          unordered_map<char,int> R;
        vector<char> unique_r;
        unordered_map<char,int> M;
        vector<char> unique_m;
        for(int i=0;i<s.length();i++){
            if(R.count(s[i])>0){
                R[s[i]]++;
            }
            else{
                R[s[i]]=1;
                unique_r.push_back(s[i]);
            }
        }
        for(int i=0;i<t.length();i++){
            if(M.count(t[i])>0){
                M[t[i]]++;
            }
            else{
                    M[t[i]]=1;
                unique_m.push_back(t[i]);
            }
        }
       vector<char>::iterator it=unique_r.begin();
        while(it!=unique_r.end()){
            unordered_map<char,int>::iterator it1=R.find(*it);
                unordered_map<char,int>::iterator it2=M.find(*it);
                   if(it2!=M.end()){
                       if(it1->first==it2->first && it2->second!=it1->second){
                           return false;
                           break;
                       }
                   }
            else{
                return false;
                break;
            }
            it++;
        }
        return true;
    }
};