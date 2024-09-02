#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iomanip>
#include <sstream>


class BitcoinExchange
{
    private:
        std::map<time_t, float> historyChart;

        std::ifstream&  openCsvFile(std::ifstream& file) const;
        time_t          parseToDate(const std::string& dateStr) const;
        void            parseCsvLine(const std::string& line);
        void            populateMapWithCsvData(void);
        float           getPriceSingleBtc(const std::string& dateStr) const;
        float           calculateTotalPrice(const float price, const float amountBtc) const;
        std::string     extractDateFromInput(const std::string& line) const;
        float           extractValueFromInput(const std::string& line) const;
        std::ifstream&  openInputFile(const std::string filePath, std::ifstream& file) const;
 
        std::map<time_t, float>::const_iterator findClosestDate(time_t date) const;

    protected:

    public:
        BitcoinExchange();
        BitcoinExchange(std::string string);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void    calculateBtcWorthFromFile(const std::string filePath);

        class   DateInvalid: public std::exception
        {
            virtual const char* what() const throw();
        };

        class   ValueInvalid: public std::exception
        {
            virtual const char* what() const throw();
        };

};

#endif