/*
�ۑ�ԍ��@�FL14-8
���e�@�@�@�FL14-3�����������āAmain�֐��ōs���Ă�����A�̏������t�h�iUser Interface�j�p�I�u�W�F�N�g�ōs���B
�@�@�@�@�@�@ui�I�u�W�F�N�g�ł́A���͐ݒ胁�\�b�h�ƕ\�����\�b�h��p�ӂ��āAhero�I�u�W�F�N�g�ɑ΂���
�@�@�@�@�@�@��A�̏��������processCtrl���\�b�h�ōs���B
�@�@�@�@�@�@���͐ݒ胁�\�b�h�ł́A���͂����g�o��hero�I�u�W�F�N�g�ɐݒ肷��B
�@�@�@�@�@�@�\�����\�b�h�ł́Ahero�I�u�W�F�N�g����擾�����g�o��\������B
�t�@�C�����FL14-A8.cpp
�쐬���@�@�F2015/06/10
�쐬�ҁ@�@�FBayaSea
*/

//�����FUI�œ��͂����l��Hero�ɓn���āAHero�������Ă��ꂽ�l��UI�ŕ\������B

#include <conio.h>
#include <iostream>
using namespace std;

//HERO�N���X��`
class Hero {
	int hp;		//HP

public:
	//HP�ݒ胁�\�b�h�@shp�FHP����p
	void setHp(int shp){
		hp = shp;			//������HP���C���X�^���X�ϐ�hp�ɑ��
	}

	//HP�擾���\�b�h
	int getHp(){
		return hp;			//�C���X�^���X�ϐ�hp�̒l��߂�
	}
};

////////////////////////////////////////////////////////////

//���[�U�C���^�t�F�[�X�N���X��`
class UI {
	Hero hero;				//hero�I�u�W�F�N�g

public:

    //�������䃁�\�b�h
    void processCtrl(){
        inp();				//���͐ݒ�
        show();				//�\��
    }

    //���͐ݒ胁�\�b�h
    void inp(){
		int hp; 			//HP���͗p

		cout << "HP�𐮐��l�œ��́i��@100�j>> ";
		cin >> hp;

		//HP�ݒ胁�\�b�h�̌Ăяo��
		hero.setHp(hp);
    }

    //�\�����\�b�h
    void show(){
        cout << "HP=" << hero.getHp() << endl;
    }
};

////////////////////////////////////////////////////////////

int main()
{
	UI ui;					//���[�U�C���^�t�F�[�X�I�u�W�F�N�g�錾

    ui. processCtrl();		//�C���^�t�F�[�X��������

	_getch();
	return 0;
}
