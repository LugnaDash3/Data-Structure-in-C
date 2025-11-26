//Program on Postfix evaluation

#include<stdio.h>
#include<string.h>
#include<math.h>

#define max 15

int top=-1;
int st[max];

void push(int value)
{
    top++;
    st[top]=value;
}
int pop()
{
    return st[top--];
}
int main()
{
    char postfix[max];
    int i,op1,op2,value;
    printf("Enter the postfix expression:");
    scanf("%s",postfix);
    for(i=0;postfix[i]!='\0';i++)
    {
        switch(postfix[i])
        {
        case '+':
            op2=pop();
            op1=pop();
            value=op1+op2;
            push(value);
            break;
        case '-':
            op2=pop();
            op1=pop();
            value=op1-op2;
            push(value);
            break;

        case '*':
            op2=pop();
            op1=pop();
            value=op1*op2;
            push(value);
            break;
        case '/':
            op2=pop();
            op1=pop();
            value=op1/op2;
            push(value);
            break;
        case '^':
            op2=pop();
            op1=pop();
            value=op1^op2;
            push(value);
            break;
        default:
            printf("\n\nEnter the value for the character %c:",postfix[i]);
            scanf("%d",&value);
            push(value);
            break;
        }
    }
    printf("The value of the postfix expressin is=%d\n",pop());
}
