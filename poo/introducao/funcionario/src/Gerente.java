public class Gerente extends Funcionario {
    private String departamento;

    public void setDepartamento(String _departamento) {

        this.departamento = _departamento;
    }

    public String getDepartamento() {
        return this.departamento;
    }

    public float calculaBonus() {
        if (getDepartamento() == "TI") {
            return super.getSalario() / 2;
        }

        return 0;
    }

    public Gerente(String _cpf, String _nome, float _salario, String _departamento) {
        super(_cpf, _nome, _salario);
        setDepartamento(_departamento);
    }

    @Override
    public void exibeDados() {
        System.out.println("GERENTE:");
        super.exibeDados();
        System.out.println(getDepartamento());
        System.out.println("BONUS: " + calculaBonus());
    }
}
