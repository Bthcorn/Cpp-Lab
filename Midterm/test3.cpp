#include <iostream>
#include <string>
#include <list>

std::list<int> mergeList(std::list<int>& a, std::list<int>& b)
{
    if (a.empty())
        return b;
    if (b.empty())
        return a;

    std::list<int> mergedList;

    if (a.front() < b.front())
    {
        mergedList.push_back(a.front());
        a.pop_front();
    }
    else if (b.front() < a.front())
    {
        mergedList.push_back(b.front());
        b.pop_front();
    }
    else
    {
        // Elements are equal, add only one of them
        mergedList.push_back(a.front());
        a.pop_front();
        b.pop_front();
    }

    std::list<int> remaining = mergeList(a, b);
    mergedList.splice(mergedList.end(), remaining);

    return mergedList;
}

int main()
{
    std::list<int> list1 = {1, 3, 5, 7, 9};
    std::list<int> list2 = {2, 4, 6, 8, 10};

    std::list<int> mergedList = mergeList(list1, list2);

    // Print the merged list
    for (const auto& elem : mergedList)
    {
        std::cout << elem << " ";
    }

    return 0;
}
