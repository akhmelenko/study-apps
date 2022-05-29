#include <iostream>
#include <string>
#include <vector>

int MinDistance(const std::vector<std::string> &v, const std::string &first, const std::string &second) {
    int firstPosition = -1;
    int secondPosition = -1;
    int minDistance = INT32_MAX;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == first)
            firstPosition = i;
        else if (v[i] == second)
            secondPosition = i;
        else
            continue;
        if (firstPosition == -1 || secondPosition == -1)
            continue;
        int currDistance = abs(firstPosition - secondPosition);
        // std::cout << "word:" << v[i] << " first=" << firstPosition << " second=" << secondPosition << " cur_dict=" << currDistance << "\n";
        if (currDistance < minDistance)
            minDistance = currDistance;
    }
    return minDistance;
}

int main() {
    std::vector<std::string> v{"ww", "mm", "tt", "ll", "ee", "ss", "dd", "ww", "pp"};
    std::cout << " min_distance=" << MinDistance(v, "ww", "ss") << std::endl;

    return 0;
}
