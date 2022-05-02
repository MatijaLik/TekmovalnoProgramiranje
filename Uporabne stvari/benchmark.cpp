#include <chrono>
using namespace std;
auto t1 = chrono::high_resolution_clock::now();
auto t2 = std::chrono::high_resolution_clock::now();

auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

cout << duration;
