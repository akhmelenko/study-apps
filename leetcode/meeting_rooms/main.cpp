#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

bool CouldAttend(std::vector<std::pair<int, int>> v) {
    if (!v.size())
        return false;
    // sorting by start time
    std::sort(v.begin(), v.end(), [](auto left, auto right) {
        return left.first < right.first;
    });
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i].second > v[i + 1].first)
            return false;
    }
    return true;
}

int main() {
    std::cout << " [1,15] [20,25] [0,30]=" << CouldAttend({{1, 15}, {20, 25}, {0, 30}}) << std::endl;
    std::cout << " [1,15] [20,25] [0,30]=" << CouldAttend({{1, 15}, {20, 25}, {25, 30}}) << std::endl;

    return 0;
}
