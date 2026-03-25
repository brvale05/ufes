import java.time.LocalDate;

public class App {
    public static void main(String[] args) throws Exception {
       
        Jogador j1 = new Jogador("18871809742", "Bruno", LocalDate.of(2005, 11, 14));
        Jogador j2 = new Jogador("18871809742", "Davi", LocalDate.of(2005, 11, 14));
        Jogador j3 = new Jogador("18871809742", "Gabriel", LocalDate.of(2005, 11, 14));

        Jogador j4 = new Jogador("18871809742", "Yuri", LocalDate.of(2005, 11, 14));
        Jogador j5 = new Jogador("18871809742", "Matheus", LocalDate.of(2005, 11, 14));
        Jogador j6 = new Jogador("18871809742", "Caio", LocalDate.of(2005, 11, 14));

        Mandante mandante = new Mandante(j1, j2, j3);
        Visitante visitante = new Visitante(j4, j5, j6);

        Jogo jogo = new Jogo(mandante, visitante);
    }
}
