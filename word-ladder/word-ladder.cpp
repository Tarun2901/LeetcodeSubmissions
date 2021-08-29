class Solution {
public:
    map<string,vector<string>> mp;
    map<string,bool> status;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = INT_MAX;
        bool b = false;
        for(string s: wordList)
        {
            if(s == endWord)
            {
                b = true;
                break;
            }
        }
        if(b == false)
        {
            //no valid
            return 0;
        }
        vector<string> nodes;
        int n = beginWord.size();
        for(string s:wordList)
        {
            int i = 0;
            int j = 0;
            int count = 0;
            while(i<n && j<n)
            {
                if(s[i] != beginWord[j])
                {
                    count++;
                }
                i++;
                j++;
            }
            if(count == 1)
            {
                nodes.push_back(s);
            }
        }
        
        for(int i = 0;i<wordList.size()-1;i++)
        {   string s = wordList[i];
            for(int j = i + 1;j<wordList.size();j++)
            {   string str = wordList[j];
                 int i1 = 0;
                int j1 = 0;
                int count = 0;
            while(i1<n && j1<n)
            {
                if(s[i1] != str[j1])
                {
                    count++;
                }
                i1++;
                j1++;
            }
            if(count == 1)
            {
                mp[s].push_back(str);
                mp[str].push_back(s);
            }
            }
        }
        for(string s:nodes)
        {
            mp[beginWord].push_back(s);
            mp[s].push_back(beginWord);
        }
        if(mp[endWord].size() == 0)
        {
            return 0;
        }
        queue<pair<string,int>> q;
        q.push(make_pair(beginWord,1));
        
        while(q.size()>0)
        {
                string tmp = q.front().first;
                int lvl = q.front().second;
                if(tmp == endWord)
                {
                    ans = lvl;
                    break;
                }
                //visited
                status[tmp] = true;
                q.pop();
                for(string s: mp[tmp])
                {
                    if(status[s] !=true)
                    {
                        q.push(make_pair(s,lvl+1));
                    }
                }
        }
        return ans == INT_MAX?0:ans;
        
    }
};