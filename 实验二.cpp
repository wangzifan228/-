#include<stdio.h>
#include<iostream>
using namespace std;
#include<cmath>
int main()
{
    cout<<"*****************��һԪ���η��̵ĸ�*****************"<<endl;
    /*��һԪ���η��̵ĸ�*/
	int a, b, c;
	float delta, x1, x2;
	cout << "������a,b,c��ֵ:" << endl;
	cin >> a >> b >> c;
	delta = b * b - 4 * a*c;
	if (delta < 0)
		cout << "�����޸�" << endl;
	else if (delta == 0)
	{
		x1 = -b / (2 * a);
		cout << "���̵ĸ�Ϊ" << x1 << endl;
	}
	else
	{
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		cout << "���̵ĸ�Ϊ" << x1 << "��" << x2 << endl;
	}


	cout<<"*****************�������ε����*****************"<<endl;
	/*�������ε����*/
	double d,e,f,s,area;
	cout<<"�����������ߵĳ���"<<endl;
    cin>>d>>e>>f;
     if(d+e<=f||d+f<=e||e+f<=d)
     cout<<"�������޷����������"<<endl;
    else
    {
      s=1.0/2*(d+e+f);
      area=sqrt(s*(s-d)*(s-e)*(s-f));
      cout<<"���Ϊ��"<<area<<endl;
    }

     cout<<"*****************��ĳһ���Ǹ���ĵڼ��ܵڼ���*****************"<<endl;
     /*��ĳһ���Ǹ���ĵڼ��ܵڼ���*/

    int year,month,date,leap,days,week = 0;
    cout<<"��������ݣ�";
     cin>>year;
     cout<<"�������·ݣ�";
     cin>>month;
     cout<<"�������գ�";
     cin>>date;

    leap=(year%4==0&&year%100!=0||year%400==0);
    switch(month)
    {
        case 12:days+=30;
        case 11:days+=31;
        case 10:days+=30;
        case 9:days+=31;
        case 8:days+=31;
        case 7:days+=30;
        case 6:days+=31;
        case 5:days+=30;
        case 4:days+=31;
        case 3:days+=28+leap;
        case 2:days+=31;
        case 1:days+=date;break;
        default:printf("data error");
        break;
    }
     printf("%4d��%2d��%2d������һ��ĵ�%d�졣\n",year,month,date,days);
     week=days%7+1;
     printf("%4d��%2d��%2d������һ��ĵ�%d�ܡ�\n",year,month,date,week);
	return 0;
}
