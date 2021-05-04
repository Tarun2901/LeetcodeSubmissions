class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for(int i = 0;i<arr.size();i++)
        {
            sum+=arr[i];
        }
       int count = 0;
        if(sum%3==0)
        {
             int sumpart = 0;
            for(int i = 0;i<arr.size();i++)
            {
                sumpart+=arr[i];
                if(sumpart == sum/3)
                {
                    count++;
                    if(count == 3)
                    {
                        return true;
                    }
                    sumpart = 0;
                }
            }
        }
        return false;
    }
};