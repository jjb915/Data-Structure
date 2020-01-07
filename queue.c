#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
} Queue;

Queue* create_queue(unsigned capacity)
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->front = queue->size = 0;
	queue->rear = -1;
	queue->capacity = capacity;
	queue->array = (int*)malloc(sizeof(int) * capacity);
	return queue;
}

int is_full(Queue* queue)
{
	return queue->size == queue->capacity;
}

int is_empty(Queue* queue)
{
	return queue->size == 0;
}

void enqueue(Queue* queue, int item)
{
	if (is_full(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	++queue->size;
	queue->array[queue->rear] = item;
	printf("%d enqueued\n", item);
}

int dequeue(Queue* queue)
{
	if (is_empty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	--queue->size;
	return item;
}

int front(Queue* queue)
{
	if (is_empty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

int rear(Queue* queue)
{
	if (is_empty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}

int main() 
{ 
	Queue* queue = create_queue(1000); 

	enqueue(queue, 10); 
	enqueue(queue, 20); 
	enqueue(queue, 30); 
	enqueue(queue, 40); 

	printf("%d dequeued from queue\n\n", dequeue(queue)); 

	printf("Front item is %d\n", front(queue)); 
	printf("Rear item is %d\n", rear(queue)); 

	return 0; 
} 
