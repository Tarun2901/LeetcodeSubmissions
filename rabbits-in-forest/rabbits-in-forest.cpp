class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        if(n == 0)
        {
            return 0;
        }
        map<int,int> mp;
        
        int count = 0;
        
        for(int i = 0;i<n;i++)
        {
            mp[answers[i]]++;
        }
        
        for(auto p:mp)
        {
            int groupsize = p.first+1;
            int reportees = p.second;
            
            int ng = (int)ceil(reportees*1.0/groupsize*1.0);
            count+= ng*groupsize;

        }
        
        return count;
    }
};