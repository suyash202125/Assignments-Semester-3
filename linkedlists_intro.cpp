#include <iostream>

using namespace std;

class Node
{
    public:
        int node_number;
        int data;
        Node *next_ptr;
        
        Node()
        {
            node_number = 0;
                   data = 0;
               next_ptr = NULL;  
        }
        Node(int num, int d)
        {
            node_number = num;
                   data = d;
        }
};

class singly_linked_list{
    public:
        Node *first;
        
        singly_linked_list()
        {
            first = NULL;
        }
        singly_linked_list(Node *n)
        {
            first = n;
        }
        
        Node* if_node_exists(int num)
        {
            Node* temp = NULL;
             Node* ptr = first;
             
            while(ptr != NULL)
            {
                if(ptr->node_number == num)
                {
                    temp = ptr;
                }
                ptr = ptr->next_ptr;
            }
            return temp;
        }

        //fuction for creating the linked list and adding new node in linked list.
        void add_node(Node *n)
        {
            if (if_node_exists(n->node_number) != NULL)
            {
                cout << "Node already exists with node number " << n->node_number << "." << endl;
                cout << "Add another node with different node number." << endl;
            }
            else
            {
                if (first == NULL)
                {
                    first = n;
                    cout << "New Node of node number " << n->node_number << " and data " << n->data << " ADDED." << endl;
                }
                else
                {
                    Node *ptr = first;
                    while (ptr->next_ptr != NULL)
                    {
                        ptr = ptr->next_ptr;
                    } 
                    ptr->next_ptr = n;
                    cout << "New Node of node number " << n->node_number << " and data " << n->data << " ADDED." << endl;
                }
            }
        }
    
        //function to insert a new node after a given node.
        void insert_node_after(int num, Node *n)
        {
            Node *ptr = if_node_exists(num);
            if(ptr == NULL)
            {
                cout << "No node exists with node number " << num << endl;
            }
            else
            {
                if(if_node_exists(n->node_number) != NULL)
                {
                    cout << "Node already exists with node number " << n->node_number << "." << endl;
                    cout << "Insert another node with different node number." << endl;
                }
                else
                {
                    n->next_ptr = ptr->next_ptr;
                    ptr->next_ptr = n;
                    cout << "New Node Inserted after node number " << num << "."<< endl;
                }
            }
        }
        
        //function for deleting a particular node.
        void delete_node_at_node_number(int num)
        {
            if(first == NULL)
            {
                cout << "Singly linked list is empty. Can't delete." << endl;
            }
            else if(first != NULL)
            {
                if(first->node_number == num)
                {
                    first = first->next_ptr;
                    cout << "Node " << num << " DELETED." << endl;
                }
                else
                {
                    Node *temp = NULL;
                    Node *prevptr = first;
                    Node *currentptr = first->next_ptr;
                    while(currentptr != NULL)
                    {
                        if(currentptr->node_number == num)
                        {
                            temp = currentptr;
                            currentptr = NULL;
                        }
                        else
                        {
                            prevptr = prevptr->next_ptr;
                            currentptr = currentptr->next_ptr;
                        }
                    }
                    if(temp != NULL)
                    {
                        prevptr->next_ptr = temp->next_ptr;
                        cout << "Node " << num << " DELETED." << endl;
                    }
                    else
                    {
                        cout << "Node doesn't exist with node number " << num << endl;
                    }
                }
            }
        }
        
        //function for updating a particular node with new data.
        void update_node_at_node_number(int num, int d)
        {
            Node *ptr = if_node_exists(num);
            if(ptr != NULL)
            {
                ptr->data = d;
                cout << "Node data updated successfully." << endl;
            }
            else
            {
                cout << "Node doesn't exist with the node number " << num << endl;
            }
        }

        //funtion for reversing the linked list.
        void reverse_linked_list()
        {
            Node *n, *q, *r;
            n = first;
            q = NULL;
            r = NULL;
            while(n != NULL)
            {
                r = q;
                q = n;
                n = n->next_ptr;
                q->next_ptr = r;
            }
            first = q;
        }
        
