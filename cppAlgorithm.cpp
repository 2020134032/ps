// cppAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int fibo(int n) {
    cout << "(fib): " << n << "\n";
    if (n == 0 || n == 1)
        return n;
    return fibo(n - 1) + fibo(n-2);

}

int main()
{
    cout << fibo(4) << endl;
    cout << fibo(5) << endl;
    cout << fibo(6) << endl;
}

/* 재귀함수: f(n) 호출 xx
그리고 기저 상태 꼭 명시
가능하면 반복문 사용*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
