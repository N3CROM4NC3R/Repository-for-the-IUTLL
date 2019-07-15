/*
	Carlos Martínez
	https://github.com/carlosEdua
	
	example of linked list in JavaScript

	this is for educational purposes and understand
	a linked list, because in other programming languages
	the list, queues and stacks are very useful
	but in JavaScript we have the Arrays with all
	this methods by default.
*/

class Node{
	constructor(data){
		this.data = data;
		this.next = null;
	}
}

class LinkedList{
	constructor(){
		this.length = 0;
		this.head;
	}

	addFirst(data){
		// if head is empty
		if(!this.head){
			this.head = new Node(data);
		}else{
			const newNode = new Node(data);
			newNode.next = this.head;
			this.head = newNode;
		}
		this.length++;

	}

	addLast(data){
		if(!this.head){
			this.head = new Node(data);
		}else{
			let headNode = this.head;
			let nextNode = headNode.next;

			while(nextNode){
				headNode = nextNode;
				nextNode = headNode.next;
			}

			let newNode = new Node(data);
			headNode.next = newNode;
		}
		this.length++;

	}

	view(){
		let headNode = this.head;

		while(headNode){
			console.log(`data: ${headNode.data} \n next: ${JSON.stringify(headNode.next)}\n`)
			headNode = headNode.next;
		}
	}
 
	insertAt(data,index = 0){
		// validations
		if(index < 0 || index > this.length - 1) return null;
		// if index is the first
		if(index == 0) {
			this.addFirst(data);
			this.length++;
		}
		else{
			let count = 0;
			let previous = this.head;
			// despues es igual a antes, esto es util al momento del ciclo
			// ya que previous tiene 
			let after = previous;

			while(count < index){
				previous = after;
				after = after.next;
				count++;
			}

			let newNode = new Node(data);

			previous.next = newNode;
			newNode.next = after;
			this.length++;
		}

	}


	deleteFirst(){
		if(this.length == 0) return null;

		this.head = this.head.next;
	}

	deleteLast(){
		if(this.length == 0) return null;

		let previous = this.head;
		let after = previous;

		while(after.next){

			previous = after;
			after = after.next;
		}

		// borrar el ultimo nodo indicando al penultimo que
		// next sea null
		previous.next = null;
	}

	deleteAt(index = -1){
		if(index < 0 || index > this.length -1)return null;

		if(index == 0){ this.deleteFirst(); return }
		if(index == this.size - 1){ this.deleteLast(); return }

		let count = 0;
		let previous = this.head;
		let after = previous;

		while(count < index ){
			previous = after;
			after = after.next;
			count++; 
		}

		let afterLastNodes = after.next;
		//delete after;

		previous.next = afterLastNodes;

		this.length--;

	}

	get size(){
		return this.length;
	}
}

const list = new LinkedList();

list.addFirst('valor1');
list.addLast('valor2');
list.addLast('valor3');
list.addLast('valor4');
list.addLast('valor5');
list.addLast('valor6');
list.addLast('valor7');

list.addFirst('de primero');

console.log(list.size)
list.view();