#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C_EXERCISE\BTL_QLCD\Header\menu.h"


void menu(char* filename,MemberNode **ptp, TreeNode *head){
    int option;
    Member MemberInit;
    char *uid;
    while (1){
        MENU
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            system("cls");
            printf("---------------==---ADD_Member--------------------");
            MEMBERIFO
            addMember(filename,&MemberInit,ptp);
            printf("Da them cu dan vao cuoi danh sach");
            break;
        case 2:
            printf("------------------DELETE_MEMBER-----------------\n");
            SEARCHUID
            deleteMember(filename,uid,head,ptp);
            printf("Da xoa cu dan");
            break;
        case 3:
            printf("------------------EDIT_MEMBER-------------------\n");
            SEARCHUID
            MEMBERIFO
            editMember(filename,MemberInit,head,uid,ptp);
            break;
        case 4:
            SEARCHMEMBER
            break;
        case 5:
            printf("------------------LIST_MEMBER-------------------\n");
            inorderTraversal(head);
            break;
        case 6:
             exit(0);
            break;
        default:
            break;
        }

    }

}