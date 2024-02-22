#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C_EXERCISE\BTL_QLCD\Header\linkedList.h"
/*
    struct : MemberNode
    Description: This function use create member
    input : member
    output : MemberNode

*/
MemberNode* createMemberNode(Member member) {
    MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
    newNode->data = member;
    newNode->next = NULL;
    return newNode;
}

/*
    Function: push_back
    Description: This function use add new member list 
    input : pointer to ponter list Membernode, member
    output : none

*/

void push_back(MemberNode **ptp, Member member){
    MemberNode *temp = createMemberNode(member);    //0xc9
    if(*ptp == NULL){
        *ptp = temp;
    }else{
        MemberNode *p = *ptp;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

/*
    Function: sortList
    Description: This function use sort list 
    input : pointer to ponter list Membernode
    output : none

*/

void sortList(MemberNode **ptp){
    for (MemberNode *i = *ptp ; i != NULL; i = i->next)
    {
        MemberNode *minNode = i;
        for (MemberNode *j =  i->next ; j != NULL; j = j->next)
        {
            if (atoll(minNode->data.uid)>atoll(j->data.uid))
            {
                minNode = j;
            }
            
        }
        Member temp =  minNode->data;
        minNode->data = i->data;
        i->data = temp;      
    }
    
}
/*
    Function: numberOfList
    Description: This function use Count the number of elements
    input : pointer to ponter list Membernode
    output : number of elements

*/
long numberOfList(MemberNode **head){
    long lenght = 0;
    MemberNode *currence = *head;
    while (currence->next != NULL)
    {
        lenght ++;
        currence = currence->next;
    }
    return lenght+1;
    
}
/*
    Function: buildTree
    Description: This function use craet BuildTree
    input : pointer to ponter list Membernode, start, end
    output : buildtree

*/
TreeNode *buildTree(MemberNode *head, long start, long end) {
    if (head == NULL || start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    MemberNode *node = head;
    for (int i = start; i < mid; i++) {
        if (node->next == NULL) {
            break;
        }
        node = node->next;
    }
    TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
    root->data = *node;
    root->left = buildTree(head, start, mid - 1);
    root->right = buildTree(node->next, mid + 1, end);
    return root;
}

/*
    Function: addRemainingValuesToList
    Description: This function use add node of buildtree enter list
    input : pointer to ponter list Membernode, buildtree root
    output : none

*/
void addRemainingValuesToList(TreeNode* root, MemberNode** head) {
    if (root) {
        addRemainingValuesToList(root->left, head);
        MemberNode* newNode = (MemberNode*)malloc(sizeof(MemberNode));
        newNode->data = root->data.data;
        newNode->next = *head;
        *head = newNode;

        addRemainingValuesToList(root->right, head);
    }
}
/*
    Function: findMin
    Description: This function use Find the minimum value
    input :  buildtree root
    output : root

*/
TreeNode* findMin(TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

/*
    Function: searchNode
    Description: This function use find member for list 
    input :uid, BuildTree
    output : node of Buildtree

*/
static TreeNode* searchNode(TreeNode* root, char* key) {
    if (root == NULL || strcmp(key, root->data.data.uid) == 0) {
        return root;
    }
    if (strcmp(key, root->data.data.uid) < 0) {
        return searchNode(root->left, key);
    }

    return searchNode(root->right, key);
}
/*
    Function: deleteNote
    Description: This function use delete member for list 
    input :uid, pointer to poniter ptp
    output : update MemberNode of list

*/
TreeNode* deleteNode(TreeNode* root, char* key, MemberNode** head) {
    if (root == NULL) {
        return root;
    }
    TreeNode* nodeToDelete = searchNode(root, key);

    if (nodeToDelete == NULL) {
        return root;
    }

    if (nodeToDelete->left == NULL) {
        TreeNode* temp = nodeToDelete->right;
        free(nodeToDelete);
        MemberNode* current = *head;
        MemberNode* prev = NULL;
        while (current != NULL && strcmp(current->data.uid, key) != 0) {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }

        return temp;
    } else if (nodeToDelete->right == NULL) {
        TreeNode* temp = nodeToDelete->left;
        free(nodeToDelete);
        MemberNode* current = *head;
        MemberNode* prev = NULL;
        while (current != NULL && strcmp(current->data.uid, key) != 0) {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }

        return temp;
    }
    TreeNode* temp = findMin(nodeToDelete->right);
    nodeToDelete->data = temp->data;
    nodeToDelete->right = deleteNode(nodeToDelete->right, temp->data.data.uid, head);

    return root;
}
/*
    Function: updateNode
    Description: This function use update member for list 
    input :uid, pointer to poniter ptp, key, new member
    output : edit member

*/
void updateNode(TreeNode* root, char* key, Member newData, MemberNode** head) {
    TreeNode* nodeToUpdate = searchNode(root, key);

    if (nodeToUpdate != NULL) {
        strcpy(nodeToUpdate->data.data.roomNumber, newData.roomNumber);
        strcpy(nodeToUpdate->data.data.name, newData.name);
        strcpy(nodeToUpdate->data.data.licensePlate, newData.licensePlate);
        MemberNode* current = *head;
        while (current != NULL && strcmp(current->data.uid, key) != 0) {
            current = current->next;
        }

        if (current != NULL) {
            strcpy(current->data.roomNumber, newData.roomNumber);
            strcpy(current->data.name, newData.name);
            strcpy(current->data.licensePlate, newData.licensePlate);
        }
    }
}
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("UID: %s, Room Number: %s, Name: %s, License Plate: %s\n",
               root->data.data.uid, root->data.data.roomNumber, root->data.data.name, root->data.data.licensePlate);
        inorderTraversal(root->right);
    }
}