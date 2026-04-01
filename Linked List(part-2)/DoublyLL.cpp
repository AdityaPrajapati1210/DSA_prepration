    #include<iostream>
    using namespace std;

    class Node{
        public:
        int data;
        Node*next;
        Node*prev;

        Node(int data){
            this->data = data;
        }
    };

    class List{
        public:
        Node*head =NULL;
        List(){

            cout <<" constructor called"<<endl;
        };
        void pushfront(int val){
            Node*newnode = new Node(val);
            if(head == NULL){
                head = newnode;
                head->next = NULL;
                head->prev = NULL;
            }else{
                head->prev = newnode;
                newnode->next = head;
                newnode->prev = NULL;
                head = newnode;
            }
        }

        void popfront(){
            if(head == NULL){
                return;
            }
            Node*del = head;
            head = head->next;
            head->prev = NULL;
            delete del;
        }

        void print(){
            Node*temp = head;
            while(temp){
                cout << temp->data<<"->";
                temp = temp->next;
            }
            cout <<"NULL"<< endl;
        }
    };

    int main(){
        List abc;
        abc.pushfront(10);
        abc.pushfront(10);
        abc.pushfront(10);
        abc.pushfront(10);
        abc.popfront();
        abc.print();
    }

