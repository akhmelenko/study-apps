#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <string.h>

int Distance(std::string str1, std::string str2) {
    int i = 0;
    int cnt = 0;
    while (i < str1.size() && i < str2.size()) {
        if (str1[i] != str2[i])
            cnt++;
        i++;
    }
    return cnt;
}

int MinDistance(std::vector<std::string> &v, const std::string &first, const std::string &second) {
    if (first == second)
        return 0;
    if (std::find(v.begin(), v.end(), first) == v.end() || std::find(v.begin(), v.end(), second) == v.end())
        return -1;

    int cnt = 0;
    std::queue<std::string> q;
    q.push(first);
    v.erase(std::find(v.begin(), v.end(), first));
    int currLevCnt = 0;
    int prevLevCnt = 1;
    while (q.size()) {
        // check the collection
        int i = 0;
        while (i < v.size()) {
            if (q.front() == second)
                return cnt;
            if (Distance(v[i], q.front()) == 1) {
                q.push(v[i]);
                v.erase(v.begin() + i);
                currLevCnt++;
            } else
                i++;
        }
        q.pop();
        prevLevCnt--;
        // check for the next level
        if (prevLevCnt == 0) {
            cnt++;
            prevLevCnt = currLevCnt;
            currLevCnt = 0;
        }
    }
    return -1;
}

int main() {
    std::vector<std::string> v{
        "aaaa",
        "cccc",
        "bbbb",
        "caaa",
        "baaa",
        "daaa",
        "eaaa",
        "dbaa",
        "dbba",
        "bbba"};
    std::cout << " min_distance=" << MinDistance(v, "aaaa", "bbbb") << std::endl;

    return 0;
}
