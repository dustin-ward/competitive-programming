#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    printf("%s", (N%2 ? "Alice\n" : "Bob\n"));
    return 0;
}