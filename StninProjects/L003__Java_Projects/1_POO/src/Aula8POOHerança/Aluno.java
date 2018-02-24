package Aula8POOHerança;

public class Aluno extends Pessoa {

    private int matricula;
    private String curso;

    // Metodos Especiais

    public Aluno(){



    }

    public int getMatricula() {
        return matricula;
    }

    public void setMatricula(int matricula) {
        this.matricula = matricula;
    }

    public String getCurso() {
        return curso;
    }

    public void setCurso(String curso) {
        this.curso = curso;
    }

    // Metodos Criados

    public void pagarMensalidade(){

        System.out.println( "Pagando Mensalidade !!!" );

    }

}
