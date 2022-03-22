#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	printf("------------------------\n");
    printf("1. 创建链表.            \n");
    printf("2. 打印链表.            \n");
    printf("3. 销毁链表.            \n");
    printf("4. 插入元素(前置).      \n");
    printf("5. 删除结点.            \n");
    printf("6. 退出程序.            \n");
    printf("7. 插入元素(后置).      \n");
    printf("------------------------\n");
	//flag用来判断是否有链表 
	int num, flag = 0, r;
	DuLinkedList L = NULL;
	while(1){
		printf("请输入选项:");
		switch(GetNumber())
		{
			case 1 :
				if(InitList_DuL(&L)){
					printf("初始化链表成功\n");
					flag = 1;
					int i, NodeNum, e;
					DuLNode *temp, *Rear = L;
					printf("请输入你要构建的结点数:");
					NodeNum =  GetNumber();
					/*构建链表*/
					for(i=1;i<=NodeNum;i++){
						printf("请输入第%d个节点的数据:",i);
						e = GetNumber();
						DuLNode *temp = (DuLNode*)malloc(sizeof(struct DuLNode));
						temp->data = e;
						Rear->next = temp;
						temp->prior = Rear;
						temp->next = NULL;
						Rear = Rear->next;
					}
					//双向链表头结点的前驱指向尾结点,尾结点的后驱指向头结点
					Rear->next = NULL;
					L->prior = Rear;
					printf("构建完成\n");
					break;
				}
				break;
			case 2 :
				if(flag)
					TraverseList_DuL(L, visit);
				else
					printf("不存在链表,无法操作\n");
				break;
			/*貌似并没有真正做到free*/
			case 3 :
				if(flag)
					DestroyList_DuL(&L);
				else
					printf("不存在链表,无法操作\n");
				break;
			case 4 :
				if(flag){
					int i, e, NodeNum;
					DuLNode *Rear = L;
					printf("请输入要插入的位置:");
					NodeNum = GetNumber();
					for(i=1; i<NodeNum; i++){
						if(Rear==NULL) break;
						Rear = Rear->next;
					}
					if(Rear){
						//越界则不用申请内存,否则会导致内存泄露 
						DuLNode *temp = (DuLNode*)malloc(sizeof(struct DuLNode));
						printf("请输入要插入的元素:");
						e = GetNumber();
						temp->data = e;
						if(NodeNum == 1){
							
						}
						if(InsertBeforeList_DuL(Rear, temp))
							printf("新结点已经插入在当前位置\n");
						else printf("插入失败\n");
					}
					else{
						printf("位置非法请重新输入\n");
					}
				}
				else
					printf("不存在链表,无法操作\n");
				break;
			case 5 :
				if(flag){
					int i, e, NodeNum;
					DuLNode *Rear = L;
					printf("请输入要删除的位置:");
					NodeNum = GetNumber();
					for(i=1;i<NodeNum; i++){
						if(Rear==NULL) break;
						Rear = Rear->next;
					}
					if(Rear){
						if(DeleteList_DuL(Rear, &e))
							printf("删除成功\n");
						else printf("空链表无法进行删除操作\n");
					}
					else printf("位置错误删除失败\n");
				}
				else
					printf("不存在链表,无法操作\n");
				break;
			case 6 :
				printf("你已退出");
				exit(0);
			case 7 :
				if(flag){
					int i, e, NodeNum;
					DuLNode *Rear = L;
					printf("请输入要插入的位置:");
					NodeNum = GetNumber();
					for(i=0; i<NodeNum; i++){
						if(Rear==NULL) break;
						Rear = Rear->next;
					}
					if(Rear){
						//越界则不用申请内存,否则会导致内存泄露 
						DuLNode *temp = (DuLNode*)malloc(sizeof(struct DuLNode));
						printf("请输入要插入的元素:");
						e = GetNumber();
						temp->data = e;
						if (InsertAfterList_DuL(Rear, temp))
							printf("新结点已经插入在当前位置之后\n");
						else printf("插入失败\n");
					}
					else{
						printf("位置非法请重新输入\n");
					}
				}
				else
					printf("不存在链表,无法操作\n");
				break;
			default :
				printf("输入有误请重新输入\n");
				break;
		}
	}
	return 0;
}
