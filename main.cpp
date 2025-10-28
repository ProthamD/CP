#include <iostream>
#include <thread>
#include <semaphore>   // C++20
#include <chrono>
using namespace std;

counting_semaphore<2> parkingLot(2); // max 2 cars allowed

void car(int id) {
    cout << "Car " << id << " is waiting to park...\n";
    parkingLot.acquire(); // wait (P)
    cout << "Car " << id << " has parked.\n";

    this_thread::sleep_for(chrono::seconds(2)); // car stays for 2s

    cout << "Car " << id << " is leaving.\n";
    parkingLot.release(); // signal (V)
}

int main() {
    thread t1(car, 1);
    thread t2(car, 2);
    thread t3(car, 3);
    thread t4(car, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
