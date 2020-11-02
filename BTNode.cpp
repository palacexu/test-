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
   b=NULL;				//�����Ķ�������ʼʱΪ��
   ch=str[j];
   while (ch!='\0')  	//strδɨ����ʱѭ��
   {  switch(ch) 
      {
	 	case '(':top++;St[top]=p;k=1; break;    //Ϊ���ӽڵ�
	 	case ')':top--;break;
	 	case ',':k=2; break;  
	 default:p=(BTNode *)malloc(sizeof(BTNode));
	  		 p->data=ch;p->lchild=p->rchild=NULL;
			if (b==NULL)    	//pΪ�������ĸ��ڵ�
	     		b=p;
	 		else    		//�ѽ������������ڵ�
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

void InOrder(BTNode *b)            //���õݹ�ķ���������������� 
 {
	if (b!=NULL)  
    {  
	 InOrder(b->lchild);
	 printf("%c ",b->data);        //���ʸ��ڵ�
	 InOrder(b->rchild);
    }
 }
 
void InOrder1(BTNode *b)           //���÷ǵݹ�ķ���������������� 
{  BTNode *St[MaxSize],*p; 
   int top=-1;
   p=b;
   while (top>-1 || p!=NULL)
   {  while (p!=NULL) 	          //ɨ��*p��������ڵ㲢��ջ
	 { 
	   top++; 
	   St[top]=p;
	   p=p->lchild;
	 }
	 if (top>-1)
	 {
	 	p=St[top];top--;	     	 //��ջ*p�ڵ�
        printf("%c ",p->data); 	     //���ֵ 
	    p=p->rchild;           	     //����������
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
