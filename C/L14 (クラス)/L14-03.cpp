/*
�ۑ�ԍ��@�FL14-3
���e�@�@�@�Fmain�֐��œ��͂���HP��hero�I�u�W�F�N�g�ɓn������Ahero�I�u�W�F�N�g�������Ă��ꂽ
�@�@�@�@�@�@�i���\�b�h����߂��ꂽ�jHP��main�֐��ŕ\������B
�@�@�@�@�@�@HP�ݒ��HP�擾�́Ahero�I�u�W�F�N�g�̂��ꂼ��̃��\�b�h�ōs���B
�@�@�@�@�@�@�������Ahero�I�u�W�F�N�g�ɓn����HP�́A�����ǃC���X�^���X�ϐ��i�I�u�W�F�N�g�Ɋi�[�j�Ɋi�[������̂Ƃ���B
�t�@�C�����FL14-03.cpp
�쐬���@�@�F2015/06/10
�쐬�ҁ@�@�FBayaSea
*/

//���s���Ɋm�F���邱�ƁF
//��hero�I�u�W�F�N�g�ɁAmain�֐�����HP��n���Ă��邱�Ƃ��m�F���Ȃ����B
//A.�m�F���܂����B�����������ƃC���X�^���X�ϐ���hp�ɂ͉����i�[�ł��Ȃ��B

//��hero�I�u�W�F�N�g���A������HP���C���X�^���X�ϐ��Ɋi�[���Ă��邱�Ƃ��m�F���Ȃ����B
//A.�m�F���܂����BsetHp���\�b�h�� =shp�������Ɠ��͂������l�ƈႤ���̂��\�������B

//��hero�I�u�W�F�N�g����߂��ꂽHP���Amain�֐��ŕ\�����Ă��邱�Ƃ��m�F���Ȃ����B
//A.�m�F���܂����BgetHp���\�b�h��return hp���O�ɂ���ƁA�C���X�^���X�ϐ��Ɋi�[�������l�ƈႤ���̂��\�������B

#include <conio.h>
#include <iostream>
using namespace std;

//HERO�N���X��`

class Hero {

	int hp;		//HP

public:

	//HP�ݒ胁�\�b�h�@shp�FHP����p
	void setHp(int shp){
		hp = shp ; 							//������HP���C���X�^���X�ϐ�hp�ɑ��
	}

	//HP�擾���\�b�h
	int getHp(){
	return 0;								//�C���X�^���X�ϐ�hp�̒l��߂�
	}
};


////////////////////////////////////////////////////////////


int main()
{
	Hero hero;									//�q�[���[�I�u�W�F�N�g�錾
	int hp; 									//HP���͗p

	cout << "HP�𐮐��l�œ��́i��@100�j>> ";
	cin >> hp;
	hero.setHp(hp);								//HP�ݒ胁�\�b�h�̌Ăяo��

	//HP�擾���\�b�h����߂��Ă���HP��\��
	cout << "HP=" << hero.getHp() << endl;

	_getch();
	return 0;
}
