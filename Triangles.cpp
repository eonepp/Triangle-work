#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Factory 
{
protected:
	virtual void CreateObject() {
		return;
	}
	virtual void DeleteObject() {
		return;
	}
	virtual void ShowObject() {
		return;
	}
	virtual void Perimetr() {
		return;
	}
	virtual void Square() {
		return;
	}
	virtual void Intesect() {
		return;
	}
	virtual void PlusVector() 
	{
		return;
	}
};

class T1: protected Factory
{
	vector <int> Triangle;
	string name;
	vector<int> ReturnTriangle()
	{
		return Triangle;
	}
	
public:
	virtual void Intersect(T1 val) {
		vector <int> ac = Triangle;
		vector <int> bc = val.ReturnTriangle();
		bool fl = true;
		int ax1 = ac[0], ay1=ac[1], ax2=ac[2], ay2=ac[3], ax3=ac[4], ay3=ac[5];
		int bx1 = bc[0], by1=bc[1], bx2=bc[2], by2=bc[3], bx3=bc[4], by3= bc[5];
		if ((bx1>ax1 && by1 > ay1) && (bx1 > ax2 && by1 > ay2)&& (bx1 > ax3 && by1 > ay3)) {
			cout << "NOIntersect\n";
			return;
		}
		if (fl = true ) 
		{
			cout << "Intersect\n";
		}
		else{
			cout << "NOIntersect\n";
		}
		
	}
	T1()
	{
		this->Triangle = {0,0, 0,0, 0,0};
		this->name = "no value";
	}
	virtual void CreateObject() 
	{
		cin >> name;
		for (int i = 0; i < Triangle.size(); i++)
		{
			cin >> Triangle[i];
		}
	}
	virtual void DeleteObjecct()
	{
		this->Triangle = { 0,0, 0,0, 0,0 };
		this->name = "no value";
	}
	virtual void ShowObject() 
	{
		cout << name << ' ';
		for (int i = 0; i < Triangle.size(); i++)
		{
			cout << "(" << Triangle.at(i)<<","<<Triangle.at(i+1)<<") ";
			i++;
		}
	}
	virtual void Perimetr()
	{
		double l1 = sqrt(pow(Triangle[0] - Triangle[2], 2) + pow(Triangle[1] - Triangle[3], 2));
		double l2 = sqrt(pow(Triangle[2] - Triangle[4], 2) + pow(Triangle[3] - Triangle[5], 2));
		double l3 = sqrt(pow(Triangle[0] - Triangle[4], 2) + pow(Triangle[1] - Triangle[5], 2));
		cout << "Perimetr= " << l1+l2+l3<<' ';
	}
	virtual void Square()
	{
		double l1 = sqrt(pow(Triangle[0] - Triangle[2], 2) + pow(Triangle[1] - Triangle[3], 2));
		double l2 = sqrt(pow(Triangle[2] - Triangle[4], 2) + pow(Triangle[3] - Triangle[5], 2));
		double l3 = sqrt(pow(Triangle[0] - Triangle[4], 2) + pow(Triangle[1] - Triangle[5], 2));

		double p = (l1 + l2 + l3) / 2;
		double square = sqrt(p*(p-l1)*(p-l2)*(p-l3));

		cout << "Square= " << square<<endl;
	}

	virtual void PlusVector()
	{
		int n, m;
		cin >> n;
		cin >> m;
		for (int i = 0; i < Triangle.size(); i++)
		{
			if (i % 2 == 0) {
				Triangle[i] += n;
			}
			else if (i % 2 == 1) {
				Triangle[i] += m;
			}
		}

	}





};

class T2: protected Factory
{
	vector <int> Rectangle;
	string name;

	vector <int> ReturnRectangle()
	{
		return Rectangle;
	}
public:
	virtual void Intersect(T2 val) {
		vector <int> ac = Rectangle;
		vector <int> bc = val.ReturnRectangle();
		int ax1 = ac[0], ay1 = ac[1], ax2 = ac[2], ay2 = ac[3], ax3 = ac[4], ay3 = ac[5], ax4 = ac[6], ay4 = ac[7];
		int bx1 = bc[0], by1 = bc[1], bx2 = bc[2], by2 = bc[3], bx3 = bc[4], by3 = bc[5], bx4=bc[6], by4=bc[7];
		int k = 0;
		if ((bx1 == ax1 && by1 == ay1) || (bx3>ax1&&by3>ay1))
		{
			cout <<"Intersect\n";
		}
		else
		{
			cout << "NOIntersect\n";

		}
	}
	virtual void PlusVector()
	{
		int q, mum;
		cin >> q;
		cin >> mum;
		for (int i = 0; i < Rectangle.size(); i++)
		{
			if (i % 2 == 0) {
				Rectangle[i] += mum;
			}
			else if (i % 2 == 1) {
				Rectangle[i] += mum;
			}
		}

	}

