/*
�ۑ�ԍ��@�FL25-DeluxeSpecial1
���e�@�@�@�FpartStr�I�u�W�F�N�g�ɓ��͂����Q��string��������i�[���āA�ŏ��ɓ��͂���������ɁA
�@�@�@�@�@�@�Q�Ԗڂɓ��͂��������񂪊܂܂�Ă��邩�ǂ����������������ʂ�\������B
�@�@�@�@�@�@�܂܂��ꍇ��"������"�A�܂܂�Ȃ��ꍇ��"������Ȃ�"�ƕ\������B
�@�@�@�@�@�@break�����g���Ă��悢�B
�@�@�@�@�@�@���͂ƕ\����main�֐��ōs���B
�t�@�C�����FL25-DX1.cpp
�쐬���@�@�F2016/1/5
�쐬�ҁ@�@�FBayaSea
*/

//���s���Ɋm�F���邱�ƁF
//�����ׂĂ̎��s����m�F���Ȃ����B

#include <string>
#include <conio.h>
#include <iostream>
using namespace std;

//���������񌟍��N���X��`
class PartStr {
	string str;		//�����Ώە�����p
	string part;	//����������i����������p�j
	int sw = 0;		//�������ʎ��ʎq�i�O�F������Ȃ��@�P�F�������j
public:
	//������A����������݁@s�F�����Ώە�����Ap�F����������
	void setStr(string s, string p) {
		str = s;
		part = p;
	}

	//���������񌟍�
	void searchPartStr()
	{
		/*null�ɂȂ�܂ŌJ��Ԃ�
		for (int i = 0; str[i] != '\0' ; i++)
		{
			//part�̐擪�̕���������
			for (int j = 0; str[i] == part[j]; j++) 
			{
				//�擪�̎��̕�����null�Ȃ�΁A�����I��
				if (part[j + 1] == '\0') {
					sw = 1;
				}else {
					i++;
				}
			}
			//str[i]���s��ɂȂ�Ȃ������ɏ�������߂�
			//if (str[i] == '\0') { break; }
			if (sw == 1){ break; }
		}*/

		//null�ɂȂ�܂ŌJ��Ԃ�
		int i = 0;

		while (1)
		{
			//part�̐擪�̕���������
			for (int j = 0; str[i] == part[j]; j++)
			{
				//�擪�̎��̕�����null�Ȃ�΁A�����I��
				if (part[j + 1] == '\0') {
					sw = 1;
				}else {
					i++;
				}
			}
			//str[i]���s��ɂȂ�Ȃ������ɏ�������߂�
			//if (str[i] == '\0') { break; }
			if (sw == 1){ 
				break; 
			}
			else{
				i++;
			}
		}

	//�������ʎ擾
	int getSw()
	{
		return sw;
	}

};
////////////////////////////////////////////////////////////
int main()
{
	PartStr partStr;
	string str;			//�����Ώە�����p
	string part;		//����������i����������p�j

	cout << "����������>> ";
	cin >> str;

	cout << "��������������>> ";
	cin >> part;

	partStr.setStr(str, part);		//������A����������ݒ胁�\�b�h�̌Ăяo��
	partStr.searchPartStr();		//���������񌟍����\�b�h�̌Ăяo��


	if (partStr.getSw()) {
		cout << "������" << endl;
	}else{
		cout << "������Ȃ�" << endl;
	}

	_getch();
	return 0;
}

