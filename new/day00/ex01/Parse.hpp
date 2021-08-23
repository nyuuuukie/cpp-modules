#pragma once

#include <string>

class Parse
{

    private:


    public:
        static int stoi(std::string input, int &res);
        static std::string itos(int number, int base);
};
