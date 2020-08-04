class Solution {
public:
	int trap(vector<int>& height) {
		int sum = 0;
		stack<int> s;
		for (int i = 0; i < height.size(); i++) {
			while (!s.empty() && height[i] > height[s.top()]) {
				int h = height[s.top()];
				s.pop();
				if (s.empty()) break;
				int m = min(height[s.top()], height[i]);
				int dis = i - s.top() - 1;
				sum += dis * (m - h);
			}
			s.push(i);
		}
		return sum;
	}
};

