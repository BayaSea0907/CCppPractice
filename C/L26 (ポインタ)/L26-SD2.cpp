/*
�ۑ�ԍ��@�FL26-SuperDeluxe2
���e�@�@�@�F���R�����P���͂��āA���̎��R���܂ł̊K��v�Z���l�i�Ⴆ�΁A5!=120(1*2*3*4*5)�j��
�@�@�@�@�@�@�\������B
�@�@�@�@�@�@�K��v�Z�͍ċA�֐����\�b�h�Ƃ���B
�@�@�@�@�@�@���R���̌^�́Aunsigned int�B
�@�@�@�@�@�@�\����main�֐��ōs���B
�t�@�C�����FL26-SD2.cpp
�쐬���@�@�F2016/2/3
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�l����N���X��`
class ValOpr {
public:
	//�K��v�Z�擾�i�ċA�j�@n�F�l
	int factorial(unsigned int n){

		if (n <= 1){		//(n == 0)
			return 1;
		}
		else{
			return n * factorial(n - 1);
		}
	}
};
//////////////////////////////////////////////////////
int main()
{
	ValOpr valopr;
	unsigned int num;			//���͒l�i�[�p

	cout << "���R�������>> ";
	cin >> num;

	//�K��v�Z�擾���\�b�h���Ăяo���ĕ\��
	cout << num << "!=" << valopr.factorial(num) << endl;

	_getch();
	return 0;
}

