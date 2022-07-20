class MyCalendarThree {
    private TreeMap<Integer, Integer> boundCnt;
    
    public MyCalendarThree() {
        boundCnt = new TreeMap();
    }
    
    public int book(int start, int end) {
        boundCnt.put(start, boundCnt.getOrDefault(start, 0) + 1);
        boundCnt.put(end, boundCnt.getOrDefault(end, 0) - 1);
        int active = 0;
        int res = 0;
        for(int val : boundCnt.values()) {
            active += val;
            if(active > res) res = active;
        }
        return res;
    }
}

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
