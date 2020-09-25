#include<stdio.h>
void push(int stack[],int ele,int *top,int *size)
{
    if(*top==*size-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        (*top)++;
        stack[*top]=ele;
    }
}
int pop(int stack[],int *top,int *size)
{
    if(*top==-1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        int x=stack[*top];
        (*top)--;
        return x;
    }
}
void display(int stack[],int *top,int *size)
{
    int i;
    if(*top==-1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for(i=*top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
int main()
{
    int size=5;
    int top=-1;
    int stack[size];
    int x=1,ele;
    while(x!=0)
    {
        printf("\nEnter 1 for push\n");
        printf("Emter 2 for pop\n");
        printf("Enter 3 for display\n");
        printf("Enter 0 for exit\n");
        scanf("%d",&x);
        if(x==0)
        {
            break;
        }
        if(x==1)
        {
            printf("Enter the element : ");
            scanf("%d",&ele);
            push(stack,ele,&top,&size);
        }
        else if(x==2)
        {
            int popele=pop(stack,&top,&size);
            printf("The element poped out is : %d",popele);
        }
        else if(x==3)
        {
            printf("The stack is : \n");
            display(stack,&top,&size);
        }
    }
    return 0;
}
