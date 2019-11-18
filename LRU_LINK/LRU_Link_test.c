
#import <UIKit/UIKit.h>
#import "AppDelegate.h"

struct Node {
    int data;
    struct Node *next;
};

void removeLastNode(struct Node *head) {
    struct Node *pNode = head;
    struct Node *preNode = nil;
    while (1) {
        if(pNode->next == nil) {
            preNode->next = nil;
            free(pNode);
            pNode = nil;
            break;
        }

        preNode = pNode;
        pNode = pNode->next;
    }
}

struct Node *getNewNode(int data) {
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = data;
    new->next = nil;
    return new;
}

bool checkFull(struct Node *head,uint maxCapacity) {
    uint curCount = 0;
    struct Node *pNode = head;
    while (true) {
        pNode = pNode->next;
        curCount += 1;
        if(!pNode) {
            break;
        }
    }
    return curCount == maxCapacity;
}

struct Node* addCache(struct Node *head,struct Node *new) {
    struct Node *pNode = head;
    struct Node *preNode = nil;
    if(head->data == new->data) head->data = new->data;
    while (true) {
        if(new->data == pNode->data) {
            if(preNode) {
                preNode->next = pNode->next;
                new->next = head;
                free(pNode);
                pNode = nil;
                return new;
            }
        }

        preNode = pNode;
        pNode = pNode->next;
        if(pNode == nil) break;
    }

    if (!checkFull(head,5)) {
        new->next = head;
    } else {
        removeLastNode(head);
        new->next = head;
    }
    
    return new;
}

int main(int argc, char * argv[]) {
  struct Node *head = getNewNode(0);
  struct  Node *new = getNewNode(1);
  head = addCache(head,new);
  struct Node *new1 = getNewNode(2);
  head = addCache(head,new1);
  struct Node *new2 = getNewNode(3);
  head = addCache(head,new2);

    struct Node *new3 = getNewNode(2);
    head = addCache(head,new3);
    
    struct Node *new4 = getNewNode(4);
    head = addCache(head,new4);
    
    struct Node *new5 = getNewNode(5);
    head = addCache(head,new5);
   struct Node *pNode = head;
   do {
       printf("%i \n",pNode->data);
       pNode = pNode->next;
   } while (pNode != nil );
}

