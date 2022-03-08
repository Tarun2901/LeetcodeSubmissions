class Solution {
public:
    

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> mapped;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            int num = nums[i];
            int buildNo = 0;
            int mult = 1;
            if(num == 0)
            {
                buildNo = mapping[num];
                mapped.push_back({buildNo,i});
                continue;
            }
            while(num>0)
            {
                int dig = num%10;
                num = num/10;
                int mappedDig = mapping[dig];
                buildNo = buildNo + mult*mappedDig;
                mult = mult*10;
               
            }
            
            mapped.push_back({buildNo,i});
        }
        sort(mapped.begin(),mapped.end());
        vector<int> ans;
        for(pair<int,int>p:mapped)
        {
            ans.push_back(nums[p.second]);
        }
        return ans;
    }
};