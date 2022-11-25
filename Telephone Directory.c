//header file used in application
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include<conio.h>

//Defining structure of a contact
typedef struct contact
{
    char name[25];
    char num[11];
    char num2[11];
    char email[30];
    char gender[7];
    char dob[11];
    int fav;
    struct contact *next;
} node;

    char myname[50]={'C','H','A','N','D','N','I','J','H','A'},mynumber[10]={'6','2','9','1','5','0','8','3','4','4'},myemail[50]={'c','a','y','m','d','n','i','j','h','a','6','3','0','@','g','m','a','i','l','.','c','o','m'},mygender[6]={'f','e','m','a','l','e'};
    int mymm=3,mydd=6,myyr=2006;
//Code snippet to search a contact using name  to show all inserted details of that contact
node* searchName(node*head,char name[25]){
     node*temp=head;
    while(temp!=NULL && strcmp(temp->name,name)!=0 ){
        temp=temp->next;
    }

    return temp;
}
//Code snippet to search a contact using number to show all inserted details of that contact
node* searchNum(node*head,char num[11]){
    node*temp=head;
    while(temp!=NULL && strcmp(temp->num,num)!=0 ){
        temp=temp->next;
    }

    return temp;
}
//Code snippet to display contacts of people of certain gender either male or female with every inserted detail
void displayGender(node*head,char gender[7]){
	printf("====== Display %s contacts =======\n",gender);
     printf("----------------------------------\n");
     node*temp=head;
    while(temp!=NULL){
    if(strcmp(temp->gender,gender)==0 ){
       printf("%s %s ",temp->name,temp->num);
       if(temp->num2!=NULL)
       printf("%s ",temp->num2);
       if(temp->email!=NULL)
       printf("%s\t\t",temp->email);
       if(temp->dob!=NULL)
       printf("%s ",temp->dob);
       if(temp->fav==1)
            printf("%s","\u2B50");
       printf("\n");
    }
    temp=temp->next;
}
}
//Code snippet to Display Favourite Contacts and thier details
void displayFavourite(node*head){
	printf("====== Favourite contacts =======\n");
     printf("----------------------------------\n");
    node*temp=head;
        while(temp!=NULL){
           if(temp->fav==1){
         printf("%s  %s  ",temp->name,temp->num);
       if(temp->num2!=NULL)
       printf("%s  ",temp->num2);
       if(temp->email!=NULL)
       printf("%s\t\t",temp->email);
       if(temp->gender!=NULL)
       printf("%s  ",temp->gender);
       if(temp->dob!=NULL)
       printf("%s  ",temp->dob);
       printf("\n");
    }
    temp=temp->next;
}
}
//Code snippet to search and delete certain contact 
node*deleteContact(node*head,char name[25]){
    node*temp=searchName(head,name),*ptr=head;
  if(temp!=NULL){
  
    while(ptr->next!=temp){
        ptr=ptr->next;
    }
    ptr->next=temp->next;
    free(temp);
}
    else {
    	printf("No such exsisting Contact\n");
	}
    return head;
}
//Code snippet to edit and Add more details to a pre exsisting Contact 
node*editContact(node*temp){
    int o=1,ch,x;
    char num[11],gen[7],email[30],dob[11];
    while(o){
        printf("Press 1 Edit exsisting Number\n");
        printf("Press 2 Add New Number\n");
        printf("Press 3 Add Date of Birth\n");
        printf("Press 4 Add Email\n");
        printf("Press 5 Add to Favourite\n");
        printf("Press 6 Mention Gender\n");
        printf("Press 0 Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 0:
            o=0;
            break;
            case 1:
            printf("Exsisting Number:%s",temp->num);
            printf("\nRewrite Number: ");
            scanf("%s",num);
            strcpy(temp->num,num);
            break;
            case 2:
            printf("Enter number to be added:: ");
            scanf("%s",num);
            if(temp->num2!=NULL)
            strcpy(temp->num2,num);
            else
            printf("Not more than 2 numbers can be added under same contact name\n");
            break;
            case 3: 
             printf("Enter Date Of Birth(dd/mm/yyyy):: ");
            scanf("%s",dob);
            strcpy(temp->dob,dob);
            break;
             case 4: 
             printf("Enter Email:: ");
            scanf("%s",email);
            strcpy(temp->email,email);
            break;
            case 5:
            temp->fav=1;
            break;
            case 6:
            printf("Enter Gender (Male/Female)");
            scanf("%s",gen);
            strcpy(temp->gender,gen);
            break;
           
        }
    }
    
    return temp;
}

