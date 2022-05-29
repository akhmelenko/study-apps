
#include <iostream>
#include <set>

class TwoSum {
    std::multiset<int> ms;

   public:
    TwoSum() {}
    void Add(int val) {
        ms.insert(val);
    }
    bool Find(int targetSum) {
        auto itL = ms.begin();
        auto itH = ms.end();
        itH--;
        while (*itL < *itH) {
            int sum = *itL + *itH;
            if (sum == targetSum)
                return true;
            else if (sum < targetSum)
                itL++;
            else
                itH--;
        }
        return false;
    }
};

int main() {
    TwoSum tSum;
    tSum.Add(3);
    tSum.Add(14);
    tSum.Add(-2);
    tSum.Add(11);
    tSum.Add(-1);
    tSum.Add(5);
    std::cout << tSum.Find(8) << std::endl;
    std::cout << tSum.Find(6) << std::endl;
    return 0;
}
