package Aula4POOContaBanco;

public class ContaBanco {

    public int numConta;
    protected String tipoConta;
    private String donoConta;
    private float saldoConta;
    private String statusConta;
    private int geradorNumConta;

    public ContaBanco(){

        this.saldoConta = 0f;
        this.statusConta = "Fechado";
        this.geradorNumConta = 1;

    }

    public void status(){

        System.out.println( "Numero da Conta: " + getNumConta() );
        System.out.println( "Tipo da Conta: " + getTipoConta() );
        System.out.println( "Dono da Conta: " + getDonoConta() );
        System.out.println( "Saldo da Conta: " + getSaldoConta() );
        System.out.println( "Status da Conta: " + getStatusConta() + "\n\n" );

    }

    public void abrirConta( String TConta, String dono ){

        setNumConta( this.geradorNumConta );
        setTipoConta( TConta );
        setDonoConta( dono );

        if ( this.tipoConta == "CP"){
            setSaldoConta( 150f );
        }else{
            setSaldoConta( 50f );
        }

        setStatusConta( "Aberto" );
        //setGeradorNumConta( this.geradorNumConta + 1 );

    }

    public float fecharConta(){

        float saque = 0f;

        if(getSaldoConta() != 0 ) {

            saque = sacar(this.saldoConta);
            setStatusConta("Fechado");

        }

        return saque;

    }

    public void depositar( float deposito ){

        float DepositoConta = getSaldoConta() + deposito;
        setSaldoConta( DepositoConta );

    }

    public float sacar( float saque ) {

        float SaqueConta = getSaldoConta();

        if( SaqueConta > saque ){
            SaqueConta = SaqueConta - saque;
        }

        return SaqueConta;
    }

    public void pagarMensal(){

        String TConta = getTipoConta();

        if( TConta == "CP" ){
            setSaldoConta( this.saldoConta - 20 );
        }else{
            setSaldoConta( this.saldoConta - 12 );
        }

    }

    public int getNumConta() {
        return numConta;
    }

    public void setNumConta(int numConta) {
        this.numConta = numConta;
    }

    public String getTipoConta() {
        return tipoConta;
    }

    public void setTipoConta(String tipoConta) {
        this.tipoConta = tipoConta;
    }

    public String getDonoConta() {
        return donoConta;
    }

    public void setDonoConta(String donoConta) {
        this.donoConta = donoConta;
    }

    public float getSaldoConta() {
        return saldoConta;
    }

    public void setSaldoConta(float saldoConta) {
        this.saldoConta = saldoConta;
    }

    public String getStatusConta() {
        return statusConta;
    }

    public void setStatusConta(String statusConta) {
        this.statusConta = statusConta;
    }

    public int getGeradorNumConta() {
        return geradorNumConta;
    }

    public void setGeradorNumConta(int geradorNumConta) {
        this.geradorNumConta = geradorNumConta;
    }

}
