/*
�ۑ�ԍ��@�FL26-ExtraSpecial1
���e�@�@�@�Fcalcarray�I�u�W�F�N�g��int�^�z��i�v�f���T�j��n���āA�ő�l���i�[����Ă���Y����
�@�@�@�@�@�@�g���čő�l��\������B
�@�@�@�@�@�@main�֐��ŁA�z��͐錾�Ɠ����ɏ���������B�@{30, 20, 50, 10, 40}
�@�@�@�@�@�@�v�f���́Aconst�w��q���g���Đ錾����B
�@�@�@�@�@�@�I�u�W�F�N�g�́A�ő�l���i�[����Ă���Y����߂��B
�@�@�@�@�@�@�\����main�֐��ōs���B
�@�@�@�@�@�@L26-12�Ƃ͖߂�l���قȂ�̂ŋC�����܂��傤�B
�t�@�C�����FL26-EX1.cpp
�쐬���@�@�F2016/1/18
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

const int MAX = 5;		//�z��v�f���̒�`

//�z��v�Z�N���X��`
class CalcArray {
public:
	//�ő�l�����Y���擾�@ary[]�F�����l�z��̐擪�A�h���X
	int getMaxId(int ary[]){
		int max = 0;		//�ő�l�̓Y���i�[�p

		//�ő�l����
		for (int i = 1; i < MAX; i++){
			if (ary[i] > ary[max]){
				max = i;
			}
		}
		return max;
	}
};
/////////////////////////////////////////////////////////////
int main()
{
	CalcArray calcarray;
	int ten[MAX] = { 30, 20, 50, 10, 40 };
	int id;						//�ő�l�����Y���擾�p

	id = calcarray.getMaxId(ten);		//�ő�l�����Y���擾���\�b�h�Ăяo��

	cout << "�ő�l=" << ten[id] << endl;

	_getch();
	return 0;
}

