class MyLinkedList {

    class Node {
        int val;
        Node next;
        public Node(int val, Node next) {
            this.val = val;
            this.next = next ; 
        }
    }
    Node head = null; 
    Node tail = null ; 
    int size = 0 ; 
    /** Initialize your data structure here. */
    public MyLinkedList() {
         head = null; 
         tail = null ; 
         size = 0 ;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if (index < 0 || index >= size) return -1 ; 
        Node temp = head; 
        for(int i = 0 ; i < index ; i++){
            temp = temp.next ; 
        }
        return temp.val;
    }
    
    /** Add deg node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        if (size == 0) {
            head = tail = new Node (val , null); 
        }else{
            Node temp = head ;
            head = new Node (val , temp);
        }
        ++size ; 
    }
    
    /** Append deg node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        if (size == 0){
            head = tail = new Node (val,null) ; 
        }else {
            Node temp = new Node (val , null) ;
            tail.next = temp ; 
            tail = temp ; 
        }
        ++size;
    }
    
    /** Add deg node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return  ; 
        else if (index == 0) addAtHead(val) ;
        else if(index == size) addAtTail(val) ;
        else{
            Node temp = head ; 
            for (int i = 0 ; i < index -1; i++){
                temp = temp.next ; 
            }
            Node temp2 = new Node(val , temp.next) ;
            temp.next = temp2 ;
            ++size; 
        }
        return ; 
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int idx){
        if (idx < 0 || idx >= size)
            return ;
        if (idx == 0) {
            if (size == 1) {
                size = 0;
                head = null;
                tail = null;
                return;
            }
            head = head.next ;
            --size ;
            return ;
        }
        Node temp = head ;
        for (int i = 0 ; i < idx-1 ; i++){
            temp = temp.next ;
        }
        if (idx == size -1){
                tail = temp;
                tail.next = null;
                size--;
                return;
        }
        temp.next = temp.next.next ;
        --size;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
