#ifndef AhoCorasick_H
#define AhoCorasick_H

#include <vector>
#include <queue>
#include <string>
#include <memory>
#include <iostream>
const int SIGMA = 26;

//Aho–Corasick algorithm
namespace Aho_Corasick {
	using namespace std;
	struct Node {
		vector<shared_ptr<Node>> children;	
		shared_ptr<Node> parent;
		shared_ptr<Node> fail; //match fail node
		string pattern;

		Node(shared_ptr<Node> _parent = nullptr) : parent(_parent), children(SIGMA, nullptr), fail(nullptr) {}; 
	};

	class AhoCorasick {
	public:
		AhoCorasick() : root(nullptr) {};
		void build(vector<string> _patterns)
		{
			patterns = _patterns;
			root = make_shared<Node>();
			for(int inx = 0; inx < patterns.size(); inx++)
			{
				addPattern(patterns[inx]);
			}
			constructFailureLink();
		}

		void query(string str)
		{
			shared_ptr<Node> node = root;
			for(int i = 0; i < str.size(); i++)
			{
				int inx = str[i] - 'a';	
				if(node->children[inx] != nullptr)
				{
					node = node->children[inx];
					if(!node->pattern.empty())
					{
						cout << node->pattern << endl;
						cout << "(" << i - node->pattern.size() + 1 << "," << i << ")" << endl; 
					}
				}
				else
				{
					while(node != root)
					{
						node = node->fail;
						if(!node->pattern.empty())
						{
							cout << node->pattern << endl;
							cout << "(" << i - node->pattern.size() + 1 << "," << i << ")" << endl; 
						}
						if(node->children[inx] != nullptr)
						{
							node = node->children[inx];
							break;
						}
					}
				}
			}
			while(node != root)
			{
				node = node->fail;
				if(!node->pattern.empty())
				{
					cout << node->pattern << endl;
					cout << "(" << str.size() - node->pattern.size() << "," << str.size() - 1 << ")" << endl; 
				}
			}
		};

		void addPattern(string pattern)
		{
			if(pattern.empty()) return;
			shared_ptr<Node> node = root;
			for(char& c : pattern)
			{
				int i = c - 'a';
				if(node->children[i] == nullptr)
				{
					node->children[i] = make_shared<Node>(node);
				}
				node = node->children[i];
			}
			node->pattern = pattern;
		}
		
	private:
		shared_ptr<Node> root;
		vector<string> patterns;

		void constructFailureLink()
		{
			queue<shared_ptr<Node>> q;
			for(shared_ptr<Node>& child : root->children)
			{
				if(child != nullptr)
				{
					child->fail = root;
					q.emplace(child);
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
						while(cur != nullptr)
						{
							if(cur->children[i] != nullptr)
							{
								node->children[i]->fail = cur->children[i];
								break;	
							}
							cur = cur->fail;
						}
						if(cur == nullptr) node->children[i]->fail = root;
					}
				}
			}
		}
	};
}
#endif




