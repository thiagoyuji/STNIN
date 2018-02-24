package Aula8POOHerança;

public class Main {

    public static void main( String[] args ){

        Visitante v1 = new Visitante();

        v1.setNome( "Juvenal" );
        v1.setIdade( 22 );
        v1.setSexo( "Masculino" );

        System.out.println( "\nVisitante --> " + v1.toString() );

        Aluno a1 = new Aluno();

        a1.setNome( "Joao" );
        a1.setIdade( 24 );
        a1.setSexo( "Masculino" );
        a1.setCurso( "Informatica" );
        a1.setMatricula( 1111 );
        a1.pagarMensalidade();

        System.out.println( "\nAluno --> " + a1.toString() + " | { Matricula: " + a1.getMatricula() + " | Curso: " + a1.getCurso() + " }" );

        Bolsista b1 = new Bolsista();

        b1.setNome( "Jubileu" );
        b1.setBolsa( 12.5f );
        b1.setSexo( "Masculino" );
        b1.pagarMensalidade();

        System.out.println( "\nBolsista --> " + b1.toString() );


    }

}
