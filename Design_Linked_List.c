typedef struct MyLinkedList {
    int value;
    struct MyLinkedList *next;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *dummy = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (dummy == NULL) return NULL;
    dummy -> next = NULL;
    return dummy;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0) return -1;
    MyLinkedList *curr = obj -> next; 
    for (int i = 0; i < index; i++)
    {
        if (curr == NULL) return -1;
        curr = curr -> next;
    }
    if (curr == NULL) return -1;
    return curr -> value;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {

    MyLinkedList *New_Node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (!New_Node) return;
    New_Node -> value = val;
    New_Node -> next = obj -> next;
    obj -> next = New_Node;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* new = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    new -> value = val;
    new -> next = NULL;

    MyLinkedList* tmp = obj;

    while (tmp -> next != NULL)
    {
        tmp = tmp -> next;
    }

    tmp -> next = new;

}
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0) return;
    MyLinkedList *tmp = obj;
    int i = 0;
    while (i < index)
    {
        if (!tmp -> next) return;
        tmp = tmp -> next;
        i++;
    }
    if (!tmp) return;
    MyLinkedList *New_Node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (!New_Node) return;

    New_Node -> value = val;
    New_Node -> next = tmp -> next;
    tmp -> next = New_Node;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || !obj->next) return;

    MyLinkedList *tmp = obj;

    for (int i = 0; i < index; i++)
    {
        if (!tmp -> next) return;
        tmp = tmp -> next;
    }
    if (!tmp -> next) return;
    MyLinkedList *tmp2 = tmp -> next;
    tmp -> next = tmp2 -> next;
    free(tmp2);
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList *tmp = obj, *next;
    while (tmp != NULL)
    {
        next = tmp -> next;
        free(tmp);
        tmp = next;
    }
}
