class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
		for (int i = nestedList.size() - 1; i >= 0; i--) {
			nodes_.push(nestedList[i]);
		}
    }

    int next() {
		int res = nodes_.top().getInteger();
		nodes_.pop();

		return res;
    }

    bool hasNext() {
		while (!nodes_.empty()) {
			NestedInteger top = nodes_.top();
			if (top.isInteger()) {
				return true;
			}

			nodes_.pop();
			const vector<NestedInteger>& list = top.getList();
			for (int i = list.size() - 1; i >= 0; i--) {
				nodes_.push(list[i]);
			}
		}

		return false;
    }

private:
	stack<NestedInteger> nodes_;
};
