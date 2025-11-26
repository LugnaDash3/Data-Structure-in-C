//Infix to Postfix conversion program
#include<stdio.h>
#include<string.h>
#define MAX 50
char stack[MAX];
int top=-1;
void push(char);
char pop();
int is_operand(char);
int is_operator(char);
int is_precedence(char);
int is_empty();
int main()
{
    char infix[MAX],postfix[MAX],ch,ch1;
    int i,j,len;
    printf("enter infix expression:");
    scanf("%s",infix);
    len=strlen(infix);
    infix[len]=')';
    infix[len+1]='\0';
    push('(');
    i=0;
    j=0;
    while(!(is_empty()))
    {
        ch=infix[i];
        if(is_operand(ch))
        {
            postfix[j]=ch;
            j++;
        }
        else if(ch=='(')
            push(ch);
        else if(is_operator(ch))
        {
            while(is_precedence(stack[top])>=is_precedence(ch))
            {
                postfix[j]=pop();
                j++;
            }
            push(ch);
        }
        else
        {
            while(stack[top]!='(')
            {
                postfix[j]=pop();
                j++;
            }
            ch1=pop();
        }
        i++;
    }
    postfix[j]='\0';
    printf("\n postfix expression is :%s",postfix);
}
void push(char ch)
{
    if(top==MAX-1)
        printf("stack overflow: no more insertion is possible in stack");
    else
    {
        top++;
        stack[top]=ch;
    }
}
char pop()
{
    char item;
    if(top==-1)
        printf("stack is empty");
    else
    {
        item=stack[top];
        top--;
        return item;
    }
}
int is_empty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int is_operand(char ch)
{
    if((ch>=65 && ch<=90) || (ch>=97 && ch<=122) || (ch>=48 && ch<=57))
        return 1;
    else
        return 0;
}
int is_operator(char ch)
{
    if(ch=='^' || ch=='/' ||ch=='%' ||ch=='*' ||ch=='+' ||ch=='-' )
        return 1;
    else
        return 0;
}
int is_precedence(char ch)
{
    if(ch=='^')
        return 3;
    else if(ch=='%' || ch=='/' || ch=='*')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    else
        return 0;
}
