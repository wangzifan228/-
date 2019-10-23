#include <conio.h>
#include <iostream>
#include <iomanip>
using namespace std;

typedef struct
{
    char name[10];
    float score;

}STD;//ѧ���ṹ��

typedef struct
{
    STD *data;
    int listsize;
    int length;
}SqList;//˳������ṹ��


//�˵���ѡ��
int menu()
{
    int n;
    while(1)
    {
        system("cls");
        cout<<"***��ӭʹ��ѧ����Ϣ����ϵͳ***"<<endl;
        cout<<"1.¼��ѧ����Ϣ  2.����ѧ������"<<endl;
        cout<<"3.�޸�ѧ����Ϣ  4.ɾ��ѧ����Ϣ"<<endl;
        cout<<"5.��ʾѧ����Ϣ  0.�˳�"<<endl;
        cout<<"******************************"<<endl;
        cout<<"��ѡ���ţ�";
        cin>>n;
        if(n<0||n>5)
            cout<<"ѡ���������������:";
        else
            return n;
    }

}

//��ʼ��
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

//����
int insertList(SqList *L,int i,STD s)
{
    if(i<1 || i>L->length+1)
    {
        cout<<"����λ�ô���"<<endl;
        return 0;
    }
    if(L->length==L->listsize)
    {
        cout<<"����������"<<endl;
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


//�����޸�
int updateList(SqList *L,int k,STD s)
{
    if(L->length==0){cout<<"�����ݣ������޸�!"<<endl;return 0;}
    if(k<1 || k>L->length)
    {
        cout<<"�޸�λ����������������:";
        return 0;
    }
    L->data[k-1]=s;
    return 1;

}


//ɾ��
int deleteList(SqList *L,int k)
{
    if(k<1 || k>L->length){cout<<"ɾ��λ����������������:"<<endl;return 0;}
    if(L->length==0){cout<<"�����ݣ�����ɾ����"<<endl; return 0;}
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
            cout<<"������Ҫ������ѧ������:";
            cin>>maxSize;
            initList(&L,maxSize);

            char judge;
            while(1)
            {
                cout<<"-------------------------"<<endl;
                cout<<"������ѧ�������ͳɼ�:"<<endl;

                cin>>stu.name>>stu.score;
                //n++;
                insertList(&L,L.length+1,stu);

                cout<<"�Ƿ��������(y/n):";
                cin>>judge;
                if(judge!='y')
                    break;
            }


            cout<<"�����������:";
            getch();
            break;
        case 2:
            cout<<"�������λ�ã�";
            cin>>k;
            cout<<"������������ѧ�������ͳɼ�:"<<endl;
            cin>>stu.name>>stu.score;
            insertList(&L,k,stu);

            cout<<"�����������:";
            getch();
            break;
        case 3:
            //int k;
            cout <<"���������޸ĵ�λ��:";
            cin>>k;
            cout<<"�������޸�ѧ����Ϣ:"<<endl;
            cin>>stu.name>>stu.score;
            updateList(&L,k,stu);

            cout<<"�����������:";
            getch();
            break;
        case 4:
            cout <<"��������ɾ����λ��:";
            cin>>k;
            if(deleteList(&L,k)){cout<<"ɾ���ɹ�!"<<endl;}
            cout<<"�����������:";
            getch();
            break;

        case 5:
            cout<<"ѧ������   ѧ���ɼ�"<<endl;
            for(int m=0;m<L.length;m++)
            {
                cout<<setw(8)<<setiosflags(ios::left)<<L.data[m].name<<"   "<<L.data[m].score<<endl;
            }
            cout<<"�����������:";
            getch();
            break;
        case 0:
            cout<<"******************************"<<"\n��л����ʹ��!\n"<<"******************************"<<endl;
            exit(0);

        }//switch

    }//while

    return 1;

}
