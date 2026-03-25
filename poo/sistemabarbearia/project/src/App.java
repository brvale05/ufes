import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class App {
    static Administrador admin;
    static Scanner sc = new Scanner(System.in);
    static DateTimeFormatter formatoData = DateTimeFormatter.ofPattern("dd/MM/yyyy");

    // Testa se o administrador está sendo criado no formato correto
    static {
        try {
            admin = new Administrador("Yuri", "00011122233", LocalDate.of(1995, 3, 10),
                    "27999888777", "admin@admin.com", LocalDate.of(2020, 1, 1), 5000.0, "admin");
        } catch (Exception e) {
            System.err.println("Erro ao criar Administrador: " + e.getMessage());
            System.exit(1);
        }
    }

    public static void main(String[] args) throws Exception {
        inicializarDados();
        
        // Instancia os menus
        MenuCliente menuCliente = new MenuCliente(sc, formatoData, admin);
        MenuBarbeiro menuBarbeiro = new MenuBarbeiro(sc);
        MenuAdministrador menuAdministrador = new MenuAdministrador(sc, admin);
        MenuAutenticacao menuAutenticacao = new MenuAutenticacao(sc, admin, formatoData);

        while (true) {
            System.out.println("\n========== SISTEMA DA BARBEARIA ==========");
            System.out.println("Quem é você?");
            System.out.println("1 - Sou Cliente");
            System.out.println("2 - Sou Barbeiro");
            System.out.println("3 - Sou Administrador");
            System.out.println("0 - Sair do Sistema");
            System.out.print("Opção: ");
            String opcao = sc.nextLine();
            
            switch (opcao) {
                case "1":
                    menuAutenticacao.loginCliente(menuCliente);
                    break;
                case "2":
                    menuAutenticacao.loginBarbeiro(menuBarbeiro);
                    break;
                case "3":
                    menuAutenticacao.loginAdministrador(menuAdministrador);
                    break;
                case "0":
                    System.out.println("Encerrando sistema...");
                    return;
                default:
                    System.out.println("Opção inválida.");
            }
        }
    }

    // Inicialização dos dados
    private static void inicializarDados() throws Exception {
        Recurso tesoura = new Recurso("Tesoura", 2);
        Recurso cadeira = new Recurso("Cadeira", 3);
        admin.adicionarRecurso(tesoura);
        admin.adicionarRecurso(cadeira);
        
        // Clientes
        Cliente joao = new Cliente("Joao", "98765432101", LocalDate.of(1990, 5, 15), 
                "27991234567", "joao@gmail.com");
        admin.adicionarCliente(joao);
        
        // Barbeiros
        try {
            Barbeiro rafael = new Barbeiro("Rafael", "12345678902", LocalDate.of(2000, 1, 1), 
                    "27997550259", "rafael@gmail.com", 2500.0);
            Barbeiro bruno = new Barbeiro("Bruno", "12345678902", LocalDate.of(2000, 1, 1), 
                    "27997550259", "bruno@gmail.com", 3000.0);
            admin.adicionarBarbeiro(rafael);
            admin.adicionarBarbeiro(bruno);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        // Serviços
        Servico corte = new Servico(30, 50.0f, "Corte de Cabelo");
        Servico barba = new Servico(20, 30.0f, "Barba");
        Servico corteBarba = new Servico(20, 70.0f, "Corte e Barba");
        Servico sobrancelha = new Servico(20, 30.0f, "Sobrancelha");
        admin.adicionarServico(corte);
        admin.adicionarServico(barba);
        admin.adicionarServico(corteBarba);
        admin.adicionarServico(sobrancelha);

        System.out.println("Dados carregados.");
    }
}