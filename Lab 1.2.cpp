#include<iostream>

using namespace std;

int variant = 4;

int main() {
	int a = 13, b = 37;
	cout << ~a + variant << " " << ~b + variant << endl;
	cout << (a+variant | b+variant) << endl;
	cout << (a+variant & b+variant) << endl;
	cout << (a+variant ^ b+variant) << endl;
	
	
	int LeftShift = a + variant << 6;
	int RightShift = b + variant >> 9;
	
	
	cout << LeftShift << " " << RightShift << endl;
	
	return 0;
}
