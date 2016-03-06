class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 0) return 0;
        int tank = 0, size = gas.size(), start = 0;
        int total = 0, used = 0;
        for (int i = 0; i < size; i++) {
            if (tank < 0) {
                tank = 0;
                start = i;
            }
            total += gas[i];
            used += cost[i];
            tank += (gas[i] - cost[i]);
        }
        return total >= used ? start : -1;
    }
};
