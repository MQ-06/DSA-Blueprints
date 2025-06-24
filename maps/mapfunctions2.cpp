#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <utility>
using namespace std;

int main()
{

    // insert

    map<string, int> student_scores;

    student_scores["mariam"] = 87;
    student_scores["rahat"] = 90;
    student_scores["umer"] = -1;
    student_scores["ramsha"] = 100;
    // inserts by key/value pair
    student_scores.insert({"mother", 1000});
    vector<pair<string, int>> v = {{"M", 1}, {"W", 3}, {"D", 9}};
    // This function inserts elements from a range defined by two iterators.
    student_scores.insert(v.begin(), v.end());
    // DELETION

    auto it = student_scores.begin();
    student_scores.erase(it);  // removes element with this iterator
    student_scores.erase("M"); // removes all elements with this key(in multimap useful bcz of same keys for many values)

    auto first = student_scores.begin();    // first element
    auto last = prev(student_scores.end()); // last element

    student_scores.erase(first, last); // all elements remove in this range

    // SEARCH

    auto value = student_scores.find("mariam"); // returns iterator to this value if find otherwise returns end

    int count = student_scores.count("A");          // return no of elements with this key
    auto it3 = student_scores.lower_bound("rahat"); // returns first element that is >= to this key
    auto it4 = student_scores.upper_bound("rahat"); // returns first element that is > than this key

    auto range = student_scores.equal_range("umer"); // Get the range of elements with key "Alice"

    for (auto it = range.first; it != range.second; it++)
    {
        std::cout << it->second << std::endl;
    }
}