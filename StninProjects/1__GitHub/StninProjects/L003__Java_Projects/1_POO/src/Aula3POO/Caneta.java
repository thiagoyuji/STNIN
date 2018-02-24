package Aula3POO;

public class Caneta {

    private String modelo;
    private String cor;
    private float ponta;
    private boolean tampada;

    public Caneta(String modelP, String corP, float pontaP){

        //construtor
        modelo = modelP;
        cor = corP;
        ponta = pontaP;


        tampar();

    }


    public String getModelo(){

        return this.modelo;

    }

    public void setModelo( String model ){

        this.modelo = model;

    }

    public float getPonta(){

        return this.ponta;

    }

    public void setPonta( float pont ){

        this.ponta = pont;

    }

    public void status(){

        System.out.println( "Modelo: " + this.modelo );
        System.out.println( "Cor: " + this.cor );
        System.out.println( "Ponta: " + this.ponta );
        System.out.println( "Tampada: " + this.tampada + "\n\n" );

    }

    public void tampar(){

        this.tampada = true;

    }

    public void destampar(){

        this.tampada = false;

    }

}
