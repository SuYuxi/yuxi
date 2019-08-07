// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int ptr4 = 0;
    int cnt = 0;
    char* buf4 = new char[4];
    
    int read(char *buf, int n) {
        int ptr = 0;
        while(ptr < n)
        {
            if(ptr4 == 0)
            {
                cnt = read4(buf4);
            }
            if(cnt == 0) break;
            while(ptr < n && ptr4 < cnt)
            {
                buf[ptr++] = buf4[ptr4++];
            }
            if(ptr4 >= cnt)
            {
                ptr4 = 0;
            }
        }
        return ptr;
    }
};
