class Bank {
public:
    vector<long long> accounts;
    Bank(vector<long long>& balance) {
        for(long long t:balance)
        {
            accounts.push_back(t);
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        int i = account1-1;
        int j = account2-1;
        if(i<accounts.size() && j<accounts.size() && accounts[i]>=money)
        {
            accounts[i]-=money;
            accounts[j]+=money;
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool deposit(int account, long long money) {
        int i = account-1;
        if(i<accounts.size())
        {
            accounts[i]+=money;
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool withdraw(int account, long long money) {
        int i = account-1;
        if(i<accounts.size() && accounts[i]>=money)
        {
            accounts[i]-=money;
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */