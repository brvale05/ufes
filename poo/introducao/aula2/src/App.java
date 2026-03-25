public class App 
{
    public static void main(String[] args) throws Exception 
    {
        Endereco end = new Endereco("rua", "vitoria", "espirito santo", "29100230");

        System.out.println("Logradouro: " + end.getLogradouro());
        System.out.println("Cidade: " + end.getCidade());
        System.out.println("Estado: " + end.getEstado());
        System.out.println("CEP: " + end.getCep());

        Cliente client = new Cliente("bruno vale", "18871887632", "27 992049698");

        System.out.println("NOME: " + client.getNome());
        System.out.println("CPF: " + client.getCpf());
        System.out.println("Telefone: " + client.getTelefone());

        client.setEndereco(end);

    }
}
