class StockSpanner {
        Stack<Integer> st;
        ArrayList<Integer> span;
    public StockSpanner() {
        st = new Stack<>();
        span = new ArrayList<>();
    }
    
    public int stockSpan(int idx)
    {   int res = 0;
        while(st.size()>0 && span.get(idx) >= span.get(st.peek()))
        {
            st.pop();
        }
     if(st.size() == 0)
     {
         res = idx + 1;
     }
     else
     {
         res = idx - st.peek();
     }
     st.push(idx);
     return res;
    }
    
    public int next(int price) {
        span.add(price);
        return stockSpan(span.size()-1);
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */