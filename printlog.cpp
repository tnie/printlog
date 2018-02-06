#include "printlog.h"
#include <iostream>
#include <ctime>
#include <iomanip>

void printlog(const std::string& str)
{
    std::time_t t2 = std::time(nullptr);
    std::cout << std::put_time(std::localtime(&t2), "%Y-%m-%d %H:%M:%S")
		<< "  " << str << std::endl;
}