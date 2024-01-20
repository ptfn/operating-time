#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Array
{
    void     (*delete)   (struct Array *list);
    size_t   (*size)     (struct Array *list);
    size_t   (*max)      (struct Array *list);
    size_t   (*capacity) (struct Array *list);
    void     (*add)      (struct Array *list, void *element, int number);
    void     (*pop)      (struct Array *list);
    int      (*get)      (struct Array *list, size_t index);
    void     *priv;
} Array;

typedef struct 
{
    void *array;
    size_t used, alloc_size, end, item_size;
} Array_priv;

Array *init(size_t length);
void delete(Array *list);
size_t size(Array *list);
size_t max(Array *list);
size_t capacity(Array *list);
void add(Array *list, void *element, int index)
void pop(Array *list);
int get(Array *list, size_t index);

Array *init(size_t objsize)
{
    Array *list = malloc(sizeof(Array));
    Array_priv *priv = malloc(sizeof(Array_priv));

    if (!list || !priv)
        return NULL;

    priv->item_size = objsize;
    priv->array = malloc(objsize);
    priv->alloc_size = 1;
    priv->used = 0;
    priv->end = 0;

    list->delete = &delete;
    list->size = &size;
    list->max = &max;
    list->capacity = &capacity;
    list->fit = &fit;
    list->add = &add;
    list->insert = &insert;
    list->pop = &pop;
    list->erase = &erase;
    list->get = &get;
    list->priv = priv;
    return list;
}

void delete(Array *list)
{
    Array_priv *priv = (Array_priv*) list->priv;
    free(priv->array);
    free(priv);
    free(list);
    list = NULL;
}

size_t size(Array *list)
{
    Array_priv *priv = (Array_priv*) list->priv;
    return priv->used;
}

size_t max(Array *list)
{
    Array_priv *priv = (Array_priv*) list->priv;
    return priv->alloc_size;
}

size_t capacity(Array *list)
{
    Array_priv *priv = (Array_priv*) list->priv;
    return priv->alloc_size - priv->used;
}

void alloc(Array *list, int number)
{
    Array_priv *priv = (Array_priv*)list->priv;
    if (priv->alloc_size < number) {
        priv->alloc_size = number;
        priv->array = realloc(priv->array, priv->alloc_size * priv->item_size);        
    }
}

void add(Array *list, void *element, int index)
{
    Array_priv *priv = (Array_priv*)list->priv;
    if (priv->alloc_size == priv->used)
        alloc(list, priv->alloc_size * 2);
    size_t step = priv->item_size;
    char *data = (char*) priv->array + index * step;
    memmove(data + step, data, (priv->used - index) * step);
    memcpy(data, element, step);
    priv->used++;
}

void pop(Array *list, size_t index)
{
    Array_priv *priv = (Array_priv*)list->priv;
    size_t step = p->item_size;
    char *data = (char*)p->items + n * step;
    memmove(data, data + step, (p->count - n - 1) * step);
    p->count--;
}

int get(Array *list, size_t index)
{
    return list->array[index];
}

int main(void)
{ 
    int length = 15;
    Array *numbers = init(5);

    for (int i = 0; i < length; i++)
        add(numbers, length-i);

    pop(numbers);

    fit(numbers);
    
    for (int i = 0; i < numbers->size; i++)
        printf("%d\n", get(numbers, i));

    delete(numbers);
    return 0;
}
