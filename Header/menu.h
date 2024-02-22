#ifndef __MENU_H__
#define __MENU_H__
#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C_EXERCISE\BTL_QLCD\Header\memberManagement.h"


#define MENU            system("cls");\
                        printf("-------------MEMBER_MANAGEMENT------------\n");\
                        printf("|>.1 Them cu dan                          \n");\
                        printf("|>.2 Xoa 1 cu dan                         \n");\
                        printf("|>.3 Sua thong tin cu dan                 \n");\
                        printf("|>.4 Tim kiem cu dan                      \n");\
                        printf("|>.5 Hien thi danh sach cu dan            \n");\
                        printf("|>.6 Thoat chuong trinh                   \n");\
                        printf("------------------------------------------\n");\
                        printf("    NHAP CHUC NANG TUONG UNG: ");


#define SEARCHMEMBER    system("cls");\
                        printf("-------------MEMBER_MANAGEMENT------------\n");\
                        printf("|>.1 Tiem kiem theo uid                   \n");\
                        printf("|>.2 Tiem kiem theo bien so xe            \n");\
                        printf("|                                         \n");\
                        printf("|                                         \n");\
                        printf("|                                         \n");\
                        printf("|                                         \n");\
                        printf("------------------------------------------\n");\
                        printf("    NHAP CHUC NANG TUONG UNG: ");


#define MEMBERIFO       printf("\nNhap_Thong_Tin_Cu_Dan\n");\
                        printf("|UID : "); \
                        fgets(MemberInit.uid, sizeof(MemberInit.uid), stdin);\
                        printf("|Room Number: ");\
                        fflush(stdin);\
                        fgets(MemberInit.roomNumber, sizeof(MemberInit.roomNumber), stdin);\
                        printf("|Name: ");\
                        fflush(stdin);\
                        fgets(MemberInit.name, sizeof(MemberInit.name), stdin);\
                        printf("License Plate: ");\
                        fflush(stdin);\
                        fgets(MemberInit.licensePlate, sizeof(MemberInit.licensePlate), stdin);
                        fflush(stdin);\

#define SEARCHUID       printf("|UID can tim: "); \
                        scanf("%s",uid);

void menu(char* filename,MemberNode **ptp, TreeNode *head);
#endif