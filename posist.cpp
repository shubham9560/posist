#include <bits/stdc++.h>
#include<string>
using namespace std;


//Defining the schema for a basic Node.

struct Data {
    int ownerId;
    float value;
    char owner_name[50];

};

struct node {
    time_t time_now ;
    string time_in_date ;   // to convert timestamp to user readable date using strftime()
    Data *data ;
    string nodeId ;
    int nodeNumber ;
    node *referenceNodeid ;

    std::vector<node *> childReferenceNodeid;                 // Array of addresses.

    node *genesisReferenceNodeid;
    set<int> HashValue;         // Hash of value of the set.

    bool isEncrypted;                       //Will block access to node if it has been encrypted.
    string password;


};

// TASK 1
//Creating the first Node i.e. genesis node.
node createGenesisNode(int node_number){

   node *n = new node ;
   n->time_now = time(0);    // Get current timestamp

   n->nodeNumber = node_number;
   stringstream ss;
    ss << node_number;
   n->nodeId = ss.str();
   cout<<"Enter DATA";
   cin>>n->data->ownerId;
   cin>>n->data->value;
   gets(n->data->owner_name);

   n->referenceNodeid = NULL;
   n->genesisReferenceNodeid = n;   // genesis node is created update address.
   n->HashValue = {n->time_now,n->data,n->nodeNumber,n->referenceNodeid,n->childReferenceNodeid,n->genesisReferenceNodeid}

 return n;                  // return address of genesis node for future purposes.
}

// TASK 2 and 3 can be achieved here
// Create set of child nodes for a given node, which we are finding using,
// node_number to query genesis node child nodes.
void addChildNode(int node_number,node *genesis,int current_node_number){

    node *l = *(genesis->childReferenceNodeid[node_number]);
    int i=1;
    while(i){
       node *p = new node;

         p->nodeNumber = current_node_number;
         p->nodeId = to_string(nodeNumber);
            cout<<"Enter DATA";
        cin>>p->data->ownerId;
        cin>>p->data->value;
        gets(p->data->owner_name);
        n->referenceNodeid = &l ;      //This node's parent address will be &l
        n->genesisReferenceNodeid = &genesis;   //copying genesis node address we received.
        n->HashValue = {n->time_now,n->data,n->nodeNumber,n->referenceNodeid,n->childReferenceNodeid,n->genesisReferenceNodeid}

        cout<<"Add more (1/0)";
        cin>>i;
    }
}

// TASK 3/4 Encrypting and Decrypting the data using a key.
void encrypt(node *n){

    n->isEncrypted = true;
    cout<<"Enter owner password";
    cin>>n->password;

    //Using a basic approach to encrypt by subtracting some value from ASCII of character.
    for(i = 0; (i < 100 && n->password[i] != '\0'); i++)
        n->password[i] = n->password[i] + 2;


}

// Would take the address of node and a password string and return non-zero if passwords match;
int decrypt(node *given_node,string pass){


        for(i = 0; (i < 100 && pass[i] != '\0'); i++)
        n->pass[i] = n->pass[i] + 2;

        if(given_node->password == pass){
            return 1;
        }
        else{
            return 0;
        }
}

// TASK 7 Changing ownership through a different password

void change_owner(node *given_node){

    string pass1,pass2;
    cout<<"Owner one enter password";
    cin>>pass;
    if(decrypt(given_node,pass)){
        cout<<"Ownership of node will be changed,enter new owner id";
        cin>>given_node->data->owner_name;
        void encrypt(given_node);
    }
}

//longest chain [ TASK 8-9 ]
void longest_chain(node *given_node){
    //This can be solved by applying DFS on the genesis node,i.e. the root node or any other node
    //whose address is given by using child node pointers array.
}

void merge_node(node *node1, node* node2){
    //Add Data of both nodes.
    // Use DFS to calculate the longer chain from two.
    //Which is larger ,its password is retained.
}

int main(){
 static int no;
 no++;                               //Would keep a static variable to keep current count of nodes between function calls,
                                     //as no database is there.
 node *gen = createGenesisNode(no);
 n++;
 addChildNode(1,gen,n);
 return 0;
}

