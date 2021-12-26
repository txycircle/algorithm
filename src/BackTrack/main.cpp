//��N����Ʒ��һ������ΪV�ı�����
//��i����Ʒ��������w[i]����ֵ��v[i]��
//��⽫��Щ��Ʒװ�뱳����ʹ��Щ��Ʒ�������ܺͲ����������������Ҽ�ֵ�ܺ����

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