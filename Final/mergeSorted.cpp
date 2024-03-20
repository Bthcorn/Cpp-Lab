#include <iostream>
#include <list>
#include <algorithm>

// template <typename T>
// std::list<T> mergeSorted(const std::list<T>& list1, const std::list<T>& list2)
// {
//     std::list<T> result;
//     std::merge(list1.begin(), list1.end(), list2.begin(), list2.end(), std::back_inserter(result));
//     return result;
// }

//recursion 
template <typename T>
std::list<T> mergeSorted(const std::list<T>& list1, const std::list<T>& list2)
{
    std::list<T> result;

    if (list1.empty())
    {
        return list2;
    }
    if (list2.empty())
    {
        return list1;
    }
    if (list1.front() < list2.front())
    {
        result.push_back(list1.front());
        std::list<T> temp = mergeSorted(std::list<T>(++list1.begin(), list1.end()), std::list<T>(list2.begin(), list2.end()));
        result.splice(result.end(), temp);
    }
    else
    {
        result.push_back(list2.front());
        std::list<T> temp = mergeSorted(std::list<T>(list1.begin(), list1.end()), std::list<T>(++list2.begin(), list2.end()));
        result.splice(result.end(), temp);
    }

    return result;
}


int main() {
    std::list<int> list1 = {1, 3, 5, 7, 9};
    std::list<int> list2 = {2, 4, 6, 8, 10};
    std::list<int> result = mergeSorted(list1, list2);
    for (const auto &i : result)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}