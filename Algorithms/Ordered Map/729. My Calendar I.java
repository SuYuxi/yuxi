class MyCalendar {
    TreeMap<Integer, Integer> events;
    public MyCalendar() {
        events = new TreeMap<Integer, Integer>();
    }
    
    public boolean book(int start, int end) {
        Integer upperBoundKey = events.higherKey(start);
        if(upperBoundKey != null && events.get(upperBoundKey) < end) return false;
        events.put(end, start);
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
