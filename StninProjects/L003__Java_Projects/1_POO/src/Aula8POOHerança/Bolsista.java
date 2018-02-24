package Aula8POOHerança;

public class Bolsista extends Aluno{

    private float bolsa;

    // Metodos Especiais

    public Bolsista(){



    }

    public float getBolsa() {
        return bolsa;
    }

    public void setBolsa(float bolsa) {
        this.bolsa = bolsa;
    }

    // Metodos Criados

    public void removerBolsa(){

        System.out.println( "Renovando Bolsa !!!" );

    }

    @Override
    public void pagarMensalidade(){

        System.out.println( "Pagando Bolsa !!!" );

    }

}
