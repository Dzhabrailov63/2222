#include "CMyVector.h"

CMyVector::CMyVector( ) : sz(0), m(0) { }
CMyVector::CMyVector(int n) : sz(n), m(new float[n]) { }
CMyVector::CMyVector(const initializer_list<float>& list) :CMyVector(list.size())
{
	int k = 0;
	for (auto el : list) m[k++] = el;
}
CMyVector::CMyVector(const CMyVector& obj) : CMyVector(obj.sz)
{
	memcpy(m, obj.m, sizeof(float) * sz);
}
CMyVector::~CMyVector()
{
	if (m != 0) delete[] m;
}

void      CMyVector::push_back(float v)
{
	if (m == nullptr)
	{
		m = new float[1]{ v };
		sz = 1;
	}
	else
	{
		float* t = new float[++sz];

		memcpy(t, m, sizeof(float) * (sz - 1));
		t[sz - 1] = v;

		delete[] m;
		m = t;
	}
}
CMyVector CMyVector::operator+(CMyVector& obj)
{
	if (this->sz != obj.sz) throw "error operator+ ( )  different size";

	CMyVector temp(this->sz);

	for (int i = 0; i < this->sz; i++)
		temp.m[i] = this->m[i] + obj.m[i];

	return temp;
}
CMyVector CMyVector::operator-(CMyVector& obj)
{
	if (this->sz != obj.sz) throw "error operator- ( )  different size";

	CMyVector temp(this->sz);

	for (int i = 0; i < this->sz; i++)
		temp.m[i] = this->m[i] - obj.m[i];

	return temp;
}
CMyVector CMyVector::operator*(CMyVector& obj)
{
	if (this->sz != obj.sz) throw "error operator* ( )  different size";

	CMyVector rez(obj.size());
	for (int i = 0; i < this->sz; i++)
		rez[i] = this->m[i] * obj.m[i];

	return rez;
}
CMyVector CMyVector::operator*(float a)
{
	CMyVector temp(this->sz);

	for (int i = 0; i < this->sz; i++)
		temp[i] = this->m[i] * a;

	return temp;
}
CMyVector CMyVector::operator/(float  a)
{
	if (a == 0) throw "error operator/()  division by zero";

	CMyVector temp(this->sz);

	for (int i = 0; i < this->sz; i++)
		temp.m[i] = this->m[i] / a;

	return temp;
}
void      CMyVector::operator=(const CMyVector& obj)
{
	if (this->sz != obj.sz)
	{
		if (m != nullptr) delete[] this->m;

		this->sz = obj.sz;
		this->m = new float[obj.sz];
	}

	for (int i = 0; i < obj.size(); i++)
		this->m[i] = obj.m[i];
}
float&    CMyVector::operator[ ](int i) const
{
	if (i >= this->sz || i < 0) throw "error operator[] going beyond";
	return m[i];
}
int       CMyVector::size() const
{
	return sz;
}