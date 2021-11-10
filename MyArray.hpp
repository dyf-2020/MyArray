#pragma once
#include<iostream>
using namespace std;


template<typename T>
class MyArray {

private:
	T* pAddress;	//指针指向堆区开辟的数组
	int m_Capacity;	//数组容量 
	int m_Size;		//数组大小
public:


	//构造函数 
	MyArray(int capacity){
		this->m_Capacity = capacity;
		this->pAddress = new T[this->m_Capacity];
		this->m_Size = 0;
	}

	//拷贝构造函数
	MyArray(const MyArray& arr) {
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//重载赋值运算符“="
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


	//析构函数
	~MyArray() {
		if (this->pAddress != nullptr) {
			delete[]this->pAddress;
			this->pAddress = nullptr;
		}
	}

	//尾插法
	void Push_Back(const T& val) {
		if (this->m_Capacity == this->m_Size) {
			cout << "满了" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删法
	void Pop_Back() {
		if (this->m_Size == 0) {
			cout << "空了" << endl;
			return;
		}
		this->m_Size--;
	}


	//通过下标方式访问数组中元素
	T& operator[](int index) {
		return this->pAddress[index];
	}

	//返回数组容量
	int getCapacity() {
		return this->m_Capacity;
	}

	//返回数组大小
	int getSize() {
		return this->m_Size;
	}

};