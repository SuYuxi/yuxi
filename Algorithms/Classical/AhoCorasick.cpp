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
    StreamChecker(vector<string> words) {
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

	void buildTrieTree(vector<string>& words)
	{
		root = make_shared<Node>();
		for(int inx = 0; inx < words.size(); inx++)
		{
			shared_ptr<Node> node = root;
			for(char& c : words[inx])
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
