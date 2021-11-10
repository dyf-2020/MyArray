#pragma once
#include<iostream>
using namespace std;


template<typename T>
class MyArray {

private:
	T* pAddress;	//ָ��ָ��������ٵ�����
	int m_Capacity;	//�������� 
	int m_Size;		//�����С
public:


	//���캯�� 
	MyArray(int capacity){
		this->m_Capacity = capacity;
		this->pAddress = new T[this->m_Capacity];
		this->m_Size = 0;
	}

	//�������캯��
	MyArray(const MyArray& arr) {
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//���ظ�ֵ�������="
	MyArray& operator=(const MyArray& arr) {
		if (this->pAddress != nullptr) {
			delete[]this->pAddress;
			this->pAddress = nullptr;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}


	//��������
	~MyArray() {
		if (this->pAddress != nullptr) {
			delete[]this->pAddress;
			this->pAddress = nullptr;
		}
	}

	//β�巨
	void Push_Back(const T& val) {
		if (this->m_Capacity == this->m_Size) {
			cout << "����" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//βɾ��
	void Pop_Back() {
		if (this->m_Size == 0) {
			cout << "����" << endl;
			return;
		}
		this->m_Size--;
	}


	//ͨ���±귽ʽ����������Ԫ��
	T& operator[](int index) {
		return this->pAddress[index];
	}

	//������������
	int getCapacity() {
		return this->m_Capacity;
	}

	//���������С
	int getSize() {
		return this->m_Size;
	}

};