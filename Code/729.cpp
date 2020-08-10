class MyCalendar {
	set<pair<int, int>> sp;
public:

	//加入边界条件，之后可以不用判断边界
	MyCalendar() {
		sp.insert({ INT_MAX,INT_MAX });
		sp.insert({ INT_MIN,INT_MIN });
	}

	bool book(int start, int end) {
		auto next = sp.lower_bound({ start,end });
		if (next->first < end) return false;
		if ((--next)->second > start) return false;


		sp.insert({ start,end });
		return true;
	}
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
