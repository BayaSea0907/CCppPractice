/*
�ۑ�ԍ��@�FL16-DeluxeSpecial1
���e�@�@�@�F���[�N���b�h�ݏ��@euc�I�u�W�F�N�g�ɂQ�̐����l�i�O�ȊO�j��ݒ肵����A���[�N���b�h��
�@�@�@�@�@�@�ݏ��@���g���čő���񐔂����߂�B
�@�@�@�@�@�@�����l���͂ƍő���񐔕\����main�֐��ōs���Aeuc�I�u�W�F�N�g�Ōv�Z�����ő���񐔂͂���
�@�@�@�@�@�@�ǃI�u�W�F�N�g�Ɋi�[���Ă������̂Ƃ���B
�@�@�@�@�@�@�܂�ui�I�u�W�F�N�g�ł̐����l���͂́A�O�ȊO�̐����l�����͂����܂ŌJ�Ԃ����͂���B
�@�@�@�@�@�@���[�N���b�h�ݏ��@���g���ƁA�ő���񐔂͏����i���鐔�j�p�̕ϐ��Ɋi�[�����B
			   ��j�Q�R�P�ƂP�T�̍ő���񐔂͂R
					  �Q�R�P�@���@�P�T�@���@�P�T�@�E�E�E�@�U
					    �P�T�@���@�@�U�@���@�@�Q�@�E�E�E�@�R
					      �U�@���@�@�R�@���@�@�O
�t�@�C�����FL16-DX1.cpp
�쐬���@�@�F2015/11/22
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//���[�N���b�h�ݏ��@�N���X��`
class Euclidean {
	int dividend;		//�폜���i�����鐔�j
	int divisor;		//�����i���鐔�j
public:
	//�����l�ݒ胁�\�b�h
	void setVar(int sdividend, int sdivisor)
	{
		dividend = sdividend;	//�����鐔
		divisor = sdivisor;		//���鐔
	}

	//�ő���񐔌v�Z���\�b�h
	void calcGrcomDiv()
	{
		int remainder;		//�]��p
		int taihi;			//�ޔ�p

		//���������̐��������idivisor�j�ɓ���ւ���
		if(divisor > dividend)
		{
			taihi = divisor;
			divisor = dividend;
			dividend = taihi;
		}

		//���[�N���b�h�̌ݏ��@�i�]�肪�O�ɂȂ�܂Łj
		while(1)
		{
			remainder = dividend % divisor;		//�]������߂�

			//�]�肪0�ɂȂ����烋�[�v����߂�
			if (remainder == 0){
				break;
			}
			dividend = divisor;				//����폜���ɓ����
			/*�Ҳ��ް��r���Ă�񂾂���
			�Ҳ��ް���߂��Ƃ���̐^����if�����Ă����ق�������
			if (remainder == 0){
				break;
			}*/
			divisor = remainder;		//�]��������ɓ����
		}
	}

	//�ő���񐔎擾���\�b�h
	int getGrComDiv()
	{
		return divisor;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Euclidean euc;		//���[�N���b�h�ݏ��@�I�u�W�F�N�g�錾
	int dividend;		//�폜���i�����鐔�j���͗p
	int divisor;		//�����i���鐔�j���͗p

	do{
		cout << "�O�ȊO�̐����l���Q����(�� 10 20) >> ";
		cin >> dividend >> divisor;
	//�ǂ��炩�̐��l��0����������͂�����
	}while((dividend == 0) || (divisor == 0));

	euc.setVar(dividend, divisor);		//�����l�ݒ胁�\�b�h�Ăяo��

	euc.calcGrcomDiv();					//�ő���񐔌v�Z���\�b�h�̌Ăяo��

	cout << "�ő����=" << euc.getGrComDiv() << endl;

	_getch();
	return 0;
}
