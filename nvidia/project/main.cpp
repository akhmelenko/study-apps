//
//   NVIDIA Development Tools Team
//       C++ Programming Test
//
// ---------------------------------
//
// This test should be self-explanatory.  All places where you are expected to
// write code are marked with TODO:  Each question is assigned a score.  Please
// see the SCORING comment below.  You are welcome to implement the questions
// in any order.
//
// This project should compile and run as-is, but all the tests will fail.
// Please implement all the TODOs as described below to get all the tests to
// succeed.
//
// You may use whatever other #includes you need.  You may use the C++ STL
// unless otherwise specified.  If you need help with STL (e.g. using fstream
// to read/write files), use the Josuttis book or read through the exercises
// and their tests, which have some file I/O already implemented.
//
// You're welcome to use stdio.h and C-style programming instead, but you'll
// have to convince us either way that your memory management is safe, even
// when ridiculous input values are passed to your functions.
//
// SCORING
// TestHierarchy                   Total = 45 points
//   a. Parser & data structure            15 points
//   b. Test function                      10 points
//   c. PrintHierarchyDepthFirst            5 points
//   d. PrintHierarchyDepthFirstSorted      5 points
//   e. PrintHierarchyBreadthFirst         10 points

#include <algorithm>
#include <array>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

// Append data filenames to this string to read/write files in the data folder.
const std::string data_location("../Data/");

#define CHECK(cond, errstream, oss)      \
    if (!(cond)) {                       \
        (oss) << errstream << std::endl; \
        return;                          \
    }

// -----------------------------------------------------------------------------
// Problem:
// Create a simple data structure to represent a hierarchy.  Write a parser to
// read files in the following format and store them in your hierarchy structure.
// Then write functions that print a hierarchy in depth-first and breadth-first
// order.  (Ask, or check out the tests, if you're not clear what that means)
//
// Example input file format (note that leading periods specify depth):
//
// grandpa & grandma
// .mom
// ..me
// ...my son
// ...my daughter
// ..my brother
// ..my sister
// ...my nephew
// .aunt gertrude
// ..my annoying cousin
//
// Make sure that you detect nonsensical structures in the input file.  For
// example, the first line should not contain any leading periods, and a line
// with one leading period cannot be followed by a line with more than two
// leading periods.
//
// Because the printing functions are external to your class, you'll need to
// choose what type of interface to expose for those functions to be simple.
// The logic for the printing functions should NOT be contained within the class.

// -----------------------------------------------------------------------------
struct REALATIVE;

std::string ClearName(const std::string &name) {
    std::string clearName = "";
    for (auto character : name) {
        if (std::isalpha(character))
            clearName += character;
    }
    return clearName;
}

typedef struct REALATIVE {
    std::string name;
    int level;
    std::string closestAncestor;
    bool operator<(const REALATIVE &rhs) const {
        // clear name
        std::string clearName = ClearName(name);
        std::string rhsClearName = ClearName(rhs.name);
        return clearName < rhsClearName;
    }
    bool operator==(const REALATIVE &rhs) const {
        return name == rhs.name;
    }

} REALATIVE_t;

int GetLevel(const std::string &str) {
    int level = 0;
    for (const auto &character : str) {
        if (character == '.')
            level++;
    }
    return level;
}

std::string ClosestAncestor(std::vector<REALATIVE_t> relatives, int level) {
    // check from end to begin
    std::reverse(relatives.begin(), relatives.end());
    for (const auto &r : relatives) {
        if (r.level == level - 1)
            return r.name;
    }
    return "";
}

class Hierarchy {
    // TODO DONE: Implement this class
    std::vector<REALATIVE_t> relatives;

   public:
    // Return false if any I/O errors occur, otherwise return true.
    bool LoadFromFile(const std::string &infile) {
        // NOTE: Feel free to replace the entire implementation of
        // this function.
        std::ifstream ifs(infile.c_str());
        if (!ifs) {
            return false;
        }

        std::string line;
        while (std::getline(ifs, line)) {
            // TODO DONE: Parse input line by line.  Handle bad input data elegantly,
            // or at least describe how in comments.

            // getting level by counting "."
            int level = GetLevel(line);
            // getting ancestor
            std::string ancestor = ClosestAncestor(relatives, level);
            // add to collection
            relatives.push_back(REALATIVE_t{
                line,
                level,
                ancestor});
        }

        // TEST
        // for (auto r : relatives)
        //     std::cout
        //         << "name=" << r.name << " level=" << r.level << " anc=" << r.closestAncestor << std::endl;

        return true;
    }
    std::vector<REALATIVE_t> GetRelatives() const {
        return relatives;
    }
};

