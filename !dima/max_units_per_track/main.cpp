

#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <map>
#include <string>
#include <cmath>

// question 1
int MaxUnitsPerTrack(std::vector<int> boxes,
                     std::vector<int> unitsPerBox,
                     int size)
{
    std::priority_queue<std::pair<int, int>> pq;
    for (int i = 0; i < boxes.size(); i++)
        pq.push({unitsPerBox[i], boxes[i]});

    int maxUnits = 0;
    int leftSpace = size;
    while (leftSpace > 0 && pq.size() > 0)
    {
        // process current box type
        int boxesNumber = pq.top().second;
        int qty = pq.top().first;
        pq.pop();
        if (boxesNumber <= leftSpace)
        {
            maxUnits += boxesNumber * qty;
            leftSpace -= boxesNumber;
        }
        else
        {
            maxUnits += leftSpace * qty;
            leftSpace = 0;
        }
    }
    return maxUnits;
}

// question 3
int PriceAfterDiscount(std::vector<std::vector<std::string>> products,
                       std::vector<std::vector<std::string>> discounts)
{
    // fill discounts hash table
    std::map<std::string, std::pair<int, int>> m;
    for (auto discount : discounts)
    {
        std::string tag = discount[0];
        int type = stoi(discount[1]);
        int amount = stoi(discount[2]);
        m[tag].first = type;
        m[tag].second = amount;
    };

    int totalDisc = 0;

    // iterate products
    for (auto product : products)
    {
        int startPrice = stoi(product[0]);
        int min = startPrice;
        for (int i = 1; i < product.size(); i++)
        {
            std::string tag = product[i];
            int discounted;
            if (tag == "EMPTY")
                continue;
            int type = m[tag].first;
            int amount = m[tag].second;
            switch (type)
            {
            case 0:
                discounted = startPrice;
                break;
            case 1:
                discounted = (startPrice * (100 - amount)) / 100;
                break;
            case 2:
                discounted = startPrice > amount ? startPrice - amount : 0;
                break;
            }
            if (min > discounted)
                min = discounted;
        }
        totalDisc += min;
    }
    return totalDisc;
}

// question 4
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

// check all pathes with last element of vector
int NodePathesSum(std::vector<int> v, int k)
{
    int sum = 0;
    int pathes = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        // current path
        sum += v[i];
        pathes += ((sum % k) == 0) ? 1 : 0;
    }
    return pathes;
}

// global value to collect result
int number = 0;

void Rec(TreeNode *node, std::vector<int> v, int k)
{
    if (!node)
        return;
    v.push_back(node->val);
    // process path with current node value
    number += NodePathesSum(v, k);
    Rec(node->left, v, k);
    Rec(node->right, v, k);
}

// idea to process path if it consist current node only
// use recursion
int PathNumber(TreeNode *node, int k)
{
    Rec(node, {}, k);
    return number;
}

int main()
{
    // q1 check
    std::cout << "q1 check\n";
    std::cout << MaxUnitsPerTrack({1, 2, 3}, {3, 2, 1}, 3) << "\n";
    std::cout << MaxUnitsPerTrack({1}, {2}, 1) << "\n";
    std::cout << MaxUnitsPerTrack({1, 1}, {9, 6}, 1) << "\n";
    std::cout << MaxUnitsPerTrack({3, 1, 6}, {2, 7, 4}, 6) << "\n";

    // q3 check
    std::cout << "q3 check\n";
    std::cout << PriceAfterDiscount(
                     {{"10", "do", "d1"}, {"15", "EMPTY", "EMPTY"}, {"20", "d1", "EMPTY"}},
                     {{"d0", "1", "27"}, {"d1", "2", "5"}})
              << "\n";
    std::cout << PriceAfterDiscount(
                     {{"10", "do", "d1"}, {"15", "EMPTY", "EMPTY"}, {"20", "d1", "EMPTY"}, {"30", "d3", "EMPTY"}},
                     {{"d0", "1", "27"}, {"d1", "2", "5"}, {"d3", "2", "10"}})
              << "\n";

    // q4 without checking because I am laisy to make a tree)
    // PathNumber(root, k);
    return 0;
}