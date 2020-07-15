#include <stdio.h>
#include <stdlib.h>

#define M_SIZE 8
#define S_NUM 4

void push(int i, int k);
int pop(int i);
bool stackFull(int i);
void init_stack();

int stack[M_SIZE];
int top[S_NUM];
int bottom[S_NUM + 1];

int main(int argc, char* argv[])
{
    init_stack();

    // 멀티 스택 테스트

    return 0;
}

bool stackFull(int i)
{
    int j, k;
    for (j = i + 1; j < S_NUM; j++) {
        if (top[j] != bottom[j + 1]) {

            for (k = top[j] + 1; k > bottom[i + 1] + 1; k--)
                stack[k] = stack[k - 1];

            for (k = i + 1; k <= j; k++) {
                top[k] += 1;
                bottom[k] += 1;
            }
            return false;
        }
    }
    for (j = i - 1; j >= 0; j--) {
        if (top[j] != bottom[j + 1]) {

            for (k = bottom[j + 1]; k < top[i]; k++)
                stack[k] = stack[k + 1];

            for (k = j + 1; k <= i; k++) {
                top[k] -= 1;
                bottom[k] -= 1;
            }

            return false;
        }
    }
    return true;
}

void push(int i, int k)
{
    if (top[i] == bottom[i + 1]) {
        if (!stackFull(i))
            stack[++top[i]] = k;
        else
            printf("stack full\n");
    }
    else {
        stack[++top[i]] = k;
    }
}

int pop(int i)
{
    if (top[i] == bottom[i])
        return -999;

    return stack[top[i]--];
}

void init_stack()
{
    int i;
    for (i = 0; i < S_NUM; i++)
        top[i] = bottom[i] = (M_SIZE / S_NUM) * i - 1;
    bottom[S_NUM] = M_SIZE - 1;
}
