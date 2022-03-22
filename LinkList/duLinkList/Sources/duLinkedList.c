#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Status InitList_DuL(DuLinkedList *L)
{
	if (*L){
		printf("已经存在空链表\n");
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
		printf("已经销毁或链表为空\n");
	}
	else{
		DuLNode *temp;
		while(Rear){
			temp = Rear;
			Rear = Rear->next;
			free(temp);
		}
		(*L)->next = (*L)->prior = NULL;
		printf("销毁成功\n"); 
	}
}
/*在p点前插入q*/
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{
	DuLNode *temp = p->next;
	if(temp!=NULL){
		p->next = q;
		temp->prior = q;
		q->next = temp;
		//如果是首结点 
		if(p->prior==NULL) q->prior = NULL;
		else q->prior = p;
	}
	//如果插入的位置是尾结点
	else{
		p->next = q;
		q->prior = p;
		q->next = NULL;
	}
	return SUCCESS;
}
/*在p点后插入q*/
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
	DuLNode *temp = p->next;
	if(temp!=NULL){
		p->next = q;
		temp->prior = q;
		q->next = temp;
		//如果是首结点 
		if(p->prior==NULL) q->prior = NULL;
		else q->prior = p;
	}
	//如果插入的位置是尾结点
	else{
		p->next = q;
		q->prior = p;
		q->next = NULL;
	}
	return SUCCESS;
}
//有四种情况:是否位于链表尾部和是否位于链表起始位置 
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
			//刚开始输入的情况处理 
			if(str[i] == '+'||str[i] == '-'){
				if(i==0) continue;
				else flag=0;
			}
			else if(str[i]<'0'||str[i]>'9'){
				flag = 0;
				break;
			}
			//c语言不会检查越界行为,如果你输入超过100个它也不会报错
			//所以要将输入写进循环中保证输入的东西都写在了该写的位置 
			if(i>=10){
				flag = 0;
				break;
			}
		}
		if(flag == 0) printf("输入非法请重新输入:");
		//将输入正确的字符处理为数字 
		else{
			for(i=0, num=0; str[i]!='\0'; i++){
				if(str[0] == '+' || str[0] == '-') continue;
				else{
					num *= 10;
					num += str[i]-48;
				}
			}
			//将变为正数的负数改回 
			if(str[0] == '-') num = -num; 
		}
	}while(flag == 0);
	return num;
}
