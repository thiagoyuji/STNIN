import java.util.Scanner;

public class Settings{
    
    private int WordForSecond;
    
    int getWordForSecond(){
        return WordForSecond;
    }
    
    void setWordForSecond( int WordForSecond ){
        this.WordForSecond = WordForSecond;
    }
    
    int inputWordForSecondFunction(){
    
        int WFS;
        
        System.out.print("\nInsert A Value of Word for Second :>> ");
        
        Scanner scanWfs = new Scanner(System.in);
        
        WFS = scanWfs.nextInt();
        
        return WFS;
        
    }
}