// TODO: Implement the following functions.  Print each node on a separate line,
// with leading periods to represent depth.  The depth-first output should be
// identical to the input file, such that Hierarchy::LoadFromFile() can load it.
// The sorted depth-first output should sort the children of each node before
// recursing into their children.  The breadth-first output should print all
// nodes at a given depth before printing any deeper nodes.  See the files
// HierarchyTest_expected_*.txt in the data directory for the expected results.
// Feel free to use helper functions, but don't change the signatures of these
// functions.

void PrintHierarchyDepthFirst(const Hierarchy &h, std::ostream &output) {
    std::vector<REALATIVE_t> relatives = h.GetRelatives();
    for (const auto relative : relatives)
        output << relative.name << '\n';
}

void PrintHierarchyDepthFirstSorted(const Hierarchy &h, std::ostream &output) {
    std::vector<REALATIVE_t> relatives = h.GetRelatives();

    int level = 0;
    // get max level
    int maxLevel = 0;
    for (const auto relative : relatives) {
        if (relative.level > maxLevel) {
            maxLevel = relative.level;
        }
    }
    // copy to set (ordering)
    std::set<REALATIVE_t> relativesSorted;
    while (level <= maxLevel) {
        for (const auto relative : relatives) {
            if (relative.level == level) {
                relativesSorted.insert(relative);
            }
        }
        level++;
    }
    // copy to vector
    std::vector<REALATIVE_t> vecSorted;
    for (const auto &elem : relativesSorted)
        vecSorted.insert(vecSorted.begin(), elem);
    // print by levels
    level = 0;
    std::vector<std::string> relativesSortedNames;
    while (level <= maxLevel) {
        for (const auto relative : vecSorted) {
            if (relative.level == level) {
                // find parent location in new collection
                auto it = std::find(
                    begin(relativesSortedNames),
                    end(relativesSortedNames),
                    relative.closestAncestor);
                if (it != std::end(relativesSortedNames)) {
                    // if (relative.closestAncestor == elem.name)
                    relativesSortedNames.insert(it + 1, relative.name);
                } else {
                    relativesSortedNames.push_back(relative.name);
                }
            }
        }
        level++;
    }

    // // print new collection
    for (const auto &name : relativesSortedNames)
        output << name << '\n';
}

void PrintHierarchyBreadthFirst(const Hierarchy &h, std::ostream &output) {
    std::vector<REALATIVE_t> relatives = h.GetRelatives();
    int level = 0;
    // get max level
    int maxLevel = 0;
    for (const auto relative : relatives) {
        if (relative.level > maxLevel) {
            maxLevel = relative.level;
        }
    }
    // print by levels
    while (level <= maxLevel) {
        for (const auto relative : relatives) {
            if (relative.level == level) {
                output << relative.name << '\n';
            }
        }
        level++;
    }
}

bool CheckIdentical(
    std::string filePath0,
    std::string filePath1) {
    //
    bool ret = false;
    std::ifstream ifs0(filePath0);
    std::ifstream ifs1(filePath1);

    if (!ifs0 || !ifs1) {
        std::cerr << "error open file" << std::endl;
    } else {
        std::string line0 = " ";
        std::string line1 = " ";
        while (!line0.empty() && !line1.empty()) {
            std::getline(ifs0, line0);
            std::getline(ifs1, line1);
            if (line0.compare(line1) != 0) {
                ret = false;
            }
        }
        // check is line numbers are equal
        if (line0.empty() && line1.empty()) {
            ret = true;
        }
    }
    ifs0.close();
    ifs1.close();
    return ret;
}

