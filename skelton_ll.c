#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node
{
    int data;
    struct Node* next;
};
 
//-------------------------------------------------------
 
void push_front(struct Node** pphead, int val)
{
    struct Node *tmp = NULL;
    
    if(*pphead != NULL)
    {
        tmp = (struct Node *)malloc(sizeof(struct Node));
	if(tmp != NULL)
	{
	    tmp->data = val;
	    tmp->next = NULL;

	    tmp->next = *pphead;
	    *pphead     = tmp;
	}
    }
}

void push_back(struct Node** pphead, int val)
{
    struct Node *tmp = NULL, *start = *pphead;
    
    if(start != NULL)
    {
        while(start->next != NULL)
        {
            start = start->next;
        }
        tmp = (struct Node *)malloc(sizeof(struct Node));
	    
	 if(tmp != NULL)
	 {
	    tmp->data = val;
	    tmp->next = NULL;
            
	     while(start->next != NULL)
	     {
		start = start->next;
	     }
	     start->next = tmp;
	 }
    }
}

int pop_front(struct Node** pphead)
{
    int data = 0;
    struct Node  *tmp = NULL;
//    start = *pphead;
    if(*pphead != NULL)
    {
	tmp      = *pphead;
	data     = (*pphead)->data;
	*pphead  = (tmp)->next;
	free(tmp);
    }   
    else
	    printf("invalid:pop_front\n");
    return data;
}

int pop_back(struct Node** pphead)
{
    int data = 0;
    struct Node *pcur = NULL, *pprev = NULL;
    pcur = *pphead;
    while(pcur->next != NULL)
    {
	pprev = pcur;
	pcur  = pcur->next;
    } 
//    printf("pcur:%d\n",pprev->data);
    pprev->next = NULL;
    data = pcur->data;
    free(pcur);

   return data;
}

void insert(struct Node** pphead,int pos,int val) //in middle
{
   struct Node *pcur = NULL, *pprev = NULL;
   pcur = *pphead;

   for(int i=0; pcur && i < pos-1; i++)
   {
           pprev = pcur;
           pcur  = pcur->next;
   }
   struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
   if(tmp != NULL)
   {
	   tmp->data = val;
	   tmp->next = NULL;
            
           pprev->next = tmp;
	   tmp->next   = pcur;
   }
   else
	   printf("not enough memory:\n");
}

void remove_middle(struct Node** pphead,int pos)   //in middle
{
   struct Node *pcur = NULL, *pprev = NULL, *tmp = NULL;
   pcur = *pphead;

   for(int i=0; pcur && i < pos-1; i++)
   {
	   pprev = pcur;
	   pcur  = pcur->next;
   }
 
   tmp = pcur->next;
   pprev->next = tmp;
   free(pcur);

}

void printList(struct Node* phead)
{
   printf("List:");
   while(phead)
   {
	   printf("%d ",phead->data);
	   phead = phead->next;
   }
   printf("\n");
}

int average_of_list_elements(struct Node* phead)
{
    int sum = 0, count = 0;
    while(phead)
    {
	    sum += phead->data;
	    count++;

	    phead = phead->next;
    } 
    return sum/count;
}

int min_of_list_elements(struct Node* phead)
{
    int min = phead->data;
    while(phead)
    {
            if(min > phead->data)
                    min = phead->data;
            phead = phead->next;
    }
    return min; 
}
 
int max_of_list_elements(struct Node* phead)
{
    int max = phead->data;
    while(phead)
    {
	    if(max < phead->data)
		    max = phead->data;
	    phead = phead->next;
    } 
    return max;
}

int count_occurrences(struct Node* phead,int val)
{
    int count = 0;
    while(phead)
    {
	    if(val == phead->data)
		    count++;
	    phead = phead->next;
    }
    return count;
}

/*int count_divisible_by_number(struct Node* phead,int d)
{
   //no.of elements divisible by d
}
*/
int count_divisible_by_number(struct Node* phead,int d)
{
   //no.of elements divisible by d
    int count = 0;
    while(phead)
    {
	    if((phead->data % d) == 0)
		    count++;
	    phead = phead->next;
    }
    return count;
}

int count_greater_than_limit(struct Node* phead,int limit)
{
   //no.of elements greater than limit
     int count = 0;
     while(phead)
     {
	     if(limit < phead->data)
		     count++;
	     phead = phead->next;
     }
     return count;
}

