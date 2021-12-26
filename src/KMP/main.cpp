#include <iostream>
#include <assert.h>
#include "RandomInput.h"
#include "KMP_solution.h"


using namespace std;

int main()
{
    typedef string T;
    RandomInput Input_gen;
    for (int i = 0; i < 11; ++i)
    {
        int size = Input_gen.RandomInt(1, 20);
        T input1;
        T input2;
        int k = -1;
        if (i % 2 == 1)
        {
            input1 = Input_gen.Random(size, '0',9);
            input2 = Input_gen.Random(size, '0', 9);
            cout << "input1: " << input1 << endl;
            cout << "input2: " << input2 << endl;
            cout << "gt: " << k << endl;
        }
        else
        {
            input1 = Input_gen.Random(size, '0', 9);
            k = Input_gen.RandomInt(0, size);
            input2 =  string(input1, input1.size() - k, k);
            input2 += string(input1, 0, input1.size() - k);
            cout << "input1: " << input1 << endl;
            cout << "input2: " << input2 << endl;
            cout << "gt: " << (input1.size()-k)%input1.size() << endl;
        }
        
        cout << "result: " << KMP(input1+input1, input2) << endl;
    }

    return 0;
        
}