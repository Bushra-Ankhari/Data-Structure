/*sub:cse202; task 1 student id:1602013*/
/* C++ Program - One Dimensional Array Program */
#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>
#include<stdlib.h>

using namespace std;
void bubble_ascending_Sort(int arr[], int n);
void printArray(int arr[], int n);
void buble_descending_sort(int arr[],int n);
void memory_allocation(int *arr,int n);
void clear_screen(void);
int main()
{



	int *p,*arr, n,insert,pos,cnt=0,num,del,position,item,loc,menu;
	cout<<"Enter the array size: ";
	cin>>n;
	cout<<endl;
arr=new int [n];
	 p=arr;

	cout<<"Please Enter "<<n<<" elements to store in the array : "<<endl<<endl;
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	do{

      cout<<"A menu of list down operations from where user can input desired operation by providing an integer input.";
      cout<<"\n\n";
      cout<<"\t0.Exit"<<endl;
      cout<<"\t1.View all elements"<<endl;
      cout<<"\t2.Insert new element"<<endl;
      cout<<"\t3.Search an element"<<endl;
      cout<<"\t4.Delete an element (user should input item to be searched and delete)"<<endl;
      cout<<"\t5.Sort elements in ascending order"<<endl;
      cout<<"\t6.Sort elements in descending order"<<endl;
      cout<<"\t7.Find memory location of an element (user should input index number)."<<endl<<endl<<endl;

	cout<<"Insert your desired option of menu list:"<<endl<<endl;
	cin>>menu;
	switch(menu){
	    case 0:
	    break;

    case 1:
        for(int i=0;i<n;i++)
        {
        cout<<arr[i]<<"\t";
        }
        clear_screen();
        break;


    case 2:
     cout<<endl<<"enter element to be inserted"<<endl;
     cin>>insert;
     cout<<endl<<"enter position or index for the inserted array:"<<endl;
     cin>>pos;
            // now create a space at the required position
    for(int i=n;i>=pos-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos-1]=insert;
    n=n+1;
    cout<<"Element inserted successfully..!!\n" <<endl<<endl;
    cout<<"Now the new array is : \n"<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
	clear_screen();
	break;



        case 3:
        cout<<"\n Enter Element to be Searched : ";
        cin>>num;
        arr[n]=num;
        pos=0;
        while(arr[pos]!=num)
        {
            pos++;
        }


        if(pos==n)
        {
                cout<<"\n Element Not Found..!!";
        }
        else
        {
                cout<<"\n Element "<<num<<" Found At Position "<<pos+1;
        }
        clear_screen();
        break;

        case 4:
         cout<<"\nEnter the ITEM you want to delete = ";
        cin>>item;

        arr[n+1]=item;

        loc=0;

        while(arr[loc]!=item)
        {
            loc++;
        }

        if(loc==n+1)
        {
            cout<<"Item not found"<<endl;
        }
        else
        {
            for(int i=loc; i<=n-1; i++)
            arr[i]=arr[i+1];
            n=n-1;
        }

        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }


    clear_screen();
    break;

    case 5:
     bubble_ascending_Sort(arr, n);

     clear_screen();
     break;

     case 6:
     buble_descending_sort(arr,n);
     clear_screen();
     break;

     case 7:
    memory_allocation(p,n);
    clear_screen();
    break;

     default:

            cout<<"wrong input.....please enter some valid input"<<endl;
            clear_screen();
            break;

	}
	}while(menu!=0);
	    delete []arr;
    return 0;
}

/* Function to print an array */
void printArray(int arr[], int n)
{


        cout<<"Sort elements in ascending order"<<endl;
     for (int i=0; i <n; i++)
        cout<< arr[i]<<"\t";

}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//  Bubble Sort
void bubble_ascending_Sort(int arr[], int n)
{
   int i, j;
 //  bool swapped;
   for (int i = 0; i < n; i++)
   {
     //swapped = false;
     for (int j = i+1; j < n; j++)
     {
        if (arr[i] > arr[j])
        {
           swap(arr[i], arr[j]);
           //swapped = true;
        }
     }

     // IF no two elements were swapped by inner loop, then break
   //  if (swapped == false)
        //break;
   }
   printArray(arr, n);
}
void buble_descending_sort(int arr[],int n)
{
   int i, j;
 //  bool swapped;
   for (int i = 0; i < n; i++)
   {
     //swapped = false;
     for (int j = i+1; j < n; j++)
     {
        if (arr[i] < arr[j])
        {
           swap(arr[i], arr[j]);
           //swapped = true;
        }
     }

     // IF no two elements were swapped by inner loop, then break
   //  if (swapped == false)
        //break;
   }
   printArray(arr, n);
}
void memory_allocation(int *p,int n){
    int loc,k, x,lower_bound=1;

cout<<"Enter index no:\n";
   cin>>k;
    if(k>n)
    {
   cout<<"The index doesn't exists \n ";

    }
    x=sizeof(int);
    loc=int(p)+x*(k-lower_bound);
    cout<<"The address of the desired index is \n\a"<<loc<<endl;

}
void clear_screen(void)
{
    cout<<"\n\npress any key to clear the screen";
    getch();
    system("cls");
}


