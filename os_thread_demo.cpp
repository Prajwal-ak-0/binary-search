#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

class Thread_Demonstration {
public:
    void runThreadExample() {
        cout << "Starting thread example...\n";
        vector<thread> threads;
        for (int i = 0; i < 5; ++i) {
            threads.emplace_back(&Thread_Demonstration::threadFunction, this, i);
        }
        for (auto& th : threads) {
            th.join();
        }
        cout << "Thread example completed.\n";
    }

    void runFileProcessingExample() {
        cout << "\nStarting file processing example with threads...\n";
        vector<int> files = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<thread> fileThreads;

        auto start = chrono::high_resolution_clock::now();

        for (int fileId : files) {
            fileThreads.emplace_back(&Thread_Demonstration::processFile, this, fileId);
        }

        for (auto& th : fileThreads) {
            th.join();
        }

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Total time taken with threads: " << elapsed.count() << " seconds\n";
    }

    void runFileProcessingWithoutThreads() {
        cout << "\nStarting file processing without threads...\n";
        vector<int> files = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        auto start = chrono::high_resolution_clock::now();

        for (int fileId : files) {
            processFile(fileId);
        }

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Total time taken without threads: " << elapsed.count() << " seconds\n";
    }

private:
    void threadFunction(int id) {
        cout << "Thread " << id << " is running\n";
        this_thread::sleep_for(chrono::seconds(1));
    }

    void processFile(int fileId) {
        cout << "Processing file " << fileId << "\n";
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Finished processing file " << fileId << "\n";
    }
};

int main() {
    Thread_Demonstration demo;
    demo.runThreadExample();
    demo.runFileProcessingExample();
    demo.runFileProcessingWithoutThreads();

    return 0;
}