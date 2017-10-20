/*Sample Code for circular queue*/
#include<stdio.h>
#include<string.h>
#define MAX 20
char data[10];
int front1=0,rear1=-1,age,front2=0,rear2=-1;
struct queue{
	char que1[MAX][10];
	int que2[MAX];
	}q;
int enqueue(){
	
	if(rear1>=MAX-1 || rear2>=MAX-1)
	printf("Queue is full\n");
	else{
		printf("Enter the name of the person\n");
		fflush(stdin);
		scanf("%s",data);
		printf("Enter the age of person\n");
		scanf("%d",&q.que2[++rear2]);
		strcpy(q.que1[++rear1],data);
	
		}
		return 0;
	}
int dequeue(){
	if(front1>rear1 || front2 >rear2)
	printf("Queue  is empty\n");
	else{
	front1++;
	printf("The first person moved out is %s\n", q.que1[front1-1]);}
	return 0;
	}
int main(){
	int i=0,j=0,n,counter=0,b;
	do{printf("Enter your choice\n1.Enter the first set of persons\n2.Remove the persons in the queue\n3.Exit\n4. Find the number of adult and children\n");
	scanf("%d",&n);
	switch(n){
		case 1:{
	    while(i<MAX){
		enqueue();
		i++;
		}
		break;}
		case 2:{
		while(j<MAX){
			dequeue();
			j++;
			}
			break;}
		case 3:
			break;
		case 4:{
	    for(b=0;b<MAX;b++){
		if(q.que2[b]>12)
		counter++;
		}
		printf("The number of adult people are\n%d\nThe number of children are\n%d\n",counter,MAX-counter);
	}}
	}
	while(n!=3);
	return 0;
}
