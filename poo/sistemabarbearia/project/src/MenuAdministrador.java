import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class MenuAdministrador {
    private Scanner sc;
    private Administrador admin;
    private DateTimeFormatter formatoData = DateTimeFormatter.ofPattern("dd/MM/yyyy");

    public MenuAdministrador(Scanner sc, Administrador admin) {
        this.sc = sc;
        this.admin = admin;
    }

    public void exibir() {
        boolean sair = false;
        
        while (!sair) {
            System.out.println("\n========== MENU ADMINISTRADOR ==========");
            System.out.println("1. [C]reate");
            System.out.println("2. [R]ead");
            System.out.println("3. [U]pdate");
            System.out.println("4. [D]elete");
            System.out.println("0. Sair");
            System.out.print("Escolha uma opção: ");
            String opcao = sc.nextLine().toLowerCase();
            
            try {
                switch (opcao) {
                    case "1":
                    case "c":
                    case "create":
                        menuCreate();
                        break;
                    case "2":
                    case "r":
                    case "read":
                        menuRead();
                        break;
                    case "3":
                    case "u":
                    case "update":
                        menuUpdate();
                        break;
                    case "4":
                    case "d":
                    case "delete":
                        menuDelete();
                        break;
                    case "0":
                        sair = true;
                        break;
                    default:
                        System.out.println("Opção inválida. Tente novamente.");
                }
            } catch (Exception e) {
                System.out.println("Erro no menu do administrador: " + e.getMessage());
            }
        }
    }

    private void menuCreate() {
        boolean sair = false;
        
        while (!sair) {
            System.out.println("\n========== MENU CREATE ==========");
            System.out.println("1. Adicionar Serviço");
            System.out.println("2. Adicionar Barbeiro");
            System.out.println("3. Adicionar Cliente");
            System.out.println("4. Adicionar Recurso");
            System.out.println("0. Voltar");
            System.out.print("Escolha uma opção: ");
            String opcao = sc.nextLine();
            
            try {
                switch (opcao) {
                    case "1":
                        admin.adicionarServico(sc);
                        System.out.println("Serviço adicionado com sucesso!");
                        break;
                    case "2":
                        admin.adicionarBarbeiro(sc);
                        System.out.println("Barbeiro adicionado com sucesso!");
                        break;
                    case "3":
                        admin.adicionarCliente(sc);
                        System.out.println("Cliente adicionado com sucesso!");
                        break;
                    case "4":
                        admin.adicionarRecurso(sc);
                        System.out.println("Recurso adicionado com sucesso!");
                        break;
                    case "0":
                        sair = true;
                        break;
                    default:
                        System.out.println("Opção inválida. Tente novamente.");
                }
            } catch (Exception e) {
                System.out.println("Erro no menu CREATE: " + e.getMessage());
            }
        }
    }

    private void menuRead() {
        admin.exibirClientes();
        admin.exibirBarbeiros();
        admin.exibirServicos();
        admin.exibirRecursos();
    }

    private void menuUpdate() {
        boolean sair = false;
        
        while (!sair) {
            System.out.println("\n========== MENU UPDATE ==========");
            System.out.println("1. Atualizar Serviços");
            System.out.println("2. Atualizar Barbeiros");
            System.out.println("3. Atualizar Clientes");
            System.out.println("4. Atualizar Recurso");
            System.out.println("0. Voltar");
            System.out.print("Escolha uma opção: ");
            String opcao = sc.nextLine();
            
            try {
                switch (opcao) {
                    case "1":
                        atualizarServico();
                        break;
                    case "2":
                        atualizarBarbeiro();
                        break;
                    case "3":
                        atualizarCliente();
                        break;
                    case "4":
                        atualizarRecurso();
                        break;
                    case "0":
                        sair = true;
                        break;
                    default:
                        System.out.println("Opção inválida. Tente novamente.");
                }
            } catch (Exception e) {
                System.out.println("Erro no menu UPDATE: " + e.getMessage());
            }
        }
    }

    private void atualizarServico() {
        System.out.println("\n========== ATUALIZAR SERVIÇO ==========");
        admin.exibirServicos();
        
        System.out.print("\nDigite o nome do serviço a atualizar: ");
        String nome = sc.nextLine().toLowerCase();
        
        try {
            Servico servico = admin.getServicoByNome(nome);
            
            System.out.println("\nServiço selecionado: " + servico);
            System.out.println("\nO que deseja atualizar?");
            System.out.println("1. Nome");
            System.out.println("2. Duração (minutos)");
            System.out.println("3. Valor (R$)");
            System.out.println("0. Cancelar");
            System.out.print("Escolha: ");
            
            String opcao = sc.nextLine();
            
            switch(opcao) {
                case "1":
                    System.out.print("Novo nome: ");
                    String novoNome = sc.nextLine();
                    servico.setnome(novoNome);
                    System.out.println("Nome atualizado com sucesso!");
                    break;
                    
                case "2":
                    System.out.print("Nova duração (minutos): ");
                    int novaDuracao = Integer.parseInt(sc.nextLine());
                    servico.setDuracao(novaDuracao);
                    System.out.println("Duração atualizada com sucesso!");
                    break;
                    
                case "3":
                    System.out.print("Novo valor (R$): ");
                    double novoValor = Double.parseDouble(sc.nextLine());
                    servico.setValor(novoValor);
                    System.out.println("Valor atualizado com sucesso!");
                    break;
                    
                case "0":
                    System.out.println("Operação cancelada.");
                    break;
                    
                default:
                    System.out.println("Opção inválida.");
            }
            
        } catch (Exception e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }
    
    private void atualizarBarbeiro() {
        System.out.println("\n========== ATUALIZAR BARBEIRO ==========");
        admin.exibirBarbeiros();
        
        System.out.print("\nDigite o cpf do barbeiro a atualizar: ");
        String cpf = sc.nextLine();
        
        try {
            Barbeiro barbeiro = admin.getBarbeiroByCpf(cpf);
            
            System.out.println("\nBarbeiro selecionado: " + barbeiro);
            System.out.println("\nO que deseja atualizar?");
            System.out.println("1. Telefone");
            System.out.println("2. Email");
            System.out.println("0. Cancelar");
            System.out.print("Escolha: ");
            
            String opcao = sc.nextLine();
            
            switch(opcao) {
                case "1":
                    System.out.print("Novo telefone: ");
                    String novoTelefone = sc.nextLine();
                    barbeiro.setTelefone(novoTelefone);
                    System.out.println("✓ Telefone atualizado com sucesso!");
                    break;
                    
                case "2":
                    System.out.print("Novo email: ");
                    String novoEmail = sc.nextLine();
                    barbeiro.setEmail(novoEmail);
                    System.out.println("✓ Email atualizado com sucesso!");
                    break;
                    
                case "0":
                    System.out.println("Operação cancelada.");
                    break;
                    
                default:
                    System.out.println("Opção inválida.");
            }
            
        } catch (Exception e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }
    
    private void atualizarCliente() {
        System.out.println("\n========== ATUALIZAR CLIENTE ==========");
        admin.exibirClientes();
        
        System.out.print("\nDigite o CPF do cliente a atualizar: ");
        String cpf = sc.nextLine();
        
        try {
            Cliente cliente = admin.getClienteByCpf(cpf);
            
            System.out.println("\nCliente selecionado: " + cliente);
            System.out.println("\nO que deseja atualizar?");
            System.out.println("1. Telefone");
            System.out.println("2. Email");
            System.out.println("0. Cancelar");
            System.out.print("Escolha: ");
            
            String opcao = sc.nextLine();
            
            switch(opcao) {
                case "1":
                    System.out.print("Novo telefone: ");
                    String novoTelefone = sc.nextLine();
                    cliente.setTelefone(novoTelefone);
                    System.out.println("Telefone atualizado com sucesso!");
                    break;
                    
                case "2":
                    System.out.print("Novo email: ");
                    String novoEmail = sc.nextLine();
                    cliente.setEmail(novoEmail);
                    System.out.println("Email atualizado com sucesso!");
                    break;
                    
                case "0":
                    System.out.println("Operação cancelada.");
                    break;
                    
                default:
                    System.out.println("Opção inválida.");
            }
            
        } catch (Exception e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }

    private void atualizarRecurso() {
        System.out.println("\n========== ATUALIZAR RECURSO ==========");
        admin.exibirRecursosComId();
        
        System.out.print("\nDigite o indice do recurso a atualizar: ");
        int indice = Integer.parseInt(sc.nextLine());
        
        try {
            Recurso recurso = admin.getRecursoByIndice(indice-1);
            
            System.out.println("\nRecurso selecionado: " + recurso.getNome());
            System.out.println("\nO que deseja atualizar?");
            System.out.println("1. Nome");
            System.out.println("2. Quantidade");
            System.out.println("0. Cancelar");
            System.out.print("Escolha: ");
            
            String opcao = sc.nextLine();
            
            switch(opcao) {
                case "1":
                    System.out.print("Novo nome: ");
                    String novoNome = sc.nextLine();
                    recurso.setNome(novoNome);
                    System.out.println("Nome atualizado com sucesso!");
                    break;
                    
                case "2":
                    System.out.print("Nova quantidade: ");
                    int quantidade = Integer.parseInt(sc.nextLine());
                    recurso.setQuantidade(quantidade);
                    System.out.println("Quantidade atualizada com sucesso!");
                    break;
                    
                case "0":
                    System.out.println("Operação cancelada.");
                    break;
                    
                default:
                    System.out.println("Opção inválida.");
            }
            
        } catch (Exception e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }

    public void menuDelete() {
        int opcao = -1;
        do {
            System.out.println("\n========== MENU REMOÇÃO ==========");
            System.out.println("1. Remover Cliente");
            System.out.println("2. Demitir Barbeiro");
            System.out.println("3. Remover Serviço");
            System.out.println("4. Remover Recurso");
            System.out.println("0. Voltar");
            System.out.print("Escolha uma opção: ");

            try {
                opcao = Integer.parseInt(sc.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Opção inválida. Digite um número.");
                continue;
            }

            try {
                switch (opcao) {
                    case 1:
                        admin.removerCliente(sc);
                        break;
                    case 2:
                        admin.removerBarbeiro(sc);
                        break;
                    case 3:
                        admin.removerServico(sc);
                        break;
                    case 4:
                        admin.removerRecurso(sc);
                        break;
                    case 0:
                        System.out.println("Voltando ao menu principal...");
                        break;
                    default:
                        System.out.println("Opção inválida!");
                }
            } catch (Exception e) {
                System.out.println("Erro ao remover: " + e.getMessage());
            }

        } while (opcao != 0);
    }
    
}