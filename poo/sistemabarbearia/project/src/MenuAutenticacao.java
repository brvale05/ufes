import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class MenuAutenticacao {
    private Scanner sc;
    private Administrador admin;
    private DateTimeFormatter formatoData;

    public MenuAutenticacao(Scanner sc, Administrador admin, DateTimeFormatter formatoData) {
        this.sc = sc;
        this.admin = admin;
        this.formatoData = formatoData;
    }

    public void loginCliente(MenuCliente menuCliente) {
        System.out.print("Digite seu CPF para entrar: ");
        String cpf = sc.nextLine().toLowerCase();
        
        try {
            Cliente cliente = admin.getClienteByCpf(cpf);
            menuCliente.exibir(cliente);
        } catch (Exception e) {
            System.out.println("Cliente com cpf'" + cpf + "' não encontrado.");
            System.out.print("Deseja realizar o cadastro agora? (S/N): ");
            String resposta = sc.nextLine();

            if (resposta.equalsIgnoreCase("S")) {
                try {
                    Cliente novoCliente = cadastrarNovoCliente(cpf);
                    admin.adicionarCliente(novoCliente);
                    System.out.println("Cadastro realizado com sucesso! Bem-vindo(a), " + novoCliente.getNome());
                    menuCliente.exibir(novoCliente);
                } catch (Exception erroCadastro) {
                    System.out.println("Erro ao realizar cadastro: " + erroCadastro.getMessage());
                }
            } else {
                System.out.println("Login cancelado.");
            }
        }
    }

    private Cliente cadastrarNovoCliente(String cpf) throws Exception {
        System.out.println("\n========== CADASTRO RÁPIDO ==========");
        System.out.println("CPF: " + cpf);
        
        System.out.print("Nome: ");
        String nome = sc.nextLine();
        
        System.out.print("Data de nascimento (dd/MM/yyyy): ");
        LocalDate dt_nasc = LocalDate.parse(sc.nextLine(), formatoData);
        
        System.out.print("Telefone: ");
        String telefone = sc.nextLine();
        
        System.out.print("Email: ");
        String email = sc.nextLine();

        return new Cliente(nome, cpf, dt_nasc, telefone, email);
    }

    public void loginBarbeiro(MenuBarbeiro menuBarbeiro) {
        System.out.print("Digite seu CPF para entrar: ");
        String cpf = sc.nextLine().toLowerCase();
        
        try {
            Barbeiro barbeiro = admin.getBarbeiroByCpf(cpf);
            menuBarbeiro.exibir(barbeiro);
        } catch (Exception e) {
            System.out.println("Erro no login: " + e.getMessage());
        }
    }

    public void loginAdministrador(MenuAdministrador menuAdministrador) {
        System.out.print("Digite a senha do admin: ");
        String senha = sc.nextLine();

        if (admin.autenticaSenha(senha)) {
            menuAdministrador.exibir();
        } else {
            System.out.println("Senha incorreta.");
        }
    }
}