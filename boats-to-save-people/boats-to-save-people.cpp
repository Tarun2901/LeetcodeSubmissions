class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i = 0;
        int j = people.size()-1;
        int count = 0;
        
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                count+=1;
                i++;
                j--;
            }
            else
            {
               if(people[i]>=people[j])
               {
                   count+=1;
                   i++;
               }
            else 
                {
                    count+=1;
                    j--;
                }
            }
        }
        return count;
    }
};