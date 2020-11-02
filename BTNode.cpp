#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef struct node
{
	int data;
	struct node *lchild, *rchild;
}BTNode;
void CreateBTNode(BTNode * &b,char *str)
{  BTNode *St[MaxSize],*p=NULL;
   int top=-1,k,j=0;  
   char ch;
   b=NULL;				//建立的二叉树初始时为空
   ch=str[j];
   while (ch!='\0')  	//str未扫描完时循环
   {  switch(ch) 
      {
	 	case '(':top++;St[top]=p;k=1; break;    //为左孩子节点
	 	case ')':top--;break;
	 	case ',':k=2; break;  
	 default:p=(BTNode *)malloc(sizeof(BTNode));
	  		 p->data=ch;p->lchild=p->rchild=NULL;
			if (b==NULL)    	//p为二叉树的根节点
	     		b=p;
	 		else    		//已建立二叉树根节点
      		{  switch(k) 
          		{
	    			case 1:St[top]->lchild=p;break;
					case 2:St[top]->rchild=p;break;
	      		}
       		}
     }
     j++;ch=str[j];
   }
}

void InOrder(BTNode *b)            //采用递归的方法中序遍历二叉树 
 {
	if (b!=NULL)  
    {  
	 InOrder(b->lchild);
	 printf("%c ",b->data);        //访问根节点
	 InOrder(b->rchild);
    }
 }
 
void InOrder1(BTNode *b)           //采用非递归的方法中序遍历二叉树 
{  BTNode *St[MaxSize],*p; 
   int top=-1;
   p=b;
   while (top>-1 || p!=NULL)
   {  while (p!=NULL) 	          //扫描*p的所有左节点并进栈
	 { 
	   top++; 
	   St[top]=p;
	   p=p->lchild;
	 }
	 if (top>-1)
	 {
	 	p=St[top];top--;	     	 //出栈*p节点
        printf("%c ",p->data); 	     //输出值 
	    p=p->rchild;           	     //处理右子树
	 }  
	}
} 

int main()
{
	BTNode *b;
	b=(BTNode*)malloc(sizeof(BTNode));
	char str[MaxSize]="A(B(,D),C())" ;
	CreateBTNode( b, str);
	InOrder(b);
	printf("\n"); 
	InOrder1(b);
	
 } 
