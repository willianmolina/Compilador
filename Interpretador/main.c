#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUM 1
#define MINUS 2

typedef struct
{
    int t;
    int a;

}token;

typedef struct
{
    char op;
    int value;

}attrib;

typedef struct
{

    char input[50];
    int conta;
    char lookahead[50];

} CONT1;


CONT1 cont1;


char nextToken(CONT1 *c)
{
    if(c->conta == strlen(c->input))
    {
        return -1;
    }
    return(c->input[c->conta++]);

}


char match(CONT1 *c, char b)
{


    if(c->lookahead[50] == b)
    {
        c->lookahead[50] = nextToken(&cont1);

    }
    else
    {
        printf("Error(match)!\n");
    }

    return c->lookahead[50];
}


attrib term(CONT1 *c)
{
    attrib r;

    r.op = -1;

    switch (c->lookahead[50])
    {
    case '0':
        match(&cont1, '0');
        r.value = 0;
        break;
    case '1':
        match(&cont1, '1');
        r.value = 1;
        break;
    case '2':
        match(&cont1, '2');
        r.value = 2;
        break;
    case '3':
        match(&cont1, '3');
        r.value = 3;
        break;
    case '4':
        match(&cont1, '4');
        r.value = 4;
        break;
    case '5':
        match(&cont1, '5');
        r.value = 5;
        break;
    case '6':
        match(&cont1, '6');
        r.value = 6;
        break;
    case '7':
        match(&cont1, '7');
        r.value = 7;
        break;
    case '8':
        match(&cont1, '8');
        r.value = 8;
        break;
    case '9':
        match(&cont1, '9');
        r.value = 9;
        break;
    }
    return r;
}


attrib rest(CONT1 *c){
    attrib e,t,r;

    e.op = -1;
  if (c->lookahead[50] == '-'){
     //-term rest
     match(&cont1, '-');
     e.op = MINUS;
     t = term(&cont1);
     r = rest(&cont1);

  } else if (c->lookahead[50] == '+'){
    //+term rest
    match(&cont1 ,'+');
    e.op = SUM;
    t = term(&cont1);
    r = rest(&cont1);

  } else if (c->lookahead[50] == -1) {

    printf("Error(rest)");
  }

  e.value = calc(t.value, r.op, r.value);
  return(e);

}

int calc(int v1, int op, int v2){
  switch (op){
    case -1:
        return (v1);
    case SUM:
        return (v1+v2);
    case MINUS:
        return (v1-v2);
  }
  return 0;//error
}

attrib expr(){
    attrib e,t,r;
    t = term(&cont1);
    r = rest(&cont1);
    e.value = calc(t.value, r.op, r.value);
    return e;
}

int main()
{
    int i = 0;

    //char lookahead[50];

    fgets(&cont1.input, 50, stdin);

    cont1.conta=0;



    cont1.lookahead[50] = nextToken(&cont1);

    attrib e = expr();

    printf("%d", e.value);



    //match(&cont1, "w");


}
