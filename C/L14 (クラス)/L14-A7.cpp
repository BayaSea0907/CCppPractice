/*
�ۑ�ԍ��@�FL14-7
���e�@�@�@�F���igoods�I�u�W�F�N�g�ɔ̔����i�ƒl��������ݒ肵����A�艿���v�Z����B
�@�@�@�@�@�@�������A�̔����i�ƒl�������̓��́A�艿�̕\����main�֐��ōs���B
�@�@�@�@�@�@�܂��A�艿�v�Z��goods�I�u�W�F�N�g�̃��\�b�h�ōs���A�����ǃI�u�W�F�N�g�Ɋi�[������̂Ƃ���B
�@�@�@�@�@�@�܂��A1�~�����͐؂�̂Ă�B
�t�@�C�����FL14-A7.cpp
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
	double rate;		//�l������

public:

    //�̔����i�E�l�����ݒ胁�\�b�h
    void setVar(int sprice, double srate){

	    price = sprice;
	    rate = srate;
    }

	//�艿�v�Z���\�b�h
	void calcTeika(){
		
		teika = (int)((double)price * (1.0 - rate));
	}

	//�艿�擾���\�b�h
    int getTeika(){

		return teika;
		
	}
};


////////////////////////////////////////////////////////////


int main()
{

	Goods goods;						//�I�u�W�F�N�g�錾
	int price;					        //�̔����i�i�~�j
	double rate;						//�l������

	cout << "�̔����i�̓��́i��@2080�j>> ";
	cin >> price;
	cout << "�l�����i20���̏ꍇ�@0.2�j>> ";
	cin >> rate;

	goods.setVar(price, rate);			//�w�����i�E�l�����ݒ�
    goods.calcTeika();				    //�艿�v�Z

	cout << "�艿=" << goods.getTeika() << endl;

	_getch();
	return 0;
}
