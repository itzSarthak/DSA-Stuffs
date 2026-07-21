#include <iostream>
#include <sstream>
#include <chrono>

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::ostringstream oss;
    for (int i = 1; i <= 1000000; ++i)
        oss << i << " ";
        
    std::cout << oss.str() << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "C++ Time elapsed: " << elapsed.count() << " ms" << std::endl;
    return 0;
}
