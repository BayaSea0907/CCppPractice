//Flyweight�inormal�j
//Flyweight�p�^�[���́A���ʂȃC���X�^���X�𐶐���h���A���L���邱�ƂŃ��\�[�X�𖳑ʂȂ��g��
//���L�ł�����̂͋��L����i�I�u�W�F�N�g�̃������g�p�ʂ�����������j
//Flyweight�p�^�[���𗘗p���邱�ƂŁA�ǂ̃C���X�^���X�������Ă���̂��Ȃǂ��A
//���p��(�Ăяo����)�Ŕc�����Ă����K�v���Ȃ��Ȃ�
//�����̌Ăяo���悩��̗v���ɂ����ʂȂ������邱�Ƃ��\�ƂȂ�
//Flyweight�p�^�[���́A�ЂƂ̃C���X�^���X���e���ŋ��L�ł���̂ŁA
//���L�����C���X�^���X���{���I(intrinsic)�ȏ��݂̂����ꍇ�ɂ̂ݗ��p����ׂ�
//��{���I(extrinsic)�ȏ��́A�ǂ����̒N�����ύX����\���̂�����̂ł���A
//���L����C���X�^���X������ɒN�����ύX���邱�ƂŁA�����������ɉe����^���邱�ƂɂȂ肩�˂Ȃ�

//��j�A���t�@�x�b�g52�i�召26�j��������\�������p���ł́A���͗ʂ������Ă��A
//��������I�u�W�F�N�g�̌���52�ōςނ͂�

//���������I�u�W�F�N�g�p�ɕ����N���X���`����
//�����ɉ����������I�u�W�F�N�g�𐶐����A���ɐ�������Ă���΁A���̕����I�u�W�F�N�g��
//�Ԃ������I�u�W�F�N�g�����N���XCharacterFactory��Flyweight�p�^�[���Ƃ��Ē�`����

//CharacterFactory�N���X�o�R�ŁA�����I�u�W�F�N�g���擾����̂ŁACharacterFactory�N���X��
//�O���[�o���ȏꏊ�ɑ��݂�����ׂ�
//�����ŁAFlyweight�Ƃ��Ă�CharacterFactory�N���X��Singleton�ɂ��Ă��܂��̂���ʓI
//
//Flyweight00(normal).cpp
//����
//�V�K���� �����I�u�W�F�N�g
//X
//�V�K���� �����I�u�W�F�N�g
//G
//�������� �����I�u�W�F�N�g
//X
//�V�K���� �����I�u�W�F�N�g
//a

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//�I�u�W�F�N�g��������------------------------------------------------
//////////////////////////////////////////////////////////////////
//�����N���X
class Character {
	char mozi;		//����
public:
	Character(char cmozi):mozi(cmozi){}
	char getMozi()const{ return mozi; }

	//�֐��I�u�W�F�N�g����Ăяo�����i�K�v�j
	bool operator==(char target){ return mozi == target; }
};
//-----------------------------------------------------------------
////////////////////////////////////////////////////////////////////
//�֐��I�u�W�F�N�g�p�N���X��`�i�T���l�Ɠ��l�v�f���ʁj
//�����̓|�C���^�Ή�
template<class X>
class EqTargetIf
{
	char target;	//�T���l
public:
	EqTargetIf(char ftarget):target(ftarget){}
	bool operator()(X ptr){ return *ptr == target; }
};
//--------------------------------------------------------------------

//Flyweight-----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//�����I�u�W�F�N�g�����t�@�N�g���iSingleton�p�^�[���j
class CharacterFactory {
	vector<Character*> vCharacter;		//�����I�u�W�F�N�g
	//�R�s�[�֎~
	CharacterFactory(){}
	CharacterFactory(const CharacterFactory& rhs){}
	CharacterFactory& operator=(const CharacterFactory& rhs){}
public:
	//�B��̃A�N�Z�X�o�H
	static CharacterFactory* GetInstance()
	{
		static CharacterFactory instance;
		return &instance;
	}

	//���������I�u�W�F�N�g�擾
	Character* GetCharacter(char mozi)
	{
		vector<Character*>::iterator result_itr;	//vector�̌����ʒuiterator�錾

		//�����I�u�W�F�N�g�����ɐ�������Ă邩�ǂ�����vector�T��
		result_itr = find_if(vCharacter.begin(), vCharacter.end(), EqTargetIf<Character*>(mozi));

		int index;		//�����I�u�W�F�N�g��vector�o�^�ʒu�擾�p

		//�܂���������Ă��Ȃ���Ε����I�u�W�F�N�g�����
		if(result_itr == vCharacter.end())
		{
			cout << "�V�K���� �����I�u�W�F�N�g" << endl;
			vCharacter.push_back(new Character(mozi));		//�����I�u�W�F�N�g�����ǉ��o�^

			//�ǉ��o�^�ʒu�擾�ivector�̍Ō�ɒǉ����Ă���̂Łj
			index = (int)(vCharacter.end() - vCharacter.begin());
			index--;
		}
		else
		{
			cout << "�������� �����I�u�W�F�N�g" << endl;
			index = (int)(result_itr - vCharacter.begin());		//�o�^��vector�v�f�ʒu�擾
		}
		return vCharacter[index];		//�����I�u�W�F�N�g�̓o�^�ʒu��߂�
	}

	~CharacterFactory()
	{
		//vector�ɓo�^���������I�u�W�F�N�g�̉��
		for(int i = 0; i < (int)vCharacter.size(); i++)	delete vCharacter[i];
	}
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	CharacterFactory* sP1 = CharacterFactory::GetInstance();	//Singleton�I�u�W�F�N�g����

	//�����I�u�W�F�N�g����
	cout << sP1->GetCharacter('X')->getMozi() << endl;
	cout << sP1->GetCharacter('G')->getMozi() << endl;
	cout << sP1->GetCharacter('X')->getMozi() << endl;
	cout << sP1->GetCharacter('a')->getMozi() << endl;

	return 0;
}
