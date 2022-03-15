class Solution {
private:
    vector<long long>ans;
    void getMax(long long n, long long prev, vector<long long>&cur){
        if(n==0){
            ans = cur;
            return;
        }
        if(n<0) return;
        for(long long k = prev; k <= n; k += 2) {
            cur.push_back(k);
            getMax(n - k, k+2, cur);
            if (ans.size() > 0) break;
            cur.pop_back();
        }
    }
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2!=0) return {};
        vector<long long>cur;
        getMax(finalSum, 2, cur);
        return ans;
    }
};