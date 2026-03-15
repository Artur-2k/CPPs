#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe&) {}
PmergeMe& PmergeMe::operator=(const PmergeMe&) { return *this; }
PmergeMe::~PmergeMe() {}



std::vector<unsigned int> PmergeMe::getPendInsertOrder(unsigned int nElements)
{
    std::vector<unsigned int> order;

    if (nElements <= 1)
        return order;

    std::vector<unsigned int> jacseq;
    jacseq.push_back(1);
    jacseq.push_back(3);
    while (jacseq.back() < nElements)
        jacseq.push_back(jacseq[jacseq.size()-1] + 2 * jacseq[jacseq.size()-2]);

    for (unsigned int k = 1u; k < jacseq.size(); k++)
    {
        unsigned int high = (jacseq[k] < nElements) ? jacseq[k] : nElements;
        unsigned int low  = jacseq[k - 1] + 1;
        if (low > nElements) break;
        for (unsigned int i = high; i >= low; --i)
            order.push_back(i);
    }
    return order;
}


void PmergeMe::binaryInsert(std::vector<int>& v, int elem,
                             unsigned int startIdx, unsigned int endIdx)
{
    while (startIdx < endIdx)
    {
        unsigned int mid = startIdx + (endIdx - startIdx) / 2;
        if (v[mid] < elem)
            startIdx = mid + 1;
        else
            endIdx = mid;
    }
    v.insert(v.begin() + startIdx, elem);
}

