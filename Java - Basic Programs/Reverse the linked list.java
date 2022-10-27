import java.util.*;
class Reverse{
    Node head;
    class Node{
        int data;
        Node next;
        Node(int data){
            this.data=data;
            this.next=null;
        }
    }
    public void add_ele(int data){
        Node newnode = new Node(data);
        if(head==null){
            head=newnode;
            return;
        }
        
        Node temp=head;
        while(temp.next!=null){
        
            temp=temp.next;
        }
        temp.next=newnode;
      }
        
    public void reverse_list(){
    Node prev=null;
    Node curr= head;
    Node next=null;
    while(curr!=null){
        next=curr.next;
        curr.next=prev;
        prev=curr;
        curr=next;
            
    }
    head=prev;
}

    public void print(){
        Node temp=head;
        while(temp!=null){
            System.out.println(temp.data);
            temp=temp.next;
        }
    }

    public static void main(String [] args){
        Reverse list = new Reverse();
        Scanner sc = new Scanner(System.in);
        int size=sc.nextInt();
               
        for(int i=0;i<size;i++){
            int a=sc.nextInt();
            list.add_ele(a);
        }
    System.out.println("Linked list before reversing");
        list.print();
    list.reverse_list();
    System.out.println("Linked list after reversing");
    list.print();
    }
}
