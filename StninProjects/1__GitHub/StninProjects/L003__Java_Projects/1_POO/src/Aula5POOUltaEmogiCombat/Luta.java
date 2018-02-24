package Aula5POOUltaEmogiCombat;

import java.util.Random;

public class Luta {

    private Lutador desafiado;
    private Lutador desafiante;
    private int rounds;
    private boolean aprovada;

    // Metodos especiais

    public Luta(){



    }

    public Lutador getDesafiado() {
        return desafiado;
    }

    public void setDesafiado(Lutador desafiado) {
        this.desafiado = desafiado;
    }

    public Lutador getDesafiante() {
        return desafiante;
    }

    public void setDesafiante(Lutador desafiante) {
        this.desafiante = desafiante;
    }

    public int getRounds() {
        return rounds;
    }

    public void setRounds(int rounds) {
        this.rounds = rounds;
    }

    public boolean getAprovada() {
        return aprovada;
    }

    public void setAprovada(boolean aprovada) {
        this.aprovada = aprovada;
    }

    // Metodos Criados

    public void marcarLuta( Lutador lutador1, Lutador lutador2 ){

        if( ( lutador1.getCategoria() == lutador2.getCategoria() ) && ( lutador1 != lutador2 ) ){

            this.aprovada = true;
            this.desafiado = lutador1;
            this.desafiante = lutador2;

        }else{

            this.aprovada = false;
            this.desafiado = null;
            this.desafiante = null;

        }

    }

    public void lutar(){

        if( this.aprovada == true ){

            System.out.println( "####DESAFIADO####\n" );
            this.desafiado.apresentar();
            System.out.println( "\n####DESAFIANTE####\n" );
            this.desafiante.apresentar();

            Random aleatorio = new Random();

            int vencedor = aleatorio.nextInt(3 );

            switch( vencedor ){

                case 0:
                    System.out.println( "\nEmpatou !!!" );
                    this.desafiado.empatarLuta();
                    this.desafiante.empatarLuta();
                    break;
                case 1:
                    System.out.println( "\nLutador: " + this.desafiado.getNome() + "Ganhou" );
                    this.desafiado.ganharLuta();
                    this.desafiante.perderLuta();
                    break;
                case 2:
                    System.out.println( "\nLutador: " + this.desafiante.getNome() + "Ganhou" );
                    this.desafiado.perderLuta();
                    this.desafiante.ganharLuta();
                    break;

            }

        }else{

            System.out.println( "A Luta Nao Pode Acontecer" );

        }

    }

}
