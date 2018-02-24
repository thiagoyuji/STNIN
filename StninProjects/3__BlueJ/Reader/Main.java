import java.util.Scanner;

public class Main{
    public static void main( String Args[] ){
     
        Menu menu = new Menu();
        InputText inputText = new InputText();
        Settings settings = new Settings();
        
        menu.printMenuOptions();
        
        Scanner scanMenuOptions = new Scanner(System.in);
        
        int MenuOptions = scanMenuOptions.nextInt();
        
        if( MenuOptions == 1 ){
            
            menu.setInputText( true );
            
            inputText.clearConsole();
            
            String Text = inputText.inputTextFunction();
            int WordForSecond = settings.inputWordForSecondFunction();
            
            // TO DO Print Text
                  
        }else if(MenuOptions == 2){
        
            menu.setExit( true );
                        
        }
    }
}
