#include<stdio.h>
#include<stdlib.h>
struct node;
struct stacks
{
	struct node *ptr ;
	struct stacks *next;
};

struct queue
{
	struct queueNode *ptr;
	struct queueNode *next ;
};
struct queue *queuestart;
struct queue *queueEnd;
struct stacks *stackstart;


void InsertInqueue(struct node*ele )
{
	struct queue *t;
	t= (struct queue*)malloc(sizeof(struct queue));
	t->ptr =ele;
	t->next =NULL;
	if(queuestart==NULL) {
		queuestart= t;
		queueEnd=t;
	}
	else {
		queueEnd->next=t;
		queueEnd=t;
	}
}

struct node *deleteFromqueue()
{
	struct queue *t;
	t=queuestart;
	queuestart=queuestart->next;
	struct node *ele;
	ele = t->ptr;
	free (t);
	return ele;
}

int isqueueEmpty()
{
	return queuestart==NULL;
}
void push(struct node * ele)

{
	struct stacks *t;
	t = (struct stacks*)malloc(sizeof(struct stacks));
	t->ptr = ele;
	t->next = stackstart;
	stackstart=t;
}
struct node *pop()
{	if(stackstart==NULL)return NULL;
	struct stacks *t;
	struct node*ele;
	t=stackstart;
	ele=t->ptr;
	stackstart= stackstart->next;
	free(t);
	return ele;

}

int isempty()
{
	return stackstart==NULL;
}


struct node *elementAtTop()
{
	return stackstart->ptr;
}




struct node {
	int num;
	struct node *left,*right;

};





struct node *start;

int  insertintbst(int num)
{
	struct node *t,*j;

	if(start ==NULL)
	{
		t= (struct node *)malloc(sizeof(struct node ));
		t->num = num;
		t->left = NULL;
		t->right = NULL;
		start = t;
		return 1;
	}
	else
	{
		j= start;
		while (1)
		{
			if(num == j->num)
			{
				return 0;

			}
			else {

				if(num < j->num)
				{
					if(j->left ==NULL)
					{

						t= (struct node *)malloc( sizeof(struct node ));
						t->num = num;
						t->left = NULL;
						t->right = NULL;
						j->left = t;
						//break;
						return 1;

					}
					j= j->left ;
				}
				else
				{
					if(j->right==NULL)
					{

						t= (struct node *)malloc( sizeof(struct node ));
						t->num = num;
						t->left = NULL;
						t->right = NULL;
						j->right = t;
						//  break;
						return 1;
					}

					j=j->right;

				}
			}
		}
	}
}


void  traverseInorderWithoutReccurtion()
{
	if(start ==NULL)
	{	printf("no element in bs t;\n");
		return ;
	}
	printf("----------------------------------------------------------------\n");

	printf(" elements in BST ;\n");
	printf("----------------------------------------------------------------\n");

	struct node *j,*t;
	j= start;

	while (j!=NULL)
	{
		push(j);
		j=j->left;

	}

	while (!isempty())
	{
		t= pop();
		printf("%d\n",t->num);
		if (t->right != NULL) {
			j = t->right;
			while (j != NULL) {
				push(j);
				j = j->left;
			}
		}
	}

	printf("----------------------------------------------------------------\n");
}
int traverseLevelOrderWithoutReccurtion()
{
	int ic,j,x;
	struct node *t;
	if(start==NULL)
	{
		printf("----------------------------------------------------------------\n");

		printf("no element in bst \n");
		printf("----------------------------------------------------------------\n");
		return 0;
	}
	printf("----------------------------------------------------------------\n");

	printf("level order traversal \n");

	printf("----------------------------------------------------------------\n");
	InsertInqueue(start);
	ic=1;
	while(isqueueEmpty()==0)
	{
		j=1;
		x=0;
		for(int j=1; j<=ic; j++)
		{
			t= deleteFromqueue();
			printf("%d\n",t->num);
			if(t->left!=NULL)
			{
				InsertInqueue(t->left);
				x++;
			}
			if(t->right !=NULL)
			{
				InsertInqueue(t->right);
				x++;
			}
		}
		ic=x;
	}
	printf("----------------------------------------------------------------\n\n");
	return 1;
}


int  traversepostorderWithoutReccurtion()
{
	struct node *t;
	t=start;
	if(start ==NULL)
	{
		printf("----------------------------------------------------------------\n");

		printf("no elements in BST \n");
		printf("----------------------------------------------------------------\n");

		return 0;
	}
	printf("----------------------------------------------------------------\n");
	printf("Post order traversal \n");
	while (1)
	{
		while(t!=NULL)
		{
			if(t->right!=NULL)
				push(t->right);
			push(t);
			t= t->left;
		}
		t=pop();
		if(isempty()==0&&t->right!=NULL&& t->right ==elementAtTop())
		{
			pop();
			push(t);
			t=t->right;
		}
		else
		{
			printf("%d\n",t->num);
			t=NULL;
		}
		if(isempty()!=0)break;

	}
	printf("----------------------------------------------------------------\n\n");

}



int  traversepreorderWithoutReccurtion()
{
	if(start==NULL)
	{
		printf("----------------------------------------------------------------\n");

		printf("no element in BST \n");
		printf("----------------------------------------------------------------\n");

		return 0;
	}
	printf("----------------------------------------------------------------\n");

	printf("Pre order without traversal\n");
	printf("----------------------------------------------------------------\n");

	struct node *t ;
	push(start);
	while (isempty()==0)
	{
		t=pop();
		printf("%d\n",t->num);
		if(t->right !=NULL) push(t->right);
		if(t->left!=NULL)  push(t->left);
	}
}

