#include "printlog.h"
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <chrono>

// Ouputs timestamp in the form like "2016-01-26 09:14:38.456".
std::string OutputNowTimestamp()
{
    namespace chrono = std::chrono;

	std::ostringstream stream;
    // Because c-style date&time utilities don't support microsecond precison,
    // we have to handle it on our own.
    auto time_now = chrono::system_clock::now();
    auto duration_in_ms = chrono::duration_cast<chrono::milliseconds>(time_now.time_since_epoch());
    auto ms_part = duration_in_ms - chrono::duration_cast<chrono::seconds>(duration_in_ms);

    tm local_time_now;
    time_t raw_time = chrono::system_clock::to_time_t(time_now);
    _localtime64_s(&local_time_now, &raw_time);
    stream << std::put_time(&local_time_now, "%Y-%m-%d %H:%M:%S.")
           << std::setfill('0') << std::setw(3) << ms_part.count();
	return stream.str();
}

void printlog(const std::string& str)
{
    std::time_t t2 = std::time(nullptr);
    std::cout << OutputNowTimestamp()
		<< "  " << str << std::endl;
}