package Aula7POOHerança;

public class Pessoa {

    private String nome;
    private int idade;
    private String sexo;

    // Metodos Especiais

    public Pessoa(){



    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getSexo() {
        return sexo;
    }

    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    @Override
    public String toString() {
        return "\nPessoa{ " + "Nome: " + getNome() + " | Idade: " + getIdade() + " | Sexo: " + getSexo() + " }";
    }

    // Metodos Criados

    public void fazerAniversario(){

        this.idade++;

    }



}
