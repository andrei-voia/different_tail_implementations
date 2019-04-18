#include<stdio.h>
//maximum tail size
#define MAX 5


//defined variables
typedef struct{
    int value[MAX];
    int length;
    int start;
    int counter;
}tail;

tail tl;


//1st problem
void reset()
{
    tl.length--;
    int i;
    for(i=0;i<tl.length;i++) tl.value[i]=tl.value[i+1];
}

void push(int number)
{
	if (tl.length < MAX)
	{
		tl.value[tl.length] = number;
		tl.length++;
	}
	else printf("Maximum tail size reached(push)\n");
}

void pop()
{
	if (tl.length == 0) printf("There are not enough elements (pop)\n");
	else reset();
}

void show()
{
    int i;
	for (i = 0; i < tl.length; i++) printf("%d ", tl.value[i]);
}


//2nd problem
int method2(int a, int b)
{
    if(tl.value[a]<tl.value[b])return 1;
    return 0;
}

void render2()
{
    int i,j;
    for(i=0;i<tl.length-1;i++)
        for(j=i+1;j<tl.length;j++)
    {
        if(method2(i,j))
        {
            int auxiliary;
            auxiliary=tl.value[i];
            tl.value[i]=tl.value[j];
            tl.value[j]=auxiliary;
        }
    }
}

void subtract2()
{
    int i;
    for(i=0;i<tl.length;i++) tl.value[i]=tl.value[i+1];
}

void push2(int number)
{
    if(tl.length<MAX)
    {
        tl.value[tl.length]=number;
        tl.length++;
        if(tl.length>1)render2();
    }
    else printf("Maximum tail size reached (push)\n");
}

void pop2()
{
    if(tl.length<1)printf("There are not enough elements (pop)\n");
    else
    {
        tl.length--;
        subtract2();
    }
}

void show2()
{
    int i;
	for (i = 0; i < tl.length; i++) printf("%d ", tl.value[i]);
}


//3rd problem
int getMax3()
{
    if(tl.start>tl.length)return tl.start;
    return tl.length;
}

void push3(int number)
{
    tl.counter++;

	if (tl.start ==MAX)
    {
        tl.length=tl.start;
        tl.start=0;
    }
		tl.value[tl.start] = number;
		tl.start++;
}

void calculate_pop3()
{
    int modify_position;
    modify_position=tl.counter%MAX;

        if(tl.counter/MAX==0)
        {
            int i;
            for(i=0;i<tl.counter;i++)
                if(tl.value[i]!=-1)
                {
                    tl.value[i]=-1;
                    break;
                }
        }
        else
        {
            tl.value[modify_position]=-1;
            tl.counter++;
        }
}

void pop3()
{
    int length=getMax3();
    if(length==0)printf("There are not enough elements (pop)\n");

    else calculate_pop3();
}

void show3()
{
    int i;
    int stop=getMax3();

	for (i = 0; i < stop; i++)
        if(tl.value[i]!=-1)     //jump over popped values
        printf("%d ", tl.value[i]);
}

int main()
{
    int option;
    printf("choose between 1 and 3\n");
    scanf("%d",&option);

    //replace here your algorithm options and the push pop variables
    if(option==1)
    {
        pop();
        push(1);
        push(5);
        push(3);
        push(10);
        push(7);
        push(23);
        pop();
        pop();

        show();
    }

    else if(option==2)
    {
        pop2();
        push2(6);
        push2(7);
        push2(1);
        push2(4);
        push2(10);
        push2(20);
        pop2();
        pop2();

        show2();
    }

    else if(option==3)
    {
        pop3();
        push3(1);
        push3(2);
        push3(3);
        push3(4);
        pop3();
        pop3();
        pop3();
        pop3();
        push3(1);
        push3(2);
        push3(3);
        push3(4);
        push3(5);
        push3(6);
        pop3();
        pop3();

        show3();
    }

    else printf("~~~~~~~~~~invalid number ~~~~~~~~");


	getchar();
	return 0;
}
