#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	printf("------------------------\n");
    printf("1. ��������.            \n");
    printf("2. ��ӡ����.            \n");
    printf("3. ���������˳�.      \n");
    printf("4. ����Ԫ��.            \n");
    printf("5. ɾ�����.            \n");
    printf("------------------------\n");
	//flag�����ж��Ƿ������� 
	int num, flag = 0, r;
	DuLinkedList L = NULL;
	while(1){
		printf("������ѡ��:");
		r = scanf("%d",&num);
		if(r == 0){
			printf("�Ƿ�����\n");
			break;
		}
		switch(num)
		{
			case 1 :
				if(InitList_DuL(&L)){
					printf("��ʼ������ɹ�\n");
					flag = 1;
					int i, NodeNum, e;
					DuLNode *temp, *Rear = L;
					printf("��������Ҫ�����Ľ����:");
					scanf("%d",&NodeNum);
					/*��������*/
					for(i=1;i<=NodeNum;i++){
						printf("�������%d���ڵ������:",i);
						scanf("%d",&e);
						DuLNode *temp = (DuLNode*)malloc(sizeof(struct DuLNode));
						temp->data = e;
						Rear->next = temp;
						temp->prior = Rear;
						temp->next = NULL;
						Rear = Rear->next;
					}
					//˫������ͷ����ǰ��ָ��β���,β���ĺ���ָ��ͷ���
					Rear->next = L;
					L->prior = Rear;
					printf("�������\n");
					break;
				}
				break;
			case 2 :
				if(flag)
					TraverseList_DuL(L, visit);
				else
					printf("����������,�޷�����\n");
				break;
			/*ò�Ʋ�û����������free*/
			case 3 :
				if(flag)
					DestroyList_DuL(&L);
				else
					printf("����������,�޷�����\n");
				exit(0);
			case 4 :
				if(flag){
					int i,e;
					DuLNode *temp = (DuLNode*)malloc(sizeof(struct DuLNode));
					DuLNode *Rear = L;
					printf("������Ҫ�����λ��:");
					scanf("%d",&i);
					printf("������Ҫ�����Ԫ��:");
					scanf("%d",&e);
					temp->data = e;
					/*����һ��*/
					while(Rear->next!=L&&i--){
						Rear = Rear->next;
					}
					if(Rear->next==L){
						printf("λ���������\n");
					}
					else{
						if(InsertBeforeList_DuL(Rear, temp))
							printf("����ɹ�\n");
					}					
				}
				else
					printf("����������,�޷�����\n");
				break;
			case 5 :
				if(flag){
					int i,e;
					DuLNode *Rear = L;
					printf("������Ҫɾ����λ��:");
					scanf("%d",&i);
					while(i--){
						Rear = Rear->next;
					}
					DeleteList_DuL(Rear, &e);
					printf("ɾ���ɹ�\n");
				}
				else
					printf("����������,�޷�����\n");
				break;
			default :
				printf("������������������\n");
		}
	}
	return 0;
}
