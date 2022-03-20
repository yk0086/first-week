#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/*LinkedList *L 是指针的指针*/ 
Status InitList(LinkedList *L)
{
	/*判断头结点是否存在*/
	if(*L){
		printf("已经存在链表\n");
		return ERROR;
	}
	//没搞懂返回类型,为啥生成新节点要返回成败与否 
	LNode *Head = (LinkedList)malloc(sizeof(struct LNode));
	/*如果申请不成功,返回NULL指针*/
	if(Head == NULL){
		printf("初始化失败\n");
		return ERROR;
	}
	printf("初始化链表成功\n");
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
/*在节点p之后插入节点q*/
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
/*没见过的函数指针*/
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
	/*遍历寻找元素e*/
	while(Rear->data != e && Rear){
		Rear = Rear->next;
		i++; 
	}
	/*没找到*/
	if(Rear->data != e) return ERROR;
	else {
		printf("在第%d个位置上\n",i);
		return SUCCESS;
	}
}
Status ReverseList(LinkedList *L)
{
	/*三个指针指向三个结点,前两个负责反转,另一个负责记住下一个结点的位置*/
	LNode *New = (*L)->next;
	LNode *Old = New->next;
	LNode *temp = Old->next;
	while(temp){
		Old->next = New;
		New = Old;
		Old = temp;
		temp = Old->next;
	}
	/*此时最后两个结点并没有反转*/
	Old->next = New;
	/*将第一个结点反向*/
	(*L)->next->next = NULL;
	(*L)->next = Old;
}
Status IsLoopList(LinkedList L)
{
	/*空链表*/
	if (L == NULL) return ERROR;      
    
	LNode *slow = L->next;
    
	/*一个结点也不用继续进行*/
	if (slow == NULL) return ERROR;      
    LNode *fast = slow->next;
    
    /*在遍历过程中如果到头了退出*/
	while (fast != NULL && slow != NULL)
    {         
		if (fast == slow) return SUCCESS;          
		slow = slow->next;
        fast = fast->next;
        /*防止越界*/
        if (fast != NULL)             
        fast = fast->next;     
    }
	return ERROR;
}
LNode* ReverseEvenList(LinkedList *L)
{
	
	/*依旧是三个指针*/
	LNode *New = (*L)->next;
	LNode *Old = New->next;
	LNode *temp = Old->next;
	/*反转后头结点应该指向第二个结点*/
	(*L)->next = (*L)->next->next;
	/*不一样的是移动的位置,所以要防止越界*/
	while(temp && temp->next){
		Old->next = New;
		New->next = temp->next;
		New = temp;
		Old = New->next;
		temp = Old->next;
	}
	Old->next = New;
	New->next = temp->next;
	/*有个警告:不兼容的指针类型*/
	return L;
}
LNode* FindMidNode(LinkedList *L)
{
	LNode *slow = (*L)->next;
	LNode *fast = slow;
    
    /*对下一个结点进行检查是为了防止越界*/
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
