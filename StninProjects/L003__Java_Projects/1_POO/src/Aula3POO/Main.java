package Aula3POO;

public class Main {

    public static void main( String[] args ) {

        // no main eu posso usar public and protected mas nao private

        Caneta c1 = new Caneta("BIC","VERMELHO", 0.6f );

        c1.status();

        System.out.println( "CANETA: " + c1.getModelo() + "-- Ponta: " + c1.getPonta() );

    }

}
