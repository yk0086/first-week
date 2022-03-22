#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Status InitList_DuL(DuLinkedList *L)
{
	if (*L){
		printf("�Ѿ����ڿ�����\n");
		return ERROR;
	}
	DuLNode *temp = (DuLNode*)malloc(sizeof(struct DuLNode));
	temp->next = temp->prior = NULL;
	*L = temp;
	return SUCCESS;
}
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	DuLNode *Rear = L;
	printf("NULL<->");
	while(Rear->next){
		Rear = Rear->next;
		visit(Rear->data);
	}
	printf("NULL\n");
	
}
visit(ElemType e)
{
	printf("%d<->",e);
}
void DestroyList_DuL(DuLinkedList *L)
{
	DuLNode *Rear = (*L)->next;
	if(Rear == NULL){
		printf("�Ѿ����ٻ�����Ϊ��\n");
	}
	else{
		DuLNode *temp;
		while(Rear){
			temp = Rear;
			Rear = Rear->next;
			free(temp);
		}
		(*L)->next = (*L)->prior = NULL;
		printf("���ٳɹ�\n"); 
	}
}
/*��p��ǰ����q*/
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
	DuLNode *temp = p->next;
	if(temp!=NULL){
		p->next = q;
		temp->prior = q;
		q->next = temp;
		//������׽�� 
		if(p->prior==NULL) q->prior = NULL;
		else q->prior = p;
	}
	//��������λ����β���
	else{
		p->next = q;
		q->prior = p;
		q->next = NULL;
	}
	return SUCCESS;
}
/*��p������q*/
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
	DuLNode *temp = p->next;
	if(temp!=NULL){
		p->next = q;
		temp->prior = q;
		q->next = temp;
		//������׽�� 
		if(p->prior==NULL) q->prior = NULL;
		else q->prior = p;
	}
	//��������λ����β���
	else{
		p->next = q;
		q->prior = p;
		q->next = NULL;
	}
	return SUCCESS;
}
//���������:�Ƿ�λ������β�����Ƿ�λ��������ʼλ�� 
Status InsertBeforeList()
{
	
}
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
	if(p->next){
		DuLNode *temp = p->next;
		p->next = p->next->next;
		free(temp);
		return SUCCESS;
	}
	else return ERROR;
	
}
int GetNumber()
{
	int i, num, flag;
	char str[100];
	do{
		flag = 1;
		scanf("%s",str);
		
		for(i=0; str[i]!='\0'; i++){
			//�տ�ʼ������������ 
			if(str[i] == '+'||str[i] == '-'){
				if(i==0) continue;
				else flag=0;
			}
			else if(str[i]<'0'||str[i]>'9'){
				flag = 0;
				break;
			}
			//c���Բ�����Խ����Ϊ,��������볬��100����Ҳ���ᱨ��
			//����Ҫ������д��ѭ���б�֤����Ķ�����д���˸�д��λ�� 
			if(i>=10){
				flag = 0;
				break;
			}
		}
		if(flag == 0) printf("����Ƿ�����������:");
		//��������ȷ���ַ�����Ϊ���� 
		else{
			for(i=0, num=0; str[i]!='\0'; i++){
				if(str[0] == '+' || str[0] == '-') continue;
				else{
					num *= 10;
					num += str[i]-48;
				}
			}
			//����Ϊ�����ĸ����Ļ� 
			if(str[0] == '-') num = -num; 
		}
	}while(flag == 0);
	return num;
}
