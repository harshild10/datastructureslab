#include<stdio.h>


#define size 5
int front = -1;
int rear = -1;

int queue[size];

void enque(int n)
{
	if (front == 0 && rear == size - 1)
	{
		printf("Queue is full");
	}
	else if (front == rear + 1)
	{
		printf("Queue is full");
	}
	else if (front == -1 && rear == -1)
	{
		front++;
		rear++;
		queue[rear] = n;
	}
	else
	{
		rear = (rear + 1) % size;
		queue[rear] = n;
	}

}

int dequeue()
{
	if (front == -1 && rear == -1)
	{
		return -1;
	}
	else
	{
		int ele;
		ele = queue[front];
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front = (front + 1) % size;
		}
		return ele;
	}
}

void display()
{
	if (front == -1 && rear == -1)
	{
		printf("Queue is empty");
	}
	else
	{
		printf("Queue contents : \n");
		if (front <= rear)
		{
			for (int i = front; i <= rear; i++)
			{
				printf("%d\n", queue[i]);
			}
		}
		else
		{
			for (int i = front; i <= size-1; i++)
			{
				printf("%d\n", queue[i]);
			}
			for (int i = 0; i <= rear; i++)
			{
				printf("%d\n", queue[i]);
			}
		}
	}
}

int main()
{
	int option;
    int item;
    do{
        printf("\nCircular Queue\n");
        printf("\n 1. Insert to Queue (EnQueue)");
        printf("\n 2. delete from the Queue (DeQueue)");
        printf("\n 3. Display the content ");
        printf("\n 4. Exit\n");
        printf("Enter the option :");
        scanf_s("%d",&option);
        switch(option)
        {
            case 1:  printf("Enter the element\n");
                     scanf("%d",&item);
                     enque(item);
                     break;
            case 2: item=dequeue();
                    if(item==-1)
                        printf("Queue is empty");
                    else
                    printf("Removed element from the queue %d",item);
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
        }
    } while (option!=4);
	return 0;
}