bool search_in_list(struct Node* phead,int val)
{
  //search for val in list
    while(phead)
    {
	if(phead->data == val)
		return true;
	phead = phead->next;
    }
    return false;
}

//-------------------------------------------------------
 
// Do not modify the code in this function

void createAndAppend(struct Node** pphead, int element)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = element;
    new_node->next = NULL;
    if(NULL == *pphead)
    {
        *pphead = new_node;
    }
    else
    {
        struct Node* temp = *pphead;
        while(NULL != temp->next)
            temp = temp->next;
         temp->next = new_node;
    }
}
 
// Do not modify
//the code in this function

int main()
{
    //call list operations
    struct Node *start = NULL;
    int data,choice;
    while(1)
    {
        printf("\n--------------------------------\n=> 1.create node and append:\n");
        printf("=> 2.display\n");
	printf("=> 3.search element in list\n");
	printf("=> 4.to find,No.of elements greater than limit\n");
	printf("=> 5.to find, count divisible by number\n");
	printf("=> 6.no of occurance of element\n");
	printf("=> 7.Max of list elements\n");
	printf("=> 8.Min of list elements\n");
	printf("=> 9.average of list elements\n");
	printf("=> 10.quit:\n");
	printf("=> 11.remove middle element\n");
	printf("=> 12.insert middle\n");
	printf("=> 13.pop back\n");
	printf("=> 14.pop front\n");
	printf("=> 15.push back\n");
	printf("=> 16.push front\n");
        printf("enter choice\n");
        scanf("%d",&choice);
   
	    switch(choice)
	    {
		    case 1:
			    {	
				scanf("%d",&data);
				createAndAppend(&start,data);
			    }
			    break;

		    case 2:{
				printList(start);
			   }
			   break;

		    case 3:
			   {
				int element;
			        printf("enter element to be search\n");
				scanf("%d",&element);
				bool result = search_in_list(start,element);
				result == 1 ? printf("val found\n") : printf("val not found\n"); 
			   }
			   break;

		    case 4:
			   {
				int limit;
				printf("enter the limit, will find greater than this\n");
				scanf("%d",&limit);
				int result = count_greater_than_limit(start,limit);
				if(result == 0)
				    printf("invalid limit\n");
				else
				{
				    printf("no of elemts greater than %d are %d\n",limit,result);
				}
			   }
			   break;
		    case 5: 
			   {
			       int d;
			       printf("enter a number, to find the no of nodes divisible by that number\n");
			       scanf("%d",&d);
		               int result = count_divisible_by_number(start,d);
			       result == 0 ? printf("invalid\n") : printf("no of nodes divisible by %d are %d times\n",d,result);
			   }
			   break;
		    case 6: 
			   {
				  int val;
				  printf("enter val, to find no of occurances\n");
				  scanf("%d",&val);
				  int result =  count_occurrences(start,val);
				  result == 0 ? printf("invalid") : printf("no of occurances of %d are %d",val,result);
			   }
			   break;
		    case 7: 
			   {
				   printf("max is %d\n",max_of_list_elements(start));
			   }
			   break;
		    case 8: 
			   {
				   printf("min is %d\n",min_of_list_elements(start));
			   }
			   break;
		    case 9: 
			   {
				   printf("average of list elements: %d\n",average_of_list_elements(start));
			   }
			   break;
			
		    case 10:exit(0);
		    case 11:
			    {
				    int pos;
				    printf("enter pos\n");
				    scanf("%d",&pos);
				    remove_middle(&start,pos);
			    }
			    break;
		    case 12:
			    {
				    int pos,val;
				    printf("enter pos,val:\n");
				    scanf("%d%d",&pos,&val);
				    insert(&start,pos,val);
			    }
			    break;
		    case 13:
			    {
				    int ret = pop_back(&start);
				    printf("deleted node data:%d\n",ret);
			    }
			    break;
		    case 14:
			    {
		                int ret = pop_front(&start);
				printf("deleted first node data:%d\n",ret);
			    }
			    break;
		    case 15:
			    {
				    int val;
				    printf("enter val, to push pack");
				    scanf("%d",&val);
				    push_back(&start,val);
			    }
			    break;
		    case 16:
			    {
				    int val;
				    printf("enter val, to push front");
				    scanf("%d",&val);
				    push_front(&start,val);
			    }
			    break;
	
		    default:
			    printf("invalid\n");
			    break;
	    }
    }
}