//Code snippet for Alphabetically sorted insertion of contact
node *insert(node *head,char tmp_name[25], char tmp_num[11])
{
    node *trav = head;
    node *temp = NULL;
    node*pre=searchName(head,tmp_name);
    if(pre!=NULL){
        printf("This contact already exsist!!\n");
        strcpy(pre->num2,tmp_num);
    }
    else{
    if (head == NULL)
    {
        head = malloc(sizeof(node));
        strcpy(head->name, tmp_name);
        strcpy(head->num, tmp_num);
        return head;
    }

    temp = malloc(sizeof(node));
    strcpy(temp->name, tmp_name);
    strcpy(temp->num, tmp_num);

    if (strcmp(temp->name, head->name) < 0)
    {
        temp->next = head;
        head = temp;
        return head;
    }

    while (trav->next != NULL)
    {
     
        if (strcmp(temp->name, trav->next->name) < 0)
        {
            temp->next = trav->next;
            trav->next = temp;
            return head;
        }
        trav = trav->next;
    }

    trav->next = temp;
    }
    return head;
}
//Code snippet to display contact details of all contacts
void display(node *head)
{
    node*temp=head;
    printf("\n");
    while (temp != NULL)
    {
      printf("%s\n-------------------------\n%s\n",temp->name,temp->num);
      //printf("\n-------------------------\n");
       if(temp->num2!=NULL)
       printf("-------------------------\n");
       printf("%s ",temp->num2);
       if(temp->email!=NULL)
       printf("\n-------------------------\n");
       printf("%s\t\t",temp->email);
       if(temp->dob!=NULL)
       printf("%s\t",temp->dob);
        if(temp->gender!=NULL)
       printf("%s\t",temp->gender);
       if(temp->fav==1)
           printf("%s\t","\u2B50");
        printf("\n");
       // printf("-------------------------\n");
       printf("________________________________________________ \n");
        temp = temp->next;
    }
}

//Pre installed user's profile (At the time of purchase)

void myprofile(){
    printf("\x1b[39mMy Profile           \n");
    printf("--------------------------\n");
    printf("%s           \n",myname);
    printf("--------------------------\n");
    printf("%s                \n",mynumber);
    printf("--------------------------\n");
    printf("Birth Date : %d/%d/%d   \n",mydd,mymm,myyr);
    printf("--------------------------\n");
    printf("%s                        \n",myemail);
    printf("--------------------------\n");
    printf("Gender : %s             \n",mygender);
    printf("--------------------------\x1b[0m \n");
}

