#define MAX_N 100

// Memoization array to store Fibonacci numbers
long long memo[MAX_N];

// Function to calculate Fibonacci number with memoization
long long fibonacci(int n) {
    // Base case
    if (n <= 1) {
        return n;
    }

    // Check if Fibonacci number for 'n' is already calculated
    if (memo[n] != -1) {
        return memo[n];
    }

    // Calculate Fibonacci number for 'n' and store it in memo array
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);

    return memo[n];
}

int main() {
    // Initialize memo array with -1
    for (int i = 0; i < MAX_N; i++) {
        memo[i] = -1;
    }
    // Example: Calculate and print Fibonacci numbers for the first 10 indices
    printf("Fibonacci %lld", fibonacci(80));

    return 0;
}