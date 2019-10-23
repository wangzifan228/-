
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
	  double perimeter();//���������ε��ܳ�
      double area();//���㲢���������ε����
	  bool istriangle();//�ж��ܷ񹹳�������
  private:
	  double a,b,c;//����Ϊ˽�г�Ա����
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
	cout<<"�����������ε����ߣ�";
	cin>>x>>y>>z;
	tri1.setA(x);
 	tri1.setB(y);
	tri1.setC(z);//Ϊ���߳�ֵ
	if(tri1.istriangle())//is triangle()����ֵΪ�����ͣ������жϸ����������Ƿ��ܹ���������
	{
     cout<<"�ܹ���������"<<endl;
	 cout<<"������Ϊ��"<<tri1.getA()<<','<<tri1.getB()<<','<<tri1.getC()<<endl;

	 cout<<"�����ε��ܳ�Ϊ:"<<tri1.perimeter()<<'\t'<<"���Ϊ��"<<tri1.area()<<endl;
	}
	else
		cout<<"���ܹ���������"<<endl;
	return 0;
}