// declare print func ptr type
// typedef void (*pPrintFunc_t)(const Hierarchy &h, std::ostream &output);
typedef void (*pPrintFunc_t)(const Hierarchy &, std::ostream &);

void CommonTest(
    std::string testFileName,
    std::string outFileName,
    std::ostream &error_output,
    Hierarchy h,
    const std::string failure_msg,
    pPrintFunc_t pPrintFunc) {
    //
    std::string testFilePath = data_location + testFileName;
    std::string outFilePath = data_location + outFileName;
    std::ofstream ofs(outFilePath.c_str());
    CHECK(ofs, failure_msg << "  I/O error.", error_output);
    // PrintHierarchyDepthFirst(h, ofs);
    pPrintFunc(h, ofs);
    ofs.close();
    // check identical
    if (CheckIdentical(
            testFilePath,
            outFilePath)) {
        std::cout << "Files are equal" << std::endl;
        return;
    }
    std::cout << "Files are not equal" << std::endl;
}

#define NEW 1

std::map<std::string, pPrintFunc_t> tests{
    {"HierarchyTest_output_DFS.txt", PrintHierarchyDepthFirst},
    {"HierarchyTest_output_DFS_sorted.txt", PrintHierarchyDepthFirstSorted},
    {"HierarchyTest_output_BFS.txt", PrintHierarchyBreadthFirst}};

// TODO DONE: Improve this test method.
// How could you verify your outputs are correct?
// How could you refactor this function to be less repetitive?
void TestHierarchy(std::ostream &error_output) {
    const std::string failure_msg("Hierarchy tests failed!");

    bool success = false;

    Hierarchy h;
    std::string infile(data_location + "HierarchyTest.txt");
    success = h.LoadFromFile(infile);
    CHECK(success, failure_msg << "  I/O error.", error_output);

    std::string outfile;
    std::string testfile;
    bool identical(false);

#if NEW

    std::vector<std::map<std::string, pPrintFunc_t>>::iterator it;
    // for (it = tests.begin(); it != tests.end(); it++)
    for (auto const &t : tests) {
        CommonTest(
            "HierarchyTest.txt",
            t.first,  //"HierarchyTest_output_DFS.txt",
            error_output,
            h,
            failure_msg,
            t.second);  //PrintHierarchyDepthFirst);
    }
#else
    outfile = data_location + "HierarchyTest_output_DFS.txt";
    {
        std::ofstream ofs(outfile.c_str());
        CHECK(ofs, failure_msg << "  I/O error.", error_output);

        PrintHierarchyDepthFirst(h, ofs);
    }
    if (CheckIdentical(
            "HierarchyTest.txt",
            "HierarchyTest_output_DFS.txt")) {
        std::cout << "Files are equal" << std::endl;
    } else {
        std::cout << "Files are not equal" << std::endl;
    }

    outfile = data_location + "HierarchyTest_output_DFS_sorted.txt";
    {
        std::ofstream ofs(outfile.c_str());
        CHECK(ofs, failure_msg << "  I/O error.", error_output);

        PrintHierarchyDepthFirstSorted(h, ofs);
    }
    if (CheckIdentical(
            "HierarchyTest_expected_DFS_sorted.txt",
            "HierarchyTest_output_DFS_sorted.txt")) {
        std::cout << "Files are equal" << std::endl;
    } else {
        std::cout << "Files are not equal" << std::endl;
    }

    outfile = data_location + "HierarchyTest_output_BFS.txt";
    {
        std::ofstream ofs(outfile.c_str());
        CHECK(ofs, failure_msg << "  I/O error.", error_output);

        PrintHierarchyBreadthFirst(h, ofs);
    }
    if (CheckIdentical(
            "HierarchyTest_expected_BFS.txt",
            "HierarchyTest_output_BFS.txt")) {
        std::cout << "Files are equal" << std::endl;
    } else {
        std::cout << "Files are not equal" << std::endl;
    }
#endif
}

// -----------------------------------------------------------------------------

int main() {
    TestHierarchy(std::cout);

#ifdef _MSC_VER
    // Pause...
    std::cout << std::endl
              << std::endl
              << "Press enter to quit..." << std::endl;
    char c;
    std::cin >> std::noskipws >> c;
#endif

    return 0;
}
