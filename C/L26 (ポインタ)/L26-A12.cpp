/*
�ۑ�ԍ��@�FL26-12
���e�@�@�@�Fcalcarray�I�u�W�F�N�g��int�^�z��i�v�f���T�j��n���āA�ő�l��\������B
�@�@�@�@�@�@main�֐��Ŕz��͐錾�Ɠ����ɏ���������B
�@�@�@�@�@�@�z��v�f����const�w��q���g���Đ錾����B
�@�@�@�@�@�@�\����main�֐��ōs���B
�t�@�C�����FL26-A12.cpp
�쐬���@�@�F2016/1/21
�쐬�ҁ@�@�FBayaSea
*/
#include <conio.h>
#include <iostream>
using namespace std;

const int MAX = 5;					//�v�f���̒�`

//�z��v�Z�N���X��`
class CalArray {
public:
	//�ő�l�T���@n[]�F�z��̐擪�A�h���X
	//�@�@�@�@�@�@�߂�l�F�ő�l
	int findMax(int n[])
	{
		
		int max = 0;	//�ő�l�̓Y�����i�[

		for (int i = 1; i < MAX; i++){
			if (n[i] > n[max]){
				max = i;
			}
		}
		return n[max];
	}
};
/////////////////////////////////////////////////////////////
int main()
{
	CalArray calarray;
	int ary[MAX] = { 30, 20, 50, 10, 40 };

	cout << "�ő�l=" << calarray.findMax(ary) << endl;

	_getch();
	return 0;
}
