package Aula9POOAnimal;

public class Main {

    public static void main( String[] args ){

        Mamifero m = new Mamifero();
        Reptil r = new Reptil();
        Peixe p = new Peixe();
        Ave a = new Ave();

        m.locomover();
        r.locomover();
        p.locomover();
        a.locomover();

        Canguru c = new Canguru();
        Cachorro k = new Cachorro();
        Cobra j = new Cobra();
        Tartaruga t = new Tartaruga();
        GoldFish g = new GoldFish();
        Arara e = new Arara();

        c.locomover();
        k.emitirSom();

    }

}
