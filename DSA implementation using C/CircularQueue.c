/* A more easy to understand code and also a menu driven program*/
#include <stdio.h>
#include<stdlib.h>
int head=0,tail=0,size;
void insert(int ar[],int value)         //to insert in the circular queue
{
    if((tail+1)%size==head)
    {
        printf("\nOverflow\n");
        
    }
    else{
       
       tail=(tail+1)%size;
        ar[tail]=value;
    }
}
int removed(int ar[])                   //to delete from the circular queue
{
    if(head==tail)
    {
        
        return -1;
    }
    else{
        head++;
        head=head%size;
        int x= ar[head];
       
        
         
        return x;
    }
}
void display(int ar[])                  //to display the elements of  the circular queue
{
    
    if ((head+1)%size>tail)
    {
        for(int i=0;i<=tail;i++)
        {
            printf("%d ",ar[i]);
        }
        for (int j=(head+1);j<size;j++)
        {
            printf("%d ",ar[j]);
        }
    }
    else{
        for(int i=head+1;i<=tail;i++)
        {
            printf("%d ",ar[i]);
        }
    }
    printf("\n");
}
int main()
{
    
    printf("Enter the size of the array:");
    scanf("%d",&size);
    size++;
    int ar[size];
    while(1)
    {
     int c;
        printf("MAIN MENU:\n");
        printf("1.Insert\n");
        printf("2.Remove\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&c);
        int a,p;
        switch(c)                                       //Menu driven program ...more friendly to the user
        {
            case 1:
            
            printf("Enter the element to be inserted:");
            scanf("%d",&a);
            insert(ar,a);
            break;
            case 2:
            
            p=removed(ar);
            if(p==-1)
            {
                printf("\nQueue Underflow:\n");
            }
            else
            {printf("\nRemoved element: %d\n",p);}
            
            break;
            case 3:
            printf("\nCircular Queue:\n");
            display(ar);
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\nWrong Choice.Enter again.\n");
            break;
        }
    }
    return 0;
}
