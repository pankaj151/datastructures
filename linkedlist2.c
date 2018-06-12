#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node * link;
}node;
typedef node node;
node *head;
int display(node * start){
      node *p;
      p=start;
      if(p==NULL){
          printf("\nThe list is empty:");
          return 0;
      }
      else{
      while(p!=NULL){
          printf("%d",p->data);
          printf("=>");
          p=p->link;
      }
      printf("NULL");
      }
      return 0;
}

// creating the first node on the linked list;
node *cr_list(node * start){
    node *newnode;
    int val;
    printf("\nEnter the value:");
    scanf("%d",&val);
    newnode=(node *)malloc(sizeof(node));
    newnode->data=val;
    newnode->link=start;
    start=newnode;
    return start;
}

//adding the new node at the end of the linked list;
node *add_end(node * start){
    node * newnode,* p;
    int val;
   
    printf("\nEnter the value:");
    scanf("%d",&val);
    newnode=(node *)malloc(sizeof(node));
    newnode->data=val;
    newnode->link=NULL;
    p=start;
    while(p->link!=NULL){
        p=p->link;
}
    p->link=newnode;
    return start;
}

//adding the new node at the begining of the linked list; 
// it will worked ass the creating new node
/*node * add_begin(node * start){
    int val;
    node * newnode;
    printf("\nEnter the data:");
    scanf("%d",&val);
    newnode=(node *)malloc(sizeof(node));
    newnode->data=val;
    newnode->link=start;
    start=newnode;
    return start;
}*/

//adding  the new at the given position;
node *add_pos(node * start,int pos){
    int val,count=2;
    node *newnode,*p;
    p=start;
    while(count<pos){
        p=p->link;
        ++count;
    }
    if(count>pos){
        printf("\nError the given position is not valid");
        return start;
    }
    printf("\nEnter the data:");
    scanf("%d",&val);
    newnode=(node *)malloc(sizeof(node));
    newnode->data=val;
    newnode->link=p->link;
    p->link=newnode;
    return start;
}

//deleting the first node of the linked list;
node * del_fir(node * start){
    node *p;
    if(start==NULL){
        printf("\n ERROR, list is empty;");
    }
    p=start;
    free(p);
    start=start->link;
    return start;
}

//deleting the last node of the linked list;
node * del_last(node * start){
    node * p,*temp;
    p=start;
    if(start==NULL){
        printf("\n ERROR, list is empty;");
    }
    p=start;
    while(p->link->link!=NULL){
        p=p->link;
    }
    temp=p->link;
     free(temp);
    p->link=NULL;
    return start;
}

  //deleting the node of given position;
 node * del_pos(node * start,int pos){
   node *curr,*temp,*prev;
   int i=1,j=1;
 if(start==NULL){
   printf("\n ERROR, list is empty:");
}
   prev=curr=start;
   
  while(i!=pos){
   curr=curr->link;
   i++;
}
  while(j!=pos-1){
   prev=prev->link;
  j++;
}
//printf("curr=%d, prev=%d",curr->data,prev->data);
    prev->link=curr->link;
    free(curr);
  return start;
}
//reversing the single linked list is painfull;
/*node * rev(node * start){
  node *first,*last,*temp;
  last=start;
  while(last!=NULL){
     temp=last->link;
     last->link=NULL;
     first=temp;
 }
   return start;
}*/

int again(){
 printf("\n*****************");
   // printf("\n1).Creating linked list");
   printf("\n0).For exit:");
   printf("\n1).show the linked list:");
   printf("\n2).Creating a linked list");
    printf("\n3).Enter data at the end:");
    printf("\n4).Enter data at the begining:");
    printf("\n5).Enter data at the given position:");
    printf("\n6).Delete the first node:");
    printf("\n7).Delete the last node:");
    printf("\n8).Delete the given node from position:");
     printf("\n*****************");  
}

int main(){	
    int choice,p;
    head=NULL;
    printf("\n*****************");
   // printf("\n1).Creating linked list");
   printf("\n0).For exit:");
   printf("\n1).show the linked list:");
   printf("\n2).Creating a linked list");
    printf("\n3).Enter data at the end:");
    printf("\n4).Enter data at the begining:");
    printf("\n5).Enter data at the given position:");
    printf("\n6).Delete the first node:");
    printf("\n7).Delete the last node:");
    printf("\n8).Delete the given node from position:");
    printf("\n9).Reverse the list.");
     printf("\n*****************");
    while(choice!=0){
        printf("\nEnter your choice:");
        scanf("%d",&choice);
    switch(choice){
        case 0: free(head);
                exit(0);
                break;
        case 1: display(head);
                break;
        case 2: head=cr_list(head);
                break;
        case 3: head=add_end(head);
                break;
        case 4: head=cr_list(head);
                break;
        case 5: printf("\nEnter the position at the list:");
                scanf("%d",&p);
                head=add_pos(head,p);
                break;
        case 6: head=del_fir(head);
                break;
        case 7: head=del_last(head);
                break;
        case 8: printf("\nEnter the position at the list:");
                scanf("%d",&p);
                head=del_pos(head,p);
                break;
        //case 9:  head=rev(head);
          //       break;
        case 10: printf("\nYou choose to show menu again:");
                 again();
                 break;
        default: printf("\nError INvalid input TRY AGAIN:");
                      break;
                      
    } 
}  
}