	T2()
	{
		this->Rectangle = {0,0, 0,0, 0,0, 0,0};
		this->name = "no value";
	}
	virtual void CreateObject()
	{
		cin >> name;
		for (int i = 0; i < Rectangle.size(); i++)
		{
			cin >> Rectangle[i];
		}
	}
	virtual void DeleteObjecct()
	{
		this->Rectangle = {0,0, 0,0, 0,0, 0,0};
		this->name = "no value";
	}
	virtual void ShowObject()
	{
		cout << name << ' ';
		for (int i = 0; i < Rectangle.size(); i++)
		{
			cout << "(" << Rectangle.at(i) << "," << Rectangle.at(i + 1) << ") ";
			i++;
		}
	}
	virtual void Perimetr()
	{
		double l1 = sqrt(pow(Rectangle[0] - Rectangle[2], 2) + pow(Rectangle[1] - Rectangle[3], 2));
		double l2 = sqrt(pow(Rectangle[2] - Rectangle[4], 2) + pow(Rectangle[3] - Rectangle[5], 2));
		cout << "Perimetr= " << l1*2+l2*2<<' ';
	}
	virtual void Square() 
	{
		double l1 = sqrt(pow(Rectangle[0] - Rectangle[2], 2) + pow(Rectangle[1] - Rectangle[3], 2));
		double l2 = sqrt(pow(Rectangle[2] - Rectangle[4], 2) + pow(Rectangle[3] - Rectangle[5], 2));
		cout << "Square= " << l1 * l2 << endl;
	}
};


void Commands(T1 a, T1 b, T2 c, T2 d)
{
	int n;
	bool fl = true;
	while (fl) 
	{
		cin >> n;
		switch (n)
		{
		case 1:
			a.PlusVector();

			a.ShowObject();
			a.Perimetr();
			a.Square();

			b.ShowObject();
			b.Perimetr();
			b.Square();

			a.Intersect(b);
			break;

		case 2:
			b.PlusVector();

			a.ShowObject();
			a.Perimetr();
			a.Square();

			b.ShowObject();
			b.Perimetr();
			b.Square();

			a.Intersect(b);
			break;
		case 3:
			c.PlusVector();

			c.ShowObject();
			c.Perimetr();
			c.Square();
				
			d.ShowObject();
			d.Perimetr();
			d.Square();

			c.Intersect(d);

		case 4:
			d.PlusVector();

			c.ShowObject();
			c.Perimetr();
			c.Square();

			d.ShowObject();
			d.Perimetr();
			d.Square();

			c.Intersect(d);
		case 0:
			fl = false;
		}

	}
	


}



int main(void) 
{
	T1 ObjectFirst;
	ObjectFirst.CreateObject();
	ObjectFirst.ShowObject();
	ObjectFirst.Perimetr();
	ObjectFirst.Square();

	T1 ObjectFirstSec;
	ObjectFirstSec.CreateObject();
	ObjectFirstSec.ShowObject();
	ObjectFirstSec.Perimetr();
	ObjectFirstSec.Square();

	ObjectFirst.Intersect(ObjectFirstSec);

	T2 ObjectSecond;
	ObjectSecond.CreateObject();
	ObjectSecond.ShowObject();
	ObjectSecond.Perimetr();
	ObjectSecond.Square();

	T2 ObjectSecondSec;
	ObjectSecondSec.CreateObject();
	ObjectSecondSec.ShowObject();
	ObjectSecondSec.Perimetr();
	ObjectSecondSec.Square();

	ObjectSecond.Intersect(ObjectSecondSec);

	Commands(ObjectFirst, ObjectFirstSec, ObjectSecond, ObjectSecondSec);


	return 0;
}