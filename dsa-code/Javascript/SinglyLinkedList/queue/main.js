/*
    A simple queue implementation in javascript using singly linked list
*/

// to create a node for singly linked list
class Node {
    constructor(value){
        this.value = value;
        this.next = null;
    }
}


// queue operations
class Queue {
    constructor() {
        this.first = null;
        this.last = null;
        this.size = 0;
    }

    // to insert an element into the queue
    enqueue(val){
        const newNode = new Node(val);
        if(!this.first){
            this.first = newNode;
            this.last = newNode;
        } else {
            this.last.next = newNode;
            this.last = newNode;
        }
        this.size++;
    }

    // to remove the first inserted value from the queue
    dequeue() {
        if(!this.first) return null;
        const node = this.first;
        this.first = this.first.next;
        this.size--;
        return node;
    }
}

// this will create a memory for queue
const queue = new Queue();

// enqueue operations to add elements/nodes into the queue
queue.enqueue("one");
queue.enqueue("two");
queue.enqueue("three");
queue.enqueue("four");

// will return the first insearted node in the queue
console.log(queue.dequeue());

// to display all the available nodes in the queue
console.log(queue);