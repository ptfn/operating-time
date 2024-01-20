#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    char oper;
    int  prio; 
} Operator;

int operation(int a, int b, char oper)
{
    int result = 0;

    switch (oper) {
        case '|': result = (a*10)+b; break;
        case '^': result = (int)pow(a, b); break;
        case '*': result = a * b; break;
        case '/': result = a / b; break; // Problem not count float numbers only int
        case '+': result = a + b; break;
        case '-': result = a - b; break;    
    default:
        break;
    }
    return result;
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    putchar('\n');
}

void action(const char *string, int size, char *result)
{
    int size_oper = 0, size_num = 0, result_number = 0;

    for (int i = 0; i < size; i++) {
        switch (string[i]) {
            case '+': case '-': case '*': case '/': case '|': case '^':
                size_oper++; break;
            case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                size_num++; break;
        default:
            break;
        } 
    }

    Operator operators[size_oper];
    int number[size_num];

    for (int i = 0, k = 0, n = 0; i < size; i++) {
        switch (string[i]) {
            case '|':
                operators[k].oper = string[i];
                operators[k].prio = 1;
                k++; break;
            case '^': 
                operators[k].oper = string[i];
                operators[k].prio = 2;
                k++; break;
            case '*': 
                operators[k].oper = string[i];
                operators[k].prio = 3;
                k++; break;
            case '/':
                operators[k].oper = string[i];
                operators[k].prio = 3;
                k++; break;
            case '+': 
                operators[k].oper = string[i];
                operators[k].prio = 4;
                k++; break;
            case '-': 
                operators[k].oper = string[i];
                operators[k].prio = 4;
                k++; break;
            case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                number[n] = string[i] - '0'; n++; break;
        default:
            break;
        } 
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < size_oper; j++) {
            if (operators[j].prio == (i+1)) {
                int s = 0, e = 1, k = 0;

                if (number[j-s] == 0) {
                    while (k > 0) {
                        if (number[j-k] != 0)
                            s = k; 
                        k++;
                    }
                } else if (number[j+e] == 0) {
                    while (k < size_num) { 
                        if (number[j+k] != 0)
                            e = k;
                        k++;
                    }
                    
                }

                number[j+e] = operation(number[j-s], number[j+e], operators[j].oper);
                number[j+s] = 0;
            }
        }
    }

    for (int i = 0; i < size_num; i++)
        if (number[i] != 0)
            result_number = number[i];

    sprintf(result, "%d", result_number);
}

char *slice(const char *string, size_t start, size_t end)
{
    char *buffer = (char*)malloc((end-start) * sizeof(char));
    size_t j = 0;
    for (size_t i = start; i <= end; ++i)
        buffer[j++] = string[i];
    buffer[j] = 0;
    return buffer;
}

char *gluing(char *string, char *temp_number, int size, int start, int end)
{
    int offset = 0;
    char *temp = (char*)malloc(size + strlen(temp_number) * sizeof(char)) ;
    offset += sprintf(temp, "%s", slice(string, start, end));
    offset += sprintf(temp+offset, "%s", temp_number);
    offset += sprintf(temp+offset, "%s", slice(string, start, end));
    return temp; 
}

int parser(char *string, int size)
{
    int i = 0, begin, end;
    char temp_number[256], result[256]; // malloc in condition

    while (i < size) {
        if (string[i] == '(') {
            begin = i;
        } else if (string[i] == ')') {
            end = i;
            char *temp = slice(string, begin, end);
            action(temp, strlen(temp), temp_number); // len is (end - begin)
            char *temp_gluing = gluing(string, temp_number, size, begin, end);
            puts(temp_gluing);
            i = 0;
        }
    }
    return 0;
}

int main(void)
{
    char *string = "(2+1)/2";
    char result[10];
    action(string, strlen(string), result);
    puts(result);
    return 0;
}
