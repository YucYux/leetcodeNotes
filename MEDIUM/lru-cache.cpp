class Node
{
    public:
        int val=0;
        int key=0;
        Node * next=NULL;
        Node * prev=NULL;;
};


class LRUCache {
public:
    int size=0;
    int num=0;
    Node* nodes[10001]={NULL};
    Node* head=NULL;    //left
    Node* tail=NULL;    //right
    LRUCache(int capacity) {
        size=capacity;
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(nodes[key])
        {
            removeNodeFromList(nodes[key]);
            addNodeToTail(nodes[key]);
            return nodes[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(get(key)!=-1)
        {
            nodes[key]->val=value;
            return;
        }
        Node* temp=new Node();
        temp->val=value;
        temp->key=key;
        addNodeToTail(temp);
        nodes[key]=temp;
        num++;
        if(num>size)
        {
            Node* waitToDelete=head->next;
            nodes[waitToDelete->key]=NULL;
            removeNodeFromList(waitToDelete);
            delete(waitToDelete);
            num--;
        }
    }
    void removeNodeFromList(Node * target)
    {
        target->prev->next=target->next;
        target->next->prev=target->prev;
    }
    void addNodeToTail(Node* target)
    {
        tail->prev->next=target;
        target->prev=tail->prev;
        target->next=tail;
        tail->prev=target;
    }
    bool empty()
    {
        if(num==0) return 1;
        else return 0;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
