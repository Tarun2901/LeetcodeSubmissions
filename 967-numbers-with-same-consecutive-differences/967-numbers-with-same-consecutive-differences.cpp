class Solution {
public:
    vector<int> ans;
    
    void travelAndMake(int i,int n,int k,string temp)
    {
        if(temp.size()==n)
        {
            int no=stoi(temp);
            ans.push_back(no);
            return;
        }
        if(i+k<=9)
        {
            travelAndMake(i+k,n,k,temp+to_string(i+k));
        }
        if(i-k>=0 && k!=0)
        {
            travelAndMake(i-k,n,k,temp+to_string(i-k));
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string str = "";
        for(int i = 1;i<=9;i++)
        {
            str = to_string(i);
            travelAndMake(i,n,k,str);
        }
        return ans;
    }
};