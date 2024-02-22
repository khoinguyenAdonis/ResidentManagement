#include "D:\c_c++\ADVANCED-C-C-ALGORITHM-\C_EXERCISE\BTL_QLCD\Header\csvManagement.h"
/*
    Function: removeDataFileCSV
    Description: This function use remove data file csv 
    input : filePath
    output : none

*/
void removeDataFileCSV(char* filePath) {
    FILE* file = fopen(filePath, "w");  // Mở file ở chế độ ghi đè
    if (file == NULL) {
        perror("Khong the mo file");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}
/*
    Function: writeFileCSV
    Description: This function use write data from list to file csv 
    input : filePath, member
    output : none

*/
void writeFileCSV(char* filePath, MemberNode** member) {
    FILE* file = fopen(filePath, "a");  // Mở file ở chế độ nối thêm
    if (file == NULL) {
        perror("Khong the mo file");
        exit(EXIT_FAILURE);
    }
    MemberNode* current = *member;
    fprintf(file, "%s,%s,%s,%s\n","uID","roomNumber","name","licensePlates");
    while (current != NULL) {
        fprintf(file, "%s,%s,%s,%s\n",current->data.uid,current->data.roomNumber,current->data.name,current->data.licensePlate);
        current = current->next;
    }
    fclose(file);
}
/*
    Function: linkFileCSV
    Description: This function use read and linked member from file csv 
    input : filePath,pointer to ponter list Membernode
    output : none

*/
void linkFileCSV(char* filePath, MemberNode **ptp) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        perror("Can't open file");
        exit(EXIT_FAILURE);
    }

    char line[110];
    fgets(line, sizeof(line), file); // Bỏ qua dòng tiêu đề

    while (fgets(line, sizeof(line), file) != NULL) {
        Member member;
        sscanf(line, "%[^,],%[^,],%[^,],%[^\n]", member.uid, member.roomNumber, member.name, member.licensePlate  );

        push_back(ptp,member);
    }

    fclose(file);
    sortList(ptp);
    removeDataFileCSV(filePath);
    writeFileCSV(filePath,ptp);
}
