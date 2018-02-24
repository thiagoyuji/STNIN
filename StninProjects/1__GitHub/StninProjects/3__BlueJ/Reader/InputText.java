import java.util.Scanner;

public class InputText{
    
    private String TextForRead;
    
    String getTextForRead(){
        return TextForRead;
    }
    
    void setTextForRead( String TextForRead ){
        this.TextForRead = TextForRead;
    }
    
    String inputTextFunction(){
    
        String Text;
        
        System.out.print("Insert Text .......:>> ");
        
        Scanner scanText = new Scanner(System.in);
        
        Text = scanText.nextLine();
        
        return Text;
    
    }
    
    void clearConsole(){
    
        int count;
        
        for( count = 0; count < 50; count++ ){
        
            System.out.println();
        
        }
    }
}
