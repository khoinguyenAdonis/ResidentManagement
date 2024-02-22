#ifndef __MEMBERMANAGEMENT_H__
#define __MEMBERMANAGEMENT_H__
#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C_EXERCISE\BTL_QLCD\Header\csvManagement.h"


void addMember(char* filename, Member* member,MemberNode **ptp);
void deleteMember(char* filename, char* uid, TreeNode *head,MemberNode **ptp);
void editMember(char* filename, Member updatedMember,TreeNode* root,char* key,MemberNode** head);
#endif