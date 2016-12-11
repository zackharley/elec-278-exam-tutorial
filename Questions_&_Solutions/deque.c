#include <stdio.h>

#define MAX 20

int deque[MAX];
int count = 0;

void addFront(int);
void addBack(int);
int removeFront();
int removeBack();
void display();

void addFront(int num) {
    if(count == MAX) return;

    if(count > 2) {        
        for(int i = count - 1; i > 0; i--) {
            deque[i] = deque[i - 1];
        }
    } else if(count == 2) {
        deque[2] = deque[1];
        deque[1] = deque[0];
    } else {
        deque[1] = deque[0];
    }

    deque[0] = num; 

    count++;
}

void addBack(int num) {
    if(count == MAX) return;
    deque[count] = num;
    count++;
}

int removeFront() {
    if(count == 0) return 0;
    int num = deque[0];
    for(int i = 0; i < count - 1; i++) {
        deque[i] = deque[i + 1];
    }
    deque[--count] = 0;
    return num;
}

int removeBack() {
    if(count == 0) return 0;
    int num = deque[count - 1];
    deque[--count] = 0;
    return num;
}

void display() {
    printf("front->");
    for(int i = 0; i < MAX; i++) {
        printf(" %d", deque[i]);
    }
    printf("<-rear\n");
}

int main() {
    int num;
    addBack(12);
    display();
    addFront(42);
    display();
    addFront(9);
    display();
    addBack(14);
    display();
    num = removeFront();
    if(num != 0) printf("Removed %d from deque.\n", num);
    display();
    num = removeBack();
    if(num != 0) printf("Removed %d from deque.\n", num);
    display();
    num = removeFront();
    if(num != 0) printf("Removed %d from deque.\n", num);
    display();
    num = removeFront();
    if(num != 0) printf("Removed %d from deque.\n", num);
    display();

    return 0;
}