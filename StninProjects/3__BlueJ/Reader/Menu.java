public class Menu{
    
    private boolean InputText;
    private boolean Exit;
    
    Menu(){
    
        InputText = false;
        Exit = false;
        
    }
    
    boolean getInputText(){
        return InputText;
    }
    
    void setInputText( boolean InputText ){
        this.InputText = InputText;
    }
    
    boolean getExit(){
        return Exit;
    }
    
    void setExit( boolean Exit ){
        this.Exit = Exit;
    }
    
    void printMenuOptions(){
    
        System.out.println("Reader Program .......:>>");
        System.out.println("1 - Use Reader .......:>>");
        System.out.println("2 - Exit .............:>>");
        System.out.print("\nInsert an Option .....:>> ");
        
    }
    
}
