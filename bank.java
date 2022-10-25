import java.util.*;
import java.io.*;

class node{
    int acc_no;
    String name;
    String address;
    Double balance;

    node next;
}
class bank{
    Scanner sc = new Scanner(System.in);
    InputStreamReader ir = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(ir);

    node head;
    bank(){
        head=null;

    }

    void create() throws IOException {
        int a;
        String b,c;
        Double d;

        node ptr;

        System.out.println("Enter the new Account Number to be Inserted:");
        a= sc.nextInt();
        System.out.println("Enter the new Name to be Inserted:");
        b= br.readLine();
        System.out.println("Enter the new Address to be Inserted:");
        c=br.readLine();
        System.out.println("Enter the new Balance to be Inserted:");
        d=sc.nextDouble();

        ptr=new node();
        ptr.acc_no=a;
        ptr.name=b;
        ptr.address=c;
        ptr.balance=d;
        ptr.next=null;

        if (head==null){
            head=ptr;
            System.out.println("\n\tCreated first Node");
        }
        else{
            ptr.next=head;
            head=ptr;
            System.out.println("\n\tInserted");
        }
    }
    void insert() throws IOException {
        int e;
        String f,g;
        Double h;

        node prev,ptr,cur;
        System.out.println("Enter the new Account Number to be Inserted:");
        e= sc.nextInt();
        System.out.println("Enter the new Name to be Inserted:");
        f= br.readLine();
        System.out.println("Enter the new Address to be Inserted:");
        g=br.readLine();
        System.out.println("Enter the new Balance to be Inserted:");
        h=sc.nextDouble();
        ptr=new node();
        ptr.acc_no=e;
        ptr.name=f;
        ptr.address=g;
        ptr.balance=h;
        ptr.next=null;

        prev=null;
        cur=head;
        while (cur!=null && cur.acc_no<e){
            prev=cur;
            cur=cur.next;
        }
        if (cur!=null && cur.acc_no==e){
            System.out.println("\n\tNo Duplication of elements");
        }
        else {
            /*Insertion is possible*/
            ptr=new node();
            ptr.acc_no=e;
            ptr.name=f;
            ptr.address=g;
            ptr.balance=h;
            ptr.next=null;

            /*now insertion*/
            if (prev==null){
//              insertion at head
                ptr.next=head;
                head=ptr;
                System.out.println("\n\tInserted at head");
            }
            else if (prev!=null && cur==null) {
//              Insertion at the End
                prev.next=ptr;
                System.out.println("\n\tInserted at the end");
            }
            else{
//                Insertion in between
                prev.next=ptr;
                ptr.next=cur;
                System.out.println("\n\tInserted in Between");
            }

        }
    }
    void delete(){
        node prev,cur;
        if (head==null){
            System.out.println("List is empty!");
        }
        else {
            System.out.println("Enter the account number you want to delete: ");
            int v=sc.nextInt();

            prev=null;
            cur=head;

            while (cur!=null && cur.acc_no<v){
                prev=cur;
                cur=cur.next;
            }

            if (cur==null ||(cur!=null && cur.acc_no!=v)){
                System.out.println("No such Account Number Exist!");
            }
            else{
                /*cur is node to be deleted*/
                if(prev==null){
                    head=cur.next;
                    cur.next=null;
                    cur=null;
                    System.out.println("Account number Deleted");
                }
                else {
                    prev.next=cur.next;
                    cur.next=null;
                    cur=null;
                    System.out.println("Account number Deleted");
                }
            }

        }


    }
    void display(){
        node cur;
        if (head==null){
            System.out.println("\n\tList is Empty");
        }
        else {
            cur=head;
            while(cur!=null){
                System.out.println("\n\tAccount Number: "+cur.acc_no+"\n\tName of the Customer:"+cur.name+"\n\tAddress of the Customer"+cur.address+"\n\tBalance amount of the account"+cur.balance);
                cur=cur.next;
            }
        }
    }
    void deposit(){
        node cur;
        int acc_tosearch;
        Double amount_todeposit;
        System.out.println("Enter the Account Number you want to Deposit:");
        acc_tosearch= sc.nextInt();
        System.out.println("Enter the amount to be deposited:");
        amount_todeposit= sc.nextDouble();
        int flag=0;
        cur=head;
        while (cur!=null) {
            if (cur.acc_no == acc_tosearch) {
                flag = 1;
                break;
            }
                cur = cur.next;
            }
        cur.balance= (cur.balance+amount_todeposit);
            if (flag==1) {
                    System.out.println("Account Number Found and amount deposited\n\t" + "Available Balance:"+cur.balance);
                }

            else{
                System.out.println("Account Number not found");
            }
        }



    void withdraw(){
        node cur;
        int acc_tosearch;
        Double amount_towithdraw;
        System.out.println("Enter the Account Number you want to withdraw:");
        acc_tosearch= sc.nextInt();
        System.out.println("Enter the amount to be Withdrawn:");
        amount_towithdraw= sc.nextDouble();
        int flag=0;
        cur=head;
        while (cur!=null) {
            if (cur.acc_no == acc_tosearch) {
                flag = 1;
                break;
            }
            cur = cur.next;
        }
        if (cur.balance>1000) {
            cur.balance = (cur.balance - amount_towithdraw);
            if (flag == 1) {
                System.out.println("Account Number Found and amount withdrawn\n\t" + "Available Balance:" + cur.balance);
            }
            else{
                    System.out.println("Account Number not found");
                }
            }

        else {
            System.out.println("Amount Not Sufficient to be Withdrawn!");
        }


    }

    public static void main(String args[]) throws IOException {
        Scanner sc1=new Scanner(System.in);
        bank b1=new bank();
        int ch;
        do {
            System.out.println("********WELCOME TO MAHARASHTRA BANK*********");
            System.out.println("\n\t1]Create first node\n\t2]Insertion of Account Number:\n\t3]Deletion of Account Number\n\t4]Deposit Amount\n\t5]Withdraw Amount\n\t6]Display the Linked List\n\t7]Exit");
            System.out.println("\nEnter your Choice:");
            ch=sc1.nextInt();
            switch (ch){
                case 1:
                    b1.create();
                    break;
                case 2:
                    b1.insert();
                    break;
                case 3:
                    b1.delete();
                    break;
                case 4:
                    b1.deposit();
                    break;
                case 5:
                    b1.withdraw();
                    break;
                case 6:
                    b1.display();
                    break;
                case 7:
                    System.out.println("********Thank you! visit again********");
                    break;
            }

        }while (ch!=7);
    }

}
