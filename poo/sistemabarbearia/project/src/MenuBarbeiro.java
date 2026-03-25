import java.time.format.DateTimeFormatter;
import java.util.List;
import java.util.Scanner;

public class MenuBarbeiro {
    private Scanner sc;

    public MenuBarbeiro(Scanner sc) {
        this.sc = sc;
    }

    public void exibir(Barbeiro barbeiro) {
        boolean sair = false;
        barbeiro.imprimeNotificacoes();
        
        while (!sair) {
            System.out.println("\n==================== MENU BARBEIRO ("+ barbeiro.getNome().toUpperCase() +") ====================");
            System.out.println("1. Ver Minha Agenda");
            System.out.println("2. Finalizar/Concluir Reserva");
            System.out.println("0. Sair");
            System.out.print("Escolha uma opção: ");
            String opcao = sc.nextLine();
            
            try {
                switch (opcao) {
                    case "1":
                        barbeiro.listarAgenda(StatusReserva.AGENDADA);
                        break;
                    case "2":
                        finalizarReserva(barbeiro);
                        break;
                    case "0":
                        sair = true;
                        break;
                    default:
                        System.out.println("Opção inválida. Tente novamente.");
                }
            } catch (Exception e) {
                System.out.println("Erro no menu do barbeiro: " + e.getMessage());
            }
        }
    }

    private void finalizarReserva(Barbeiro barbeiro) {
        System.out.println("\n========== FINALIZAR RESERVA ==========");
        List<Reserva> reservasPendentes = barbeiro.listarAgendaComIndices(StatusReserva.AGENDADA);
        
        if (reservasPendentes.isEmpty()) {
            System.out.println("Nenhuma reserva pendente para finalizar.");
            return;
        }
        
        for (int i = 0; i < reservasPendentes.size(); i++) {
            Reserva r = reservasPendentes.get(i);
            System.out.println("[" + i + "] " + r.getServico().getnome() +
                    " - Cliente: " + r.getCliente().getNome() +
                    " em " + r.getData().format(DateTimeFormatter.ofPattern("dd/MM HH:mm")));
        }
        
        System.out.print("Digite o índice da reserva a ser concluída: ");
        try {
            int idx = Integer.parseInt(sc.nextLine());
            
            if (idx >= 0 && idx < reservasPendentes.size()) {
                Reserva r = reservasPendentes.get(idx);
                barbeiro.finalizaReserva(r);
                System.out.println("Sucesso! O serviço foi marcado como CONCLUÍDO.");
            } else {
                System.out.println("Índice inválido.");
            }
        } catch (NumberFormatException e) {
            System.out.println("Por favor, digite um número válido.");
        } catch (Exception e) {
            System.out.println("Erro ao finalizar: " + e.getMessage());
        }
    }
}