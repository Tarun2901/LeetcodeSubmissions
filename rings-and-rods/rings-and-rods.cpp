class Solution {
public:
    int countPoints(string rings) {
        string color = "";
        
        for(int i = 0;i<rings.size();i+=2)
        {
            color.push_back(rings[i]);
        }
        vector<int>pos;
        for(int i = 1;i<rings.size();i+=2)
        {
            pos.push_back(rings[i]-'0');
        }
        vector<bool>green(10,false);
        vector<bool>red(10,false);
        vector<bool>blue(10,false);
        for(int i = 0;i<color.size();i++)
        {
            int po = pos[i];
            if(color[i] == 'B')
            {
                blue[po] = true;
            }
            if(color[i] == 'R')
            {
                red[po] = true;
            }
            if(color[i] == 'G')
            {
                green[po] = true;
            }
        }
        int count = 0;
        for(int i = 0;i<10;i++)
        {
            if(green[i] && blue[i] && red[i])
            {
                count++;
            }
        }
        return count;
    }
};