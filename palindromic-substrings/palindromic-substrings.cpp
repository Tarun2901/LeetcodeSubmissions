class Solution {
public:
    bool ispalindrome(string temp)
	{
		if(temp.size()==1)
		{
			return 1;
		}
		int i=0;
		int j=temp.size()-1;
		while(i<j)
		{
			if(temp[i]!=temp[j])
			{
				return 0;
			}
			i++;
			j--;
		}
		return 1;
	}
    int countSubstrings(string s) {
        	int count=0;
		for(int i=0;i<s.size();i++)
		{
			string temp="";
			for(int j=i;j<s.size();j++)
			{
				temp+=s[j];
				if(ispalindrome(temp))
				{
					count++;
				}
			}
		}
		return count;
    }
};