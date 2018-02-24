package Aula4POOInterface;

import com.sun.org.apache.xpath.internal.SourceTree;

import javax.xml.bind.SchemaOutputResolver;

public class ControleRemoto implements Controlador{

    private int volume;
    private boolean ligado;
    private boolean tocando;

    public ControleRemoto(){
        this.volume = 50;
        this.ligado = false;
        this.tocando = false;

    }

    private int getVolume() {
        return volume;
    }

    private void setVolume(int volume) {
        this.volume = volume;
    }

    private boolean getLigado() {
        return ligado;
    }

    private void setLigado(boolean ligado) {
        this.ligado = ligado;
    }

    private boolean getTocando() {
        return tocando;
    }

    private void setTocando(boolean tocando) {
        this.tocando = tocando;
    }

    // Metodos Abstratos

    @Override
    public void ligar() {
        setLigado( true );
    }

    @Override
    public void desligar() {
        setLigado( false );
    }

    @Override
    public void abrirMenu() {
        System.out.println( "Ligado: " + getLigado() );
        System.out.println( "Tocando: " + getTocando() );
        System.out.print( "Volume: " + getVolume() + "% " );

        for( int i = 0; i <= this.getVolume(); i += 10 ){

            System.out.print( "|" );

        }

        System.out.println( "\n" );

    }

    @Override
    public void fecharMenu() {
        System.out.println( "Fechando Menu ..." );
    }

    @Override
    public void maisVolume() {
        if( this.getLigado() ){

            this.setVolume( this.getVolume() + 5 );

        }else{

            System.out.println( "Impossivel Aumentar Volume !!! " );

        }
    }

    @Override
    public void menosVolume() {
        if( this.getLigado() ){

            this.setVolume( this.getVolume() - 5 );

        }else {

            System.out.println( "Impossivel Diminuir Volume" );

        }

    }

    @Override
    public void ligarMudo() {
        if( this.getLigado() && this.getVolume() > 0 ){

            setVolume( 0 );

        }
    }

    @Override
    public void desligarMudo() {

        if( this.getLigado() && this.getVolume() == 0 ){

            this.setVolume( 50 );

        }

    }

    @Override
    public void play() {
        if( this.getLigado() && !this.getTocando() ){

            this.setTocando( true );

        }
    }

    @Override
    public void pause() {
        if( this.getLigado() && this.getTocando() ){

            this.setTocando( false );

        }

    }
}
