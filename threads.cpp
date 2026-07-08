#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

void generate_oddnums(){
    for(int i=0;i<=100;i++){
        if(i%2!=0){
            lock_guard<mutex> lock(mtx);
            cout << i << endl;
        }
    }
}

void genrate_evennumbers(){
    for(int i=0;i<=100;i++){
        if(i%2==0){
            lock_guard<mutex> lock(mtx);
            cout << i << endl;
        }
    }
}

int main(){
    auto start = chrono::high_resolution_clock::now();
    thread t1(generate_oddnums);
    thread t2(genrate_evennumbers);
    t1.join();
    t2.join();
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " ms" << endl;
    return 0;
}