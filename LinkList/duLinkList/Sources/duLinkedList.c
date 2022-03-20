#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Status InitList_DuL(DuLinkedList *L)
{
	
	DuLNode *temp = (DuLNode*)malloc(sizeof(struct DuLNode));
	temp->next = temp->prior = NULL;
	*L = temp;
}
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	/*遇到头结点说明遍历了一遍*/
	DuLNode *Rear = L->next;
	while(Rear->next!=L){
		visit(Rear->data);
		Rear = Rear->next;
	}
	printf("%d<->%d\n",Rear->data,L->next->data);
}
visit(ElemType e)
{
	printf("%d<->",e);
}
void DestroyList_DuL(DuLinkedList *L)
{
	DuLNode *Rear = (*L)->next;
	DuLNode *temp;
	while(Rear->next!=*L){
		temp = Rear;
		Rear = Rear->next;
		free(temp);
	}
	free(Rear);
}
/*在p点前插入q*/
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
	/*利用能循环一周的特点来到Rear前面*/
	DuLNode *temp = p;
	while(temp->next!=p){
		temp = temp->next;
	}
	InsertAfterList_DuL(temp, q);
	return SUCCESS;
}
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
	DuLNode *temp = p->next;
	q->prior = p;
	q->next = temp;
	p->next = q;
	temp->prior = q;
	return SUCCESS;
}
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
	DuLNode *temp = p->next;
	p->next = p->next->next;
	free(temp);
}
