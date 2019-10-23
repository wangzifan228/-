
#include <iostream>
#include <math.h>
using namespace std;class triangle
  {
  public:
	  void setA(double x);
	  void setB(double y);
   	  void setC(double z);
	  int getA();
	  int getB();
	  int getC();
	  double perimeter();//计算三角形的周长
      double area();//计算并返回三角形的面积
	  bool istriangle();//判断能否构成三角形
  private:
	  double a,b,c;//三边为私有成员数据
  };
inline void triangle::setA(double x)
{
    a=x;
}
inline void triangle::setB(double y)
{
    b=y;
}
inline void triangle::setC(double z)
{
    c=z;
}
inline int  triangle::getA()
{
  return a;
}
inline int  triangle::getB()
{
  return b;
}
inline int  triangle::getC()
{
  return c;
}

double triangle::perimeter()
{

  return a+b+c;

}
double triangle::area()
{
   	double  n=(a+b+c)/2;
	return sqrt(n*(n-a)*(n-b)*(n-c));
}
bool triangle::istriangle()
{
   if(a+b>=c&&a+c>=b&&b+c>=a)
	  return 1;
  else
	  return 0;

}
int main()
{
	triangle tri1;
	double x,y,z;
	cout<<"请输入三角形的三边：";
	cin>>x>>y>>z;
	tri1.setA(x);
 	tri1.setB(y);
	tri1.setC(z);//为三边初值
	if(tri1.istriangle())//is triangle()返回值为布尔型，用于判断给出的三边是否能构成三角形
	{
     cout<<"能构成三角形"<<endl;
	 cout<<"三条边为："<<tri1.getA()<<','<<tri1.getB()<<','<<tri1.getC()<<endl;

	 cout<<"三角形的周长为:"<<tri1.perimeter()<<'\t'<<"面积为："<<tri1.area()<<endl;
	}
	else
		cout<<"不能构成三角形"<<endl;
	return 0;
}
