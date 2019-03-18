/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class nestediterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
		begins.emplace_back(nestedList.begin());
		ends.emplace_back(nestedList.end());
    }

    int next() {
		hasNext();
		return (begins.back()++)->getInteger();
    }

    bool hasNext() {
		while(!begins.empty())
		{
			if(begins.back() == ends.back())
			{
				begins.pop_back();
				ends.pop_back();
			}
			else
			{
				vector<NestedInteger>::iterator iter = begins.back();	
				if(iter->isInteger())
					return true;
				else
				{
					begins.back()++;
					begins.emplace_back(iter->getList().begin());
					ends.emplace_back(iter->getList().end());
				}
			}
		}
		return false;
    }

private:
	vector<vector<NestedInteger>::iterator> begins, ends;
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
