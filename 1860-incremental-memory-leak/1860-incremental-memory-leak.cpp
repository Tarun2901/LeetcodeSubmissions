class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int sec = 1;
        while(memory1>=0 && memory2>=0)
        {
            if(memory1 >= memory2)
            {
                if(sec<=memory1)
                {
                    memory1 = memory1 - sec;
                }
                else
                {
                    return {sec,memory1,memory2};
                }
            }
            else
            {
                 if(sec<=memory2)
                {
                    memory2 = memory2 - sec;
                }
                else
                {
                    return {sec,memory1,memory2};
                }
            }
            sec++;
        }
        return {sec,memory1,memory2};
    }
};