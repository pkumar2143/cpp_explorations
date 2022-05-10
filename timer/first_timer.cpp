#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main(){
    double total_time;

    cout << "Start [Enter]: ";
    cin.get();
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    
    cout << "Stop  [Enter]: ";
    cin.get();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    cout << endl;

    duration<double> time_span = duration_cast<duration<double>>(t2-t1);

    cout << "Time elapsed = " << time_span.count() << " seconds. \n";
    return 0;
}