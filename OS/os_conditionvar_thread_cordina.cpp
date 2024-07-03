#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
bool ready = false;

void worker_thread() {
    // Wait until main() sends data
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, []{ return ready; });

    // After the wait, we own the lock.
    cout << "Worker thread is processing data\n";

    // Send data back to main()
    ready = false;
}

int main() {
    thread worker(worker_thread);

    // Send data to the worker thread
    {
        lock_guard<mutex> lock(mtx);
        ready = true;
        cout << "Main thread signals data ready for processing\n";
    }
    cv.notify_one();

    // Wait for the worker
    worker.join();

    return 0;
}


// Explanation:
// Mutex (mtx): This is used to protect the shared state (ready).

// Condition Variable (cv): This is used to notify the worker thread that the condition (ready) has been met.

// Shared State (ready): This boolean flag indicates whether the data is ready for processing.

// Steps:
// Worker Thread:

// The worker thread acquires the mutex and then waits on the condition variable (cv.wait(lock, []{ return ready; })). The lambda function []{ return ready; } is a predicate that checks if the condition is met. If ready is false, the thread will block and release the mutex until it is notified.

// Once the condition is met (i.e., ready becomes true), the worker thread proceeds to process the data.

// Main Thread:

// The main thread acquires the mutex and sets ready to true, signaling that the data is ready for processing.

// It then notifies the worker thread using cv.notify_one().

// Notification and Wake-up:

// The condition variable's notify_one() method wakes up one of the threads that are waiting on the condition variable.

// The worker thread wakes up, checks the condition (ready is true), and proceeds to process the data.

// Key Points:
// Predicate in wait: The predicate ensures that the thread does not wake up spuriously (i.e., without a real notification).

// Mutex Protection: The mutex ensures that the shared state (ready) is accessed and modified in a thread-safe manner.

// Condition Variable: The condition variable allows threads to wait efficiently without busy-waiting, saving CPU cycles.

// Condition variables are a powerful tool for coordinating threads and ensuring that threads only proceed when certain conditions are met, making them essential in concurrent programming.