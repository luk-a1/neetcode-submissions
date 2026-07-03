class Node{
    int val;
    int key;
    Node* next;
    Node* prev;
public:
    Node(int k, int key_): val(k), key(key_), next(nullptr), prev(nullptr){}

    void setNext(Node* node) {next = node;}
    void setPrev(Node* node) {prev = node;}
    Node* getPrev() {return prev;}
    Node* getNext() {return next;}
    int getVal() const {return val;}
    int getKey() const {return key;}
    void updateVal(int val) {this->val = val;}
};

class LRUCache {
    int count_;
    int capacity_;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> m;
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        count_ = 0;
        head = nullptr;
        tail = nullptr; 
    }

    void setHead(int key){
        
        if(head == m[key]) return;
        if(tail == m[key]){
            head->setPrev(tail);
            tail->setNext(head);
            tail = tail->getPrev();
            tail->setNext(nullptr);
            head = head->getPrev();
            return;
        }

        m[key]->getNext()->setPrev(m[key]->getPrev());
        m[key]->getPrev()->setNext(m[key]->getNext());

        head->setPrev(m[key]);
        m[key]->setNext(head);
        head = m[key];
        head->setPrev(nullptr);
    }
    
    int get(int key) {
        if(m.contains(key)){ setHead(key); return head->getVal();}
        else return -1;
    }
    
    void put(int key, int value) {
        if(m.contains(key)) {m[key]->updateVal(value); setHead(key);}
        else
        {
            m[key] = new Node(value, key);
            if(isFull()){
                head->setPrev(m[key]);
                m[key]->setNext(head);
                head = m[key];
                Node* temp = tail;
                tail = tail->getPrev();
                m.erase((tail->getNext())->getKey());
                tail->setNext(nullptr);
                delete temp;
            }
            else
            {
                if(count_ == 0){
                    tail = m[key];
                    head = m[key];
                }
                else{
                    head->setPrev(m[key]);
                    m[key]->setNext(head);
                    head = m[key];
                }
                count_++;
            }
        }
    }
    bool isEmpty(){return count_ == 0;}
    bool isFull(){return count_ == capacity_;}
};