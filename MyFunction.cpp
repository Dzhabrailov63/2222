#include "CMyVector.h"

ostream& operator<< (ostream& out, const CMyVector& v1)
{
	for (int i = 0; i < v1.size(); i++)
		out << v1[i] << " ";
	out << endl;

	return out;
}

CMyVector operator*(float a, CMyVector obj)
{
	CMyVector temp(obj.size());

	for (int i = 0; i < obj.size(); i++)
		temp[i] = obj[i] * a;

	return temp;
}

void filling_vector(const char* str, CMyVector& v)
{
	cout << str << endl;

	for (int i = 0; i < v.size(); i++)
		cin >> v[i];
	while (cin.peek() == ' ') cin.get();
	if (cin.peek() != '\n')
	{
		throw "error operator+ ( )  different size";
	}
}