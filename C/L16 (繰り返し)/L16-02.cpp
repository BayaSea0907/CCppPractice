/*
�ۑ�ԍ��@�FL16-2
���e�@�@�@�F�v�Zcalc�I�u�W�F�N�g�̃��\�b�h�ŁA���͒l�����ׂĊ|���Z������A���̒l��\������B
�@�@�@�@�@�@�������A�J�Ԃ���while�����g����0�����͂����܂ōs���B
�t�@�C�����FL16-02.cpp
�쐬���@�@�F2015/10/01
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�v�Z�N���X��`
class Calc {
	int mul = 1;			//��Z���ʗp(1)

public:
	//��Z���\�b�h
	void multiply(){
		int num;           //���͗p
		int sw = 1;        //�J�Ԑ���p�i�P�F�J�Ԃ��j

		//���͒l�����Z����
		while(sw != 0){
			cout << "�����l�����>> ";
			cin >> num;

			//���͒l����
			if(num == 0){
				sw = 0;			//�J�Ԃ�����߂�
			}
			else{
				mul *= num;		//�|���Z
			}
		}
	}

	//��Z���ʎ擾���\�b�h
	int getMul()
	{ 
		return mul;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Calc calc;		//�v�Z�I�u�W�F�N�g�錾

	calc.multiply();      //��Z���\�b�h�Ăяo��
	cout << "��Z����=" << calc.getMul() << endl;

	_getch();
	return 0;
}

