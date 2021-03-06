/**
 * Huffman�����Գ���
 *
 * @author skywang
 * @date 2014/03/25
 */

/*
* �������� 2021/03/06 �����޷�ͨ������ΪHuffman::create(int[],int)���г�����δ��ʼ���ı���ָ�����parent
*/

#include <iostream>
#include "Huffman.hpp"
using namespace std;


int main()
{
	int a[] = { 5,6,8,7,15 };
	int i, ilen = sizeof(a) / (sizeof(a[0]));
	Huffman<int>* tree = new Huffman<int>();

	cout << "== ��������: ";
	for (i = 0; i < ilen; i++)
		cout << a[i] << " ";

	tree->create(a, ilen);

	cout << "\n== ǰ�����: ";
	tree->preOrder();

	cout << "\n== �������: ";
	tree->inOrder();

	cout << "\n== �������: ";
	tree->postOrder();
	cout << endl;

	cout << "== ������ϸ��Ϣ: " << endl;
	tree->print();

	// ���ٶ�����
	tree->destroy();

	return 0;
}