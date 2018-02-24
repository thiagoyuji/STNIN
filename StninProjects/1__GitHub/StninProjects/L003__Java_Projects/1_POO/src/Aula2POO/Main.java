package Aula2POO;

public class Main {

    public static void main( String[] args ) {

        // no main eu posso usar public and protected mas nao private

        Caneta c1 = new Caneta();

        c1.modelo = "Bic";
        c1.cor = "Azul";
        // c1.ponta = 0.5f; erro acesso Private
        c1.carga = 80;
        c1.tampada = true;

        c1.status();

        c1.destampar();

        c1.status();

    }

}
