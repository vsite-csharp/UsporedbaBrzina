// CppApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <format>

int Loop(int count, bool output)
{
    auto total = 0;

    for (int row = 1; row < count; ++row)
    {
        for (int column = 1; column < count; ++column)
        {
            total += row + column;
            if (output)
            {
                //printf("%d\n", row + column);
                //std::cout << row + column << '\n';
                std::cout << std::format("{}\n", row + column);
            }
        }
    }
    return total;
}

int main()
{
    std::ios::sync_with_stdio(false);

    for (int i = 0; i < 10; ++i)
    {
        const auto start = std::chrono::high_resolution_clock::now();

        auto total = Loop(11, true);

        const auto end = std::chrono::high_resolution_clock::now();
        const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << i << ". C++ total: " << total << "\n";
        std::cout << i << ". C++ execution: " << duration << " us\n";
    }

    std::cout << std::endl;

    for (int i = 0; i < 10; ++i)
    {
        const auto start = std::chrono::high_resolution_clock::now();

        auto total = Loop(1001, false);

        const auto end = std::chrono::high_resolution_clock::now();
        const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << i << ". C++ total: " << total << "\n";
        std::cout << i << ". C++ execution: " << duration << " us\n";
    }
}

