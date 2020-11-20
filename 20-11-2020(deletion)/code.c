#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;

int length=0;

void insertend(int ele)
{
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        length=1;
    }
    else
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        length++;
    }
    
}


void deletefront()
{
    if(length==0)
    {
        printf("\nList is empty.\n");
    }
    else
    {   struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp=head;
        head=head->next;
        temp->next=NULL;
        length--;
        printf("\nThe element deleted is : %d",temp->data);
    }
}

void deleteend()
{
    if(length==0)
    {
        printf("\nList is empty.\n");
    }
    else
    {   struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        struct node *del;
        del=(struct node*)malloc(sizeof(struct node));
        del=temp->next;
        temp->next=NULL;
        length--;
        printf("\nThe element deleted is : %d",del->data);
    }
}

void deleterandom(int pos)
{
    if(length==0)
        printf("\nList is empty.\n");
    else if(pos==1)
        deletefront();
    else if(pos>=length+1)
        deleteend();
    else
    {   
        struct node *del;
        del=(struct node*)malloc(sizeof(struct node));
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp=head;
        for(int i=1;i<pos-1;i++)
        {
               temp=temp->next;
        }
        del=temp->next;
        temp->next=del->next;
        del->next=NULL;
        length--;
        printf("\nThe element deleted is : %d",del->data);
        
    }
            
}

void display()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    if(temp==NULL)
    {
        printf("\n List is empty \n");
    }
    else
    {
        printf("\nThe contents of the list are :\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
    
}

int main()
{
    int choice,ele,pos;
    char ch;
    do
    {
    printf("\n1. Insert at end \n2. Display  \n3. Delete at front \n4.Delete at end \n5.Delete at random \n6.exit");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter the element to be inserted\n");
                scanf("%d",&ele);
                insertend(ele); 
                break;
        case 2: display();
                break;
        case 3: deletefront(); 
                break;
        case 4: deleteend();
                break;
        case 5: printf("\nEnter the position : ");
                scanf("%d",&pos);
                deleterandom(pos);
                break;
    }
    }while(choice!=6);
    return 0;
}
