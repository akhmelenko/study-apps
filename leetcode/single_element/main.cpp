#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>

int singleNumber(std::vector<int> &nums) {
    std::map<int, int> m;
    for (auto &n : nums)
        if (m[n])
            m.erase(n);
        else
            m[n] = 1;
    return m.begin()->first;
}

int singleNumber2(std::vector<int> &nums) {
    std::set<int> s;
    auto it = s.begin();
    for (auto &n : nums) {
        it = s.find(n);
        if (it != s.end())
            s.erase(it);
        else
            s.insert(n);
    }
    return *s.begin();
}

int singleNumber3(std::vector<int> &nums) {
    std::list<int> l;
    for (auto &n : nums) {
        auto it = std::find(l.begin(), l.end(), n);
        if (it != l.end())
            l.erase(it);
        else
            l.push_front(n);
    }
    return *l.begin();
}

int singleNumber4(std::vector<int> &nums) {
    int temp = 0;
    for (auto &n : nums) {
        temp ^= n;
    }
    return temp;
}

int main() {
    std::vector<int> v = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    std::cout << " | single is =" << singleNumber(v) << std::endl;
    std::cout << " | single is =" << singleNumber2(v) << std::endl;
    std::cout << " | single is =" << singleNumber3(v) << std::endl;
    std::cout << " | single is =" << singleNumber4(v) << std::endl;

    return 0;
}
