/*sub:cse202 task 01;student id:1602013*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void search_element(int*,int*);
void insert_element(int*,int*);
void delete_element(int *, int *);
void buble_ascending_sort(int *, int *);
void memory_allocation(int *, int *);
void clear_screen(void);


int main()
{
    int n,*arr,i,menu,*ptr,y=0;
    printf("Enter the array size : ");
    scanf("%d" ,&n);


    arr=(int *)malloc(n*sizeof(int));


    printf("Please Enter %d elements to store in the array :\n\n",n);
    for(ptr=arr; ptr<arr+n; ptr++)
    {
        scanf("%d", ptr);
    }
    printf("\n\n\n");

    do
    {
        printf("A menu of list down operations from where user can input desired operation by providing an integer input.\n\n");

        printf("\t0.Exit\n");
        printf("\t1.View all items\n");
        printf("\t2.Insert new element\n");
        printf("\t3.Search an element\n");
        printf("\t4.Delete an element\n");
        printf("\t5.Sort elements in ascending order\n");
        printf("\t6.Sort elements in descending order\n");
        printf("\t7.Find memory location of an element (user should input index number).\n\n\n");



        printf("Insert your desired option of menu list:\n\n");

        scanf("%d",&menu);

        switch(menu)
        {
        case 0:
            break;
        case 1:

    printf("\nThe array element:\n");
    for(int j=0; j<n; j++)
    {
        printf("%d\t ",arr[j]);

    }
    printf("\n");
    clear_screen();
            break;
        case 2:
            insert_element(arr,&n);
            clear_screen();
            break;
        case 3:
            search_element(arr,&n);
             clear_screen();
            break;
        case 4:
            delete_element(arr,&n);
            break;
        case 5:
            buble_ascending_sort(arr,&n);
            break;
        case 6:

          for(int j=0;j<n;j++)
          {
              for(int k=0;k<(n-1);k++)
                if((arr[k+1])>arr[k])
              {
                  y=arr[k+1];
                  arr[k+1]=arr[k];
                  arr[k]=y;
              }
          }
          printf("Sorted elements in descending order are :\n");
          for(int k=0;k<n;k++)
          {
              printf("%d ",arr[k]);
          }
            clear_screen();
            break;
        case 7:
            memory_allocation(arr,&n);
            clear_screen();
            break;
        default:
            printf("\nError in input; try again\n");
            clear_screen();

        }
    }while(menu!=0);

    free(arr);


    return 0;

}


void insert_element(int *b, int *n)
{
    int k,item,i,j;
    printf("\nEnter an element: ");
    scanf("%d",&item);
    printf("\nEnter the position you want to insert the element :");
    scanf("%d",&k);

    for(j=*n-1; j>=k-1; j-- )
    {
        *(b+(j+1))=*(b+j);
    }

    *(b+(k-1))=item;
    *n=*n+1;
    printf("The element %d is inserted successfully at position %d:\n",item,k);
    printf("And the array: \n");

    for(i=0; i<*n; i++)
    {
        printf("%d ", *(b+i));

    }
    printf("\n");

}


void search_element(int *b, int *n)
{
    int item,loc;
    printf("Enter the element you want to search = ");
    scanf("%d",&item);

    *(b+*n)=item;

    loc=1;

    while(*(b+loc)!=item)
    {
        loc++;
    }

    if(loc==*n)
    {
        printf("Not found\n");
    }
    else
        printf("The element %d is at location %d\n",item,loc+1);

}


void delete_element(int *b, int  *n)
{

    int ele,loc;
    printf("Enter the element you want to delete = ");
    scanf("%d",&ele);

    *(b+*n)=ele;

    loc=0;

    while(b[loc]!=ele)
    {
        loc++;
    }

    if(loc==*n)
    {
        printf("Element not found!!\n");
    }
    else
    {
        for(int i=loc; i<*n; i++)
            *(b+i)=*(b+(i+1));
        *n=*n-1;

    printf("The element %d is deleted successfully:\n",ele);
    printf("And the new array: \n");

    for(int i=0; i<*n; i++)
    {
        printf("%d ",*(b+i));
    }
    }

    clear_screen();
}


void buble_ascending_sort(int *b, int  *n)
{
    int y,i,j;
    for( i=1; i<*n; i++)
        for( j=0; j<*n-i; j++)
            if(*(b+(j+1))<*(b+j))
            {
                y=*(b+(j+1));
                *(b+(j+1))=*(b+j);
                *(b+j)=y;
            }

    printf("The ascending sorted array is:\n");
    for(int i=0; i<*n; i++)
    {
        printf("%d ",*(b+i));
    }
    printf("\n");
    clear_screen();
}


void memory_allocation(int *b, int *n)
{
    int loc,ind;
    printf("Enter the index number of an element:");
    scanf("%d",&ind);

    loc=(int)b+(sizeof(int)*(ind-1+0));
    printf("The memory allocation of the element %d   is   %d\n\n",*(b+(ind-1)),loc);


}

void clear_screen(void)
{
    printf("\n\npress any key to clear the screen");
    getch();
    system("cls");
}

