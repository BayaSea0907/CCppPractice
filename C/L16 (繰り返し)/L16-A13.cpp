/*
�ۑ�ԍ��@�FL16-13
���e�@�@�@�F���kuku�I�u�W�F�N�g�̃��\�b�h�ŁA�Q�d���[�v���g���Ċ|���Z����\������B
�@�@�@�@�@�@�e���l��3���\���ōs���B
�@�@�@�@�@�@�iiomanip���C���N���[�h���āAcout��setw(3)�ɑ����Đ��l��\������j�B
�t�@�C�����FL16-A13.cpp
�쐬���@�@�F2015/10/01
�쐬�ҁ@�@�FBayaSea
*/

#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;

//���N���X��`
class Kuku {
public:
	//���\�����\�b�h
	void showKuku()
	{
		cout << "�|���鐔   *1   *2   *3   *4   *5   *6   *7   *8   *9" << endl << endl;

		//�s�i�i�j�̐���@gyo�F�s�i�i�j�p���[�v�J�E���^
		for(int gyo = 1; gyo <= 9; gyo++)
		{
			cout << gyo << "�̒i >> ";

			//��̐���@retu�F��p���[�v�J�E���^
			for(int retu = 1; retu <= 9; retu++)
			{

				cout << setw(3) << gyo*retu << "�@"  ;		//�s*��̌��ʂ̒l��3���ŕ\��
			}

			cout <<  endl;									//�s���̉��s
		}
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Kuku kuku;			//���I�u�W�F�N�g�錾

	kuku.showKuku();	//���\�����\�b�h�̌Ăяo��

	_getch();
	return 0;
}
