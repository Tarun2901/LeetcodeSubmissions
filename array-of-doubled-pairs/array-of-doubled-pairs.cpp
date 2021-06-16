class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++)
        {
            if(mp.find(arr[i]) == mp.end())
            {
                mp[arr[i]] = 1;
            }
            else
            {
                mp[arr[i]]++;
            }
        }
        for(int i = 0;i<n;i++)
        {   
            if(arr[i]<0)
                
            {   cout<<arr[i];
                if(abs(arr[i])%2!=0 && mp[arr[i]]>0)
                {
                    return false;
                 }
                int half = arr[i]/2;
                if(mp.find(half)!=mp.end() && mp[arr[i]]>0)
                {
                    if(mp[arr[i]] == 1)
                    {
                        mp.erase(arr[i]);
                    }
                    else
                    {
                        mp[arr[i]]--;
                    }
                    
                    if(mp[half] == 1)
                    {
                        mp.erase(half);
                    }
                    else
                    {
                        mp[half]--;
                    }
                }
            }
            else
            {   int db = 2*arr[i];
                if(mp.find(db)!=mp.end() && mp[arr[i]]>0)
                {
                  if(mp[arr[i]] == 1)
                  {
                      mp.erase(arr[i]);
                  }
                    else
                    {
                        mp[arr[i]]--;
                    }
                    if(mp[db] == 1)
                    {
                        mp.erase(db);
                    }
                    else
                    {
                        mp[db]--;
                    }
                }
            }
        }
    
        for(auto p:mp)
        {
            cout<<p.first<<" "<<p.second<<" ";
            if(p.second>0)
            {
                return false;
            }
        }
        return true;
    }
};