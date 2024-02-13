class Node {
  constructor(prev = this, next = this, data = null){
    this._next = next; 
    this._prev = prev;
    this._data = data;
  }
  get next(){
    return this._next;
  }
  set next(next){
    this._next = next;
  }
  get prev(){
    return this._prev;
  }
  set prev(prev){
    this._prev = prev;
  }
  get data(){
    return this._data;
  }
  set data(data){
    this._data = data;
  }
}

export class LinkedList {
  constructor(){
    // sentry node, it will always stay there in the list, when the list 
    // is empty, it will link to itself
    this._base_node = new Node();
    this._count = 0;
  }

  #insert(node_next, data) {
    const new_node = new Node(node_next.prev, node_next, data);
    node_next.prev.next = new_node;
    node_next.prev = new_node;
    this._count++;
  }

  #remove(node) {
    node.next.prev = node.prev;
    node.prev.next = node.next;
    this._count--;
    return node.data;
  }

  push(data) {
    this.#insert(this._base_node, data);
  }

  pop() {
    return this.#remove(this._base_node.prev);
  }

  shift() {
    return this.#remove(this._base_node.next);
  }

  unshift(data) {
    this.#insert(this._base_node.next, data);
  }

  delete(data) {
    let cur_node = this._base_node.next;
    while(this._base_node !== cur_node){
      if (data === cur_node.data){
        this.#remove(cur_node);
        break;
      }
      cur_node = cur_node.next;
    }
  }

  count() {
    return this._count;
  }
}
