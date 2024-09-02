#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <cctype>
#include <iostream>
#include <exception>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class   RPN
{
     private:
        std::stack<double>  m_valueStack;
        void    doCalculationOperator(const std::string token, double operand1, double operand2);

    public:
        RPN();
        RPN(const RPN& other);
        RPN&    operator = (const RPN& other);
        ~RPN();
       
        double  caculateResultRPN(const std::string inputStr);
       
        class   ErrorException : public std::exception 
        {
            virtual const char* what() const throw();
        };

};

#endif