int GetHeightWithoutReccurtion()
{

	int ic,j,x,h;
	struct node *t;
	if(start==NULL)
	{	printf("----------------------------------------------------------------\n");
		printf("no element in BST \n");
		printf("----------------------------------------------------------------\n");

		return 0;

	}
	InsertInqueue(start);
	ic=1;
	h=0;
	while(isqueueEmpty()==0)
	{
		j=1;
		x=0;
		for(int j=1; j<=ic; j++)
		{
			t= deleteFromqueue();

			if(t->left!=NULL)
			{
				InsertInqueue(t->left);
				x++;
			}
			if(t->right !=NULL)
			{
				InsertInqueue(t->right);
				x++;
			}
		}
		ic=x;
		h=h+1;
	}
	printf("----------------------------------------------------------------\n");

	printf("height of tree is %d \n",h);
	printf("----------------------------------------------------------------\n");

}

int searchInBST(int num)
{	struct node *t;
	t=start;
	if(start ==NULL)
	{
		printf("----------------------------------------------------------------\n");

		printf("no element in bst \n");
		printf("----------------------------------------------------------------\n");

		return 0;
	}
	while(t!=NULL)
	{
		if(t->num==num)
		{
			printf("----------------------------------------------------------------\n");

			printf("found\n");
			printf("----------------------------------------------------------------\n");

			return 1;
			break;
		}
		if(num<=t->num)
		{
			t=t->left;

		}
		else
		{
			t=t->right ;
		}

	}
	if(t==NULL)
		printf("----------------------------------------------------------------\n");
	printf("notfoundinbst\n\n");
	printf("----------------------------------------------------------------\n");

	return 0;

}

int	traverseInOrderWithReccurtion(struct node *t)
{
	if(t==NULL)
	{
		return;
	}
	else
	{
		traverseInOrderWithReccurtion(t->left);
		printf("%d\n",t->num);
		traverseInOrderWithReccurtion(t->right);
	}
}


int	traversePostOrderWithReccurtion(struct node *t)
{
	if(t==NULL)
	{
		return;
	}

	else
	{
		traversePostOrderWithReccurtion(t->left);
		traversePostOrderWithReccurtion(t->right);
		printf("%d\n",t->num);
	}
}




int 	traversePreOrderWithReccurtion(struct node *t)
{
	if(t==NULL)
	{
		return;
	}
	else
	{
		printf("%d\n",t->num);
		traversePreOrderWithReccurtion(t->left);
		traversePreOrderWithReccurtion(t->right);
	}
}


int main ()
{
	int num,ch,x;
	start = NULL;
	stackstart = NULL;
	queuestart=NULL;
	queueEnd=NULL;
	while (1)
	{

		printf("1.insert in bst \n");

		printf("2.traverse inorder  without recurtion \n\n");

		printf("3.traverse preorder without reccurtion\n\n");

		printf("4.traverse postorder without reccurtion\n\n");

		printf("5.traverse level orderwitout reccurtion  \n\n");

		printf("6.getHeightOftree without recurtion \n\n");

		printf("7 searchint BST without recurtion \n\n");

		printf("8.traverse inorder  with recurtion \n\n");

		printf("9.traverse Post order with reccurtion\n\n");

		printf("10.traverse pre order with reccurtion\n\n");


		printf("enter your choice \n");
		scanf("%d",&ch);

		if(ch==1)
		{
			printf("enter a no to insert ");
			scanf("%d",&num);
			if(  insertintbst(num))
			{
				printf("----------------------------------------------------------------\n");

				printf("%d inserted \n",num);
				printf("----------------------------------------------------------------\n");
			}
			else
			{
				printf("----------------------------------------------------------------\n");

				printf("no .already exist \n");
				printf("----------------------------------------------------------------\n");

			}
		}
		if(ch==2)
		{
			traverseInorderWithoutReccurtion();
		}

		if(ch==3)
		{
			traversepreorderWithoutReccurtion();
		}


		if(ch==4)
		{
			traversepostorderWithoutReccurtion();

		}

		if(ch==5)
		{
			traverseLevelOrderWithoutReccurtion();
		}
		if(ch==6)
		{
			GetHeightWithoutReccurtion();
		}

		if(ch==7)
		{	printf("enter an element to search in BST ");
			scanf("%d",&x);
			searchInBST(x);
		}
		if(ch==8)
		{
			printf("----------------------------------------------------------------\n");
			printf(" In order traversal with recurtion\n");
			printf("----------------------------------------------------------------\n");
			traverseInOrderWithReccurtion(start);
			printf("----------------------------------------------------------------\n");

		}

		if(ch==9)
		{
			printf("----------------------------------------------------------------\n");
			printf(" Post order traversal with recurtion\n\n");
			printf("----------------------------------------------------------------\n");

			traversePostOrderWithReccurtion(start);
			printf("----------------------------------------------------------------\n");

		}
		if(ch==10)
		{
			printf("----------------------------------------------------------------\n");
        	printf("Pre order traversal with recurtion\n\n");
			printf("----------------------------------------------------------------\n");
			
			traversePreOrderWithReccurtion(start);
			printf("----------------------------------------------------------------\n");
		}
	}
	return 0;
}