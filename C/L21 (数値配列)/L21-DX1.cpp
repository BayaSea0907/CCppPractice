/*
�ۑ�ԍ��@�FL21-DeluxeSpecial1
���e�@�@�@�Fmarathon�I�u�W�F�N�g�ɁA���͂���3Km�}���\�������Ґl���Ɗ����҃^�C����v�f�Ƃ���z���
�@�@�@�@�@�@�i�[���āA���σ^�C����\������B�Q���҂͍ő�10�l�B
�@�@�@�@�@�@�^�C���͎����i�Ⴆ�΁A13��20�b�ł����13.2�A12��5�b�ł����12.05�j�œ��͂���B
�@�@�@�@�@�@�܂��A�����Ґl���i0�l�ȏ�10�l�ȉ��j����͂��āA�͈͊O�Ȃ�΍ē��͂���B
�@�@�@�@�@�@�͈͓��Ȃ�΁A�����҃^�C�����^�C�����͗p�z��ɓ��͂��āA�����Ґ��Ɗ����҃^�C���z����I
�@�@�@�@�@�@�u�W�F�N�g�Ɋi�[����B
�@�@�@�@�@�@�����āA���σ^�C�����v�Z���āA�����ǃI�u�W�F�N�g�Ɋi�[����B
�@�@�@�@�@�@�����Ґl�����O�l�̏ꍇ�́A"�o�^�^�C���͂���܂���"�ƕ\������B
�@�@�@�@�@�@���͂Ɗ����҂O�l�̏ꍇ�̕\����main�֐��ōs���A���σ^�C���̕\���̓I�u�W�F�N�g�ōs���B
�t�@�C�����FL21-DX1.cpp
�쐬���@�@�F2015/12/03
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//�}���\���N���X��`
class Marathon {
	int person = 0;		//�����Ґ��i0�j
	double time[10];	//�����҃^�C���p
	int heikin = 0;		//���σ^�C���b
public:
	//�����Ґ��ݒ�@n�F�����Ґ�
	void setPerson(int n){
		person = n;
	}

	//�����҃^�C���ݒ�@t[]�F�^�C���z��
	void setTime(double t[]){
		for (int i = 0; i < person; i++) {
			time[i] = t[i];
		}
	}

	//���σ^�C���v�Z
	void calcAveTime(){
		//�^�C���𐮐��ɒ���
		for (int i = 0; i < person; i++){
			//�^�C���𐮐��ɒ����č��v�����߂�
			heikin += (int)(time[i] * 100.0);

			//��2��(�b)��60�𒴂����猅���グ��
			if (60 <= (heikin % 100)){
				heikin += 40;
			}
		}

		//���v�^�C�� �� �o�^�l��
		heikin /= person;
		//��2���� �b/100�ƂȂ��Ă���̂� �b/60�ɒ���
		heikin = ((heikin - (heikin % 100)) + ((int)((double)(heikin % 100) * 0.6) + 0.9999));
	}

	//���σ^�C���\��
	void showAveTime(){
		cout << person << "�l�̕��σ^�C��="
			 <<	heikin / 100 << "��" <<	heikin % 100 << "�b" << endl;
	}
};
////////////////////////////////////////////////////////////
int main()
{
	Marathon marathon;	//�}���\���I�u�W�F�N�g�錾
	double time[10];	//�^�C�����͗p
	int person;			//�l�����͗p

	while (1){
		cout << "�o�^����l���̓��́i�O�ȏ�P�O�l�ȉ��j>> ";
		cin >> person;

		//�͈͓��������烋�[�v�𔲂���
		if (0 <= person && person <= 10) { break; }

		cout << "���͐l�����Ⴂ�܂��B�ē��͂��Ă�������" << endl;

	}

	//�����҂��P�l�ȏア���ꍇ
	if(person != 0)
	{
		//�����҃^�C������
		for (int i = 0; i < person ; i++){
			cout << i + 1 << "�l�ڂ̃^�C���i���D�b�j�̓���>> ";
			cin >> time[i];
		}

		marathon.setPerson(person);	//�����Ґ��ݒ胁�\�b�h�̌Ăяo��
		marathon.setTime(time);		//�����҃^�C���ݒ胁�\�b�h�̌Ăяo��
		marathon.calcAveTime();		//���όv�Z���\�b�h�̌Ăяo��
		marathon.showAveTime();		//���σ^�C���\�����\�b�h�̌Ăяo��
	}
	else{
		cout << "�o�^�^�C���͂���܂���" << endl;
	}

	_getch();
	return 0;
}

