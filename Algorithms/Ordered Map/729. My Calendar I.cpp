class MyCalendar {
public:
    map<int, int> books;
    
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        map<int, int>::iterator upperIt = books.upper_bound(start);
        if(upperIt != books.end() && upperIt->second < end) return false;
        books[end] = start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
