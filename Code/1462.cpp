class Solution {
public:
	vector<int> closestDivisors(int num) {
		int sq = sqrt(float(num + 2));
		while (sq) {
			if ((num + 1) % sq == 0) return { sq,(num + 1) / sq };
			if ((num + 2) % sq == 0) return { sq,(num + 2) / sq };
			sq--;
		}
		return { 0,0 };
	}
};