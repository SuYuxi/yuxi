class MyCalendarTwo {
    private TreeMap<Integer, Integer> boundCnt;
    
    public MyCalendarTwo() {
        boundCnt = new TreeMap();
    }
    
    public boolean book(int start, int end) {
        boundCnt.put(start, boundCnt.getOrDefault(start, 0) + 1);
        boundCnt.put(end, boundCnt.getOrDefault(end, 0) - 1);
        int active = 0;
        boolean res = true;
        for(int val : boundCnt.values()) {
            active += val;
            
            if(active > 2) {
                boundCnt.put(start, boundCnt.get(start) - 1);
                boundCnt.put(end, boundCnt.get(end) + 1);
                if(boundCnt.get(start) == 0) boundCnt.remove(start);
                if(boundCnt.get(end) == 0) boundCnt.remove(end);               
                return false;
            }
        }
        return res;
    }
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */
