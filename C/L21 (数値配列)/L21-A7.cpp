/*
�ۑ�ԍ��@�FL21-7
���e�@�@�@�FL21-4�����������āAtest�I�u�W�F�N�g�ɂT�����̓��_��v�f�ɂ��z����i�[���āA�z��v�f
�@�@�@�@�@�@�i���_�j���~���\�[�g����B�\�[�g�O��̔z��v�f��\������B
�@�@�@�@�@�@�I�u�W�F�N�g�̓��_�z�����ёւ���B
�@�@�@�@�@�@�~���\�[�g�Ƃ́A�傫���l���O�ɁA�������l����ɂ���悤�ɕ��ѕς��邱�Ƃ������B
�@�@�@�@�@�@�T�����̓��_�����z��́Amain�֐��ŗ\�ߔz���錾����Ɠ����ɏ���������B
�@�@�@�@�@�@�\���̓I�u�W�F�N�g�ōs���B
�t�@�C�����FL21-A7.cpp
�쐬���@�@�F2015/11/12
�쐬�ҁ@�@�FBayaSea
*/

#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

//�e�X�g�N���X��`
class Test {
	int ten[5];		//���_�z��̐錾
public:
	//���_�ݒ�@n[]�F���_�z��
	void setTen(int n[])
	{
		//�z��v�f�ɓ��_��ݒ�@cnt�F���[�v�J�E���^
		for (int cnt = 0; cnt < 5; cnt++)
		{
			ten[cnt] = n[cnt];
		}
	}
	//�~���\�[�g
	void sortTen(){
		int taihi;	//�ꎞ�ޔ�p

		//��r�����v�f�̐���
		//i�F��p���[�v�J�E���^
		for (int i = 0; i < 4; i++){

			//��r�Ώۗv�f�̐���@j�F���[�v�J�E���^
			for (int j = i + 1; j < 5 ; j++){
				//��v�f�Ɣ�r�Ώۗv�f�̒l�̌���
				if (ten[i] < ten[j]){
					taihi = ten[i];
					ten[i] = ten[j];
					ten[j] = taihi;
				}
			}
		}
	}
	//���_�\��
	void showTen(){
		//�z��v�f�̕\���@i�F���[�v�J�E���^
		for (int i = 0; i < 5; i++){
			cout << setw(3) << ten[i];
		}

	}
};
////////////////////////////////////////////////////////////


int main()
{
	Test test;							//�e�X�g�I�u�W�F�N�g�錾
	int ten[5] = { 3, 5, 20, 7, 15 };	//���_�z��錾�Ɠ����̏�����

	test.setTen(ten);	//���_�ݒ胁�\�b�h�̌Ăяo��

	cout << "�\�[�g�O�F";
	test.showTen();		//���_�\�����\�b�h�̌Ăяo��

	test.sortTen();		//�~���\�[�g���\�b�h�̌Ăяo��

	cout << endl << "�\�[�g��F";
	test.showTen();		//���_�\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}


