/*
�ۑ�ԍ��@�FL26-10
���e�@�@�@�Fcalcarray�I�u�W�F�N�g�ɂT�̓_����v�f�Ƃ���int�^�z��i�v�f���T�j��n���āA���v��
�@�@�@�@�@�@���ς�\������B
�@�@�@�@�@�@�z��v�f����const�w��q���g���Đ錾����B
�@�@�@�@�@�@main�֐��Ŕz��͐錾�Ɠ����ɏ���������B
�@�@�@�@�@�@�\����main�֐��ōs���B
�t�@�C�����FL26-A10.cpp
�쐬���@�@�F2016/1/18
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

const int MAX = 5;					//�v�f���̒�`

//�z��v�Z�N���X��`
class CalcArray {
public:
	//���v�E���ώ擾�@n[]�F�_���z��̐擪�A�h���X�A*p�F���v�p�̈�̃A�h���X
	//�@�@�@�@�@�@�@�@�߂�l�Fdouble���ϓ_
	double getAveSum(int n[], int* p){
		int sum = 0;	//���v�p
		int i;			//�Y���p


		//���v�_�i�[
		for(i = 0; i < MAX; i++){
			sum += n[i];
		}
		*p = sum;

		//���ϓ_
		return (double)sum / (double)i;

	}
};
/////////////////////////////////////////////////////////////
int main()
{
	CalcArray calcarray;
	int ten[MAX] = { 100, 200, 300, 400, 500 };
	double ave;		//���ϓ_�擾�p
	int sum;		//���v�擾�p

	ave = calcarray.getAveSum(ten, &sum);	//���v�E���ώ擾���\�b�h�Ăяo��

	cout << "���v=" << sum << " ����=" << ave << endl;

	_getch();
	return 0;
}

