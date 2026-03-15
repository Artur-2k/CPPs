// btc input.txt
// yyyy-mm-dd | value
// 2009-01-02,0
// 2045 -> will use the lower bound date
// value must be between 0 and 1000 inclusive

#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
    try
    {
        if (argc != 2) throw std::runtime_error("Error: invalid number of program arguments");
        BitcoinExchange bex;
        (void)argc;
        std::cout << "\n-----------------EXCHANGE START-----------------" << std::endl;
        bex.exchange(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\n-----------------END OF PROGRAM-----------------" << std::endl;

    return 0;
}