/*
 *
 * Enviroment: CentOS-7.6.1810
 * Required  : yum install boost-devel
 *
 * Compilation: g++ -std=c++11 map_find_perf.cpp -o map_find_perf
 */
#include <stdio.h>
#include <iostream>
#include <map>
#include <hash_map>
#include <unordered_map>
#include <boost/progress.hpp>   // For progress_timer
 
using namespace std;
using namespace boost;
using namespace __gnu_cxx;      // For hash_map
 
// map的查找
void map_find_test(int size, int times)
{
    int count = 0;
    map<int, int> m;
    progress_timer t; // progress_timer变量会在创建时计时，析构时自动打印出耗时，所以不会受到前面初始化的影响，下同，不再解释

    for (int i = 0; i < size; i++) {
        m[i] = i;
    }

    for (int i = 0; i<times; i++) {
        for (int j = 0; j<size; j++) {
            if (m.find(j) != m.end()) {
                count++;
            }
        }
    }
    cout << "map size " << size << ", find counts " << count << ", map:";
    return;
}

// unordered_map的查找
void unorder_map_find_test(int size, int times)
{
    int count = 0;
    unordered_map<int, int> um;
    progress_timer t;

    for (int i = 0; i < size; i++) {
        um[i] = i;
    }

    for (int i = 0; i < times; i++) {
        for (int j = 0; j < size; j++) {
            if (um.find(j) != um.end()) {
                count++;
            }
        }
    }
    cout << "unordered_map size " << size << ", find counts " << count << ", unordered_map:";
    return;
}

// hash_map的查找
void hash_map_find_test(int size, int times)
{
    int count = 0;
    progress_timer t;
    hash_map<int, int> hm;

    for (int i = 0; i<size; i++) {
        hm[i] = i;
    }

    for (int i = 0; i < times; i++) {
        for (int j = 0; j < size; j++) {
            if (hm.find(j) != hm.end()) {
                count++;
            }
        }
    }
    cout << "hash_map size " << size << ", find counts " << count << ", hash_map:";
    return;
}

/*
 *  size  : map的实际大小
 *  times : 查找的轮次，每一轮次都从0查找到size-1
 */
void test(int size, int times)
{
    map_find_test(size, times);
    unorder_map_find_test(size, times);
    hash_map_find_test(size, times);
    printf("\n\n");
}
 
int main()
{
    //test(10,10000000);   // 容量：10        查找：1千万轮次
    //test(100, 1000000);  // 容量：100       查找：1百万轮次
    //test(1000, 100000);  // 容量：1000      查找：10万轮次
    //test(10000, 10000);  // 容量：10000     查找：1万轮次
    //test(100000, 1000);  // 容量：100000    查找：1000轮次
    test(1000000, 100);  // 容量：1000000   查找：100轮次
    //test(10000000, 10);  // 容量：10000000  查找：10轮次
 
    return 0;
}
