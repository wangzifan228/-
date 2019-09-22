#include<stdio.h>
#include<iostream>
using namespace std;
#include<cmath>
int main()
{
    cout<<"*****************求一元二次方程的根*****************"<<endl;
    /*求一元二次方程的根*/
	int a, b, c;
	float delta, x1, x2;
	cout << "请输入a,b,c的值:" << endl;
	cin >> a >> b >> c;
	delta = b * b - 4 * a*c;
	if (delta < 0)
		cout << "方程无根" << endl;
	else if (delta == 0)
	{
		x1 = -b / (2 * a);
		cout << "方程的根为" << x1 << endl;
	}
	else
	{
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
		cout << "方程的根为" << x1 << "和" << x2 << endl;
	}


	cout<<"*****************求三角形的面积*****************"<<endl;
	/*求三角形的面积*/
	double d,e,f,s,area;
	cout<<"请输入三条边的长度"<<endl;
    cin>>d>>e>>f;
     if(d+e<=f||d+f<=e||e+f<=d)
     cout<<"三条边无法组成三角形"<<endl;
    else
    {
      s=1.0/2*(d+e+f);
      area=sqrt(s*(s-d)*(s-e)*(s-f));
      cout<<"面积为："<<area<<endl;
    }

     cout<<"*****************求某一天是该年的第几周第几天*****************"<<endl;
     /*求某一天是该年的第几周第几天*/

    int year,month,date,leap,days,week = 0;
    cout<<"请输入年份：";
     cin>>year;
     cout<<"请输入月份：";
     cin>>month;
     cout<<"请输入日：";
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
     printf("%4d年%2d月%2d日是这一年的第%d天。\n",year,month,date,days);
     week=days%7+1;
     printf("%4d年%2d月%2d日是这一年的第%d周。\n",year,month,date,week);
	return 0;
}
