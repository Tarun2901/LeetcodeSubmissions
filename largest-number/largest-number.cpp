class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s = "";
        map<int,int> mp;
        for(int i = 0;i<nums.size();i++)
        {
            for(int j = 0;j<nums.size()-1-i;j++)
            {
                string a = to_string(nums[j]);
                string b = to_string(nums[j+1]);
                
                string ab = a+b;
                string ba = b+a;
                if(ab>ba)
                {
                    continue;
                }
                else 
                {
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
        for(int i = 0;i<nums.size();i++)
        {   
           s+= to_string(nums[i]);
         
        }
        return s[0] == '0'?"0":s;
    }
};