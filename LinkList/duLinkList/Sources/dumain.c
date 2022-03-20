#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	printf("------------------------\n");
    printf("1. 创建链表.            \n");
    printf("2. 打印链表.            \n");
    printf("3. 销毁链表并退出.      \n");
    printf("4. 插入元素.            \n");
    printf("5. 删除结点.            \n");
    printf("------------------------\n");
	//flag用来判断是否有链表 
	int num, flag = 0, r;
	DuLinkedList L = NULL;
	while(1){
		printf("请输入选项:");
		r = scanf("%d",&num);
		if(r == 0){
			printf("非法输入\n");
			break;
		}
		switch(num)
		{
			case 1 :
				if(InitList_DuL(&L)){
					printf("初始化链表成功\n");
					flag = 1;
					int i, NodeNum, e;
					DuLNode *temp, *Rear = L;
					printf("请输入你要构建的结点数:");
					scanf("%d",&NodeNum);
					/*构建链表*/
					for(i=1;i<=NodeNum;i++){
						printf("请输入第%d个节点的数据:",i);
						scanf("%d",&e);
						DuLNode *temp = (DuLNode*)malloc(sizeof(struct DuLNode));
						temp->data = e;
						Rear->next = temp;
						temp->prior = Rear;
						temp->next = NULL;
						Rear = Rear->next;
					}
					//双向链表头结点的前驱指向尾结点,尾结点的后驱指向头结点
					Rear->next = L;
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
				exit(0);
			case 4 :
				if(flag){
					int i,e;
					DuLNode *temp = (DuLNode*)malloc(sizeof(struct DuLNode));
					DuLNode *Rear = L;
					printf("请输入要插入的位置:");
					scanf("%d",&i);
					printf("请输入要插入的元素:");
					scanf("%d",&e);
					temp->data = e;
					/*遍历一次*/
					while(Rear->next!=L&&i--){
						Rear = Rear->next;
					}
					if(Rear->next==L){
						printf("位置输入错误\n");
					}
					else{
						if(InsertBeforeList_DuL(Rear, temp))
							printf("插入成功\n");
					}					
				}
				else
					printf("不存在链表,无法操作\n");
				break;
			case 5 :
				if(flag){
					int i,e;
					DuLNode *Rear = L;
					printf("请输入要删除的位置:");
					scanf("%d",&i);
					while(i--){
						Rear = Rear->next;
					}
					DeleteList_DuL(Rear, &e);
					printf("删除成功\n");
				}
				else
					printf("不存在链表,无法操作\n");
				break;
			default :
				printf("输入有误请重新输入\n");
		}
	}
	return 0;
}
