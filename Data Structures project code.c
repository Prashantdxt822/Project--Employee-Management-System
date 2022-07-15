// PRASHANT DIXIT(2K20-MC-100)

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
// Global declaration
int count = 0;
  
// Structure declaration
struct node {
    struct node* prev;
    int age;
    long int phno;
    float sal;
    char name[20], dept[10], desg[20];
    struct node* next;
} * head, *temp, *tail, *temp2;
  
// Function to create node

void print_details(struct node* current)
{
    printf("the age of the employee is: %d\n",current->age);
    printf("the name of the employee is: %s\n",current->name);
    printf("the department of the employee is: %s\n",current->dept);
    printf("the designation of the employee is: %s\n",current->desg);
    printf("the salary of the employee is:  %f\n",current->sal);
    printf("the phone number of the employee is: %ld\n",current->phno);

}
  


void create()
{
    
    int age;
    long int phno;
    float sal;
    char name[20], dept[10], desg[20];
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;

    printf("\nenter the age of the employee : ");
    scanf("%d",&age);
    printf("enter the name of the employee : ");
    scanf("%s",name);
    printf("enter the department of the employee:");
    scanf("%s",dept);
    printf("enter the designation of the employee : ");
    scanf("%s",desg);
    printf("enter the salary of the employee :  ");
    scanf("%f",&sal);
    printf("enter the phone number of the employee : ");
    scanf("%ld",&phno);


    temp->age = age;
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->desg, desg);
    temp->sal = sal;
    temp->phno = phno;
    count++;
}
  
// Function to insert a node at the beginning of list
void Insert_beginning()
{
    // If DLL is empty
    if (head == NULL) {
        create();
        head = temp;
        tail = head;
    }
  
    // Else create a new node and
   
    else {
        create();
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
  
// Function to insert node at the end
void insert_end()
{
    // If list is empty
    if (head == NULL) {
        create();
        head = temp;
        tail = head;
    }
  
    // Else create a new node 
   
    else {
        create();
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
  
// Function to display from beginning
void display_beginning()
{
    int count2=0;
    temp2 = head;
    if (temp2 == NULL) {
        printf("\n list is empty\n");
        return;
    }
    printf("\n Displaying all the employees "
           "from beginning:\n");
    while (temp2 != NULL) {
        count2++;
        printf("\nthe details of employee %d are as follows:-\n",count2);
       print_details(temp2);
        temp2 = temp2->next;
    }
  
    // Print the count
    printf("\nnumber of employees=%d\n", count);
}
  
// Function to delete the node from end
int delete_end()
{
    printf("details of the deleted employee are:-\n");
    struct node* temp;
    temp = head;
    if (temp == NULL) {
        printf("list is empty\n");
        return 0;
    }
    if (temp->next == NULL) {
        print_details(temp);
        free(temp);
        head = NULL;
    }
    else {
        temp = tail;
        temp2 = tail->prev;
        temp2->next = NULL;
        print_details(temp);
        free(temp);
        tail = temp2;
    }
    count--;
    return 0;
}
  
// Function to delete the node from beginning
int delete_begin()
{
    struct node* temp;
    temp = head;
    if (temp == NULL) {
        printf("list is empty\n");
        return 0;
    }
    if (temp->next == NULL) {
        print_details(temp);
        free(temp);
        head = NULL;
    }
    else {
        head = head->next;
        head->prev = NULL;
        print_details(temp);
        free(temp);
    }
    count--;
    return 0;
}
void search_byname()
{
    char str[20];
    printf("please enter the name of the employee you want to search\n");
    scanf("%s",str);

     temp2 = head;
    if (temp2 == NULL) {
        printf("\n list is empty\n");
        return;
    }
  
    while (temp2 != NULL) {
       
       if(strcmp(temp2->name,str)==0)
       {
           printf("employee found\n");
           print_details(temp2);
           return;
       }
        temp2 = temp2->next;
    }
    printf("employee not found\n");


}

void delete_byname()
{
    printf("\nplease enter the name of the employee you want to delete\n");
    char sname[20];
    scanf("%s",sname);
    int x=0;
    struct node* ptr=head;
    while(ptr !=NULL)
        {

        if(strcmp(sname,ptr->name)==0)
        {
        x=1; 
        break;
        }
        else
        {
        x=2;       
        }   
        ptr=ptr->next;
        }
      if(x==1 && ptr!=head && ptr->next!=NULL)
    {
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        free(ptr);
        printf("employee is successfully deleted!\n");
        count--;
    }
    if(ptr==head)
    {
        head=head->next;
        head->prev=NULL;
        free(ptr);
        printf("employee is successfully deleted!\n");
        count--;
    }
   if(ptr->next==NULL)
    {
        ptr->prev->next=NULL;
        ptr->prev=NULL;
        free(ptr);
        printf("employee is successfully deleted!\n");
        count--;
    }
   if(x==2)
    {
        printf("employee not found!\n");
    }

}



// Function displaying menus
void employerDetails()
{
    int ch, n, i;
    head = NULL;
    temp = tail = NULL;
  
    while (1) {
    printf("\n\n**********  MENU **********\n");
    printf("\nplease enter choice from the following options\n");
    printf("\n 1.Create a list of n number of employees");
    printf("\n 2.Display from beginning");
    printf("\n 3.Insert data at the end");
    printf("\n 4.Delete data at the end");
    printf("\n 5.Insert data at the beginning");
    printf("\n 6.Delete data at the beginning");
    printf("\n 7.Search an employee by name");
    printf("\n 8.Delete an employee by name");
    printf("\n 9.Exit\n");
    printf("----------------------\n");
        printf("\n enter choice : ");
        scanf("%d", &ch);
  
        // Switch statements begins
        switch (ch) {
        case 1:
            printf("\n enter number of"
                   " employees:");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("\nenter the details for employee %d\n",i+1);
            
                insert_end();
            }
            break;
        case 2:
            display_beginning();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            delete_end();
            break;
        case 5:
            Insert_beginning();
            break;
        case 6:
            delete_begin();
            break;
        case 7:
            search_byname();
            break;
        case 8:
            delete_byname();
            break;
        case 9:
            exit(0);
        default:
            printf("wrong choice\n");
        }
    }
}
  
// Driver Code
int main()
{
    // Function Call
    employerDetails();
  
    return 0;
}