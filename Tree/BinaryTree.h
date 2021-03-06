
//https://www.cnblogs.com/smile233/p/8145760.html
#pragma once

#include <iostream>

template<class T>
struct BiNode
{
	T data;
	BiNode<T> *lchild, *rchild;

};

//����������ʵ��
template<class T>
class BinaryTree
{
public:
	BinaryTree() { root = Create(root); }
	~BinaryTree() { Release(root); }
	void PreOrder() { PreOrder(root); }      // �ݹ�ǰ�����������
	void InOrder() { InOrder(root); }        // �ݹ��������������
	void PostOrder() { PostOrder(root); }    // �ݹ�������������
	//������������Ϊ�˷�װ�ĸ��ã�
	//��һ���������
	void LeverOrder();


private:
	BiNode<T>* root;
	BiNode<T>* Create(BiNode<T>* bt);
	void Release(BiNode<T>* bt);
	void PreOrder(BiNode<T>* bt);           // ǰ�������������
	void InOrder(BiNode<T>* bt);            // ���������������
	void PostOrder(BiNode<T>* bt);          // ���������������


};