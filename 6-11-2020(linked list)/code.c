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

void insertfront(int ele)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=head;
    head=temp;
    length++;
}

void insertrandom(int ele,int pos)
{
    if(pos==1)
        insertfront(ele);
    else if(pos>=length)
        insertend(ele);
    else
    {   
        struct node *inst;
        inst=(struct node*)malloc(sizeof(struct node));
        struct node *temp;
        temp=(struct node*)malloc(sizeof(struct node));
        temp=head;
        for(int i=1;i<pos-1;i++)
        {
               temp=temp->next;
        }
        inst->data=ele;
        inst->next=temp->next;
        temp->next=inst;
        length++;
        
    }
            
}

void deleteele(int ele)
{
     struct node *temp,*del;
     temp=(struct node*)malloc(sizeof(struct node));
     del=(struct node*)malloc(sizeof(struct node));
     del=NULL;
     if(head->data==ele)
     {
         del=head;
         head=head->next;
         del->next=NULL;
     }
     else
     {
         temp=head;
         while(temp->next!=NULL)
         {
            if(temp->next->data==ele)
            {
    
                del=temp->next;
                temp->next=del->next;
                del->next=NULL;
                length--;
                break;
            }    
            else
            {
                temp=temp->next;
            }

         }
     }
     if(del==NULL)
     {
         printf("\nElement not found.\n");
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
    printf("\n1. Inset at end \n2.Insert at front \n3.Insert at random position \n4. Display  \n5. Delete  \n6.exit");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter the element to be inserted\n");
                scanf("%d",&ele);
                insertend(ele); 
                break;
        case 2: printf("Enter the element to be inserted\n");
                scanf("%d",&ele);
                insertfront(ele); 
                break;
        case 3: printf("Enter the element to be inserted\n");
                scanf("%d",&ele);
                printf("Enter the position \n");
                scanf("%d",&pos);
                insertrandom(ele,pos);
                break;
        case 4: display();
                break;
        case 5: printf("Enter the element to be deleted\n");
                scanf("%d",&ele);
                deleteele(ele); 
                break;
    }
    }while(choice!=6);
    return 0;
}
