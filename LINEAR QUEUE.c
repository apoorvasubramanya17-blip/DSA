#include<stdio.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;
void insert(){
int item;
if(rear==MAX-1){
    printf("overflow\n");
}
printf("Etner the elemnt to enter:");
scanf("%d",&item);
if(front==-1){
    front=0;
    }
    rear++;
    queue[rear]=item;
    printf("Inserted element %d into the queue",item);
}
void delete(){
int item;
if(front==-1){
        printf("the stack is empty");
   return;
}
item=queue[front];
if(front==rear){
    front=-1;
    rear=-1;
}
else{
    front++;
}printf("Deleted element in %d\n",item);

}
void display(){
int i;
if(front==-1){
    printf("Stack is empty\n");
    return;
}
printf("the stack elements are\n");
for(i=front;i<=rear;i++){
printf("%d",queue[i]);
}
printf("\n");
}
int main(){
int choice;
while(1){
    printf("Enter your choice:");
    printf("1.Insert");
    printf("2.Delete");
    printf("3.Dispaly");
    printf("4.Exit");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
case 1:
    {insert();
    break;}
case 2:
    {delete();
    break;
    }
case 3:
   {display();
    break;}
case 4:
   {printf("Exiting the program...\n");
    return 0;}
default:
    printf("Invalid Choice");
    }
    }
 return 0;
}
