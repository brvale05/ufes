import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.List;
import java.util.Scanner;

public class MenuCliente {
    private Scanner sc;
    private DateTimeFormatter formatoData;
    private Administrador admin;

    public MenuCliente(Scanner sc, DateTimeFormatter formatoData, Administrador admin) {
        this.sc = sc;
        this.formatoData = formatoData;
        this.admin = admin;
    }

    public void exibir(Cliente cliente) {
        boolean sair = false;
        cliente.imprimeNotificacoes();
        
        while (!sair) {
            System.out.println("\n==================== MENU CLIENTE (" + cliente.getNome().toUpperCase() + ") ====================");
            System.out.println("1. Realizar Reserva");
            System.out.println("2. Cancelar Reserva");
            System.out.println("3. Avaliar Reserva");
            System.out.println("4. Ver Minha Agenda");
            System.out.println("0. Sair");
            System.out.print("Escolha uma opção: ");
            String opcao = sc.nextLine();
            
            try {
                switch (opcao) {
                    case "1":
                        realizarReserva(cliente);
                        break;
                    case "2":
                        cancelarReserva(cliente);
                        break;
                    case "3":
                        avaliarReserva(cliente);
                        break;
                    case "4":
                        cliente.listarAgendaComIndices();
                        break;
                    case "0":
                        sair = true;
                        break;
                    default:
                        System.out.println("Opção inválida. Tente novamente.");
                }
            } catch (Exception e) {
                System.out.println("Erro no menu do cliente: " + e.getMessage());
            }
        }
    }

    private void realizarReserva(Cliente cliente) {
        List<Barbeiro> listaBarbeiros = admin.listarBarbeirosComIndices();
        
        System.out.print("Digite o índice do barbeiro desejado: ");
        try {
            int indexBarbeiro = Integer.parseInt(sc.nextLine());
            
            if (indexBarbeiro >= 0 && indexBarbeiro < listaBarbeiros.size()) {
                Barbeiro barbeiroSelecionado = listaBarbeiros.get(indexBarbeiro);
                realizarReservaComBarbeiro(cliente, barbeiroSelecionado);
            } else {
                System.out.println("Índice inválido.");
            }
        } catch (NumberFormatException e) {
            System.out.println("Por favor, digite um número válido.");
        } catch (Exception e) {
            System.out.println("Erro ao selecionar barbeiro: " + e.getMessage());
        }
    }

    private void realizarReservaComBarbeiro(Cliente cliente, Barbeiro barbeiro) {
        System.out.println("\n========== NOVA RESERVA ==========");

        admin.exibirServicos();

        System.out.print("Digite o nome do serviço exato: ");
        String nomeServico = sc.nextLine().toLowerCase();
        
        System.out.print("Digite a data (dd/MM/yyyy): ");
        String dataTexto = sc.nextLine();
        
        try {
            Servico servico = admin.getServicoByNome(nomeServico);

            LocalDate data = LocalDate.parse(dataTexto, formatoData);
            if (data.isBefore(LocalDate.now())) {
                System.out.println("Data inválida (já passou)");
                return;
            }
            
            List<LocalTime> horarios = barbeiro.getHorariosDisponiveis(data, servico);
            
            if (horarios.isEmpty()) {
                System.out.println("Não há horários disponíveis para esta data.");
                return;
            }
            
            System.out.println("Horários disponíveis:");
            for (int i = 0; i < horarios.size(); i++) {
                System.out.println("[" + i + "] " + horarios.get(i));
            }
            
            System.out.print("Escolha o número do horário: ");
            int idxHorario = Integer.parseInt(sc.nextLine());
            
            if (idxHorario >= 0 && idxHorario < horarios.size()) {
                LocalDateTime dataHoraFinal = LocalDateTime.of(data, horarios.get(idxHorario));
                AlocaReserva alocador = new AlocaReserva();
                alocador.realizarAgendamento(cliente, barbeiro, servico, dataHoraFinal);
                System.out.println("Agendamento realizado com sucesso para " + dataHoraFinal.format(formatoData) + " às " + horarios.get(idxHorario) + ".");
            } else {
                System.out.println("Horário inválido.");
            }
        } catch (Exception e) {
            System.out.println("Erro ao agendar: " + e.getMessage());
        }
    }

    private void cancelarReserva(Cliente cliente) {
        System.out.println("\n========== CANCELAR RESERVA ==========");
        List<Reserva> reservasAgendadas = cliente.listarAgendaComIndices(StatusReserva.AGENDADA);
        
        if (reservasAgendadas.isEmpty()) {
            System.out.println("Nenhuma reserva agendada disponível para cancelamento.");
            return;
        }
        
        for (int i = 0; i < reservasAgendadas.size(); i++) {
            Reserva r = reservasAgendadas.get(i);
            System.out.println("[" + i + "] " + r.getServico().getnome() + " em " +
                    r.getData().format(DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm")));
        }
        
        System.out.print("Digite o índice da reserva para cancelar: ");
        try {
            int idx = Integer.parseInt(sc.nextLine());
            Reserva r = reservasAgendadas.get(idx);
            
            if (r != null && r.verificaSePodeCancelar()) {
                cliente.cancelarReserva(r);
            } else {
                System.out.println("Reserva não encontrada.");
            }
        } catch (Exception e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }

    private void avaliarReserva(Cliente cliente) {
        System.out.println("\n========== AVALIAR RESERVA ==========");
        List<Reserva> reservasConcluidas = cliente.listarAgendaComIndices(StatusReserva.CONCLUIDA);
        
        if (reservasConcluidas.isEmpty()) {
            System.out.println("Nenhuma reserva concluída disponível para avaliação.");
            return;
        }
        
        for (int i = 0; i < reservasConcluidas.size(); i++) {
            Reserva r = reservasConcluidas.get(i);
            System.out.println("[" + i + "] " + r.getServico().getnome() + " em " + 
                    r.getData().format(formatoData));
        }
        
        System.out.print("Digite o índice da reserva: ");
        try {
            int idx = Integer.parseInt(sc.nextLine());
            Reserva r = reservasConcluidas.get(idx);
            
            if (r != null && r.verificaSePodeAvaliar()) {
                System.out.print("Nota (0-5): ");
                int nota = Integer.parseInt(sc.nextLine());
                System.out.print("Comentário: ");
                String comentario = sc.nextLine();
                cliente.avaliaReserva(r, nota, comentario);
            } else {
                System.out.println("Reserva inválida (não finalizada ou já avaliada).");
            }
        } catch (Exception e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }
}