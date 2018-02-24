package Aula8POOHerança;

public class Visitante extends Pessoa {

    private String setor;
    private boolean trabalhando;

    // Metodos Especiais

    public Visitante(){



    }

    public String getSetor() {
        return setor;
    }

    public void setSetor(String setor) {
        this.setor = setor;
    }

    public boolean getTrabalhando() {
        return trabalhando;
    }

    public void setTrabalhando(boolean trabalhando) {
        this.trabalhando = trabalhando;
    }

    // Metodos Criados

    public void mudaTrabalho(){

        this.trabalhando = !this.trabalhando;

    }

}
