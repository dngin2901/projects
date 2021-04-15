class Node {
    private:

        int data;
        Node *next;
        Node *prev;


    public:
        Node(int value);
        ~Node();

        friend class List;
};

class List {

    private:
        Node *head;
        Node *tail;
        int node_count;

    public:
        List();
        ~List();
        void push_back(int d);
        void push_front(int d);
        void to_string();
        void delete_first();
        void delete_last();
        bool contains();
        int size();
        int middle_node();
        bool contains(int x);
        void deleteNode(int x);
        void insert(int index, int d);

};