#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_URL_LENGTH    21

// DO NOT MODIFY //
struct Node {
    char url[MAX_URL_LENGTH];
    struct Node* prev;
    struct Node* next;
};

typedef struct {
    struct Node* head;
    struct Node* cursor;
} BrowserHistory;
// DO NOT MODIFY //

BrowserHistory* browserHistoryCreate(char * homepage) {
    BrowserHistory * new = (struct Node* )malloc(sizeof(BrowserHistory));
    struct Node* head = (struct Node* )malloc(sizeof(struct Node));
    struct Node* cursor = (struct Node* )malloc(sizeof(struct Node));
    
    new -> head = head;
    new -> cursor = cursor;
    
    new -> head ->prev= NULL;
    new -> head -> next = new -> cursor;
    new -> cursor -> prev = new -> head;
    new -> cursor -> next = NULL;
    
    strcpy(new -> cursor -> url, homepage);
    
    return new;
}

void browserHistoryVisit(BrowserHistory* obj, char * url) {
    struct Node * new = (struct Node* )malloc(sizeof(struct Node));
    new -> next = NULL;
    new -> prev = obj -> cursor;
    strcpy(new->url , url);
    
    if(obj->cursor-> next != NULL){
        struct Node* temp = obj->cursor-> next;
        while(temp != NULL){
            struct Node * next = temp -> next;
            free(temp);
            temp = next;
        }
        obj-> cursor -> next = NULL;
    }
    
    obj->cursor-> next = new;
    obj->cursor =new;
    
}

char * browserHistoryBack(BrowserHistory* obj, int steps) {
   while (obj->cursor -> prev != obj->head && steps >0){
         obj -> cursor = obj -> cursor -> prev;
         steps -= 1;
     }
    return obj->cursor->url;
}

char * browserHistoryForward(BrowserHistory* obj, int steps) {
  while (obj->cursor -> next != NULL && steps >0){
         obj -> cursor = obj -> cursor -> next;
         steps -= 1;
     }
    return obj->cursor->url;
}

void browserHistoryFree(BrowserHistory* obj) {
   struct Node* temp = obj -> head;
    
    while ( temp != NULL){
        struct Node * new = temp -> next;
        free(temp);
        temp = new;
    }
    free(obj);
}

// DO NOT MODIFY //
int main() {
      int i=0, count =0;
    char arg1[500];
    char arg2[500];
    char cmd[100][500];
    char parm[100][500];
    char output[100][500];

    fgets(arg1,500,stdin);
    fgets(arg2,500,stdin);
        if (arg1[strlen(arg1) - 1] == '\n') {
        arg1[strlen(arg1)-1]='\0';
        }
        if (arg2[strlen(arg2) - 1] == '\n') {
            arg2[strlen(arg2)-1]='\0';
        }
    char *token = strtok(arg1, " "); // 공백으로 문자열 나누기

    while (token != NULL) {
        strcpy(cmd[i], token); // 나눈 문자열을 배열에 저장하기
        token = strtok(NULL, " ");
        i++;
    }

    count = i;

    i=0;
    token = strtok(arg2, " "); // 공백으로 문자열 나누기
    while (token != NULL) {
        strcpy(parm[i], token); // 나눈 문자열을 배열에 저장하기
        token = strtok(NULL, " ");
        i++;
    }


    BrowserHistory* obj;
    for(i=0; i<count; i++) {
        if (strcmp(cmd[i],"BrowserHistory") == 0) {
            obj = browserHistoryCreate(parm[i]);
        } else if (strcmp(cmd[i],"visit") == 0) {
            browserHistoryVisit(obj, parm[i]);
        } else if (strcmp(cmd[i],"back") == 0) {
            printf("%s ", browserHistoryBack(obj,atoi(parm[i])));
        } else if (strcmp(cmd[i],"forward") == 0) {
            printf("%s ", browserHistoryForward(obj,atoi(parm[i])));
        }
    }
    browserHistoryFree(obj);
    return 0;
}
// DO NOT MODIFY //
