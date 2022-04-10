class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        vector<int> record;
        
        for(string s:ops)
        {
            if(s == "C")
            {
                if(record.size() > 0)
                {
                    record.pop_back();
                }
            }
            else if(s == "D")
            {
                int prev = record[record.size() - 1];
                record.push_back(prev*2);
            }
            else if(s == "+")
            {
                int prev = record[record.size() - 1];
                int prev2 = record[record.size() - 2];
                record.push_back(prev+prev2);
            }
            else 
            {
                int num = stoi(s);
                record.push_back(num);
            }
        }
        int sum = 0;
        
        for(int num:record)
        {
            sum+=num;
        }
        return sum;
    }
};