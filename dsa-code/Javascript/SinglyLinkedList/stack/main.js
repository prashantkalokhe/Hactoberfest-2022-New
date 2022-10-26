/*
    Javascript implementation for creating a stack using singly linked list
*/

// to create a single node for linked list
class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

// stack operations
class Stack {
    constructor(value) {
        this.top = null;
        this.size = 0;
    }

    //to add a new value into the stack
    push(val) {
        const newNode = new Node(val);
        if(!this.top){
            this.top = newNode;
        } else {
            const temp = this.top;
            this.top = newNode;
            this.top.next = temp;
        }
        this.size++;
    }

    // to delete a last inserted value from the stack 
    pop() {
        if(this.size<=0) return null;
        else{
            const node = this.top;
            this.top = this.top.next;
            this.size--;
            return node;
        }
    }
}


const stk = new Stack();

// these following operations will create a stack of (one,two,three,four)
stk.push("one");
stk.push("two");
stk.push("three");
stk.push("four");

// this will remove four from the stack
console.log(stk.pop());

// will display the elements in the stack
console.log(stk);