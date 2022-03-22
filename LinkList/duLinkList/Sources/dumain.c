#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	printf("------------------------\n");
    printf("1. ��������.            \n");
    printf("2. ��ӡ����.            \n");
    printf("3. ��������.            \n");
    printf("4. ����Ԫ��(ǰ��).      \n");
    printf("5. ɾ�����.            \n");
    printf("6. �˳�����.            \n");
    printf("7. ����Ԫ��(����).      \n");
    printf("------------------------\n");
	//flag�����ж��Ƿ������� 
	int num, flag = 0, r;
	DuLinkedList L = NULL;
	while(1){
		printf("������ѡ��:");
		switch(GetNumber())
		{
			case 1 :
				if(InitList_DuL(&L)){
					printf("��ʼ������ɹ�\n");
					flag = 1;
					int i, NodeNum, e;
					DuLNode *temp, *Rear = L;
					printf("��������Ҫ�����Ľ����:");
					NodeNum =  GetNumber();
					/*��������*/
					for(i=1;i<=NodeNum;i++){
						printf("�������%d���ڵ������:",i);
						e = GetNumber();
						DuLNode *temp = (DuLNode*)malloc(sizeof(struct DuLNode));
						temp->data = e;
						Rear->next = temp;
						temp->prior = Rear;
						temp->next = NULL;
						Rear = Rear->next;
					}
					//˫������ͷ����ǰ��ָ��β���,β���ĺ���ָ��ͷ���
					Rear->next = NULL;
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
				break;
			case 4 :
				if(flag){
					int i, e, NodeNum;
					DuLNode *Rear = L;
					printf("������Ҫ�����λ��:");
					NodeNum = GetNumber();
					for(i=1; i<NodeNum; i++){
						if(Rear==NULL) break;
						Rear = Rear->next;
					}
					if(Rear){
						//Խ�����������ڴ�,����ᵼ���ڴ�й¶ 
						DuLNode *temp = (DuLNode*)malloc(sizeof(struct DuLNode));
						printf("������Ҫ�����Ԫ��:");
						e = GetNumber();
						temp->data = e;
						if(NodeNum == 1){
							
						}
						if(InsertBeforeList_DuL(Rear, temp))
							printf("�½���Ѿ������ڵ�ǰλ��\n");
						else printf("����ʧ��\n");
					}
					else{
						printf("λ�÷Ƿ�����������\n");
					}
				}
				else
					printf("����������,�޷�����\n");
				break;
			case 5 :
				if(flag){
					int i, e, NodeNum;
					DuLNode *Rear = L;
					printf("������Ҫɾ����λ��:");
					NodeNum = GetNumber();
					for(i=1;i<NodeNum; i++){
						if(Rear==NULL) break;
						Rear = Rear->next;
					}
					if(Rear){
						if(DeleteList_DuL(Rear, &e))
							printf("ɾ���ɹ�\n");
						else printf("�������޷�����ɾ������\n");
					}
					else printf("λ�ô���ɾ��ʧ��\n");
				}
				else
					printf("����������,�޷�����\n");
				break;
			case 6 :
				printf("�����˳�");
				exit(0);
			case 7 :
				if(flag){
					int i, e, NodeNum;
					DuLNode *Rear = L;
					printf("������Ҫ�����λ��:");
					NodeNum = GetNumber();
					for(i=0; i<NodeNum; i++){
						if(Rear==NULL) break;
						Rear = Rear->next;
					}
					if(Rear){
						//Խ�����������ڴ�,����ᵼ���ڴ�й¶ 
						DuLNode *temp = (DuLNode*)malloc(sizeof(struct DuLNode));
						printf("������Ҫ�����Ԫ��:");
						e = GetNumber();
						temp->data = e;
						if (InsertAfterList_DuL(Rear, temp))
							printf("�½���Ѿ������ڵ�ǰλ��֮��\n");
						else printf("����ʧ��\n");
					}
					else{
						printf("λ�÷Ƿ�����������\n");
					}
				}
				else
					printf("����������,�޷�����\n");
				break;
			default :
				printf("������������������\n");
				break;
		}
	}
	return 0;
}
