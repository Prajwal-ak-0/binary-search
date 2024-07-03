#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;
int counter = 0;

void incrementCounter(int id) {
    for (int i = 0; i < 100000; ++i) {
        mtx.lock();
        ++counter;
        mtx.unlock();
    }
    cout << "Thread " << id << " finished. Counter = " << counter << "\n";
}

int main() {
    const int numThreads = 5;
    thread threads[numThreads];

    for (int i = 0; i < numThreads; ++i) {
        threads[i] = thread(incrementCounter, i);
    }

    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    cout << "Final counter value: " << counter << "\n";
    return 0;
}