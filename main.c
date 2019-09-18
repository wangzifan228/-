#define  _CRT_SECURE_NO_WARNINGS

/*************************************************
** ���� : ѧ���ɼ�����ϵͳ
** �汾 : v1.0
** ��Ȩ : GNU General Public License(GNU GPL)
/**************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "score.h"
#include<string.h>

/*----------------------------------*
		Main Function
*-----------------------------------*/

int main()
{

	printf("******************************\n");
	printf("       ѧ���ɼ��������ϵͳ        \n");
	printf("******************************\n\n");

	/*-1.������ʼ��-*/
	int N = 0;            //ѧ������
	SS  *pstu = NULL;    //ѧ������-�ṹ������ָ��ʵ��
	float a = 0;
	float b = 0;
	//2.��ȡѧ����Ϣ
	pstu = readDataFromFile(&N);

	/*-3.����ѧ���ܳɼ����ܳɼ� = 0.3*ƽʱ�ɼ� + 0.8*��ĩ�ɼ�)--*/
	calcuScore(pstu, N);

	/*-4.����ѧ���ɼ�����-*/
	sortScore(pstu, N);

	/*-5.�����������ѧ����Ϣ-*/
	printOut(pstu, N);

	/*-6.����ѧ�Ų�ѯѧ���ɼ�-*/
	searchScore(pstu, N);

	/*-7.ͳ�Ƴɼ���ֵ-*/
	calcuAverage(pstu, N, a);

	/*-8.ͳ�Ƴɼ�����-*/
	calcuVariance(pstu, N, b);

	/*-9.�ͷŶ�̬�ڴ�ռ�-*/
	free(pstu);


	system("pause");
	return 0;
 } 