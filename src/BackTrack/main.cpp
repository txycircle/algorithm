//有N件物品和一个容量为V的背包。
//第i件物品的重量是w[i]，价值是v[i]。
//求解将哪些物品装入背包可使这些物品的重量总和不超过背包容量，且价值总和最大。

#include<iostream>
#include "BackTrack_solution.h"
#include "RandomInput.h"
using namespace std;

int main()

{
    typedef vector<int> T;
    RandomInput Input_gen;
    for (int i = 0; i < 11; ++i)
    {
        int size = Input_gen.RandomInt(1, 20);
        T input1;
        T input2;

        input1 = Input_gen.Random(0, 5000, size);
        input2 = Input_gen.Random(0, 5000, size);
        int target = Input_gen.RandomInt(1, 5000);

        cout << "input1: " << endl;
        for (int i = 0; i < input1.size(); ++i)
            cout << input1[i] << ' ';
        cout << endl;
        cout << "input2: " << endl;
        for (int i = 0; i < input2.size(); ++i)
            cout << input2[i] << ' ';
        cout << endl;
        cout << "target: " << target << endl;

        
        if (BackTrack(input1, input2, target, 1) == BackTrack(input1, input2, target, 2)) cout << "ok" << endl;
        else 
        {
            cout << "solution1:" << BackTrack(input1, input2, target, 1) << endl;
            cout << "solution2:" << BackTrack(input1, input2, target, 2) << endl;
        }
    }
	return 0;
}