import java.util.Scanner;

public class Reader{      
    public static void main( String Args[] ) throws InterruptedException{
    
        String Texto;
        String[] PalavrasSeparadas;
        
        long Velocidade;
        int Count;
        
        Scanner scan = new Scanner(System.in);
        
        System.out.print("Digite um Texto ....:>> ");
        Texto = scan.nextLine();
        
        System.out.print("Digite a Velocidade :>> ");
        Velocidade = scan.nextInt();
        
        clearConsole();
        
        PalavrasSeparadas = Texto.split(" ");
        
        for( Count = 0; Count < PalavrasSeparadas.length; Count++ ){
        
            System.out.println(PalavrasSeparadas[Count]);
            
            Thread.sleep(Velocidade);
            
            clearConsole();
            
        }
        
    }
    
    public static void clearConsole(){
    
        System.out.print('\u000C');
    
    }
}
