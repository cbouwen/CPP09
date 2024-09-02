#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Need to pass 1 argument" << std::endl;
        return (EXIT_SUCCESS);
    }

    BitcoinExchange bitcoinExchange;

    bitcoinExchange.calculateBtcWorthFromFile(av[1]);
}