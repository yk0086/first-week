#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/*LinkedList *L ��ָ���ָ��*/ 
Status InitList(LinkedList *L)
{
	/*�ж�ͷ����Ƿ����*/
	if(*L){
		printf("�Ѿ���������\n");
		return ERROR;
	}
	//û�㶮��������,Ϊɶ�����½ڵ�Ҫ���سɰ���� 
	LNode *Head = (LinkedList)malloc(sizeof(struct LNode));
	/*������벻�ɹ�,����NULLָ��*/
	if(Head == NULL){
		printf("��ʼ��ʧ��\n");
		return ERROR;
	}
	printf("��ʼ������ɹ�\n");
	Head->next = NULL;
	*L = Head;
	return SUCCESS;
}
void DestroyList(LinkedList *L)
{ 
	LNode *temp;
	LNode *Rear = *L;
	while(Rear){
		temp = Rear;
		Rear = Rear->next;
		free(temp);
	}
}
/*�ڽڵ�p֮�����ڵ�q*/
Status InsertList(LNode *p, LNode *q)
{
	LNode *temp = p->next;
	p->next = q;
	q->next = temp;
	return SUCCESS;
}
Status DeleteList(LNode *p, ElemType *e)
{
	LNode *temp = p->next;
	*e = temp->data;
	p->next = temp->next;
	free(temp);
	return SUCCESS;
}
/*û�����ĺ���ָ��*/
void TraverseList(LinkedList L, void (*visit)(ElemType e))
{
	LNode *Rear = L->next;
	while(Rear){
		visit(Rear->data);
		Rear = Rear->next;
	}
	printf("NULL\n");
}
Status SearchList(LinkedList L, ElemType e)
{
	int i = 1;
	LinkedList Rear = L->next;
	/*����Ѱ��Ԫ��e*/
	while(Rear->data != e && Rear){
		Rear = Rear->next;
		i++; 
	}
	/*û�ҵ�*/
	if(Rear->data != e) return ERROR;
	else {
		printf("�ڵ�%d��λ����\n",i);
		return SUCCESS;
	}
}
Status ReverseList(LinkedList *L)
{
	/*����ָ��ָ���������,ǰ��������ת,��һ�������ס��һ������λ��*/
	LNode *New = (*L)->next;
	LNode *Old = New->next;
	LNode *temp = Old->next;
	while(temp){
		Old->next = New;
		New = Old;
		Old = temp;
		temp = Old->next;
	}
	/*��ʱ���������㲢û�з�ת*/
	Old->next = New;
	/*����һ����㷴��*/
	(*L)->next->next = NULL;
	(*L)->next = Old;
}
Status IsLoopList(LinkedList L)
{
	/*������*/
	if (L == NULL) return ERROR;      
    
	LNode *slow = L->next;
    
	/*һ�����Ҳ���ü�������*/
	if (slow == NULL) return ERROR;      
    LNode *fast = slow->next;
    
    /*�ڱ��������������ͷ���˳�*/
	while (fast != NULL && slow != NULL)
    {         
		if (fast == slow) return SUCCESS;          
		slow = slow->next;
        fast = fast->next;
        /*��ֹԽ��*/
        if (fast != NULL)             
        fast = fast->next;     
    }
	return ERROR;
}
LNode* ReverseEvenList(LinkedList *L)
{
	
	/*����������ָ��*/
	LNode *New = (*L)->next;
	LNode *Old = New->next;
	LNode *temp = Old->next;
	/*��ת��ͷ���Ӧ��ָ��ڶ������*/
	(*L)->next = (*L)->next->next;
	/*��һ�������ƶ���λ��,����Ҫ��ֹԽ��*/
	while(temp && temp->next){
		Old->next = New;
		New->next = temp->next;
		New = temp;
		Old = New->next;
		temp = Old->next;
	}
	Old->next = New;
	New->next = temp->next;
	/*�и�����:�����ݵ�ָ������*/
	return L;
}
LNode* FindMidNode(LinkedList *L)
{
	LNode *slow = (*L)->next;
	LNode *fast = slow;
    
    /*����һ�������м����Ϊ�˷�ֹԽ��*/
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
void visit(ElemType e)
{
	printf("%d->",e);
}
