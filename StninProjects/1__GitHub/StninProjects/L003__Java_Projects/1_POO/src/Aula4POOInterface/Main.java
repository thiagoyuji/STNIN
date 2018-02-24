package Aula4POOInterface;

public class Main {

    public static void main( String[] args ){

        ControleRemoto CR = new ControleRemoto();

        CR.ligar();
        CR.maisVolume();
        CR.play();

        CR.abrirMenu();
        CR.fecharMenu();

    }

}
