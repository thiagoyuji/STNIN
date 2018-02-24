#include <stdio.h>
#include <stdlib.h>

typedef char * String;
typedef int Integer;
typedef int * IntegerPointer;

Integer soma( IntegerPointer, IntegerPointer );
Integer subtracao( IntegerPointer, IntegerPointer );

typedef Integer ( *FuncPointer )( IntegerPointer, IntegerPointer );

struct Test {

	FuncPointer Func;
    
}var = {soma};

void main (   ){

	String nome = "Seu Nome";
	Integer idade = 10;
	Integer idade2 = 20;

	printf ("%s -> %d\n", nome, idade);

    //struct Test t;
    
    //t.Func = soma;
    
    printf ("soma -> %d\n\n", var.Func(&idade,&idade2));
    
}

Integer soma( IntegerPointer A, IntegerPointer B ){
    
    return *A + *B;
    
}
Integer subtracao( IntegerPointer A, IntegerPointer B ){
    
    return *A - *B;
    
}
