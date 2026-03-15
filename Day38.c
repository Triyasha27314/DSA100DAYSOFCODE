/*Problem: Deque (Double-Ended Queue)
A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides 
more flexibility than a standard queue or stack.*/

#include <stdio.h>
#include <string.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int empty() 
{
    return (front == -1);
}

int size() 
{
    if (empty()) return 0;
    return rear - front + 1;
}

void push_front(int x) 
{
    if (front == -1) 
    {
        front = rear = 0;
    } 
    else if (front > 0) 
    {
        front--;
    } 
    else 
    {
        printf("Deque Overflow\n");
        return;
    }
    deque[front] = x;
}

void push_back(int x) 
{
    if (front == -1) 
    {
        front = rear = 0;
    } 
    else if (rear < MAX - 1) 
    {
        rear++;
    } 
    else 
    {
        printf("Deque Overflow\n");
        return;
    }
    deque[rear] = x;
}

void pop_front() 
{
    if (empty()) 
    {
        printf("Deque Underflow\n");
        return;
    }

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back() 
{
    if (empty()) 
    {
        printf("Deque Underflow\n");
        return;
    }

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

int getFront() 
{
    if (empty()) return -1;
    return deque[front];
}

int getBack() 
{
    if (empty()) return -1;
    return deque[rear];
}

void clear() 
{
    front = rear = -1;
}

void reverse() 
{
    if (empty()) return;

    int i = front, j = rear;
    while (i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

void sortDeque() 
{
    if (empty()) return;

    for (int i = front; i <= rear; i++) {
        for (int j = i + 1; j <= rear; j++) {
            if (deque[i] > deque[j]) {
                int temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }
}

void display() 
{
    if (empty()) {
        printf("Deque Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

int main() 
{
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    printf("Deque: ");
    display();

    printf("Front: %d\n", getFront());
    printf("Back: %d\n", getBack());
    printf("Size: %d\n", size());

    pop_front();
    pop_back();

    printf("After pops: ");
    display();

    reverse();
    printf("Reversed: ");
    display();

    sortDeque();
    printf("Sorted: ");
    display();

    return 0;
}