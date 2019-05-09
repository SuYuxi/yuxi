class Solution {
public:
    int repeatedStringMatch(string A, string B) {
		string C = A;
		for(int t = 1; t <= B.size() / A.size() + 2; t++)
		{
			if(C.find(B) != std::string::npos) return t;
			C += A;
		}
		return -1;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

//Aho–Corasick algorithm
#include <vector>
#include <queue>
#include <string>
#include <memory>
using namespace std;

const int SIGMA = 26;

struct Node {
	vector<shared_ptr<Node>> children;	
	shared_ptr<Node> parent;
	shared_ptr<Node> fail; //match fail node
	bool isWord;

	Node(shared_ptr<Node> _parent = nullptr) : parent(_parent), children(SIGMA, nullptr), fail(nullptr), isWord(false) {}; 
};

class StreamChecker {
public:
    StreamChecker(string words) {
		buildTrieTree(words);
		buildFailureLink();
		curNode = root; 
    }
    
    bool query(char letter) {
		int inx = letter - 'a';
		while(curNode != nullptr && curNode->children[inx] == nullptr)
		{
			curNode = curNode->fail;
		}
		if(curNode == nullptr)
		{
			curNode = root;
		}
		else
		{
			curNode = curNode->children[inx];
		}
		return curNode->isWord;
	};

private:
	shared_ptr<Node> root, curNode;

	void buildTrieTree(string& words)
	{
		root = make_shared<Node>();
		shared_ptr<Node> node = root;
		for(char& c : words)
		{
			int i = c - 'a';
			if(node->children[i] == nullptr)
			{
				node->children[i] = make_shared<Node>(node);
			}
			node = node->children[i];
		}
		node->isWord = true;
	}

	void buildFailureLink()
	{
		queue<shared_ptr<Node>> q;
		for(shared_ptr<Node>& child : root->children)
		{
			if(child != nullptr)
			{
				q.emplace(child);
				child->fail = root;
			}
		}
		while(!q.empty())
		{
			shared_ptr<Node> node = q.front();
			q.pop();
			for(int i = 0; i < SIGMA; i++)
			{
				if(node->children[i] != nullptr)
				{
					q.emplace(node->children[i]);
					shared_ptr<Node> cur = node->fail;
					while(cur != nullptr && cur->children[i] == nullptr)
					{
						cur = cur->fail;
					}
					if(cur == nullptr)
					{
						node->children[i]->fail = root;
					}
					else
					{
						node->children[i]->fail = cur->children[i];
						node->children[i]->isWord |= cur->children[i]->isWord;
					}
				}
			}
		}
	}
};

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
		int t = 1;
		StreamChecker ac(B);
		while(t <= B.size() / A.size() + 2)
		{
			for(char& a : A)
			{
				if(ac.query(a)) return t;
			}
			t++;
		}
		return -1;
    }
};

//Rabin-Karp (Rolling Hash)
//https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
#include<string>

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
		int q = (B.size() - 1) / A.size() + 1;
		int MOD = 1e9 + 7; //prime
		int p = 113; //prime
		int pinv = pow(p, MOD - 2, MOD); //the mod inverse of p(MOD should be prime), by FERMAT's little therorem
		long aHash = 0, bHash = 0;
		long power = 1;
		for(int i = 0; i < B.size(); i++)
		{
			bHash += B[i] * power;
			bHash %= MOD;
			power = (power * p) % MOD;
		}
		power = 1;
		for(int i = 0; i < B.size(); i++)
		{
			aHash += A[i % A.size()] * power;
			aHash %= MOD;
			power = (power * p) % MOD;
		}

		if(aHash == bHash && check(0, A, B)) return q;
		power = (power * pinv) % MOD;

		for(int i = B.size(); i < (q + 1) * A.size(); i++)
		{
			aHash -= A[(i - B.size()) % A.size()];
			aHash *= pinv;
			aHash += power * A[i % A.size()];
			aHash %= MOD;
			if(aHash == bHash && check(i - B.size() + 1, A, B))
			{
				return i < q * A.size() ? q : q + 1;
			}
		}
		return -1;
    }

	bool check(int inx, string A, string B) {
		int sizeA = A.size(), sizeB = B.size();
		for(int i = 0; i < sizeB; i++)
		{
			if(A[(inx + i) % sizeA] != B[i]) return false;
		}
		return true;
	}

	int pow(int x, int y, int m) 
	{ 
		if (y == 0) 
			return 1; 
		long p = pow(x, y / 2, m) % m; 
		p = (p * p) % m; 
	  
		return (y % 2 == 0)? p : (x * p) % m; 
	} 
};
