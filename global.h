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

template<class InputIterator>
void printContainer(int size, InputIterator first, InputIterator last) {
    cout << "size[" << size << "] content[";
    for (InputIterator it = first; it != last; ) {
        cout << *it;
        if (++it != last) {
            cout << ", ";
        }
    }
    cout << "] \n";
}


template <typename T>
void const printValue(const T value) {
    cout << "value [" << value << "]\n";
}
