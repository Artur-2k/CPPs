#include "PmergeMe.hpp"

std::vector<int> parseInput(int argc, char* argv[])
{
    std::vector<int> result;

    for (int i = 1; i < argc; ++i)
    {
        errno = 0;
        char* end;
        long value = strtol(argv[i], &end, 10);

        if (*end != '\0')
            throw std::runtime_error("invalid character");
        if (errno == ERANGE)
            throw std::runtime_error("value out of range");
        if (value > INT_MAX)
            throw std::runtime_error("value exceeds INT_MAX");

        result.push_back(static_cast<int>(value));
    }

    if (result.empty())
        throw std::runtime_error("no input provided");

    return result;
}

int main(int ac, char* av[]) {
    try {
        std::vector<int> input = parseInput(ac, av);
        std::list<int> inputList(input.begin(), input.end());

        PmergeMe::sort(input);
        PmergeMe::sort(inputList);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
