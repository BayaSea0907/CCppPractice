//Singleton(normal)
//�I�u�W�F�N�g���A�v���O�����S�̂ł����ЂƂł��邱�Ƃ�ۏ؂��A
//���A���̃I�u�W�F�N�g�ւ̗B��̃A�N�Z�X�o�H��񋟂���

//�����ЂƂ̃I�u�W�F�N�g����邽�߂ɂ́A�ÓI�ϐ��iincetanceP�j�ƗB��̃A�N�Z�X�o�H�iGetInstance()�j���`����
//�I�u�W�F�N�g�����̃^�C�~���O�́A���߂�GetInstance()���Ăяo�����Ƃ��ƂȂ�
//���̂��߁A�v���O�����̊J�n����I���܂ł̊ԂɁA��x��GetInstance()���Ăяo����Ȃ���΁A
//�I�u�W�F�N�g�͐�������邱�ƂȂ��I������

//���\�b�h�̌Ăяo�����i�Q�ʂ�j
//Singleton* sP1 = Singleton::GetInstance();	//Singleton�I�u�W�F�N�g����
//sP1->show();									//�@�|�C���^���g���ČĂяo��
//Singleton::GetInstance()->show();				//�A�B��̃A�N�Z�X�o�H����Ăяo��

//�y���_�z
//�ÓI�ϐ���B��̃A�N�Z�X�o�H���`���Ă��A���̂܂܂ł͂������̃I�u�W�F�N�g�����i�錾�j��
//�錾�Ɠ����̏�������֐��ւ̒l�n���A�I�u�W�F�N�g�̑�������ł��Ă��܂�
//�����ŁA�R���X�g���N�^�A�R�s�[�R���X�g���N�^�A������Z�qoverload��public�ȊO�̈����ɂ���
//
//Singleton* sP1 = Singleton::GetInstance();	//Singleton�I�u�W�F�N�g����
//
//public�ɂ����ꍇ
//�@�������̃I�W�F�N�g�������i�錾�j�ł��Ă��܂�
//Singleton* sXP(new Singleton);

//�A�f�t�H���g�̃R�s�[�R���X�g���N�^���N�����Ă��܂�
//Singleton* sP2 = new Singleton(*sP1);
//Singleton single = *sP2;

//�B�f�t�H���g�̑�����Z�qoverload���N�����Ă��܂�
//Singleton* sP2;
//*sP2 = *sP1;

//�C���̂ق��A��������Singleton�I�u�W�F�N�g��ʂ̃|�C���^�ł��Ǘ������ꍇ�A
//�s�p�ӂɃ|�C���^�̂Q�d����i�G���[�j���s���Ă��܂��\��������
//Singleton* p2;
//p2 = p1;
//delete p1;
//delete p2;

//�y���_�z
//��������Singleton�I�u�W�F�N�g�̉���ꏊ�ɂ��āA�ÓI�ϐ����g���Ă��邪
//proxy�p�^�[���𗬗p�ł���
//�������A��ʂɂ͏W��őΉ�������iSingleton02.cpp�j
//Singlton01(normal-pointer).cpp
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

	static Singleton* incetanceP;			//�B��̃C���X�^���X���Ǘ�����|�C���^

public:
	//�B��̃A�N�Z�X�o�H
	static Singleton* GetInstance()
	{
		//����Singleton�I�u�W�F�N�g����������Ă��Ȃ��ꍇ
		if(incetanceP == 0)
		{
			incetanceP = new Singleton;
		}
		return incetanceP;
	}

	void show(){ cout << "singleton" << endl; }

	~Singleton(){}
};

//static�C���X�^���X�ϐ��̎���
Singleton* Singleton::incetanceP = 0;

//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	Singleton* sP1 = Singleton::GetInstance();		//Singleton�I�u�W�F�N�g����

	//���\�b�h�̌Ăяo�����i�Q�ʂ�j
	sP1->show();						//�@�|�C���^���g���ČĂяo��
	Singleton::GetInstance()->show();	//�A�B��̃A�N�Z�X�o�H����Ăяo��

	delete sP1;

	return 0;
}
