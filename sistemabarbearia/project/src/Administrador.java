import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class Administrador extends Empregado{
    private String senha;
    private static HashMap<String, Servico> servicos = new HashMap<>();
    private static HashMap<String, Barbeiro> barbeiros = new HashMap<>();
    private static HashMap<String, Cliente> clientes = new HashMap<>();

    private static List<Recurso> listaRecursos = new ArrayList<>();

    public Administrador(String nome, String cpf, LocalDate dt_nasc, String telefone, String email,
                        LocalDate adimissao, double salario, String senha) throws Exception{
        super(nome, cpf, dt_nasc, telefone, email, adimissao, salario);
        setSenha(senha);
    }

    public void adicionarRecurso(Recurso recurso) {
        listaRecursos.add(recurso);
    }

    public void adicionarRecurso(Scanner sc) {

        System.out.print("Nome do recurso: ");
        String nome = sc.nextLine();
        System.out.print("Quantidade inicial desse recurso: ");
        int quantidade = Integer.parseInt(sc.nextLine());

        Recurso recurso = new Recurso(nome, quantidade);

        adicionarRecurso(recurso);

    }

    public void exibirRecursosComId() {
        System.out.println("\n========== Recursos da Barbearia ==========");
        for (int i = 0; i < listaRecursos.size(); i++) {
            int j = i+1;
            System.out.println("[" + j + "]" + listaRecursos.get(i).getNome());
        }
    }

    public void exibirRecursos() {
        System.out.println("\n========== Recursos da Barbearia ==========");
        for (Recurso recurso : listaRecursos) {
            System.out.println(recurso);
        }
    }

    public void adicionarServico(Servico servico) {
        servicos.put(servico.getnome().toLowerCase(), servico);
        System.out.println("Serviço adicionado com sucesso!");
    }

    public void adicionarServico(Scanner sc) {

        System.out.print("Nome do serviço: ");
        String nome = sc.nextLine();
        System.out.print("Duração do serviço (em minutos): ");
        int duracao = Integer.parseInt(sc.nextLine());
        System.out.print("Valor do serviço: ");
        double preco = Double.parseDouble(sc.nextLine());

        Servico servico = new Servico(duracao, preco, nome);

        servicos.put(servico.getnome().toLowerCase(), servico);
        
    }

    public List<Barbeiro> listarBarbeirosComIndices() {
        System.out.println("\n========== Barbeiros Disponíveis ==========");
        // Converte a coleção de barbeiros para uma lista para ter indices
        List<Barbeiro> listaOrdenada = new ArrayList<>(barbeiros.values());
        
        if (listaOrdenada.isEmpty()) {
            System.out.println("Nenhum barbeiro cadastrado.");
        } else {
            for (int i = 0; i < listaOrdenada.size(); i++) {
                // Exibe [0] Nome (indice + nome)
                System.out.println("[" + i + "] " + listaOrdenada.get(i).getNome() + ", Nota: " + listaOrdenada.get(i).calcularMediaAvaliacoes());
            }
        }
        return listaOrdenada;
    }

    public void adicionarBarbeiro(Barbeiro barbeiro) throws Exception{

        for (Recurso recurso : listaRecursos) {
            if (!recurso.estaDisponivel()) {
                throw new Exception("Não há '" + recurso.getNome() + "' suficiente para contratar mais barbeiros");
            }
        }

        for (Barbeiro b : barbeiros.values()) {
            if (b.getCpf().equalsIgnoreCase(barbeiro.getCpf())) {
                throw new Exception("Barbeiro com CPF '" + barbeiro.getCpf() + "' já existe.");
            }
        }

        // Consome 1 unidade de cada recurso
        for (Recurso recurso : listaRecursos) {
            recurso.consumir();
        }

        barbeiros.put(barbeiro.getCpf().toLowerCase(), barbeiro);
    }

    public void adicionarBarbeiro(Scanner sc) throws Exception{
        
        // Verifica disponibilidade de recursos
        for (Recurso recurso : listaRecursos) {
            if (!recurso.estaDisponivel()) {
                throw new Exception("Não há '" + recurso.getNome() + "' suficiente para contratar mais barbeiros");
            }
        }
        // Consume 1 recurso de cada tipo
        for (Recurso recurso : listaRecursos) {
            recurso.consumir();
        }

        // Le dados do barberio a ser contratado
        System.out.print("Nome do barbeiro: ");
        String nome = sc.nextLine();
        System.out.print("CPF do barbeiro: ");
        String cpf = sc.nextLine();
        System.out.print("Data de nascimento (dd/mm/yyyy): ");
        LocalDate dt_nasc = LocalDate.parse(sc.nextLine(), java.time.format.DateTimeFormatter.ofPattern("dd/MM/yyyy"));
        System.out.print("Telefone do barbeiro: ");
        String telefone = sc.nextLine();
        System.out.print("Email do barbeiro: ");
        String email = sc.nextLine();
        System.out.print("Salário do barbeiro: ");
        double salario = Double.parseDouble(sc.nextLine());

        // Cria barbeiro
        Barbeiro barbeiro = new Barbeiro(nome, cpf, dt_nasc, telefone, email, salario);

        //barbeiros.put(barbeiro.getNome().toLowerCase(), barbeiro);
        barbeiros.put(barbeiro.getCpf().toLowerCase(), barbeiro);
        System.out.println("Barbeiro " + barbeiro.getNome() + " contratado com sucesso! Recursos alocados.");

    }

    public void adicionarCliente(Cliente cliente) throws Exception{
        if (clientes.containsKey(cliente.getNome().toLowerCase())) {
            throw new Exception("Cliente com nome '" + cliente.getNome() + "' já existe.");
        }

        clientes.put(cliente.getCpf(), cliente);
    }

    public void adicionarCliente(Scanner sc) throws Exception {
        
        // Le dados do novo cliente
        System.out.print("Nome do cliente: ");
        String nome = sc.nextLine();
        System.out.print("CPF do cliente: ");
        String cpf = sc.nextLine();
        System.out.print("Data de nascimento (dd/mm/yyyy): ");
        LocalDate dt_nasc = LocalDate.parse(sc.nextLine(), java.time.format.DateTimeFormatter.ofPattern("dd/MM/yyyy"));
        System.out.print("Telefone do cliente: ");
        String telefone = sc.nextLine();
        System.out.print("Email do cliente: ");
        String email = sc.nextLine();

        // Cria cliente
        Cliente cliente = new Cliente(nome, cpf, dt_nasc, telefone, email);
        //clientes.put(cliente.getNome().toLowerCase(), cliente);
        clientes.put(cliente.getCpf(), cliente);

    }

    public void exibirServicos() {
        System.out.println("\n========== Serviços Disponíveis ==========");
        for (Servico servico : servicos.values()) {
            System.out.println(servico);
        }
    }

    public void exibirBarbeiros() {
        System.out.println("\n========== Barbeiros Disponíveis ==========");
        for (Barbeiro barbeiro : barbeiros.values()) {
            System.out.println(barbeiro);
        }
    }

    public void exibirClientes() {
        System.out.println("\n========== Clientes Cadastrados ==========");
        for (Cliente cliente : clientes.values()) {
            System.out.println(cliente);
        }
    }

    public Servico getServicoByNome(String nome) throws Exception{
        if (!servicos.containsKey(nome)) {
            throw new Exception("Serviço não encontrado: " + nome);
        }
        return servicos.get(nome);
    }

    public Cliente getClienteByCpf(String cpf) throws Exception{
        if (!clientes.containsKey(cpf)) {
            throw new Exception("Cliente não encontrado: " + cpf);
        }
        return clientes.get(cpf);
    }

    public Barbeiro getBarbeiroByCpf(String cpf) throws Exception {
        if (!barbeiros.containsKey(cpf)) {
            throw new Exception("Barbeiro não encontrado: " + cpf);
        }
        return barbeiros.get(cpf);
    }

    public Recurso getRecursoByIndice(int indice) throws Exception {
        if (indice > listaRecursos.size() || indice < 0) {
            throw new Exception("Indice digitado invalido: ");
        }
        return listaRecursos.get(indice);
    }

    public boolean autenticaSenha(String senhaInput)
    {
        return senhaInput.equals(this.getSenha());
    }

    private String getSenha()
    {
        return senha;
    }

    private void setSenha(String _senha)
    {
        senha = _senha;
    }

    public void removerCliente(Scanner sc) throws Exception {
        exibirClientes();
        System.out.print("Digite o CPF do cliente a ser removido: ");
        String cpf = sc.nextLine();

        if (!clientes.containsKey(cpf)) {
            throw new Exception("Cliente não encontrado com o CPF: " + cpf);
        }

        Cliente removido = clientes.remove(cpf);
        System.out.println("Cliente " + removido.getNome() + " removido com sucesso.");
    }

    public void removerBarbeiro(Scanner sc) throws Exception {
        exibirBarbeiros();
        System.out.print("Digite o CPF do barbeiro a ser demitido: ");
        String cpf = sc.nextLine();

        String key = cpf.toLowerCase();

        if (!barbeiros.containsKey(key)) {
            throw new Exception("Barbeiro não encontrado com o CPF: " + cpf);
        }

        Barbeiro demitido = barbeiros.remove(key);

        // Devolve a todos recursos 1 unidade
        for (Recurso recurso : listaRecursos) {
            recurso.repor(); 
        }

        System.out.println("Barbeiro " + demitido.getNome() + " demitido e recursos liberados.");
    }

    public void removerServico(Scanner sc) throws Exception {
        exibirServicos();
        System.out.print("Digite o nome do serviço a ser removido: ");
        String nome = sc.nextLine();
        String key = nome.toLowerCase();

        if (!servicos.containsKey(key)) {
            throw new Exception("Serviço não encontrado: " + nome);
        }

        Servico removido = servicos.remove(key);
        System.out.println("Serviço '" + removido.getnome() + "' removido com sucesso.");
    }

    public void removerRecurso(Scanner sc) throws Exception {
        exibirRecursos();
        System.out.print("Digite o número (índice) do recurso a remover: ");
        
        int indice;
        try {
            indice = Integer.parseInt(sc.nextLine());
        } catch (NumberFormatException e) {
            throw new Exception("Índice inválido.");
        }

        // Ajuste do índice visual (começa em 1 no exibirRecursos) para o índice da lista (começa em 0)
        int indiceReal = indice - 1;

        if (indiceReal < 0 || indiceReal >= listaRecursos.size()) {
            throw new Exception("Recurso não encontrado no índice informado.");
        }

        Recurso removido = listaRecursos.remove(indiceReal);
        System.out.println("Recurso '" + removido.getNome() + "' removido do sistema.");
    }

}
