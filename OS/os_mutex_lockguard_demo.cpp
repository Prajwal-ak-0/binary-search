// #include <iostream>
// #include <thread>
// #include <mutex>

// using namespace std;

// mutex mtx; // Mutex to protect shared data
// int counter = 0; // Shared counter

// void incrementCounter(int id) {
//     for (int i = 0; i < 100000; ++i) {
//         mtx.lock(); // Lock the mutex before accessing the shared counter
//         ++counter; // Increment the shared counter
//         if (counter == 500000) {
//             throw runtime_error("Exception: Counter reached 500000");
//         }
//         mtx.unlock(); // Unlock the mutex after modifying the shared counter
//     }
//     cout << "Thread " << id << " finished. Counter = " << counter << "\n";
// }

// int main() {
//     const int numThreads = 5;
//     thread threads[numThreads];

//     // Create and start multiple threads
//     for (int i = 0; i < numThreads; ++i) {
//         threads[i] = thread(incrementCounter, i);
//     }

//     // Wait for all threads to finish
//     for (int i = 0; i < numThreads; ++i) {
//         threads[i].join();
//     }

//     cout << "Final counter value: " << counter << "\n";
//     return 0;
// }

// In this example, if the counter reaches 500000, an exception is thrown. The problem with this approach is that if an exception is thrown, the mtx.unlock() statement will never be executed, causing the mutex to remain locked indefinitely (deadlock). This can lead to undefined behavior and make the program unresponsive.



#include <iostream>
#include <thread>
#include <mutex>
#include <stdexcept>

using namespace std;

mutex mtx; // Mutex to protect shared data
int counter = 0; // Shared counter

void incrementCounter(int id) {
    for (int i = 0; i < 100000; ++i) {
        lock_guard<mutex> lock(mtx); // Lock the mutex using lock_guard
        ++counter; // Increment the shared counter
        if (counter == 500000) {
            throw runtime_error("Exception: Counter reached 500000");
        }
        // The mutex will be automatically unlocked when lock goes out of scope
    }
    cout << "Thread " << id << " finished. Counter = " << counter << "\n";
}

int main() {
    const int numThreads = 5;
    thread threads[numThreads];

    // Create and start multiple threads
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = thread(incrementCounter, i);
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    cout << "Final counter value: " << counter << "\n";
    return 0;
}

// In this example, the lock_guard object is used to manage the mutex. When an exception is thrown, the lock_guard object's destructor is called automatically, which in turn unlocks the mutex. This ensures that the mutex is always unlocked, even in the presence of exceptions.