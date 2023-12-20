#include <stdio.h>
#include <stdlib.h>

// Define the struct for intNode
struct intNode {
    int element;
    struct intNode *next;
};

// Function to add a new node with element 'elem' in sorted order
struct intNode *addIntNodeSorted(struct intNode *start, int elem) {
    struct intNode *newNode = (struct intNode *)malloc(sizeof(struct intNode));
    newNode->element = elem;
    newNode->next = NULL;

    if (start == NULL || elem < start->element) {
        newNode->next = start;
        return newNode;
    }

    struct intNode *current = start;
    while (current->next != NULL && elem > current->next->element) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return start;
}

// Function to check if an element is present in the sorted linked list
int isPresentIntNodeSorted(struct intNode *start, int elem) {
    int position = 1;
    struct intNode *current = start;

    while (current != NULL) {
        if (current->element == elem) {
            return position;
        }
        current = current->next;
        position++;
    }
    return 0;
}

// Function to delete a node with the specified element from the sorted linked list
struct intNode *deleteIntNodeSorted(struct intNode *start, int elem) {
    if (start == NULL) {
        return NULL;
    }

    if (start->element == elem) {
        struct intNode *temp = start;
        start = start->next;
        free(temp);
        return start;
    }

    struct intNode *current = start;
    while (current->next != NULL && current->next->element != elem) {
        current = current->next;
    }

    if (current->next != NULL) {
        struct intNode *temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    return start;
}

// Function to print the linked list
void printLL(struct intNode *start) {
    printf("Start -> ");
    struct intNode *current = start;
    while (current != NULL) {
        printf("%d -> ", current->element);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free all nodes of a linked list
struct intNode *freeIntNodeSorted(struct intNode *start) {
    while (start != NULL) {
        struct intNode *temp = start;
        start = start->next;
        free(temp);
    }
    return NULL;
}

// Function to reverse the linked list in descending order
struct intNode *reverseIntNodeSorted(struct intNode *start) {
    struct intNode *prev = NULL;
    struct intNode *current = start;
    struct intNode *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to update each element of the linked list by adding a random value between 0 to 9
void updateIntNode(struct intNode *start) {
    struct intNode *current = start;
    while (current != NULL) {
        int randomValue = rand() % 10;
 ;       current->element += randomValue;
        current = current->next;
    }
}

// Function to sort the linked list back in ascending order without using extra storage
struct intNode *sortIntNode(struct intNode *start) {
    if (start == NULL || start->next == NULL) {
        return start;
    }
    struct intNode *sorted = NULL;
    while (start != NULL) {
        struct intNode *current = start;
        start = start->next;
	if (sorted == NULL || current->element <= sorted->element) {
            current->next = sorted;
            sorted = current;
        } else {
            struct intNode *temp = sorted;
            while (temp->next != NULL && temp->next->element < current->element) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    return sorted;
}

// Function to merge two sorted linked lists and return the merged list
struct intNode *mergeIntNodeSorted(struct intNode *start1, struct intNode *start2) {
    if (start1 == NULL) {
        return start2;
    }
    if (start2 == NULL) {
        return start1;
    }
    struct intNode *merged = NULL;
    if (start1->element <= start2->element) {
        merged = start1;
        start1 = start1->next;
    } else {
        merged = start2;
        start2 = start2->next;
    }
    struct intNode *current = merged;
    while (start1 != NULL && start2 != NULL) {
        if (start1->element <= start2->element) {
            current->next = start1;
            start1 = start1->next;
        } else {
            current->next = start2;
            start2 = start2->next;
        }
        current = current->next;
    }
    if (start1 != NULL) {
        current->next = start1;
    } else {
        current->next = start2;
    }
    return merged;
}

int main(){
    printf("---> we are making two linked list. 1st one for all operation and 2nd one for merging <---\n");	
    int choice;
    struct intNode *s1 = NULL;
    struct intNode *s2 = NULL;
    do{
	    printf("\n");
	    printf("1.Adding element to a linkedlist\n");
	    printf("2.Check whether that element is present in linked list\n");
	    printf("3.Deleting an element in the linkedlist\n");
	    printf("4.Printing the linkedlist\n");
	    printf("5.Free the linkedlist\n");
	    printf("6.Reversing the linkedlist\n");
	    printf("7.Apdating the linkedlist\n");
	    printf("8.Sorting the linkedlist\n");
	    printf("9.Merging the linkedlist");
	    printf("Enter 0 to exit\n");
	    printf("enter your choice: ");
	    scanf("%d",&choice);
	    printf("\n");
	    switch(choice){
		    case 1:{
				   printf("how many elements you want to enter in linkedlist1: ");
				   int n,e;
				   scanf("%d",&n);
				   for(int i=0; i<n; i++)
				   {
					   printf("enter your element: ");
					   scanf("%d",&e);
					   s1=addIntNodeSorted(s1,e);
				   }
				   printf("how many elements in linkedlist2: ");
				   scanf("%d",&n);
				   for(int i=0; i<n; i++){
             printf("enter your element: ");
             scanf("%d",&e);
             s2=addIntNodeSorted(s2,e);
           }
				   break;
			   }
		    case 2:{
				   int e;
				   printf("enter the element you want to find: "); 
				   scanf("%d",&e);
           int position = isPresentIntNodeSorted(s1, e);
           if (position > 0) {
             printf("%d is present at position %d in Linked List 1.\n", e, position);
           } else {
             printf("%d is not present in Linked List 1.\n", e);
           }
				   break;
			   }
         case 3:{
				   int e;
           printf("enter the element you want to delete: ");
           scanf("%d",&e);
				   s1 = deleteIntNodeSorted(s1,e);
			   }
		     case 4:{
				   printf("Linked List 1: ");
           printLL(s1);
           printf("Linked List 2: ");
           printLL(s2);
				   break;
			   }
		    case 5:{
				   printf("1.you want to free linkedlist1\n");
				   printf("2.you want to free linkedlist2\n");
				   printf("Enter your choice:");
				   int choice;
				   scanf("%d",&choice);
				   if(choice==1)
					   s2 = freeIntNodeSorted(s2);
				   if(choice==2)
					   s2 = freeIntNodeSorted(s2);
				   else
					   printf("invalid choice\n");
				   break;
			   }
		    case 6:{
				   s1 = reverseIntNodeSorted(s1);
				   break;
			   }
	       case 7:{
				   updateIntNode(s1);
				   break;
			   }
	       case 8:{
				   s1 = sortIntNode(s1);
				   break;
			   }
		    case 9:{
				   struct intNode *mergedList = mergeIntNodeSorted(s1, s2);
           printf("Merged List: ");
           printLL(mergedList);
				   // Freeing the merged list
           mergedList = freeIntNodeSorted(mergedList);
				   break;
			   }
	    }
    }while(choice!=0);
    return 0;
}
