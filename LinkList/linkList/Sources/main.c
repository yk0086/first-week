#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("------------------------\n");
    printf("1. ��������.            \n");
    printf("2. ��ӡ����.            \n");
    printf("3. ���������˳�.      \n");
    printf("4. ����Ԫ��.            \n");
    printf("5. ɾ�����.            \n");
    printf("6. ����Ԫ��.            \n");
    printf("7. ��ת����.            \n");
    printf("8. �жϺ����Ƿ�ɻ�.    \n");
    printf("9. ��ӡ�����е�Ԫ��.    \n");
    printf("10.��ż����.            \n");
    printf("------------------------\n");
	//flag�����ж��Ƿ������� 
	//r��ʾreturnֵ 
	int num, flag = 0, r;
	LinkedList L = NULL;
	while(1){
		printf("������ѡ�����:");
		r = scanf("%d",&num);
		if(r == 0){
			printf("�Ƿ�����\n");
			break;
		}
		switch(num)
		{
			case 1 :
				if(InitList(&L)){
					flag = 1;
					int i,NodeNum;
					printf("��������Ҫ�����Ľ����:");
					scanf("%d",&NodeNum);
					LNode *Rear = L;
					LNode *temp;
					ElemType e;
					//��������
					for(i=1;i<=NodeNum;i++){
						printf("�������%d���ڵ������:",i);
						scanf("%d",&e);//printf("%d",e);
						temp =(LNode*)malloc(sizeof(struct LNode));
						temp->data = e;//printf("%d",e);
						temp->next = NULL;
						Rear->next = temp;
						Rear = Rear->next;
					}
					printf("�������\n");
					break;
				}
				break;
			case 2 :
				if(flag)
					TraverseList(L, visit);
				else
					printf("����������,�޷�����\n");
				break;
			case 3 :
				if(flag){
					DestroyList(&L);
					printf("���ٳɹ�\n");
				} 	
				else
					printf("����������,�޷�����\n");
				/*����������������������������ʱ 
				������δ֪����,����������һ�����ٺ��˳�*/
				exit(0);
			//�������в����λ���������� 
			case 4 :
				if(flag){
				int i;
				LNode *Rear = L;
				LNode *temp = (LNode*)malloc(sizeof(struct LNode));
				printf("��������������Ԫ��:"); 
				scanf("%d",&temp->data);
				printf("��������Ҫ���뵽��λ��:");
				scanf("%d",&i);
				//�ҵ����λ�� 
				while(i--) Rear = Rear->next;
				if(InsertList(Rear,temp))
					printf("����ɹ�\n");
				}
				else
					printf("����������,�޷�����\n");
				break;
			/*Ҳ����Щ����,������������˺���Ҫ��*/
			case 5 :
				if(flag){
					int i;
					ElemType e;
					LNode *Rear = L;
					printf("����������ɾ���Ľ��λ��:");
					scanf("%d",&i);
					while(i--) Rear = Rear->next;
					/*ΪɶҪ��ֵ�����e*/
					if(DeleteList(Rear, &e))
						printf("ɾ���ɹ�\n");	
				}
				else
					printf("����������,�޷�����\n");
				break;
			/*ֻ���ҵ�Ԫ�س��ֵĵ�һ��λ��*/
			case 6 :
				if(flag){
					int e;
					printf("���������ҵ���Ԫ��");
					scanf("%d",&e);
					SearchList(L, e);
				}
				else
					printf("����������,�޷�����\n");
				break;
			case 7 :
				if(flag){
					if(ReverseList(&L))
					printf("��ת�ɹ�\n");
				}
				else
					printf("����������,�޷�����\n");
				break;
			/*��ʵ��û����֤��������Ƿ���ȷ*/
			case 8 :
				if(flag){
					if(IsLoopList(L)) printf("����ɻ�\n");
					else printf("�����ɻ�\n"); 
				}
				else
					printf("����������,�޷�����\n");
				printf("�ر�˵��:����������в�û���뵽���ûػ�����,\n���Բ�����ô���ú�����Ӧ������ʾ���ɻ�\n"); 
				break;
			/*����ż�������,��õ�����ƫ�ұߵ�Ԫ��*/
			case 9 :
				if(flag){
					printf("�����е��Ԫ����%d\n",FindMidNode(&L)->data); 
				}
				else
					printf("����������,�޷�����\n");
				break;
			/*Ŀǰ��û�뵽��ô���������ԭ�͵ķ���ֵ*/
			case 10 :
				if(flag){
					if(ReverseEvenList(&L))
						printf("��ż�����ɹ�\n");
					else 
						printf("��ż����ʧ��\n");
				}
				else
					printf("����������,�޷�����\n");
				break;
			default :
				printf("��������,����������\n");
				break; 
		}
	}
	return 0;
}
