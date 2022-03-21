#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("------------------------\n");
    printf("1. 创建链表.            \n");
    printf("2. 打印链表.            \n");
    printf("3. 销毁链表.            \n");
    printf("4. 插入元素.            \n");
    printf("5. 删除结点.            \n");
    printf("6. 查找元素.            \n");
    printf("7. 反转链表.            \n");
    printf("8. 判断函数是否成环.    \n");
    printf("9. 打印链表中点元素.    \n");
    printf("10.积偶调换.            \n");
    printf("11.将链表回环           \n");
    printf("12.退出                 \n");
    printf("------------------------\n");
    printf("请输入序号:");
	//flag用来判断是否有链表 
	//r表示return值 
	int num, flag = 0, r;
	LinkedList L = NULL;
	while(1){
		switch(GetNumber())
		{
			case 1 :
				if(InitList(&L)){
					flag = 1;
					int i,NodeNum;
					printf("请输入你要构建的结点数:");
					NodeNum = GetNumber();
					LNode *Rear = L;
					LNode *temp;
					ElemType e;
					//构建链表
					for(i=1;i<=NodeNum;i++){
						printf("请输入第%d个节点的数据:",i);
						e = GetNumber();//printf("%d",e);
						temp = (LNode*)malloc(sizeof(struct LNode));
						temp->data = e;//printf("%d",e);
						temp->next = NULL;
						Rear->next = temp;
						Rear = Rear->next;
					}
					printf("构建完成\n");
					break;
				}
				break;
			case 2 :
				if(flag)
					TraverseList(L, visit);
				else
					printf("不存在链表,无法操作\n");
				break;
			case 3 :
				if(flag){
					DestroyList(&L);
					printf("销毁成功\n");
				} 	
				else
					printf("不存在链表,无法操作\n");
				break;
			//与设想中插入的位置有所出入 
			case 4 :
				if(flag){
				int i, num;
				LNode *Rear = L;
				LNode *temp = (LNode*)malloc(sizeof(struct LNode));
				printf("请输入你想插入的元素:"); 
				temp->data = GetNumber();
				printf("请输入你要插入到的位置:");
				num = GetNumber();
				//找到这个位置 
				for(i=1; i<num; i++){
					if(Rear == NULL){
						printf("所输入删除位置不存在\n");
						break;
					}
					Rear = Rear->next;
				}
				if(Rear && InsertList(Rear,temp))
					printf("插入成功\n");
				}
				else
					printf("不存在链表,无法操作\n");
				break;
			/*也是有些出入,不过这个符合了函数要求*/
			case 5 :
				if(flag){
					int i, num;
					ElemType e;
					LNode *Rear = L;
					printf("请输入你想删除的结点位置:");
					if(Rear->next == NULL){
						printf("\n链表为空无法进行删除操作\n"); 
					}
					else{
						num = GetNumber();
						for(i=1; i<num; i++){
							if(Rear == NULL){
								printf("所输入删除位置不存在\n");
								break;
							}
							Rear = Rear->next;
						}
						/*为啥要把值分配给e*/
						if(Rear && DeleteList(Rear, &e))
							printf("删除成功\n");
						if(Rear) printf("删除的结点元素为%d\n",e);
					}
				}
				else
					printf("不存在链表,无法操作\n");
				break;
			/*只能找到元素出现的第一个位置*/
			case 6 :
				if(flag){
					int e;
					printf("输入你想找到的元素:");
					e = GetNumber();
					SearchList(L, e);
				}
				else
					printf("不存在链表,无法操作\n");
				break;
			case 7 :
				if(flag){
					if(ReverseList(&L))
					printf("反转成功\n");
				}
				else
					printf("不存在链表,无法操作\n");
				break;
			/*其实并没有验证这个函数是否正确*/
			case 8 :
				if(flag){
					if(IsLoopList(L)) printf("链表成环\n");
					else printf("链表不成环\n"); 
				}
				else
					printf("不存在链表,无法操作\n");
				//printf("特别说明:在这个程序中并没有想到设置回环函数,\n所以不管怎么调用函数都应该是显示不成环\n");
				break;
			/*若是偶数个结点,则得到的是偏右边的元素*/
			case 9 :
				if(flag){
					printf("链表中点的元素是%d\n",FindMidNode(&L)->data); 
				}
				else
					printf("不存在链表,无法操作\n");
				break;
			/*目前还没想到怎么用这个函数原型的返回值*/
			case 10 :
				if(flag){
					if(ReverseEvenList(&L))
						printf("奇偶调换成功\n");
					else 
						printf("奇偶调换失败\n");
				}
				else
					printf("不存在链表,无法操作\n");
				break;
			case 11:
				if(flag){
					if(LoopList(L))
						printf("操作成功\n");
				}
				else
					printf("不存在链表,无法操作\n");
				break;
			case 12 :
				printf("你已退出");
				exit(0);
			default :
				printf("输入有误,请重新输入\n");
				break;
		}
	}
	return 0;
}
