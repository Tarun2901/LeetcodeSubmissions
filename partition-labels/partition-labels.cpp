class Solution {
public:
    
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        vector<int> ans;
        int ma=0;
        int start=0;
        for(int i=0;i<n;i++){
            if(mp[s[i]]>ma){
                ma=mp[s[i]];
            }
            else if(i==ma){
                ans.push_back(i-start+1);
                start=i+1;
                ma=i+1;
            }
        }
        return ans;
    }
};