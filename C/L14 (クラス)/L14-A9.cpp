/*
�ۑ�ԍ��@�FL14-9
���e�@�@�@�FL14-7�����������āAmain�֐��ōs���Ă�����A�̏������t�h�iUser Interface�j�p�I�u�W�F�N�g�ōs���B
�@�@�@�@�@�@ui�I�u�W�F�N�g�ł́A���͐ݒ胁�\�b�h�ƕ\�����\�b�h��p�ӂ��āAgoods�I�u�W�F�N�g�ɑ΂�
�@�@�@�@�@�@��艿�v�Z���܂߂���A�̏��������processCtrl���\�b�h�ōs���B
�@�@�@�@�@�@���͐ݒ胁�\�b�h�ł́A���͂����̔����i�ƒl���������igoods�I�u�W�F�N�g�ɐݒ肷��B
�@�@�@�@�@�@�\�����\�b�h�ł́Agoods�I�u�W�F�N�g����擾�����艿��\������B
�t�@�C�����FL14-A9.cpp
�쐬���@�@�F2015/06/10
�쐬�ҁ@�@�FBayaSea
*/

#include <conio.h>
#include <iostream>
using namespace std;

//���i�N���X��`
class Goods {
	int teika;		//�艿�i�~�j
	int price;		//�̔����i�i�~�j
	double rate;	//�l������

public:

//�̔����i�E�l�����ݒ胁�\�b�h
    void setVar(int sprice, double srate){
	    price =sprice;
	    rate = srate;
    }

	//�艿�v�Z���\�b�h
	void calcTeika(){
		teika = (int)((double)price / (1.0 - rate));
	}

	//�艿�擾���\�b�h
	int getTeika(){
		return teika;
	}
};

////////////////////////////////////////////////////////////

//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Goods goods;				//goods�I�u�W�F�N�g�錾

public:

    //�������䃁�\�b�h
    void processCtrl(){

		inp();					//���͐�
		goods.calcTeika();		//�艿�v�Z           
        show();		  	        //�\��
    }

    //���͐ݒ胁�\�b�h
	void inp(){
		int price;				//�̔����i���͗p
		double rate;			//�l�������͗p

		cout << "�̔����i�̓��́i��@2080�j>> ";
		cin >> price;

		cout << "�l�����i20���̏ꍇ�@0.2�j>> ";
		cin >> rate;

		//�w�����i�E�l�����ݒ�
		goods.setVar(price, rate);
	}

    //�\�����\�b�h
    void show(){
		cout << "�艿=" << goods.getTeika() << endl;
    }
};

////////////////////////////////////////////////////////////

int main()
{
	UI ui;			    //���[�U�C���^�t�F�[�X�I�u�W�F�N�g�錾

	ui.processCtrl();	//�C���^�t�F�[�X��������

	_getch();
	return 0;
}
