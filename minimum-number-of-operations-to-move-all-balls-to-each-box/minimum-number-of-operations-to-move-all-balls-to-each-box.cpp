class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans(boxes.size(),0);
        
        for(int i = 0;i<boxes.length();i++)
        {
            for(int j = i+1;j<boxes.length();j++)
            {
                if(boxes[j] == '1')
                {
                    ans[i]+=abs(i-j);
                }
            }
            for(int k = i-1;k>=0;k--)
            {
                if(boxes[k] == '1')
                {
                    ans[i]+=abs(i-k);
                }
            }
        }
        return ans;
    }
};