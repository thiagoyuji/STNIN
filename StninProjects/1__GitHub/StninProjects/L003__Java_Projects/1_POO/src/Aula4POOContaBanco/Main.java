package Aula4POOContaBanco;

public class Main {

    public static void main( String[] args ){

        ContaBanco ContaJoao = new ContaBanco();
        ContaBanco ContaMaria = new ContaBanco();

        ContaJoao.status();
        ContaMaria.status();

        ContaJoao.abrirConta( "CP", "Joao" );
        ContaJoao.depositar( 300f );
        float saqueJ = ContaJoao.sacar( 100f );
        ContaJoao.pagarMensal();

        ContaJoao.status();

        float restoContaJ = ContaJoao.fecharConta();

        ContaJoao.status();

        //---------------------------------------------------

        ContaMaria.abrirConta( "CC", "Maria" );
        ContaMaria.depositar( 500f );
        float saqueM = ContaMaria.sacar( 100f );
        ContaMaria.pagarMensal();

        ContaMaria.status();

        float restoContaM = ContaMaria.fecharConta();

        ContaMaria.status();

    }

}
