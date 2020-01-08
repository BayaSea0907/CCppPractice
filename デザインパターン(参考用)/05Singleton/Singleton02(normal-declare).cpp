//Singleton(normal�F�I�u�W�F�N�g�錾)
//�y���_�z
//�iSingleton01.cpp�j�Ŗ��ƂȂ�A��������Singleton�I�u�W�F�N�g�̉���ꏊ���������邽�߂ɁA
//Singleton�I�u�W�F�N�g��ÓI�ϐ��Ƃ��Đ錾����

//�ÓI�ϐ��Ő錾�����I�u�W�F�N�g�̃A�h���X��GetInstance()�Ŗ߂������Ȃ̂ŁAshared�|�C���^���g���K�v�͂Ȃ�
//
//Singlton02(normal-declare).cpp
//����
//singleton
//singleton

#include <iostream>
#include <string>
using namespace std;

///////////////////////////////////////////////////////////////////
//Singleton�N���X��`
class Singleton {
	//������R�s�[���֎~����
	Singleton(){}									//�����֎~
	Singleton(const Singleton& rhs){}				//�R�s�[�R���X�g���N�^�֎~
	Singleton& operator=(const Singleton& rhs){}	//������Z�qoverload�֎~
public:
	//�B��̃A�N�Z�X�o�H
	static Singleton* GetInstance()
	{
		//�B���Singleton�I�u�W�F�N�g�ÓI�ϐ��Ƃ��Đ錾����
		static Singleton instance;

		return &instance;
	}

	void show(){ cout << "singleton" << endl; }

	~Singleton(){}
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	Singleton* sP1 = Singleton::GetInstance();		//Singleton�I�u�W�F�N�g����

	//���\�b�h�̌Ăяo�����i�Q�ʂ�j
	sP1->show();						//�@�|�C���^���g���ČĂяo��
	Singleton::GetInstance()->show();	//�A�B��̃A�N�Z�X�o�H����Ăяo��

	return 0;
}
