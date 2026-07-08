#include <iostream>
#include <thread>
#include <fstream>
#include <mutex>
using namespace std;

mutex mtx;

void readFile(const string& filename, double& outSum, double& outAvg, int& outCount){
    ifstream fin(filename);

    double num;
    double sum = 0;
    int count = 0;

    while(fin >> num){
        sum += num;
        count++;
    }

    double avg = sum / count;

    outSum = sum;
    outAvg = avg;
    outCount = count;

    lock_guard<mutex> lock(mtx);
    cout << "Sum = " << sum<< "Avg = " << avg << "Count = " << count << endl;
}

int main(){
    double sums[4], avgs[4];
    int counts[4];

    thread t1(readFile, "file1.txt", ref(sums[0]), ref(avgs[0]), ref(counts[0]));
    thread t2(readFile, "file2.txt", ref(sums[1]), ref(avgs[1]), ref(counts[1]));
    thread t3(readFile, "file3.txt", ref(sums[2]), ref(avgs[2]), ref(counts[2]));
    thread t4(readFile, "file4.txt", ref(sums[3]), ref(avgs[3]), ref(counts[3]));

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    double totalSum = 0;
    int totalCount = 0;
    for(int i = 0; i < 4; i++){
        totalSum += sums[i];
        totalCount += counts[i];
    }
    double totalAvg = totalSum / totalCount ;

    cout << "Total Sum = " << totalSum << endl;
    cout << "Total Avg = " << totalAvg << endl;


    return 0;
}
