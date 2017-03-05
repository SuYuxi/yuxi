char* convert(char* s, int numRows) {
	int len = strlen(s);
	if(numRows <= 1 || len <= numRows) { return s; }
	char* buffer[numRows];
	for(int i = 0; i < numRows; i += 1) {
		char* p = (char*) malloc(len  +1);
		buffer[i] = p;
	}
	int row = 0, step = 0;
	for(int inx = 0; inx < len; inx += 1) {
		char p[] = {*(s+inx),'\0'};
		strcat(buffer[row], p);
		if(row == 0) {
			step = 1;
		}
		else if(row == numRows - 1) {
			step = -1;
		}
		row += step;
	}
	char* result = (char*) malloc(len + 1);
	for(int i = 0;i < numRows;i += 1) {
		strcat(result, buffer[i]);
		free(buffer[i]);
	}	
	return result;
}
