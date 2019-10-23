#include <conio.h>
#include <iostream>
#include <iomanip>
using namespace std;

typedef struct
{
    char name[10];
    float score;

}STD;//学生结构体

typedef struct
{
    STD *data;
    int listsize;
    int length;
}SqList;//顺序链表结构体


//菜单栏选择
int menu()
{
    int n;
    while(1)
    {
        system("cls");
        cout<<"***欢迎使用学生信息管理系统***"<<endl;
        cout<<"1.录入学生信息  2.插入学生数据"<<endl;
        cout<<"3.修改学生信息  4.删除学生信息"<<endl;
        cout<<"5.显示学生信息  0.退出"<<endl;
        cout<<"******************************"<<endl;
        cout<<"请选择编号：";
        cin>>n;
        if(n<0||n>5)
            cout<<"选择错误，请重新输入:";
        else
            return n;
    }

}

//初始化
int initList(SqList *L,int max)
{
    L->data = (STD *)malloc(max * sizeof(STD));
    if(L->data==NULL)
    {
        cout<<"error!"<<endl;
        return 0;
    }
    L->listsize=max;
    L->length=0;
    return 1;
}

//插入
int insertList(SqList *L,int i,STD s)
{
    if(i<1 || i>L->length+1)
    {
        cout<<"插入位置错误！"<<endl;
        return 0;
    }
    if(L->length==L->listsize)
    {
        cout<<"容量不够！"<<endl;
        return 0;
    }

    for(int m=L->length;m>i-1;m--)
    {
        L->data[m]=L->data[m-1];
    }
    L->data[i-1]=s;
    L->length++;
    return 1;
}


//更新修改
int updateList(SqList *L,int k,STD s)
{
    if(L->length==0){cout<<"无数据，不可修改!"<<endl;return 0;}
    if(k<1 || k>L->length)
    {
        cout<<"修改位置有误，请重新输入:";
        return 0;
    }
    L->data[k-1]=s;
    return 1;

}


//删除
int deleteList(SqList *L,int k)
{
    if(k<1 || k>L->length){cout<<"删除位置有误，请重新输入:"<<endl;return 0;}
    if(L->length==0){cout<<"无数据，不可删除！"<<endl; return 0;}
    for(int m=k-1;m<L->length-1;m++)
    {
        L->data[m]=L->data[m+1];
    }
    L->length--;
    return 1;
}

int main()
{
    SqList L;
    STD stu;
    //string choise;
    int n,maxSize,k;

    while(1)
    {
        n=menu();
        switch(n)
        {
        case 1:
            cout<<"输入需要创建的学生人数:";
            cin>>maxSize;
            initList(&L,maxSize);

            char judge;
            while(1)
            {
                cout<<"-------------------------"<<endl;
                cout<<"请输入学生姓名和成绩:"<<endl;

                cin>>stu.name>>stu.score;
                //n++;
                insertList(&L,L.length+1,stu);

                cout<<"是否继续输入(y/n):";
                cin>>judge;
                if(judge!='y')
                    break;
            }


            cout<<"按任意键继续:";
            getch();
            break;
        case 2:
            cout<<"输入插入位置：";
            cin>>k;
            cout<<"请输入需插入的学生姓名和成绩:"<<endl;
            cin>>stu.name>>stu.score;
            insertList(&L,k,stu);

            cout<<"按任意键继续:";
            getch();
            break;
        case 3:
            //int k;
            cout <<"请输入需修改的位置:";
            cin>>k;
            cout<<"请输入修改学生信息:"<<endl;
            cin>>stu.name>>stu.score;
            updateList(&L,k,stu);

            cout<<"按任意键继续:";
            getch();
            break;
        case 4:
            cout <<"请输入需删除的位置:";
            cin>>k;
            if(deleteList(&L,k)){cout<<"删除成功!"<<endl;}
            cout<<"按任意键继续:";
            getch();
            break;

        case 5:
            cout<<"学生姓名   学生成绩"<<endl;
            for(int m=0;m<L.length;m++)
            {
                cout<<setw(8)<<setiosflags(ios::left)<<L.data[m].name<<"   "<<L.data[m].score<<endl;
            }
            cout<<"按任意键继续:";
            getch();
            break;
        case 0:
            cout<<"******************************"<<"\n感谢您的使用!\n"<<"******************************"<<endl;
            exit(0);

        }//switch

    }//while

    return 1;

}
