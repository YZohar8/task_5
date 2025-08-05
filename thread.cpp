#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex> // Required for mutex

using namespace std;

// Create a global mutex
mutex mtx;
int counter = 0;

void foo(int a) {
    sleep(1); // Sleep to simulate work

    // Lock the mutex before printing
    mtx.lock();
    counter++;
    cout << counter << endl;
    mtx.unlock();
}

int main() {
    thread threads[20];

    // Start 20 threads
    for (int i = 0; i < 20; i++) {
        threads[i] = thread(foo, i);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 20; i++) {
        threads[i].join();
    }

    return 0;
}
