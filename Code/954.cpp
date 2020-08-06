class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        sort(A.begin(), A.end());
        queue<int> queue_positive, queue_negitive;
        for(auto num:A){
            if(num<0){
                if(!queue_negitive.empty() && num*2==queue_negitive.front()) queue_negitive.pop();
                else queue_negitive.push(num);
            }else{
                if(!queue_positive.empty() && num%2==0 && num/2==queue_positive.front()) queue_positive.pop();
                else queue_positive.push(num);
            }
        }
        if(queue_negitive.empty() && queue_positive.empty()) return true;
        else return false;

    }
};