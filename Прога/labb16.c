#include <stdio.h>
#include <stdlib.h>

typedef struct Node { //определение структуры
    struct Node* nextList;
    int data;
    struct Node* nextNode;
} Node;

Node* addNode(Node* head, int data, Node** tail) {//Определение функции `addNode`, которая добавляет новый узел в список
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->nextList = NULL;

    if (head == NULL) {
        *tail = newNode;
        return newNode;
    } else {
        (*tail)->nextNode = newNode;
        *tail = newNode;
        return head;
    }
}

void printList(Node* head) {//выводит все элементы начиная с верха
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->nextNode;
    }
    printf("\n");
}

void freeList(Node* head) { //освобождает память
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->nextNode;
        free(temp);
    }
}

int main() {
    Node* firstList = NULL;//объявление списков для двух списков
    Node* secondList = NULL;
    Node *firstTail = NULL, *secondTail = NULL;
    Node* S = NULL;
    int data, count = 0;

    printf("Enter a sequence of numbers (0 to end entry)\n");
    while (1) { //pапуск бесконечного цикла для ввода чисел
        scanf("%d", &data);//ввод числа
        if (data == 0) break;//Проверка, если введен 0, то выход из цикла

        count++;//увеличение счётчика
        if (count % 2 == 1) {//Проверка на четность счетчика для добавления элементов в разные списки
            firstList = addNode(firstList, data, &firstTail);
            if (S == NULL) S = firstList;
        } else {
            secondList = addNode(secondList, data, &secondTail);
            if (S == NULL) S = secondList;
        }
    }

    if (firstTail && secondTail) {// Объединение двух списков в кольцевую структуру, если оба списка заполнены
        firstTail->nextList = secondList;
        secondTail->nextList = firstList;
    }

    printf("First list:\n");
    printList(firstList);

    printf("Second list:\n");
    printList(secondList);

    printf("Press 'a' to go left and 'd' to go right. Any other key to exit\n");//Вывод сообщения с инструкциями для пользователя
    Node *lst_ptr = firstList;
    Node* Snd_ptr = secondList;
    char c;
    getchar();
    while(1) { //Бесконечный цикл для перемещения по списку
        char key = 'f';

        printf("Value: %d; Addr prev: %p next: %p\n", lst_ptr->data, lst_ptr->nextList, lst_ptr->nextNode);
        scanf("%c%*c", &key);//Считывание символа в переменную `key


        printf("Key entered: '%c'\n", key);
        if (key == 'a') {
            if (lst_ptr->nextList)
                lst_ptr = lst_ptr->nextList;
            else
                printf("Can't go here: prev is NULL\n");

        } else if(key == 'd') {
            if (lst_ptr->nextNode)
                lst_ptr = lst_ptr->nextNode;
            else
                printf("Can't go here: next is NULL\n");

        } else {
            printf("Exiting..\n");
            break;
        }
    }

    freeList(firstList); //освобождение помяти занятой 
    freeList(secondList);

    return 0;
}