void PmergeMe::_sort(std::vector<int>& v)
{
    if (v.size() <= 1)
        return;

    int straggler = 0;
    unsigned int nPairs = v.size() / 2;
    bool hasStraggler = v.size() % 2 != 0;

    if (hasStraggler)
    {
        straggler = v.back();
        v.pop_back();
    }

    std::vector<std::pair<int,int> > pairs;
    for (unsigned int i = 0u; i < v.size(); i += 2)
        pairs.push_back(std::make_pair(v[i], v[i + 1]));

    for (std::vector<std::pair<int,int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        if (it->first < it->second) std::swap(it->first, it->second);

    std::vector<int> winners;
    for (std::vector<std::pair<int,int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
        winners.push_back(it->first);

    _sort(winners);

    std::vector<bool> used(nPairs, false);
    std::vector<std::pair<int,int> > sortedPairs;
    for (unsigned int i = 0u; i < nPairs; i++)
    {
        int w = winners[i];
        for (unsigned int j = 0u; j < nPairs; j++)
        {
            if (!used[j] && pairs[j].first == w)
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    std::vector<int> main;
    main.push_back(sortedPairs[0].second);
    for (std::vector<std::pair<int,int> >::iterator it = sortedPairs.begin(); it != sortedPairs.end(); ++it)
        main.push_back(it->first);

    unsigned int nPend = nPairs + (hasStraggler ? 1u : 0u);
    std::vector<unsigned int> insertIndexes = getPendInsertOrder(nPend);

    for (unsigned int i = 0u; i < insertIndexes.size(); i++)
    {
        unsigned int idx = insertIndexes[i];
        int elem;
        unsigned int upperBoundIdx;

        if (idx <= nPairs)
        {
            elem = sortedPairs[idx - 1].second;
            int upperBound = sortedPairs[idx - 1].first;
            upperBoundIdx = std::find(main.begin(), main.end(), upperBound) - main.begin();
        }
        else
        {
            elem = straggler;
            upperBoundIdx = main.size();
        }

        binaryInsert(main, elem, 0, upperBoundIdx);
    }

    v = main;
}

void PmergeMe::sort(std::vector<int>& original)
{
    std::vector<int> sorted = original;

    timeval tv_start, tv_end;
    gettimeofday(&tv_start, NULL);
    _sort(sorted);
    gettimeofday(&tv_end, NULL);

    unsigned long elapsed = (tv_end.tv_sec - tv_start.tv_sec) * 1000000
                          + (tv_end.tv_usec - tv_start.tv_usec);

    std::cout << "Before: ";
    for (std::vector<int>::iterator it = original.begin(); it != original.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "After:  ";
    for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << original.size()
              << " elements with std::vector : " << elapsed << " us" << std::endl;
}


void PmergeMe::binaryInsertList(std::list<int>& v, int elem,
                                 unsigned int startIdx, unsigned int endIdx)
{
    while (startIdx < endIdx)
    {
        unsigned int mid = startIdx + (endIdx - startIdx) / 2;
        std::list<int>::iterator it = v.begin();
        std::advance(it, mid);
        if (*it < elem)
            startIdx = mid + 1;
        else
            endIdx = mid;
    }
    std::list<int>::iterator insertPos = v.begin();
    std::advance(insertPos, startIdx);
    v.insert(insertPos, elem);
}

void PmergeMe::_sortList(std::list<int>& v)
{
    if (v.size() <= 1)
        return;

    int straggler = 0;
    unsigned int nPairs = v.size() / 2;
    bool hasStraggler = v.size() % 2 != 0;

    if (hasStraggler)
    {
        straggler = v.back();
        v.pop_back();
    }

    std::list<std::pair<int,int> > pairs;
    std::list<int>::iterator it = v.begin();
    while (it != v.end())
    {
        int a = *it; ++it;
        int b = *it; ++it;
        pairs.push_back(std::make_pair(a, b));
    }

    for (std::list<std::pair<int,int> >::iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
        if (pit->first < pit->second) std::swap(pit->first, pit->second);

    std::list<int> winners;
    for (std::list<std::pair<int,int> >::iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
        winners.push_back(pit->first);

    _sortList(winners);

    std::vector<bool> used(nPairs, false);
    std::vector<std::pair<int,int> > pairsVec(pairs.begin(), pairs.end());
    std::list<std::pair<int,int> > sortedPairs;

    for (std::list<int>::iterator wit = winners.begin(); wit != winners.end(); ++wit)
    {
        int w = *wit;
        for (unsigned int j = 0u; j < nPairs; j++)
        {
            if (!used[j] && pairsVec[j].first == w)
            {
                sortedPairs.push_back(pairsVec[j]);
                used[j] = true;
                break;
            }
        }
    }

    std::list<int> main;
    main.push_back(sortedPairs.front().second);
    for (std::list<std::pair<int,int> >::iterator pit = sortedPairs.begin(); pit != sortedPairs.end(); ++pit)
        main.push_back(pit->first);

    std::vector<std::pair<int,int> > sortedPairsVec(sortedPairs.begin(), sortedPairs.end());
    unsigned int nPend = nPairs + (hasStraggler ? 1u : 0u);
    std::vector<unsigned int> insertIndexes = getPendInsertOrder(nPend);

    for (unsigned int i = 0u; i < insertIndexes.size(); i++)
    {
        unsigned int idx = insertIndexes[i];
        int elem;
        unsigned int upperBoundIdx;

        if (idx <= nPairs)
        {
            elem = sortedPairsVec[idx - 1].second;
            int upperBound = sortedPairsVec[idx - 1].first;
            upperBoundIdx = 0;
            for (std::list<int>::iterator lit = main.begin(); lit != main.end(); ++lit, ++upperBoundIdx)
                if (*lit == upperBound) break;
        }
        else
        {
            elem = straggler;
            upperBoundIdx = main.size();
        }

        binaryInsertList(main, elem, 0, upperBoundIdx);
    }

    v = main;
}

void PmergeMe::sort(std::list<int>& original)
{
    std::list<int> sorted = original;

    timeval tv_start, tv_end;
    gettimeofday(&tv_start, NULL);
    _sortList(sorted);
    gettimeofday(&tv_end, NULL);

    unsigned long elapsed = (tv_end.tv_sec - tv_start.tv_sec) * 1000000
                          + (tv_end.tv_usec - tv_start.tv_usec);

    std::cout << "Before: ";
    for (std::list<int>::iterator it = original.begin(); it != original.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "After:  ";
    for (std::list<int>::iterator it = sorted.begin(); it != sorted.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << original.size()
              << " elements with std::list   : " << elapsed << " us" << std::endl;
}
