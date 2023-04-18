#include <iostream>
#include <unordered_map>  // for memoization

// memoization map to store already computed Fibonacci numbers
std::unordered_map<int, long long> memo;

long long fibonacci(int n) {
    // base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // check if already computed
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    // compute and memoize the Fibonacci number
    long long fib = fibonacci(n - 1) + fibonacci(n - 2);
    memo[n] = fib;
    return fib;
}

int main() {
    int n = 75;  // the Fibonacci number to compute
    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;
    return 0;
}