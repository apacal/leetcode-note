/**
 *       Filename:  global.h
 *    Description:  
 *        Version:  1.0
 *        Created:  04/06/2016 19:10:40
 *       Compiler:  gcc
 *         Author:  Apacal (apacal.cn), apacalzqz@gmail.com
 *        Company:  tencent
 */

#include <iostream>
#include <vector>
using namespace std;


template <typename T>
void const printVector(const vector<T>& vec) {
    cout << "vector size[" << vec.size() << "] content[";
    for (typename vector<T>::const_iterator it = vec.begin(); it != vec.end(); ) {
        cout << *it;
        if (++it != vec.end()) {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

template <typename T>
void const printValue(const T value) {
    cout << "value [" << value << "]\n";
}
