#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <sys/time.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <cerrno>
#include <cstdlib>
#include <climits>
#include <stdexcept>

class PmergeMe
{
private:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    static std::vector<unsigned int> getPendInsertOrder(unsigned int nElements);

    static void _sort(std::vector<int>& v);
    static void binaryInsert(std::vector<int>& v, int elem,
                             unsigned int startIdx, unsigned int endIdx);

    static void _sortList(std::list<int>& v);
    static void binaryInsertList(std::list<int>& v, int elem,
                                 unsigned int startIdx, unsigned int endIdx);

public:
    static void sort(std::vector<int>& original);
    static void sort(std::list<int>& original);
};

#endif