//Driving Function
int main()
{
    int choice,ch,o=1,x;
    	 char tmp_name[25], tmp_num[11],gen[7];
    node *head = NULL,*temp;
    
//Factory installed contacts
head=insert(head,"Ambulance","033-23145");
head=insert(head,"Police","100");
head=insert(head,"Ola","9088765670");
head=insert(head,"Uber","7088765670");
head=insert(head,"Customer Care","8988765670");
head=insert(head,"Gas","033-865670");
head=insert(head,"Railway","8611233470");
head=insert(head,"Airway","6789865670");
head=insert(head,"Balance","*121#");
head=insert(head,"Fire Brigde","2231456789");
head=insert(head,"Service Centre","5555555");
//Displaying Screen Commands
    printf("\x1b[33m======WELCOME TO YOUR PHONE BOOK=====\x1b[0m\n");
    while(o){
         
    printf("\x1b[35m\nPress 1: Add new contact");
    printf("\nPress 2: Display My Profile");
    printf("\nPress 3: Display All Contacts");
    printf("\nPress 4: Display specific Gender contact");
    printf("\nPress 5: Display favourite contact");
    printf("\nPress 6: Search Contact");
    printf("\nPress 7: Edit contact");
    printf("\nPress 8: Delete contact");
    printf("\nPress 9: Edit My Profile");
    printf("\nPress 0: Exit\n\x1b[0m");

    printf("\x1b[33m\nEnter your choice = ");
    scanf("%d\x1b[0m", &choice);

  switch(choice){
      case 0:
      o=0;
      break;
     case 1:  
    printf("\nEnter the name you want to insert = ");
    // fgets(tmp_name, 25, stdin);
    scanf(" %[^\n]s", tmp_name);
    printf("\nEnter the number you want to insert = ");
    // fgets(tmp_num, 11, stdin);
    scanf(" %[^\n]s", tmp_num);
            head = insert(head,tmp_name,tmp_num);
            temp=searchName(head,tmp_name);
            editContact(temp);
            break;
            case 2:
            printf("\n");
            myprofile();
            break;
    case 3:
    printf("\x1b[34m==========Contact list===========\x1b[36m");
            display(head);
            printf("\x1b[0m");
            break;
    case 4:
    printf("Enter gender (Female/Male):: ");
    scanf("%s",gen);
     printf("\x1b[34m==========Contact list===========\x1b[36m\n");
            displayGender(head,gen);
            printf("\x1b[0m");
            break;
    case 5:
     printf("\x1b[34m==========Contact list===========\x1b[36m\n");
        displayFavourite(head);
        printf("\x1b[0m");
            break;
    case 6: 
        printf("\x1b[34m1.Search using name\n");
         printf("2.Search using number\n");
         scanf("%d",&ch);
         if(ch==1){
             printf("Name:: ");
             scanf(" %[^\n]s", tmp_name);
             temp=searchName(head,tmp_name);
         }
         else if(ch==2){
             printf("Number:: ");
             scanf(" %[^\n]s", tmp_num);
             temp=searchNum(head,tmp_num);
         }
         if(temp!=NULL){
         printf("\x1b[0m");
                    printf("\x1b[32m%s %s ",temp->name,temp->num);
       if(temp->num2!=NULL)
       printf("%s ",temp->num2);
       if(temp->email!=NULL)
       printf("%s\t\t",temp->email);
       if(temp->gender!=NULL)
       printf("%s ",temp->gender);
       if(temp->dob!=NULL)
       printf("%s ",temp->dob);
        if(temp->gender!=NULL)
       printf("%s ",temp->gender);
       if(temp->fav==1)
            printf("%s","\u2B50");
       printf("\x1b[0m");
         }
         else{
             printf("No such name exsists in your phone book");
         }
       break;
       case 7:
        printf("\x1b[34m1.Search using name\n");
         printf("2.Search using number\n");
         scanf("%d",&ch);
         if(ch==1){
             printf("Name:: ");
             scanf(" %[^\n]s", tmp_name);
             temp=searchName(head,tmp_name);
         }
         else if(ch==2){
             printf("Number:: ");
             scanf(" %[^\n]s", tmp_num);
             temp=searchNum(head,tmp_num);
         }
          temp=editContact(temp);
           printf("\x1b[0m");
          break;
        case 8:
         printf("\x1b[31m");
        printf("Enter Contact Name For Deletion::\n");
        scanf("%s",tmp_name);
        head=deleteContact(head,tmp_name);
         printf("\x1b[0m");
        break;
        case 9: 
        printf("User Name: ");
        scanf("%s",myname);
        printf("User Number: ");
        scanf("%s",mynumber);
        printf("User Email: ");
        scanf("%s",myemail);
        printf("User Date of Birth: ");
        scanf("%d %d %d",&mydd,&mymm,&myyr);
        printf("User Gender: ");
        scanf("%s",mygender);
        break;
    }
}
    printf("\n::::PROGRAM EXITED::::\n");

    return 0;
}

