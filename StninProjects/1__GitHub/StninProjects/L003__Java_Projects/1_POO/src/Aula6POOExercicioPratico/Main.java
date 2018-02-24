package Aula6POOExercicioPratico;

public class Main {

    public static void main( String[] args ){

        Pessoa pessoa[] = new Pessoa[ 2 ];
        Livro livro[] = new Livro[ 3 ];

        pessoa[ 0 ] = new Pessoa( "Pedro", 22, "Masculino" );
        pessoa[ 1 ] = new Pessoa( "Maria", 25, "Feminino" );

        livro[ 0 ] = new Livro( "Aprendendo Java", "Jose Silva", 300, pessoa[ 0 ] );
        livro[ 1 ] = new Livro( "POO para Iniciantes", "Pedro Silva", 500, pessoa[ 1 ] );
        livro[ 2 ] = new Livro( "Java Avancado", "Maria Silva", 800, pessoa[ 0 ] );

        livro[ 0 ].avancarPag();
        livro[ 0 ].avancarPag();

        livro[ 0 ].voltarPag();

        livro[ 0 ].abrir();

        System.out.println( livro[ 0 ].detalhes() );

    }

}
