/*
�ۑ�ԍ��@�FL25-ExcellentSpecial1
���e�@�@�@�FcontStr�I�u�W�F�N�g�ɓ��͂���������̕����i�ő啶�����P�O�j�����ꂼ�ꉽ�������̂���
�@�@�@�@�@�@���ׁA�����R�[�h�̏��������Ɍ��ʂ�\������B
�@�@�@�@�@�@�����p�^�[���z��i�v�f���P�P�j�ƕ������z��i�v�f���P�O�j�̂Q�𕶎��p�^�[���\���̂�
�@�@�@�@�@�@�p�ӂ��A�����Ƃ��̌��𓯂��z��v�f�ԍ��őΉ�������B
�@�@�@�@�@�@�R���X�g���N�^�ŁA�����p�^�[���\���̂̕����p�^�[���z��ƌ��z������ꂼ��k�������ƂO
�@�@�@�@�@�@�ŏ���������B
�@�@�@�@�@�@���͂ƕ\���́Amain�֐��ōs���B
�@�@�@�@�@�@�����p�^�[���ƌ��ݒ胁�\�b�h�ł́A���߂Č���镶���𕶎��p�^�[���z��Ɋi�[���āA����
�@�@�@�@�@�@����������邲�Ƃɕ����p�^�[���z��v�f�ɑΉ��������i�[�p�z��̗v�f���C���N�������g��
�@�@�@�@�@�@��B
�t�@�C�����FL25-XC1.cpp
�쐬���@�@�F2016/1/5
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�����p�^�[���\���̒�`
struct Pattern {
	char mozi[11];		//�����p�^�[���i�[�p
	int kosu[10];		//�������i�[�p
};

//������\�������N���X��`
class ContentStr {
	Pattern pat;		//�����p�^�[���\����
	char str[11];		//���͕�����p
	int max = 0;		//�����p�^�[���z��Ɋi�[�����������ikosu�z��ɂ��g���j
public:
	//�R���X�g���N�^
	ContentStr() {
		int i;

		//0�ŏ�����
		for (i = 0; i < 10; i++) {
			pat.kosu[i] = 0;
		}

		//�k�������ŏ�����
		for (i = 0; i < 11; i++){
			pat.mozi[i] = '\0';
		}
	}


	//������ݒ�@s[]�F�i�[������
	void setStr(char s[]) {
		strcpy_s(str, 11, s);
	}

	//�����p�^�[���ƌ��ݒ�
	void searchMoziKosu()
	{
		//null�ɂȂ�܂ŌJ��Ԃ�
		for (int i = 0; str[i] != '\0'; i++)
		{
			max = strlen(pat.mozi);		//�����p�^�[���z��̕�����
			
			//��xmozi�z��Ɋi�[���������̌����͍s��Ȃ�
			for (int j = 0; (str[j] != '\0') && (str[i] != pat.mozi[j]); j++)
			{
				//���͕�������������
				if (str[i] == str[j])
				{
					//�����p�^�[�����i�[����Ă��Ȃ��ꍇ
					if (pat.mozi[max] == '\0') {
						pat.mozi[max] = str[j];
					}
					//pat.mozi[max] = str[j];
					pat.kosu[max]++;
				}
			}
		}
	}

	//�����R�[�h�����\�[�g
	void sortMoziCode(){
		char temp;

		for (int i = 0; pat.mozi[i] != '\0'; i++)
		{
			for (int j = i + 1; pat.mozi[j] != '\0'; j++) 
			{
				if (pat.mozi[i] > pat.mozi[j]) 
				{
					temp = pat.mozi[i];
					pat.mozi[i] = pat.mozi[j];
					pat.mozi[j] = temp;

					temp = pat.kosu[i];
					pat.kosu[i] = pat.kosu[j];
					pat.kosu[j] = temp;
				}
			}
		}
	}

	//�����p�^�[���\���̎擾�@�߂�l�F�����p�^�[���\����
	Pattern getPattern() {
		return pat;
	}

};
////////////////////////////////////////////////////////////


int main()
{
	ContentStr contStr;		//������\�������I�u�W�F�N�g�錾
	char str[11];			//��������͗p
	Pattern pat;			//�����p�^�[���\���̎擾�p

	cout << "����������>> ";
	cin >> str;

	contStr.setStr(str);		//������ݒ胁�\�b�h�̌Ăяo��

	contStr.searchMoziKosu();	//�����p�^�[���ƌ��ݒ胁�\�b�h�̌Ăяo��

	contStr.sortMoziCode();		//�����R�[�h�����\�[�g���\�b�h�̌Ăяo��

	pat = contStr.getPattern();		//�����p�^�[���擾���\�b�h�̌Ăяo��
	
	for (int i = 0; pat.mozi[i] != '\0'; i++) {
		cout << "����" << pat.mozi[i] << " ��=" << pat.kosu[i] << endl;;
	}

	_getch();
	return 0;
}

