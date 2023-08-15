#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// 추가로 헤더파일이 필요한 경우 자유롭게 추가해도 됩니다.

#define MAX_LEN	100

// 스택 구조체
typedef struct {
    double* arr;
    int top;
}Stack;

// 스택 초기화 함수
void initStack(Stack* stack, int size) {
    stack->arr = (double*)malloc(size * sizeof(double));
    stack->top = -1;
}

// 스택 삽입 함수
void push(Stack* stack, double value) {
	stack -> arr[++(stack -> top)] = value;
    // YOUR CODE
}

// 스택 삭제 함수 //끝
double pop(Stack* stack) {
	if (isEmpty(stack)){
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack->arr[(stack -> top)--];
    // YOUR CODE
}

// 스택이 비어있는지 확인하는 함수
int isEmpty(Stack* stack) {
	return (stack -> top == -1);
    // YOUR CODE
}




// prefix notation 문자열을 계산하는 함수
double prefix_calculate(char* expression) {
	int len = strlen(expression)-1;
	double val1, val2, val =0;
	int i, j= 0;
	char *last = expression + len;
	char reverse_expression[len];
	char sign; 
	Stack s;
	
	while (last >= expression ){
		reverse_expression[j] = *(last);
		last--; j++;
	}
	

	initStack(&s, len);
	for(i=0 ; i <= len; i++){
		sign = reverse_expression[i];
		if (sign != '+' && sign != '-' && sign != '*' && sign != '/' && sign != ' '){
			val = sign - '0';
			push(&s, val);
		}
		else if (sign == '+' || sign == '-' || sign == '*' || sign == '/'){
			val2= pop(&s);
			val1= pop(&s);
			switch (sign){
				case '+' : push(&s, val2 + val1); break;
				case '-' : push(&s, val2 - val1); break;
				case '*' : push(&s, val2 * val1); break;
				case '/' : push(&s, val2 / val1); break;
			}
		}
		else{
			
		}
	}
	
	return pop(&s);
	
	// YOUR CODE
}

int main() {

	// 아래 main 함수는 수정하지 마세요. 
	char expression[MAX_LEN];
	// 개행문자를 제외한 모든 사용자 입력을 받는다는 의미입니다.
  scanf("%[^\n]", expression);

  double result = prefix_calculate(expression);
  printf("%.2lf\n", result);
	
	return 0;
}
