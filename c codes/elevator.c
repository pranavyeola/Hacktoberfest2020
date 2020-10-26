#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   struct node *next;
   struct node *prev;
};

//this link always point to first Link
struct node *head = NULL;

//this link always point to last Link
struct node *last = NULL;

struct node *current = NULL;

//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
//   struct node *current;

   for(current = head; current != NULL; current = current->next){
      length++;
   }

   return length;
}

//display the list in from first to last
void displayForward() {

   //start from the beginning
   struct node *ptr = head;

   //navigate till the end of the list
   printf("\n ");

   while(ptr != NULL) {
      printf("%d",ptr->data);
      ptr = ptr->next;
   }


}


//insert link at the last location
void insertLast(int data) {

   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   //link->key = key;
   link->data = data;

   if(isEmpty()) {
      head=link;//make it the last link
      last = link;
   } else {
      //make link a new last link
      last->next = link;

      //mark old last node as prev of new link
      link->prev = last;
   }

   //point last to new last node
   last = link;
}

int elevator(int floor)
{
  int i;
  //struct node*current;
  if(current->data==floor)
    printf("you are already at floor %d",floor);
  else if((current->data)<=floor)
  {
    current=current->next;
    for(i=current->data;i<=floor;i++)
    {
      if(i==floor)
      {
        printf("\n\tYou reached at Floor %d",i);
        return 1;//indicating that elevator is going up;
      }
      else  printf("\n\tGoing up to floor %d",i);
      current=current->next;
    }
  }
else if((current->data)>floor)
  {

    current=current->prev;
    for(i=(current->data);i>=floor;i--)
    {
      if(i==floor)
      {
        printf("\n\t You reached at Floor %d",i);
        return 0;//indicating that elevator is going up;
      }
      else  printf("\n\tGoing down to floor %d",i);
      if((current->data) > (head->data))
        current=(current->prev);
    }
  }

}
void ascsort(int floor[],int inputs)
{
  int i,j,swap;
  for (i = 0 ; i < inputs-1; i++)
  {
    for (j = 0 ;j<inputs-i-1; j++)
    {
      if (floor[j] > floor[j+1]) /* For decreasing order use < */
      {
        swap       = floor[j];
        floor[j]   = floor[j+1];
        floor[j+1] = swap;
      }
    }
  }
}
void descsort(int floor[],int inputs)
{
  int i,j,swap;
  for (i = 0 ; i < inputs-1; i++)
  {
    for (j = 0 ;j<inputs-i-1; j++)
    {
      if (floor[j] < floor[j+1])
      {
        swap       = floor[j];
        floor[j]   = floor[j+1];
        floor[j+1] = swap;
      }
    }
  }
}

void main() {
  int n,k,l,floor[8],inputs,dir,i,j,swap,flag=0,arr[8],brr[8];//people capacity
  char ch;
  printf("\n\t Enter how many floors");
  scanf("%d",&n);
  for(i=0;i<=n;i++)
    insertLast(i);
  displayForward();

  printf("\n\tAt start elevator is at ground Floor");
  do{
    while(1)
    {
      printf("\n\tEnter how many inputs(max capacity is 8)");
      scanf("%d",&inputs);
      if(inputs<=8 && inputs>0)
        break;
    }
    for(i=0;i<inputs;i++)
    {
      while(1)
      {
        printf("Enter input %d",i+1);
        scanf("%d",&floor[i]);
        if(floor[i]<=n && floor[i]>=0)
          break;
      }
    }
    if(flag==0)
    {
      ascsort(floor,inputs);
      current=head;
      for(i=0;i<inputs;i++)
      dir=elevator(floor[i]);
      flag=1;
    }
    else if(flag==1)
    {
      int j=0,l=0;
      if(dir==1)
      {
        for(i=0;i<inputs;i++)
        {
          if(floor[i]>current->data)
          {
            arr[j]=floor[i];
            j++;
          }
          else
          {
            brr[l]=floor[i];
            l++;
          }
        }
        ascsort(arr,j);
        descsort(brr,l);
        for(i=0;i<j;i++)
        {
          dir=elevator(arr[i]);
        }
        for(i=0;i<l;i++)
        {
          dir=elevator(brr[i]);
        }
      }
      else if(dir==0)
      {
        j=0,l=0;
        for(i=0;i<inputs;i++)
        {
          if(floor[i]<current->data)
          {
            arr[j]=floor[i];
            j++;
          }
          else
          {
            brr[l]=floor[i];
            l++;
          }
        }
        descsort(arr,j);
        ascsort(brr,l);
        for(i=0;i<j;i++)
        {
          dir=elevator(arr[i]);
        }
        for(i=0;i<l;i++)
        {
          dir=elevator(brr[i]);
        }
      }
    }
    printf("\n\t Do you want to continue..press(y/n)");
    ch=getchar();
    ch=getchar();
  }while(ch=='y');
}
