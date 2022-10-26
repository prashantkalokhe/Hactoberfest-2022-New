/*
    implementation of doubly linked list in javascript using class
*/

// class to create a node for doubly linked list
class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

// doubly linked list operations
class DoublyLinkedList {
    constructor(){
        this.first = null;
        this.last = null;
        this.size = 0;
    }

    //to insert nodes into last of the doubly linked list
    append(value){
        const newNode = new Node(value);
        if(!this.first){
            this.first = newNode;
            this.last = newNode;
        } else {
            let temp = newNode;
            temp.prev = this.last;
            this.last.next = temp;
            this.last = temp;
        }
        this.size++;
    }

    //to insert nodes into first of the doubly linked list
    prepend(value){
        const newNode = new Node(value);
        if(!this.first){
            this.first = newNode;
            this.last = newNode;
        } else {
            let temp = newNode;
            this.first.prev = temp;
            temp.next = this.first;
            this.first = temp;
        }
        this.size++;
    }

    //will return the particular indexed node in the doubly linked list
    get(index) {
        if(index<=0 || index>this.size) return null;
        else {
            let node = this.first;
            for(let i=1;i<index;i++){
                node = node.next;
            }
            return node;
        }
    }
    
    //to insert nodes into given index of the doubly linked list
    insert(ind,val) {
        let prevNode = this.get(ind-1);
        if(prevNode){
            let nextNode = prevNode.next;
            let node = new Node(val);
            node.prev = prevNode;
            prevNode.next = node;
            node.next = nextNode;
            nextNode.prev = node;
            this.size++;
        }
    }
}

const list = new DoublyLinkedList();

//sample operations
list.append("four");
list.prepend("one");
list.insert(2,"three");
list.insert(2,"two");

console.log(list);