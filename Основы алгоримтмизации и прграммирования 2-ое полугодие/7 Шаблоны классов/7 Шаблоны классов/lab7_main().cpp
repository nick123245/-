#include "Vector.h"
#include "Time.h"
#include <iostream>
using namespace std;

int main()
{
	//Vector<int>A(5, 0);
	//cin >> A;
	//cout << A << endl;
	//Vector <int>B(10, 1);
	//cout << B << endl;
	//B = A;
	//cout << B << endl;
	//cout << A[2] << endl;
	//cout << "size=" << A() << endl;
	//B = A + 10;
	//cout << B << endl;
	//cout << "////////////////////////////" << endl;
	Time t;
	cin >> t;
	cout << t;
	cout << "////////////////////////////" << endl;
	Time k;
	cout << "k?";
	cin >> k;
	Time p;
	p = t + k;
	cout << p;

	/*Time t;
	cin >> t;
	cout << t;

	Vector<Time>A(5, t);
	cin >> A;
	cout << A << endl;

	Vector<Time>B(10, t);
	cout << B << endl;*/

	/*B = A;
	cout << B << endl;
	cout << A[2] << endl;
	cout << "size=" << A() << endl;*/

	//B = A + t;

	//cout << B << endl;



}