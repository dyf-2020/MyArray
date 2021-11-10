#include"MyArray.hpp"
#include<iostream>
using namespace std;


void printIntArray(MyArray<int>&arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << endl;
	}
	cout << endl << endl;
}

void test01(){
	MyArray<int>a(5);
	for (int i = 0; i < 5; i++) {
		a.Push_Back(i);
		
	}
	printIntArray(a);
	for (int i = 0; i < 5; i++) {
		a[i] = i * 2;
	}
	a.Pop_Back();
	printIntArray(a);
}

int main() {
	test01();
	system("pause");
	/*MyArray<int>b(2);
	a = b;
	cout << "hhh" << endl;*/
}