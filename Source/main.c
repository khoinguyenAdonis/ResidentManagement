#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C_EXERCISE\BTL_QLCD\Header\menu.h"

#define FILEPATH "D:\\c_c++\\ADVANCED-C-C-ALGORITHM-\\C_EXERCISE\\BTL_QLCD\\10000_Members.csv"


MemberNode *array = NULL;
int main(){
    linkFileCSV(FILEPATH,&array);
    long number = numberOfList(&array);
    TreeNode *bstRoot = buildTree(array,0,number);// xay dung build tree
    menu(FILEPATH,&array,bstRoot);
    return 0;
}

