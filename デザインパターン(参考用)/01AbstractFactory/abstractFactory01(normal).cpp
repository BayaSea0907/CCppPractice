//AbstractFactory�i��ʂ̃|�C���^�g�p�j
//�I�u�W�F�N�g�������A�����H��ƂȂ�֐��ōs��
//���i�ƂȂ�N���X�̐������A�\�[�X�R�[�h�̒��ɎU�݂��Ȃ��Ȃ邽�߁A�ύX���e�ՂɂȂ�
//�܂��A�����̍ۂɁA���̏������s�킹�邱�Ƃ��e�ՂɂȂ�i���̃��\�b�h���Ăяo���ď������邱�Ƃ��\�j
//
//�y�d�v�|�C���g�z
//�����u�^�C���v�ł����Ă��Ⴂ�����邪�A���̈Ⴂ�́A���i���쐬����H��̈Ⴂ�ɂ���Đ��܂��ƍl����̂ŁA
//���i�̓����I�ȈႢ���A�O������C�ɂ�����K�v���Ȃ��Ȃ�
//��x�I�u�W�F�N�g�����H�������Ă��܂��΁A��͑S�Ă̑��삪�C���^�t�F�[�X�N���X�o�R�ōs����_�����_
//���ʓI�ɂǂ�ȕ��i������悤�Ƃ��A�������삪�ł���
//�܂��A�P�̍H��ō쐬����镔�i�̃Z�b�g�́A��ɓ������̂Ȃ̂ŁA�����̕��i����ɐ������g�ݍ��킹�Ő����ł���
//
//�y���_�z
//���i��������ƁA�قƂ�ǑS�Ẳӏ��Œǉ���Ƃ��K�v�ɂȂ��Ă��܂�
//�ォ�畔�i��ǉ����邱�Ƃ͗e�Ղł͂Ȃ�
//abstractFactory01(normal).cpp
//����
//�����H��`
//�X���b�N�^�C���i���[�V���O�p�j
//�n�C�I�N
//�����H��a
//�X�^�b�h���X�^�C���i����n�p�j
//�k�o�K�X

#include <iostream>
#include <string>
using namespace std;

//�^�C���N���X----------------------------------------------------------
//�^�C���ɂ́A�X���b�N�^�C���ƃX�^�b�h���X�^�C��������
///////////////////////////////////////////////////////////////////
//�^�C��interface�N���X��`
class ITire
{
public:
	virtual ~ITire(){}
};
//----------------------------------------------------------------
//�X���b�N�^�C���N���X��`
class CTire1 : public ITire
{
public:
	CTire1(){ cout << "�X���b�N�^�C���i���[�V���O�p�j" << endl; }
};
//----------------------------------------------------------------
//�X�^�b�h���X�^�C���N���X��`
class CTire2 : public ITire
{
public:
	CTire2(){ cout << "�X�^�b�h���X�^�C���i����n�p�j" << endl; }
};
//--------------------------------------------------------------------

//�R���N���X----------------------------------------------------------
//�R���ɂ́A�K�\�����Ƃk�o�K�X������
///////////////////////////////////////////////////////////////////
//�R��interface�N���X��`
class IFuel
{
public:
	virtual ~IFuel(){}
};
//----------------------------------------------------------------
//�n�C�I�N�N���X��`
class CFuel1 : public IFuel
{
public:
	CFuel1(){ cout << "�n�C�I�N" << endl; }
};
//----------------------------------------------------------------
//�k�o�K�X�N���X��`
class CFuel2 : public IFuel
{
public:
	CFuel2(){ cout << "�k�o�K�X" << endl; }
};
//--------------------------------------------------------------------

//�I�u�W�F�N�g�����H��N���X------------------------------------------
//�����H��`�A�a�Ƃ��A�P�̍H��Ń^�C���ƔR���𐶐�
///////////////////////////////////////////////////////////////////
//�����H��interface�N���X��`�i����interface�N���X�j
class IFactory{
public:
	virtual ITire* CreateTire() = 0;
	virtual IFuel* CreateFuel() = 0;
	virtual ~IFactory(){}
};
//----------------------------------------------------------------
//�����H��`�N���X��`
//�X���b�N�^�C���ƃn�C�I�N�𐶐�
class CFactoryA : public IFactory{
public:
	ITire* CreateTire(){ return new CTire1(); }		//�X���b�N�^�C��
	IFuel* CreateFuel(){ return new CFuel1(); }		//�n�C�I�N
};
//----------------------------------------------------------------
//�����H��a�N���X��`
//�X�^�b�h���X�^�C���Ƃk�o�K�X�𐶐�
class CFactoryB : public IFactory{
public:
	ITire* CreateTire(){ return new CTire2(); }		//�X�^�b�h���X�^�C��
	IFuel* CreateFuel(){ return new CFuel2(); }		//�k�o�K�X
};
//--------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	IFactory* factoryP;					//�I�u�W�F�N�g�����H��Ǘ��p�|�C���^
	ITire* tireP;						//�^�C���Ǘ��p�|�C���^
	IFuel* fuelP;						//�R���Ǘ��p�|�C���^

	//�����H��`
	cout << "�����H��`" << endl;
	factoryP = new CFactoryA();			//�H��`����
	tireP = factoryP->CreateTire();		//�^�C������
	fuelP = factoryP->CreateFuel();		//�R������

	delete fuelP;
	delete tireP;
	delete factoryP;

	//----------------------------------------------------------
	//�����H��a
	cout << "�����H��a" << endl;
	factoryP = new CFactoryB();			//�H��a����
	tireP = factoryP->CreateTire();		//�^�C������
	fuelP = factoryP->CreateFuel();		//�R������

	delete fuelP;
	delete tireP;
	delete factoryP;

	return 0;
}