        //fuction for traversing and printing the linked list.
        void traverse_and_display_linked_list()
        {
            if(first == NULL)
            {
                cout << "No nodes in the singly linked list." << endl;
            }
            else
            {
                cout << "LINKED LIST in (node_number, data) format: ";
                Node *temp = first;
                
                while(temp != NULL)
                {
                    cout << "(" << temp->node_number << ", " << temp->data << ") --> ";
                    temp = temp->next_ptr;
                }
                
                cout << endl;
            }
        }
};

int main()
{
    int add_this_many_nodes, insert_this_many_node, delete_this_many_node, update_this_many_node;
    singly_linked_list s;
    
    cout << "=========================CREATING LINKED LIST=========================" << endl << endl;
    cout << "Enter the number of nodes you want to add: ";
    cin >> add_this_many_nodes;
    cout << endl;
    for(int i=0; i<add_this_many_nodes; i++)
    {
        int data_d, num;
        Node *new_node = new Node();
        cout << "Enter the node number of the new node you want to add: ";
        cin >> num;
        cout << "Enter the data at the node number " << num << " you want to store: ";
        cin >> data_d;
        
        cout << endl;
        
        new_node->node_number = num;
        new_node->data = data_d;
       
        s.add_node(new_node);
        cout << endl;
        cout << "Printing the linked list after adding the new node." << endl;
        s.traverse_and_display_linked_list();
        cout << endl;
    }
    

    cout << "=========================INSERTING NEW NODES=========================" << endl << endl;
    cout << "Enter the number of nodes you want to insert: ";
    cin >> insert_this_many_node;
    for(int i=0; i<insert_this_many_node; i++)
    {
        int data_d, num, insert_node_num;
        Node *new_node = new Node();
        cout << endl << "Enter the node number after which you want to insert the new node: ";
        cin >> num;
        cout << "Enter the node number of the new node which you want to insert: ";
        cin >> insert_node_num;
        cout << "Enter the data at the new node number " << insert_node_num << " you want to store: ";
        cin >> data_d;
        
        cout << endl;
        
        new_node->node_number = insert_node_num;
        new_node->data = data_d;
        
        s.insert_node_after(num, new_node);
        
        cout << endl << "Printing the linked list after inserting the new node." << endl;
        s.traverse_and_display_linked_list();
        //cout << endl;
    }
    
    cout << endl;
    cout << "=========================DELETING NODES=========================" << endl << endl;

    cout << "Enter the number of nodes you want to delete: ";
    cin >> delete_this_many_node;
    for(int i=0; i<delete_this_many_node; i++)
    {
        int delete_this_node;
        cout << endl << "Enter the node number of the node you want to delete: ";
        cin >> delete_this_node;

        cout << endl;

        s.delete_node_at_node_number(delete_this_node);

        cout << endl;

        cout << "Printing the linked list after deleting the node " << delete_this_node << endl;
        s.traverse_and_display_linked_list();
        //cout << endl;
    }
    
    cout << endl;
    cout << "=========================UPDATING LINKED LIST=========================" << endl << endl;

    cout << "Enter the number of nodes you want to update: ";
    cin >> update_this_many_node;
    for(int i=0; i<update_this_many_node; i++)
    {
        int update_this_node, data_d;
        cout << endl << "Enter the node number of the node you want to update: ";
        cin >> update_this_node;
        cout << "Enter the new data with which you want to update the node " << update_this_node << ": ";
        cin >> data_d;

        cout << endl;
        
        s.update_node_at_node_number(update_this_node, data_d);
        
        cout << endl;
        
        cout << "Printing the linked list after updating the node with new data." << endl;
        s.traverse_and_display_linked_list();
        //cout << endl;
    }
    cout << endl;
    cout << "=========================REVERSING LINKED LIST=========================" << endl << endl;
    cout << "Printing the linked list after reversing." << endl;
    s.reverse_linked_list();
    s.traverse_and_display_linked_list();

    return 0;
}