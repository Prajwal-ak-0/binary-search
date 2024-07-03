#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter(0);

void increment_counter(int id) {
    for (int i = 0; i < 100; ++i) {
        counter.fetch_add(1, std::memory_order_relaxed);
    }
    std::cout << "Thread " << id << " finished. Counter = " << counter.load(std::memory_order_relaxed) << "\n";
}

int main() {
    const int num_threads = 10;
    std::thread threads[num_threads];

    // Create and start multiple threads
    for (int i = 0; i < num_threads; ++i) {
        threads[i] = std::thread(increment_counter, i);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; ++i) {
        threads[i].join();
    }

    std::cout << "Final counter value: " << counter.load(std::memory_order_relaxed) << "\n";
    return 0;
}




// Explanation:
// Atomic Variable (counter): This is an atomic integer that will be incremented by multiple threads.

// fetch_add Method: This method atomically adds a value to the atomic variable. The std::memory_order_relaxed argument specifies the memory ordering constraints. In this case, relaxed means that there are no ordering constraints beyond the atomic operation itself.

// load Method: This method atomically reads the value of the atomic variable. Again, std::memory_order_relaxed is used for the memory ordering.

// Steps:
// Thread Function (increment_counter):

// Each thread increments the atomic counter 100 times using fetch_add.

// After incrementing, each thread prints the current value of the counter using load.

// Main Function:

// Creates and starts 10 threads, each running the increment_counter function.

// Waits for all threads to finish using join.

// Prints the final value of the counter.

// Key Points:
// Lock-Free: Atomic operations are lock-free, meaning they do not use traditional locks, which can improve performance and avoid issues like deadlocks.

// Memory Ordering: The std::memory_order_relaxed argument specifies relaxed memory ordering, which means there are no synchronization or ordering constraints beyond the atomic operation itself. This can provide performance benefits but may not be suitable for all use cases.

// Thread Safety: Atomic variables ensure that operations on shared data are thread-safe without the need for explicit locks.

// Atomic variables are a powerful tool for concurrent programming, especially when performance and lock-free operations are critical.