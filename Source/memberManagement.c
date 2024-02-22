#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C_EXERCISE\BTL_QLCD\Header\memberManagement.h"

/*
    Function: addMember
    Description: This function use add member for list and file csv  
    input :filename,member, pointer to poniter ptp
    output : none

*/
void addMember( char* filename, Member* member,MemberNode **ptp){

    FILE* file = fopen(filename, "a");  // Mở file ở chế độ append (nối thêm vào cuối file)
    if (file == NULL) {
        perror("Khong the mo file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%s,%s,%s,%s\n", member->uid, member->roomNumber, member->name,member->licensePlate);
    fclose(file);
    push_back(ptp,*member);
}

/*
    Function: deleteMember
    Description: This function use delete member for list and file csv  
    input :filename,uid, pointer to poniter ptp, pointer tree
    output : none

*/
void deleteMember(char* filename, char* uid, TreeNode *head,MemberNode **ptp){
    deleteNode(head,uid,ptp);
    removeDataFileCSV(filename);
    writeFileCSV(filename,ptp);
}
/*
    Function: editMember
    Description: This function use editMember member for list and file csv  
    input :filenpath,uid, pointer to poniter ptp, pointer tree,new member
    output : none

*/
void editMember(char* filename, Member updatedMember,TreeNode* root,char* key,MemberNode** head){
    updateNode(root, key, updatedMember,head);
    removeDataFileCSV(filename);
    writeFileCSV(filename,head);

}