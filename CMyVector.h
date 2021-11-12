#pragma once

#include <iostream>
#include <initializer_list> 

using namespace std;

class CMyVector
{
private:
	int  sz;
	float* m;

public:
	CMyVector();
	CMyVector(int);
	CMyVector(const initializer_list<float>& list);	
	CMyVector(const CMyVector& obj);

	int  size() const;
	void push_back(float v);

	CMyVector operator+(CMyVector& obj);
	CMyVector operator-(CMyVector& obj);	
	CMyVector operator*(CMyVector& obj);
	CMyVector operator*(float a);	
	CMyVector operator/(float  a);
	
	void     operator=(const CMyVector& obj);
	float&   operator [ ](int i) const;

	~CMyVector();	
};




