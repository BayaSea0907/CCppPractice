/*
�ۑ�ԍ��@�FL26-DeluxeSpecial2
���e�@�@�@�Fstropr�I�u�W�F�N�g��char�^�����z��Ɋi�[����������"CUgameAllStar"�Ɠ��͂����P����
�@�@�@�@�@�@��n���āA������ɂP���������邩�ǂ����̌������ʂ�\������B
�@�@�@�@�@�@������ɂP����������ꍇ��"����"�A�Ȃ��ꍇ��"�Ȃ�"�ƕ\������B
�@�@�@�@�@�@�܂��A������ɂP�������������ꍇ�ɂ́A���̕����ȍ~�̕�������\������B
�@�@�@�@�@�@main�֐��ŁAchar�^�����z��͂͐錾�Ɠ����ɏ���������B
�@�@�@�@�@�@�\����main�֐��ōs���B
�t�@�C�����FL26-DX2.cpp
�쐬���@�@�F2016/1/28
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�����񑀍�N���X��`
class StrOpr {
public:
	//�����񌟍��@str[]�F�����Ώە����z��̐擪�A�h���X�@c�F��������
	//�@�@�@�@�@�߂�l�Fchar*�@�������ʁi�z��v�f�̃A�h���X�@����ANULL�@�Ȃ��j
	char* findLetter(char str[], char c){
		char *p = NULL;		//�Y���p

		//��������
		for (int i = 0; str[i] != '\0'; i++){
			if (str[i] == c){
				p = &str[i];
				break;
			}
		}
		return p;
	}

};
////////////////////////////////////////////////////////////
int main()
{
	StrOpr stropr;
	char str[20] = "CUgameAllStar";
	char c;				//�����������͗p
	char *p;			//�������ʗv�f�A�h���X�擾�p

	cout << "�������������>> ";
	cin >> c;

	p = stropr.findLetter(str, c);		//�����񌟍����\�b�h�Ăяo��

	//�������ʂ̕\��
	if (p == NULL){
		cout << "�Ȃ�" << endl;
	}
	else{
		cout << "����" << endl;

		cout << "���������ȍ~�̕�����=" << p << endl;
	}

	_getch();
	return 0;
}

