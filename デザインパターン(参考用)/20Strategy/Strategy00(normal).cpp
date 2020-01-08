//Strategy�inormal�j
//���鏈���̃A���S���Y�������̐헪�P�ʃI�u�W�F�N�g�Ƃ��čl���A�K�v�ɉ����Đ헪�P�ʂŌ�������
//�A���S���Y����if���Ȃǂŕ��򂳂������ɁA�헪�P�ʃI�u�W�F�N�g�Ō�������̂�
//�����⑼�̐헪�̒ǉ����ȒP�ɍs����

//�y�v���O�����z�o�u���\�[�g�헪�A�N�C�b�N�\�[�g�헪�̂����ꂩ��헪�I�u�W�F�N�g�Ƃ��đI������
//���ʐ헪interface���`���A�h���N���X�Ƃ��Ă��ꂼ��̐헪�N���X���`����
//���̂ق��ɁA�I�������헪�I�u�W�F�N�g���Ǘ�����N���X�iSortOperation�j���`����
//�����āA����SortOperation�I�u�W�F�N�g�ŊǗ����Ă���I�������헪�I�u�W�F�N�g�̃\�[�g�������s��
//�헪�I�u�W�F�N�g�P�ʂŃA���S���Y����؂�ւ�����̂ŁA�_��Ń����e�i���X���₷���݌v�ƂȂ�
//
//Strategy00(normal).cpp
//����
//�o�u���\�[�g
//�N�C�b�N�\�[�g

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Strategy��`----------------------------------------------------------
//////////////////////////////////////////////////////////////////
//�\�[�g�헪interface�N���X��`�i���ۃN���X��`�j
class ISortStrategy {
public:
	virtual void sort(vector<int> vIntData) = 0;
};

//////////////////////////////////////////////////////////////////
//�o�u���\�[�g�N���X��`
class BubbleSortStrategy : public ISortStrategy {
public:
	void sort(vector<int> vIntData)
	{
		cout << "�o�u���\�[�g" << endl;
	}
};
//----------------------------------------------------------------
//�N�C�b�N�\�[�g�N���X��`
class QuickSortStrategy : public ISortStrategy {
public:
	void sort(vector<int> vIntData)
	{
		cout << "�N�C�b�N�\�[�g" << endl;
	}
};
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//�\�[�g����N���X��`
class SortOperation {
	ISortStrategy* sortStrategyP;	//�I�����s����\�[�g�헪�I�u�W�F�N�g�Ǘ��|�C���^
	vector<int> vIntData;			//�f�[�^�z��
public:
	SortOperation(ISortStrategy* ssortStrategyP):sortStrategyP(ssortStrategyP){}

	void setData(int data){ vIntData.push_back(data); }
	void sort(){ sortStrategyP->sort(vIntData); }

	~SortOperation()
	{
		vIntData.clear();		//vector�f�[�^�̏���
		delete sortStrategyP;	//�헪�I�u�W�F�N�g�̉��
	}
};
//----------------------------------------------------------------------

///////////////////////////////////////////////////////////////////
int main()
{
	SortOperation* sort1P = new SortOperation(new BubbleSortStrategy());
	SortOperation* sort2P = new SortOperation(new QuickSortStrategy());

	//�o�u���\�[�g�헪
	sort1P->setData(200);
	sort1P->setData(100);
	sort1P->setData(150);
	sort1P->sort();

	//�N�C�b�N�\�[�g�헪
	sort2P->setData(400);
	sort2P->setData(300);
	sort2P->setData(200);
	sort2P->sort();

	delete sort1P;
	delete sort2P;

	return 0;
}
