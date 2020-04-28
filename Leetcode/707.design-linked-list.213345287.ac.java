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
    int sz = 0 ;
    /** Initialize your data structure here. */
    public MyLinkedList() {
         head = null; 
         tail = null ; 
         sz = 0 ;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if (index < 0 || index >= sz) return -1 ;
        Node temp = head; 
        for(int i = 0 ; i < index ; i++){
            temp = temp.next ; 
        }
        return temp.val;
    }
    
    /** Add deg node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        if (sz == 0) {
            head = tail = new Node (val , null); 
        }else{
            Node temp = head ;
            head = new Node (val , temp);
        }
        ++sz ;
    }
    
    /** Append deg node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        if (sz == 0){
            head = tail = new Node (val,null) ; 
        }else {
            Node temp = new Node (val , null) ;
            tail.next = temp ; 
            tail = temp ; 
        }
        ++sz;
    }
    
    /** Add deg node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if (index < 0 || index > sz) return  ;
        else if (index == 0) addAtHead(val) ;
        else if(index == sz) addAtTail(val) ;
        else{
            Node temp = head ; 
            for (int i = 0 ; i < index -1; i++){
                temp = temp.next ; 
            }
            Node temp2 = new Node(val , temp.next) ;
            temp.next = temp2 ;
            ++sz;
        }
        return ; 
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int idx){
        if (idx < 0 || idx >= sz)
            return ;
        if (idx == 0) {
            if (sz == 1) {
                sz = 0;
                head = null;
                tail = null;
                return;
            }
            head = head.next ;
            --sz ;
            return ;
        }
        Node temp = head ;
        for (int i = 0 ; i < idx-1 ; i++){
            temp = temp.next ;
        }
        if (idx == sz -1){
                tail = temp;
                tail.next = null;
                sz--;
                return;
        }
        temp.next = temp.next.next ;
        --sz;
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
