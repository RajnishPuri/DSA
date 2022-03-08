#include <stdio.h>  
   
//Represent a node of the doubly linked list  
  
struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
};      
   
//Represent the head and tail of the doubly linked list  
struct node *head, *tail = NULL;  
   
//addNode() will add a node to the list  
void addNode(int data) {  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
      
    //If list is empty  
    if(head == NULL) {  
        //Both head and tail will point to newNode  
        head = tail = newNode;  
        //head's previous will point to NULL  
        head->previous = NULL;  
        //tail's next will point to NULL, as it is the last node of the list  
        tail->next = NULL;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newNode;  
        //newNode's previous will point to tail  
        newNode->previous = tail;  
        //newNode will become new tail  
        tail = newNode;  
        //As it is last node, tail's next will point to NULL  
        tail->next = NULL;  
    }  
}  
   
//display() will print out the nodes of the list  
void display() {  
    //Node current will point to head  
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    printf("Nodes of doubly linked list: \n");  
    while(current != NULL) {  
        //Prints each node by incrementing pointer.  
        printf("%d ", current->data);  
        current = current->next;  
    }  
}  
   
int main()  
{  
    //Add nodes to the list  
    addNode(1);  
    addNode(2);  
    addNode(3);  
    addNode(4);  
    addNode(5);  
      
    //Displays the nodes present in the list  
    display();  
   
    return 0;  
    }  
// Output:

// Nodes of doubly linked list: 
// 1 2 3 4 5
// JAVA
// public class DoublyLinkedList {  
      
//     //Represent a node of the doubly linked list  
  
//     class Node{  
//         int data;  
//         Node previous;  
//         Node next;  
          
//         public Node(int data) {  
//             this.data = data;  
//         }  
//     }  
      
//     //Represent the head and tail of the doubly linked list  
//     Node head, tail = null;  
      
//     //addNode() will add a node to the list  
//     public void addNode(int data) {  
//         //Create a new node  
//         Node newNode = new Node(data);  
          
//         //If list is empty  
//         if(head == null) {  
//             //Both head and tail will point to newNode  
//             head = tail = newNode;  
//             //head's previous will point to null  
//             head.previous = null;  
//             //tail's next will point to null, as it is the last node of the list  
//             tail.next = null;  
//         }  
//         else {  
//             //newNode will be added after tail such that tail's next will point to newNode  
//             tail.next = newNode;  
//             //newNode's previous will point to tail  
//             newNode.previous = tail;  
//             //newNode will become new tail  
//             tail = newNode;  
//             //As it is last node, tail's next will point to null  
//             tail.next = null;  
//         }  
//     }  
      
//     //display() will print out the nodes of the list  
//     public void display() {  
//         //Node current will point to head  
//         Node current = head;  
//         if(head == null) {  
//             System.out.println("List is empty");  
//             return;  
//         }  
//         System.out.println("Nodes of doubly linked list: ");  
//         while(current != null) {  
//             //Prints each node by incrementing the pointer.  
  
//             System.out.print(current.data + " ");  
//             current = current.next;  
//         }  
//     }  
      
//     public static void main(String[] args) {  
          
//         DoublyLinkedList dList = new DoublyLinkedList();  
//         //Add nodes to the list  
//         dList.addNode(1);  
//         dList.addNode(2);  
//         dList.addNode(3);  
//         dList.addNode(4);  
//         dList.addNode(5);  
          
//         //Displays the nodes present in the list  
//         dList.display();  
//     }  
// }  