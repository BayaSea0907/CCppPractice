/*
�ۑ�ԍ��@�FL26-11
���e�@�@�@�Fstropr�I�u�W�F�N�g�̃A�h���X���|�C���^�Ɋi�[���āA�|�C���^���g���ăI�u�W�F�N�g��
�@�@�@�@�@�@string�^������"CUgameAllStar"�Ɠ��͂����P������n���āA������ɂP���������邩�ǂ���
�@�@�@�@�@�@�̌������ʂ�\������B
�@�@�@�@�@�@������ɂP����������ꍇ�́g����h�A�Ȃ��ꍇ�́g�Ȃ��h�ƕ\������B
�@�@�@�@�@�@string�^�������main�֐��Ő錾�Ɠ����ɏ���������B
�@�@�@�@�@�@���͂ƕ\���́Amain�֐��ōs���B
�t�@�C�����FL26-A11.cpp
�쐬���@�@�F2016/1/18
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�����񑀍�N���X��`
class StrOpr {
public:
	//�����񌟍��@str�F�����Ώە�����@c�F��������
	//�@�@�@ �@�߂�l�F�������ʁi�P�@�������A�@�O�@������Ȃ��j
	int findLetter(string str, char c)
	{
		int result = 0;			//�������ʎ擾�p

		//�k�������ɂȂ�܂ŌJ��Ԃ�
		for (int i = 0; str[i] != '\0'; i++){
			//�����������������ꍇ
			if (str[i] == c){
				result = 1;
				break;
			}
		}
		return result;
	}
};
/////////////////////////////////////////////////////////////
int main()
{
	StrOpr stropr;
	StrOpr* p;			//stropr�I�u�W�F�N�g�ւ̃|�C���^
	string str = "CUgameAllStar";
	char c;			//���͌��������p
	int result;		//�������ʎ擾�p

	p = &stropr;		//stropr�I�u�W�F�N�g�̃A�h���X���|�C���^�֊i�[

	cout << "�������������>> ";
	cin >> c;

	result = p->findLetter(str, c);		//�����񌟍����\�b�h�Ăяo��

	//�������ʂ̕\��
	if (result){
		cout << "����" << endl;
	}
	else{
		cout << "�Ȃ�" << endl;
	}
		
	_getch();
	return 0;
}
