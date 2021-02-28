//https://blog.csdn.net/fanjiule/article/details/80986659

#pragma once

#include <iostream>
using namespace std;

//һ���ڵ�
template<class T>
struct DNode  //Ϊʲô��д��class ����struct�أ�
{
public:
	T value;
	DNode* prev;
	DNode* next;

	DNode() {};
	DNode(T t, DNode* prev, DNode* next) {
		this->value = t;
		this->prev = prev;
		this->next = next;
	}

};

//˫��������������
template<class T>
class DoubleLink
{
public:
	DoubleLink();
	~DoubleLink();

	int size();
	int is_empty();
	
	T get(int index); //��ȡ�ڵ�
	T get_first();
	T get_last();

	int insert(int index, T t);
	int insert_first(T t);
	int append_last(T t);

	int del(int index);
	int delete_first();
	int delete_last();

private:
	int count;
	DNode<T>* phead;

private:
	DNode<T>* get_node(int index);  //��Щ�趨Ϊprivate�������ǣ� 

};

//����ʵ��
template<class T>
DoubleLink<T>::DoubleLink() : count(0)  //ʹ�ó�ʼ���б��Ĺ��캯����
{
	//������ͷ��ע���ͷû�д洢����
	phead = new DNode<T>();
	phead->prev = phead->next = phead; //�� Ϊʲô����phead
	//������������Ϊ0
	//count=0

}

//��������
template<class T>
DoubleLink<T>::~DoubleLink()
{
	//ɾ�����нڵ�
	DNode<T>* ptemp;
	DNode<T>* pnode = phead->next;

	while (pnode != phead)
	{
		ptemp = pnode;
		pnode = pnode->next;
		delete ptemp; //ɾ����ʱ��ѡ��������˳��ȥɾ������prev���ӹ�����ָ��Ҳ�ᶼû��
	}

	//ɾ����ͷ
	delete phead;
	phead = NULL;
}

//���ؽڵ���Ŀ
template<class T>
int DoubleLink<T>::size()
{
	return count;
}

//���������Ƿ�Ϊ�գ��ǣ��򷵻�1�����򷵻�0
template<class T>
int DoubleLink<T>::is_empty()
{
	return count == 0;

}

//��ȡ��indexλ�õĽڵ�
template<class T>
DNode<T>* DoubleLink<T>::get_node(int index)
{
	//�жϲ�����Ч��
	if (index < 0 || index >= count)
	{
		cout << "get node failed! the index in out of bound!" << endl;
		return NULL;
	}

	//�������
	if (index <= count / 2)
	{
		int i = 0;
		DNode<T>* pindex = phead->next;
		while (i++ < index) {// ��עi++������;����ʱ���Ǳ���index��2������ȥ���飬Ӧ����û�����
			pindex = pindex->next;
		}
		return pindex;
	}

	//�������
	int j = 0;
	int rindex = count - index - 1;
	DNode<T>* prindex = phead->prev; // ���Ʒ��� Ӧ����Ҫ��ָ��ָ��������������һ���ڵ�
	while (j++ < rindex) {
		prindex = prindex->prev; // ?�о�ѭ����ֹ��������
	}

	return prindex;
}

//��ȡ��indexλ�õĽڵ��ֵ
template<class T>
T DoubleLink<T>::get(int index)
{
	return get_node(index)->value;
}

//��ȡ��һ���ڵ��ֵ
template<class T>
T DoubleLink<T>::get_first()
{
	return get_node(0)->value;
}


//��ȡ���һ���ڵ��ֵ
template<class T>
T DoubleLink<T>::get_last()
{
	return get_node(count - 1)->value;
}

//���ڵ���뵽��indexλ��֮ǰ
template<class T>
int DoubleLink<T>::insert(int index, T t)  //�ɹ�ʱ��0��Ϊ����ֵ������
{
	if (index == 0)
		return insert_first(t);

	DNode<T>* pindex = get_node(index);
	DNode<T>* pnode = new DNode<T>(t, pindex->prev, pindex);
	pindex->prev->next = pnode;
	pindex->prev = pnode;

	count++;

	return 0;

}

//���ڵ���뵽��һ���ڵ㴦 (?�Ҿ�����ʵ�����úͲ嵽һ���indexλ�õĺ�������)
template<class T>
int DoubleLink<T>::insert_first(T t)
{
	DNode<T>* pnode = new DNode<T>(t, phead, phead->next);
	phead->next->prev = pnode;
	phead->next = pnode;
	count++;
	return 0;
}


// ���ڵ�׷�ӵ�������ĩβ
template<class T>
int DoubleLink<T>::append_last(T t)
{
	DNode<T>* pnode = new DNode<T>(t, phead->prev, phead);
	phead->prev->next = pnode;
	phead->prev = pnode;
	count++;

	return 0;
}

//ɾ��indexλ�õĽڵ�
template<class T>
int DoubleLink<T>::del(int index)
{
	DNode<T>* pindex = get_node(index);
	pindex->next->prev = pindex->prev;
	pindex->prev->next = pindex->next;

	delete pindex;

	count--;
	return 0;
}



// ɾ����һ���ڵ�
template<class T>
int DoubleLink<T>::delete_first()
{
	return del(0);
}

// ɾ�����һ���ڵ�
template<class T>
int DoubleLink<T>::delete_last()
{
	return del(count - 1);
}
