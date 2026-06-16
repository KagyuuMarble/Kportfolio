public class Funcionario extends Pessoa
{
   private String registro;
   private double salario;
   
   //construct
   public Funcionario(String nome, String telefone, Data nascimento, String registro, double salario)
   {
      super(nome, telefone, nascimento);
      this.registro = registro;
      this.salario = salario; 
   }
   public Funcionario(String nome, Data nascimento, String registro, double salario)
   {
      super(nome, nascimento);
      this.registro = registro;
      this.salario = salario;
   }
   
   //gets and sets
   public String getRegistro()
   {
      return registro;
   }
   public final double getSalario()
   {
      return salario;
   }
   public double getSalarioComBonificacao()
   {
      return salario + bonificar();
   }
   public void setRegistro(String registro)
   {
      this.registro = registro;
   }
   public void setSalario(double salario)
   {
      this.salario = salario;
   }
   
   //metodos
   public double bonificar()
   {
      return salario * 0.1;
   }
   
   //metodo toString
   public String toString()
   {
      return super.toString() +
      "Registro:\t" + registro + "\n"
       + "Salario:\t" + salario + "\n";
   }
   
}