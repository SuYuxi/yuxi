# Program Explanation by SuYuxi
- Phone: [070-1053-7585](tel://070-1053-7585)
- Email: &lt;soration2099@gmail.com&gt;
- Github: [SuYuxi](http://github.com/SuYuxi/yuxi)

## Universality and Expansibility
- As all these three tasks are actually identical in the logical structure that retrieving the longest consecutive subarray, but different in judgement condition (in ascending or equal order). In order to get better universality and expansibility, I tried to solve all these three tasks within one program by using dynamical function binding to define the judgement function.
- In my code, I used the two Pointer Algorithm to get the longest subarray which time complexity is O(n) without redundant computation. Meanwhile I enabled the program to get not only the longest ascending and equal subarray but also the descending subarray by choosing different process mode. In addtion, input validation function is added so that any illegal input will get a error prompt message and terminate the program. 

## About Code
- I wrote three programs in Java, Python3 and C++.
- They are identical in function but somewhat different in coding realization due to different language features. 

## Usage
- Input following commands in shell in the corresponding directory to compile and run the code and then input the mode and data following the prompt message 

#### Java
- javac getLongestSubString.java  
- java getLongestSubString 

#### C++
- clang++ -std=c++11 -c getLongestSubString.cpp
- clang++ -std=c++11 getLongestSubString.o -o main
- ./main

#### Python3
- python3 getLongestSubString.py

### Hope you enjoy my work, thank you.
