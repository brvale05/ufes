public class App {
    public static void main(String[] args) throws Exception 
    {
        Diretor dir = new Diretor("1234567", "bruno", 50000);

        dir.setFaturamento(300000);

        Gerente ger = new Gerente("43824632", "davi", 20000, "TI");

        dir.exibeDados();
        ger.exibeDados();
    }
}
